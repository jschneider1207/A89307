#include "driver.hpp"

// -----------------------------------------------------------------------------
//                         >---- I2CDriver class ----<
// -----------------------------------------------------------------------------
namespace A89307
{

  I2CDriver::I2CDriver(TwoWire *wire) : _wire(wire), _begun(false)
  {
  }

  I2CDriver::~I2CDriver()
  {
  }

  void I2CDriver::begin()
  {
    if (!_begun)
    {
      _wire->begin();
      // _wire->setClock(CLK_SPEED);
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

  void I2CDriver::ping()
  {
    D(Serial.println("Pinging address 0x55...");)
    requestAddress(72);
    DataWord data = {0, 0, 0, 0};
    readNext(&data);
    D(Serial.println("Device found");)
  }

  void I2CDriver::flushBus()
  {
    bool turnOn = _begun;
    end(); // Ensure TwoWire is disabled for this, will turn it back on after
    D(Serial.println("Checking if someone is holding SDA low...");)
    pinMode(SDA_PIN, INPUT);
    if (digitalRead(SDA_PIN) == LOW)
    {
      D(Serial.println("Was being held low, bit-banging the clock a bunch");)
      // A slave is holding it high,
      pinMode(SCL_PIN, OUTPUT);
      digitalWrite(SCL_PIN, HIGH);
      // tell them to stfu by bit-banging the clock
      float period = 1 / CLK_SPEED;
      uint32_t clock_half_period_us = (uint32_t)(period / 2 * 1000000);
      delayMicroseconds(clock_half_period_us);
      for (uint8_t i = 0; i < 0xFF; i++)
      {
        digitalWrite(SCL_PIN, LOW);
        delayMicroseconds(clock_half_period_us);
        digitalWrite(SCL_PIN, HIGH);
        delayMicroseconds(clock_half_period_us);
      }
      pinMode(SCL_PIN, INPUT);
      D(Serial.println("Done, releasing SCL");)
    }
    else
    {
      D(Serial.println("Done, line not being held low");)
    }

    if (turnOn)
    {
      begin();
    }
  }

  uint8_t I2CDriver::readAddress(uint8_t address, DataWord *data)
  {
    requestAddress(address);
    readNext(data);
    return 0;
  }

  uint8_t I2CDriver::writeAddress(uint8_t address, DataWord *data)
  {
    DataWord buffer = {0x00, 0x00, 0x00, 0x00};
    memcpy(&buffer, data, sizeof(DataWord));

    D(Serial.print("writeAddress(");
      Serial.print(address);
      Serial.print(", 0b");
      Serial.print(buffer.value, BIN);
      Serial.println(')');)

    bool completed = false;
    while (!completed)
    {
      beginTransmission();
      write(address);
      write(buffer.bytes[2]);
      write(buffer.bytes[1]);
      write(buffer.bytes[0]);
      uint8_t err = endTransmission();
      if (err != 0)
      {
        // D(Serial.print("Write error: ");
        //   Serial.println(err);)
        pause();
      }
      else
      {
        completed = true;
      }
    }
    longPause();
    return 0;
  }

  uint8_t I2CDriver::requestAddress(uint8_t address)
  {
    bool completed = false;
    while (!completed)
    {
      beginTransmission();
      write(address);
      if (endTransmission() != 0)
      {
        pause();
      }
      else
      {
        completed = true;
      }
    }
    longPause();
    return 0;
  }

  uint8_t I2CDriver::readNext(DataWord *data, bool sendStop)
  {
    DataWord buffer = {0x00, 0x00, 0x00, 0x00};
    while (request(3, sendStop) < 3)
    {
      pause();
    }

    buffer.bytes[2] = read();
    buffer.bytes[1] = read();
    buffer.bytes[0] = read();
    memcpy(data, &buffer, sizeof(DataWord));
    longPause();
    return 0;
  }

  // -----------------------------------------------------------------------------
  //                         >---- Private interface ----<
  // -----------------------------------------------------------------------------

  void I2CDriver::beginTransmission(void)
  {
    _wire->beginTransmission(DEVICE_ADDRESS);
  }

  uint8_t I2CDriver::endTransmission(bool sendStop)
  {
    return _wire->endTransmission(sendStop);
  }

  uint8_t I2CDriver::request(size_t quantity, bool sendStop)
  {
    return _wire->requestFrom(DEVICE_ADDRESS, quantity, sendStop);
  }
  uint8_t I2CDriver::read(void)
  {
    return _wire->read();
  }

  size_t I2CDriver::write(uint8_t byte)
  {
    return _wire->write(byte);
  }

  inline void I2CDriver::pause(void)
  {
    DELAY(1000);
  }

  inline void I2CDriver::longPause(void)
  {
    DELAY(15000);
  }

  I2CDriver Driver(&Wire);
}