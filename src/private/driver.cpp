#include "driver.hpp"

// -----------------------------------------------------------------------------
//                         >---- I2CDriver class ----<
// -----------------------------------------------------------------------------
namespace A89307
{

  I2CDriver::I2CDriver(I2C_DMAC *wire) : _wire(wire), _begun(false)
  {
  }

  I2CDriver::~I2CDriver()
  {
  }

  void I2CDriver::begin()
  {
    if (!_begun)
    {
      _wire->begin(); // Default clock speed is 100kHz
      _wire->setPriority(DMAC_PRIORITY);
      _begun = !_begun;
    }
  }

  void I2CDriver::end()
  {
    if (_begun)
    {
      _wire->end();
      _begun = !_begun;
    }
  }

  /**
   * @brief The chip seems super finicky with I2C, this seems to help ensure it boots into I2C mode.
   *
   */
  void I2CDriver::enable()
  {
    bool turnOn = _begun;
    end(); // ensure TwoWire is disabled for this, will turn it back on after
    D(Serial.println("Pulling both lines low for 1 sec...");)
    pinMode(SDA_PIN, OUTPUT);
    pinMode(SCL_PIN, OUTPUT);
    digitalWrite(SDA_PIN, LOW);
    digitalWrite(SCL_PIN, LOW);
    delay(1000);
    pinMode(SDA_PIN, INPUT);
    pinMode(SCL_PIN, INPUT);
    D(Serial.println("Done, releasing lines");)
    if (turnOn)
    {
      begin();
    }
  }

  void I2CDriver::readAddress(uint8_t address, DataWord *data)
  {
    uint8_t buffer[3] = {0x00, 0x00, 0x00};
    _wire->readBytes(DEVICE_ADDRESS, address, (uint8_t *)buffer, 3);
    waitForRead();
    D(Serial.print("0x");
      Serial.print(buffer[0], HEX);
      Serial.print(buffer[1], HEX);
      Serial.println(buffer[2], HEX);)
  }

  void I2CDriver::writeAddress(uint8_t address, DataWord *data)
  {
    _wire->writeBytes(DEVICE_ADDRESS, address, (uint8_t *)data, 3);
    waitForWrite();
  }

  // -----------------------------------------------------------------------------
  //                         >---- Private interface ----<
  // -----------------------------------------------------------------------------

  inline void I2CDriver::waitForRead()
  {
    while (_wire->readBusy)
      ;
  }

  inline void I2CDriver::waitForWrite()
  {
    while (_wire->writeBusy)
      ;
  }

  I2CDriver Driver(&I2C);
}