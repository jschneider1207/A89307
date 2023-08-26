#include "A89307.hpp"

A89307::A89307(TwoWire *wire) : _wire(wire)
{
}

A89307::~A89307()
{
}

bool A89307::begin()
{
	_wire->begin();
	return true;
}

bool A89307::loadRegisters()
{
	for (uint8_t i; i < 21; i++)
	{
		if (!readRegister(&_registers[i]))
		{
			i--;
		}
		delay(DELAY);
	}

	return true;
}

void A89307::printRegisters()
{
	for (uint8_t i = 0; i < 21; i++)
	{
		Serial.print("Register ");
		Serial.print(_registers[i].shadowAddress);
		Serial.print(": 0b");
		Serial.println(_registers[i].value, BIN);
	}
}

/* Private interface */

bool A89307::readRegister(A89307_Reg::Register *reg)
{
	uint8_t err = 255;
	while ((err = beginRead(reg->shadowAddress)) != 0)
	{
		delay(DELAY);
	}

	uint8_t *data;
	if (!finishRead(data))
	{
		reg->initialized = false;
	}
	else
	{
		uint8_t tmp;

		tmp = (*data++);
		reg->value |= (uint32_t)tmp << 16;

		tmp = (*data++);
		reg->value |= (uint32_t)tmp << 8;

		tmp = (*data++);
		reg->value |= (uint32_t)tmp;

		reg->initialized = true;
	}
	return reg->initialized;
}

uint8_t A89307::beginRead(uint8_t address)
{
	uint8_t result;
	_wire->beginTransmission(deviceAddress);
	if (_wire->write(address) == 0)
	{
		Serial.println("I2C BUFFER FULL");
	}
	return _wire->endTransmission();
}

bool A89307::finishRead(uint8_t *data)
{

	while (3 != _wire->requestFrom(deviceAddress, 3))
	{
		delay(DELAY);
	}

	delay(DELAY);

	uint8_t count = _wire->readBytes(data, 3);

	return count == 3;
}
