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

	Address::fillAddressMapDefault(_addressMap);
	Register::fillAllRegsWithDefault(_registers);

	return true;
}

void A89307Driver::printRegister(RegisterId id)
{
	char name[32];
	Register *reg = &_registers[id];
	if (Register::copyRegisterName(id, name) > 0)
	{
		Serial.print(name);
		Serial.print(" = 0b");
		Serial.print(reg->value, BIN);
		Serial.print(" (");
		Serial.print(reg->value);
		Serial.println(")");
	}
}

void A89307Driver::printRegisters()
{
	for (Register reg : _registers)
	{
		printRegister((RegisterId)reg.id);
	}
}

void A89307Driver::printAddressMap()
{
	for (uint8_t idx = 0; idx < ADDRESS_COUNT; idx++)
	{

		Serial.print("0x");
		Serial.printHex(_addressMap[idx].shadowAddress);
		Serial.print(":");
		Serial.println(_addressMap[idx].value, BIN);
	}
}

uint8_t A89307Driver::readShadowRegisters()
{
	uint8_t timeout = TIMEOUT;

	// Kick off read
	while (beginRead(_addressMap[0].shadowAddress) != 0 && timeout > 0)
	{
		timeout--;
		delay(1);
	};

	if (timeout == 0)
	{
		return ReadError::ReadInitFailed;
	}

	// Read all the addresses
	uint8_t regIdx = 0;
	for (uint8_t addrIdx = 0; addrIdx < ADDRESS_COUNT; addrIdx++)
	{
		uint8_t buff[3] = {0x00, 0x00, 0x00};
		while (readNext(buff, addrIdx == (ADDRESS_COUNT - 1)) != 0 && timeout > 0)
		{
			timeout--;
			delay(1);
		};

		if (timeout == 0)
		{
			return ReadError::NoReply;
		}

		// uint32_t data = *((uint32_t *)buff);
		uint32_t data = 0x00;
		data |= ((uint32_t)buff[0]) << 16;
		data |= ((uint32_t)buff[1]) << 8;
		data |= ((uint32_t)buff[2]);

		_addressMap[addrIdx].value = data;

		// Fill registers for current address
		while (_registers[regIdx].shadowAddress == _addressMap[addrIdx].shadowAddress)
		{
			uint32_t tmp = (data >> _registers[regIdx].position) & (_registers[regIdx].bitMask());
			_registers[regIdx++].value = tmp;
		}
	}

	return ReadError::Success;
}

// -----------------------------------------------------------------------------
//                         >---- Private interface ----<
// -----------------------------------------------------------------------------

uint8_t A89307Driver::beginRead(uint8_t address)
{
	_wire->beginTransmission(DEVICE_ADDRESS);
	if (_wire->write(address) == 0)
	{
		Serial.println("I2C BUFFER FULL");
	}
	return _wire->endTransmission();
}

uint8_t A89307Driver::readNext(uint8_t *data, bool sendStop)
{
	if (!_wire->requestFrom(DEVICE_ADDRESS, 3, sendStop))
	{
		return ReadError::NoReply;
	};

	(*data++) = _wire->read();
	(*data++) = _wire->read();
	(*data++) = _wire->read();
	return 0;
}