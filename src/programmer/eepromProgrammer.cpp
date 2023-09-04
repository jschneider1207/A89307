#include "eepromProgrammer.hpp"

// -----------------------------------------------------------------------------
//                         >---- EEPROMProgrammer class ----<
// -----------------------------------------------------------------------------
namespace A89307
{
  EEPROMProgrammer::EEPROMProgrammer(Write writes[], uint8_t count, I2CDriver *driver) : _driver(driver), _writes(writes), _count(count), _writesRemaining(count), _writeIdx(0)
  {
  }

  EEPROMProgrammer::~EEPROMProgrammer()
  {
  }

  void EEPROMProgrammer::begin()
  {
    _driver->enable();
    _driver->begin();
    _driver->ping();
    enableEEPROM();
  }

  void EEPROMProgrammer::end()
  {
    disableEEPROM();
    _driver->end();
  }

  uint8_t EEPROMProgrammer::writeNext()
  {
    if (_writesRemaining == 0)
    {
      return 0;
    }

    const Write *write = &(_writes[_writeIdx]);

    clearEEPROM(write->address);

    delayMicroseconds(10);

    writeEEPROM(write->address, (*write).data);
    delayMicroseconds(10);
    DataWord readBack = {0x00};
    _driver->requestAddress(write->address);
    _driver->readNext(&readBack);

    Serial.print("Wrote 0x");
    Serial.print(write->data.bytes[2], HEX);
    Serial.print(write->data.bytes[1], HEX);
    Serial.print(write->data.bytes[0], HEX);
    Serial.print(" to address ");
    Serial.print(write->address);
    Serial.print(", reading back received 0x");
    Serial.print(readBack.bytes[2], HEX);
    Serial.print(readBack.bytes[1], HEX);
    Serial.println(readBack.bytes[0], HEX);

    if (write->data.value != readBack.value)
    {
      Serial.println("Write failed, will retry");
    }
    else
    {
      _writeIdx++;
      _writesRemaining--;
    }

    return _writesRemaining;
  }

  void EEPROMProgrammer::enableEEPROM(void)
  {
    Serial.print("Enabling EEPROM... ");
    DataWord data = {0x01, 0x00, 0x00, 0x00};
    _driver->writeAddress(0xC4, &data);
    Serial.println("Complete");
  }

  void EEPROMProgrammer::disableEEPROM(void)
  {
    Serial.print("Disabling EEPROM... ");
    DataWord data = {0x00, 0x00, 0x00, 0x00};
    _driver->writeAddress(0xC4, &data);
    Serial.println("Complete");
  }

  void EEPROMProgrammer::clearEEPROM(uint8_t addr)
  {
    Serial.print("Clearing address ");
    Serial.print(addr);
    Serial.print("... ");

    // Write the address to 192
    DataWord data = {addr, 0x00, 0x00, 0x00};
    _driver->writeAddress(192, &data);

    // Write data to 193
    data.value = 0;
    _driver->writeAddress(193, &data);

    // Write erase and voltage high to 191
    data.bytes[0] = 0x03;
    _driver->writeAddress(191, &data);

    delay(20); // requires 15 ms high-voltage pulse to erase.

    // Write erase and voltage high to 191
    _driver->writeAddress(191, &data);

    delay(20); // requires 15 ms high-voltage pulse to erase.

    Serial.println("Complete");
  }

  void EEPROMProgrammer::writeEEPROM(uint8_t addr, DataWord word)
  {
    Serial.print("Writing to address ");
    Serial.print(addr);
    Serial.print("... ");

    // Write the address to 192
    DataWord tmp = {addr, 0x00, 0x00, 0x00};
    _driver->writeAddress(192, &tmp);

    // Write data to 193
    _driver->writeAddress(193, &word);

    // Write write and voltage high to 191
    tmp.bytes[0] = 0x05;
    _driver->writeAddress(191, &tmp);

    delay(20); // requires 15 ms high-voltage pulse to write.

    Serial.println("Complete");
  }

}