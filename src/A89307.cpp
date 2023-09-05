#include "A89307.hpp"

namespace A89307
{

	// -----------------------------------------------------------------------------
	//                         >---- A89307Chip class ----<
	// -----------------------------------------------------------------------------

	A89307Chip::A89307Chip(I2CDriver *driver) : _driver(driver)
	{
	}

	A89307Chip::~A89307Chip()
	{
	}

	bool A89307Chip::begin()
	{
		Serial.begin(115200);
		// _driver->enable();
		// _driver->flushBus();
		_driver->begin();
		// _driver->ping();

		Address::fillAddressMapDefault(_addressMap);
		Register::fillAllRegsWithDefault(_registers);
		syncRegisters();

		return true;
	}

	bool A89307Chip::end()
	{
		_driver->end();
		return true;
	}

	void A89307Chip::readAddressMap()
	{
		for (Address address : _addressMap)
		{
			_driver->readAddress(address.shadowAddress, &(address.data));
		}
		syncRegisters();
	}

	void A89307Chip::writeAddressMap()
	{
		for (Address address : _addressMap)
		{
			// These addresses are locked/have no registers
			if (address.eepromAddress == 27 || address.eepromAddress == 31)
			{
				continue;
			}

			D(
					Serial.print("Writing to address ");
					Serial.print(address.shadowAddress);
					Serial.print(":\t{0x");
					if (address.data.bytes[2] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[2], HEX);
					Serial.print(", 0x");
					if (address.data.bytes[1] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[1], HEX);
					Serial.print(", 0x");
					if (address.data.bytes[0] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[0], HEX);
					Serial.print("}\t (0b");
					Serial.print(address.data.value, BIN);
					Serial.println(')');)
			_driver->writeAddress(address.shadowAddress, &(address.data));
			D(Serial.println("Write complete");)
		}
	}

	uint8_t A89307Chip::syncStatus(uint8_t *outOfSync)
	{
		uint8_t oosCount = 0;

		for (Address address : _addressMap)
		{
			D(Serial.print("Reading address ");
				Serial.println(address.shadowAddress);)
			uint8_t buff[4] = {0x00, 0x00, 0x00, 0x00};
			_driver->readAddress(address.shadowAddress, (DataWord *)buff);
			D(Serial.println("Read complete");)
			if (address.data.value != ((DataWord *)buff)->value)
			{
				// 	oosCount++;
				// 	// *outOfSync = address.shadowAddress;
				// 	// outOfSync++;
				D(Serial.print("Address ");
					Serial.print(address.shadowAddress);
					Serial.print(" out of sync. Expected 0b");
					Serial.print(address.data.value, BIN);
					Serial.print(", got 0b");
					Serial.println(((DataWord *)buff)->value, BIN);)
			}
		}

		return oosCount;
	}

	void A89307Chip::printRegister(RegisterId id)
	{
		char name[32];
		Register *reg = &_registers[id];
		Register::copyRegisterName(id, name);
		Serial.print(name);
		Serial.print(" = 0x");
		Serial.print(reg->value, HEX);
		Serial.print(" (");
		Serial.print(reg->value);
		Serial.println(")");
	}

	void A89307Chip::printRegisters()
	{
		for (Register reg : _registers)
		{
			printRegister((RegisterId)reg.id);
		}
	}

	void A89307Chip::printAddressMap()
	{
		for (uint8_t idx = 0; idx < ADDRESS_COUNT; idx++)
		{

			Serial.print("0x");
			Serial.print(_addressMap[idx].shadowAddress, HEX);
			Serial.print(":0x");
			Serial.println(_addressMap[idx].data.value, HEX);
		}
	}

	// -----------------------------------------------------------------------------
	//                         >---- Private interface ----<
	// -----------------------------------------------------------------------------

	void A89307Chip::syncRegisters()
	{
		uint8_t registerIdx = 0;
		for (Address address : _addressMap)
		{
			while (_registers[registerIdx].shadowAddress == address.shadowAddress && registerIdx < RegisterId::Reg_No)
			{
				uint32_t tmp = (address.data.value >> _registers[registerIdx].position) & (_registers[registerIdx].bitMask());
				_registers[registerIdx++].value = tmp;
			}
		}
	}
}