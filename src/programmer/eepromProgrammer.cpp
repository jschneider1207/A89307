#include "eepromProgrammer.hpp"

// -----------------------------------------------------------------------------
//                         >---- EEPROMProgrammer class ----<
// -----------------------------------------------------------------------------

EEPROMProgrammer::EEPROMProgrammer(const Write writes[], const uint8_t count, TwoWire *wire) : _wire(wire), _writes(writes), _count(count)
{
}

EEPROMProgrammer::~EEPROMProgrammer()
{
}

void EEPROMProgrammer::begin(uint8_t sdaPin, uint8_t sclPin)
{
  pinMode(sdaPin, OUTPUT);
  pinMode(sclPin, OUTPUT);
  digitalWrite(sdaPin, LOW);
  digitalWrite(sclPin, LOW);
  delay(2500);
  pinMode(sdaPin, INPUT_PULLUP);
  pinMode(sclPin, INPUT_PULLUP);

  Serial.begin(115200);
  flushBus(sdaPin, sclPin);
  _wire->begin();
  _wire->setClock(24000);
  pingDriver();
}

void EEPROMProgrammer::programDevice()
{
  bool eepromEnabled = false;
  uint8_t writesRemaining = _count; // 9
  uint8_t idx = 0;

  enableEEPROM();

  uint8_t addr = _writes[idx].address;
  uint8_t dat[3] = {0x00, 0x00, 0x00};
  dat[0] = _writes[idx].data.bits[0];
  dat[1] = _writes[idx].data.bits[1];
  dat[2] = _writes[idx].data.bits[2];

  clearEEPROM(addr);

  delayMicroseconds(10);

  writeEEPROM(addr, dat);

  delayMicroseconds(10);
  while (writesRemaining > 0)
  {
    uint8_t result[3] = {0x00, 0x00, 0x00};
    readEEPROM(addr, result);

    Serial.print("Wrote 0x");
    Serial.print(dat[0], HEX);
    Serial.print(dat[1], HEX);
    Serial.print(dat[2], HEX);
    Serial.print(" to address ");
    Serial.print(addr);
    Serial.print(", reading back received 0x");
    Serial.print(result[0], HEX);
    Serial.print(result[1], HEX);
    Serial.println(result[2], HEX);
    Serial.print("Repeat this write, or continue? (1 for continue, 0 for repeat) ");
    uint8_t action = readInteger();
    Serial.println(action);

    if (action == 1)
    {
      idx++;
      writesRemaining--;
    }

    if (writesRemaining == 0)
    {
      disableEEPROM();
    }
  }
}

uint32_t EEPROMProgrammer::readInteger(void)
{
  // Flush input buffer
  while (Serial.available())
    Serial.read();

  while (!Serial.available())
    ;

  return Serial.parseInt();
}

void EEPROMProgrammer::pingDriver(void)
{
  Serial.println("Searching for device...");
  uint32_t start = millis();
  while (true)
  {
    _wire->beginTransmission(DEVICE_ADDRESS);
    if (_wire->endTransmission() == 0)
    {
      uint32_t end = millis();
      Serial.println("Device found!");
      Serial.print("It took ");
      Serial.print((end - start));
      Serial.println("ms for the device to reply.");
      break;
    }
    delayMicroseconds(10);
  }
}

void EEPROMProgrammer::flushBus(uint8_t sdaPin, uint8_t sclPin)
{
  Serial.println("Flushing I2C bus...");
  pinMode(sdaPin, INPUT_PULLUP);
  Serial.print("Current SDA level: ");
  uint8_t sda = digitalRead(sdaPin);
  if (sda == 0)
  {
    Serial.println("SDA indicating potential pending communication");
  }
  else
  {
    Serial.println("SDA high, not flushing bus");
    return;
  }

  Serial.println("Pulling SCL high");
  pinMode(sclPin, OUTPUT);
  digitalWrite(sclPin, HIGH);
  delayMicroseconds(10);
  Serial.println("Beginning to flush bus");
  for (uint8_t i = 0; i < 128; i++)
  {
    digitalWrite(sclPin, LOW);
    delayMicroseconds(10);
    digitalWrite(sclPin, HIGH);
  }
  Serial.println("Flush complete, releasing SCL");
  pinMode(sclPin, INPUT_PULLUP);
  pinMode(sdaPin, INPUT_PULLUP);
}

void EEPROMProgrammer::enableEEPROM(void)
{
  Serial.print("Enabling EEPROM... ");
  blockingWrite(0xC4, (uint8_t[3]){0x00, 0x00, 0x01});
  Serial.println("Complete");
}

void EEPROMProgrammer::disableEEPROM(void)
{
  Serial.print("Disabling EEPROM... ");
  blockingWrite(0xC4, (uint8_t[3]){0x00, 0x00, 0x00});
  Serial.println("Complete");
}

void EEPROMProgrammer::clearEEPROM(uint8_t addr)
{
  Serial.print("Clearing address ");
  Serial.print(addr);
  Serial.print("... ");

  // Write the address to 192
  blockingWrite(192, (uint8_t[3]){0x00, 0x00, addr});

  // Write data to 193
  blockingWrite(193, (uint8_t[3]){0x00, 0x00, 0x00});

  // Write erase and voltage high to 191
  blockingWrite(191, (uint8_t[3]){0x00, 0x00, 0x03});

  delay(20); // requires 15 ms high-voltage pulse to erase.

  // Write erase and voltage high to 191
  blockingWrite(191, (uint8_t[3]){0x00, 0x00, 0x03});

  delay(20); // requires 15 ms high-voltage pulse to erase.

  Serial.println("Complete");
}

void EEPROMProgrammer::writeEEPROM(uint8_t addr, uint8_t data[3])
{
  Serial.print("Writing to address ");
  Serial.print(addr);
  Serial.print("... ");

  // Write the address to 192
  blockingWrite(192, (uint8_t[3]){0x00, 0x00, addr});

  // Write data to 193
  blockingWrite(193, data);

  // Write write and voltage high to 191
  blockingWrite(191, (uint8_t[3]){0x00, 0x00, 0x05});

  delay(20); // requires 15 ms high-voltage pulse to write.

  Serial.println("Complete");
}

void EEPROMProgrammer::readEEPROM(uint8_t addr, uint8_t data[3])
{
  Serial.print("Reading address ");
  Serial.print(addr);
  Serial.print("... ");

  uint8_t err = -1;
  while (err != 0)
  {
    _wire->beginTransmission(DEVICE_ADDRESS);
    _wire->write(addr);
    err = _wire->endTransmission();
    delayMicroseconds(10);
  }

  while (_wire->requestFrom(DEVICE_ADDRESS, 3) < 3)
  {
    delayMicroseconds(10);
  }
  data[0] = _wire->read();
  data[1] = _wire->read();
  data[2] = _wire->read();

  Serial.println("Complete");
}

void EEPROMProgrammer::blockingWrite(uint8_t addr, uint8_t data[3])
{
  uint8_t err = -1;
  while (err != 0)
  {
    _wire->beginTransmission(DEVICE_ADDRESS);
    _wire->write(addr);
    _wire->write(data[0]);
    _wire->write(data[1]);
    _wire->write(data[2]);
    err = _wire->endTransmission();
    delayMicroseconds(10);
  }
}