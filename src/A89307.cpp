#include "A89307.hpp"

extern "C"
{
#ifdef __AVR__
#include <avr/pgmspace.h>
#else
#define PROGMEM
#define memcpy_P memcpy
#define pgm_read_word
#define strcpy_P strcpy
#endif
}

using namespace A89307;

// -----------------------------------------------------------------------------
//                         >---- A89307Driver class ----<
// -----------------------------------------------------------------------------

A89307Driver::A89307Driver(TwoWire *wire) : _wire(wire)
{
}

A89307Driver::~A89307Driver()
{
}

bool A89307Driver::begin()
{
	_wire->begin();

	Register::fillAllRegsWithDefault(_registers);

	return true;
}

/**
 * @brief Gets the value of a register.
 *
 * @param id Id of the register to retrieve.
 * @param data Pointer to store the register data.
 * @param forceRefresh Read the register from the device first.
 * @return 0 for success or -1 for failure.
 */
int32_t A89307Driver::getRegister(RegisterId id, Register **reg, bool forceRefresh)
{
	if ((id < RegisterId::Rated_Speed) || (id >= RegisterId::Reg_No))
	{
		return -1;
	}

	int32_t err = 0;
	if (forceRefresh)
	{
		err = readRegister(id);
	}

	*reg = &_registers[id];
	return err;
}

/**
 * @brief Reads a register from the device.
 *
 * @param id Id of the register to read.
 * @return 0 for success or error code for fail.
 */
uint8_t A89307Driver::readRegister(RegisterId id)
{
	return readAddress(_registers[id].shadowAddr());
}

uint8_t A89307Driver::readRegisters()
{
	uint8_t timeout = TIMEOUT;
	for (uint8_t i = 0; i < ADDRESS_COUNT; i++)
	{
		Serial.print("Reading address 0x");
		Serial.printHexln(SHADOW_ADDRESS_LIST[i]);
		uint8_t err = readAddress(SHADOW_ADDRESS_LIST[i]);
		if (err != 0)
		{
			Serial.print("Read error: 0x");
			Serial.printHexln(err);
			if (timeout == 0)
			{
				return 0xFF;
			}

			timeout--;
			i--;
			delay(1);
		}
		delay(DELAY);
	}
	return 0;
}

void A89307Driver::printRegister(RegisterId id)
{
	char name[32];
	Register *reg;
	if (Register::copyRegisterName(id, name) > 0)
	{
		getRegister(id, &reg);
		Serial.print('\t');
		Serial.print(name);
		Serial.print(" = 0b");
		Serial.println(reg->value, BIN);
	}
}

void A89307Driver::printRegisters()
{
	uint8_t currentAddress = 0x00;
	for (uint8_t reg = 0; reg < RegisterId::Reg_No; reg++)
	{
		uint8_t tmp = _registers[reg].shadowAddr();
		if (currentAddress != tmp)
		{
			currentAddress = tmp;
			Serial.print("Address 0x");
			Serial.printHex(currentAddress);
			Serial.println(":");
		}
		printRegister((RegisterId)reg);
	}
}

// -----------------------------------------------------------------------------
//                         >---- Private interface ----<
// -----------------------------------------------------------------------------

const uint8_t A89307Driver::EEPROM_ADDRESS_LIST[ADDRESS_COUNT] = {8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 29, 30};
const uint8_t A89307Driver::SHADOW_ADDRESS_LIST[ADDRESS_COUNT] = {72, 73, 74, 75, 76, 77, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 92, 93, 94};
/**
 * @brief Reads an address from the device and populates the associated registers.
 *
 * @note The address is looked up using the given register id.
 * @param id Register id.
 * @return 0 for success or error code for fail.
 */
uint8_t
A89307Driver::readAddress(RegisterId id)
{
	return readAddress(&_registers[id]);
}

/**
 * @brief Reads an address from the device and populates the associated registers.
 *
 * @note The address for the given resister is used.
 * @param reg Pointer to the register.
 * @return 0 for success or error code for fail.
 */
uint8_t A89307Driver::readAddress(Register *reg)
{
	return readAddress(reg->shadowAddr());
}

/**
 * @brief Reads an address from the device and populates the associated registers.
 *
 * @param address The address to read.
 * @return 0 for success or error code for fail.
 */
uint8_t A89307Driver::readAddress(uint8_t address)
{
	uint8_t err = 0;
	err = beginRead(address);
	if (err != 0)
	{
		return ReadError::ReadInitFailed;
	}

	delay(DELAY);

	uint8_t words[3] = {0x00, 0x00, 0x00};
	if (!finishRead(words))
	{
		return ReadError::NoReply;
	}

	int32_t data = validateRead(words);
	if (data == -1)
	{
		return ReadError::InvalidData;
	}

	RegisterId registerIds[MAX_REGISTERS_PER_ADDRESS];
	uint8_t count = Address::copyRegistersForAddress(address, registerIds);

	for (uint8_t i = 0; i < count; i++)
	{
		RegisterId id = registerIds[i];
		_registers[id].value = -1;
		uint8_t tmp = ((data >> _registers[id].position) & _registers[id].bitMask());
		_registers[id].value = tmp;
	}

	return 0;
}

uint8_t A89307Driver::beginRead(uint8_t address)
{
	_wire->beginTransmission(DEVICE_ADDRESS);
	if (_wire->write(address) == 0)
	{
		Serial.println("I2C BUFFER FULL");
	}
	return _wire->endTransmission();
}

bool A89307Driver::finishRead(uint8_t *word)
{

	if (_wire->requestFrom(DEVICE_ADDRESS, 3) == 0)
	{
		return false;
	}

	delay(DELAY);

	uint8_t count = _wire->readBytes(word, 3);

	return count == 3;
}

/**
 * All the A89307's register addresses are 24 bits wide with the 6 MSB used
 * by the chip for error detection and correction (ECC) and the 18 LSB bits
 * used to store data.
 *
 * As I2C works in three byte transmissions, the 6 MSB bits of the first byte
 * are the ECC bits and should always be 0x00. 0xFFFF for the 16 LSB bits
 * is treated as a read/transmission error.
 * @note Read breakdown: 000000XX YYYYYYYY ZZZZZZZZ
 * @param data Array of 3 bytes read from the I2C bus.
 * @return Data bits if valid, else -1
 */
int32_t A89307Driver::validateRead(uint8_t word[3])
{
	// uint32_t tmp = word[0];
	uint8_t ecc = word[0] >> 2;
	if (ecc != 0x00)
	{
		return -1;
	}

	uint32_t data = 0;
	data |= (((1UL << 2) - 1) & word[0]) << 16; // 2 LSB of first word are 2 MSB of data
	data |= word[1] << 8;
	data |= word[2];

	return (((1UL << 16) - 1) & data) == 0xFFFF ? -1 : data;
}
