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
		_driver->enable();
		_driver->flushBus();
		_driver->begin();
		_driver->ping();

		Address::fillAddressMapDefault(_addressMap);
		Register::fillAllRegsWithDefault(_registers);

		return true;
	}

	bool A89307Chip::end()
	{
		_driver->end();
		return true;
	}

	void A89307Chip::writeAddressMap()
	{
		for (Address address : _addressMap)
		{
			// These addresses are locked/have no registers
			if (address.eepromAddress == 27 || address.eepromAddress == 31 || address.shadowAddress == 72)
			{
				continue;
			}

			D(
					Serial.print("Writing to address ");
					Serial.print(address.shadowAddress);
					Serial.print(": 0x");
					if (address.data.bytes[2] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[2], HEX);
					Serial.print(", 0x");
					if (address.data.bytes[1] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[1], HEX);
					Serial.print(", 0x");
					if (address.data.bytes[0] < 16) { Serial.print('0'); } Serial.print(address.data.bytes[0], HEX);
					Serial.print(" (0b");
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
			DataWord fromChip;
			_driver->readAddress(address.shadowAddress, &fromChip);
			D(Serial.println("Read complete");)
			if (address.data.value != fromChip.value)
			{
				oosCount++;
				// *outOfSync = address.shadowAddress;
				// outOfSync++;
				D(Serial.print("Address ");
					Serial.print(address.shadowAddress);
					Serial.print(" out of sync. Expected 0b");
					Serial.print(address.data.value, BIN);
					Serial.print(", got 0b");
					Serial.println(fromChip.value, BIN);)
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

			Serial.print(_addressMap[idx].eepromAddress);
			Serial.print(":");
			Serial.println(_addressMap[idx].data.value, BIN);
		}
	}

	uint8_t A89307Chip::readShadowRegistersSequentially()
	{
		_driver->requestAddress(_addressMap[0].shadowAddress);

		// Read all the addresses
		uint8_t regIdx = 0;
		for (uint8_t addrIdx = 0; addrIdx < ADDRESS_COUNT; addrIdx++)
		{
			DataWord data = {0x00};
			_driver->readNext(&data, addrIdx == (ADDRESS_COUNT - 1));

			if ((data.bytes[2] >> 2) != 0 ||
					(data.bytes[1] == 0xFF && data.bytes[0] == 0xFF))
			{
				addrIdx--;
			}
			else
			{
				_addressMap[addrIdx].data = data;

				// Fill registers for current address
				while (_registers[regIdx].shadowAddress == _addressMap[addrIdx].shadowAddress)
				{
					uint32_t tmp = (data.value >> _registers[regIdx].position) & (_registers[regIdx].bitMask());
					_registers[regIdx++].value = tmp;
				}
			}
		}

		return 0;
	}

	uint8_t A89307Chip::readShadowRegisters()
	{
		// Read all the addresses
		uint8_t regIdx = 0;
		for (uint8_t addrIdx = 0; addrIdx < ADDRESS_COUNT; addrIdx++)
		{
			DataWord data = {0x00};
			_driver->requestAddress(_addressMap[addrIdx].shadowAddress);
			_driver->readNext(&data);

			if ((data.bytes[0] >> 2) != 0x00 ||
					(data.bytes[1] == 0xFF && data.bytes[2] == 0xFF))
			{
				addrIdx--;
			}
			else
			{
				Serial.print("DEBUG: ");
				Serial.print(_addressMap[addrIdx].shadowAddress);
				Serial.print(":");
				Serial.print(data.bytes[2], BIN);
				Serial.print(' ');
				Serial.print(data.bytes[1], BIN);
				Serial.print(' ');
				Serial.println(data.bytes[0], BIN);
				Serial.print("DEBUG: ");
				Serial.print(_addressMap[addrIdx].shadowAddress);
				Serial.print(":");
				Serial.println(data.value, BIN);
				_addressMap[addrIdx].data = data;

				// Fill registers for current address
				while (_registers[regIdx].shadowAddress == _addressMap[addrIdx].shadowAddress)
				{
					uint32_t tmp = (data.value >> _registers[regIdx].position) & (_registers[regIdx].bitMask());
					_registers[regIdx++].value = tmp;
				}
			}
		}

		return 0;
	}

	uint8_t A89307Chip::updateRegister(RegisterId id, uint32_t value)
	{
		Register *reg = &(_registers[id]);
		uint8_t addressIdx = reg->shadowAddress - _addressMap[0].shadowAddress;
		Address *address = &(_addressMap[addressIdx]);

		reg->value = value;
		uint32_t mask = ~(reg->bitMask() << reg->position);
		uint32_t tmp = (address->data.value & mask) | (reg->value << reg->position);
		address->data.value = tmp;
		return _driver->writeAddress(address->shadowAddress, &(address->data));
	}

	// -----------------------------------------------------------------------------
	//                         >---- Private interface ----<
	// -----------------------------------------------------------------------------

}