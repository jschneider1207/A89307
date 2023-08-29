

#include "A89307.hpp"

A89307Driver *driver = new A89307Driver();

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing");

  pinMode(PIN_PC4, INPUT_PULLUP);
  driver->begin();
}

uint32_t readInteger()
{
  // Flush input buffer
  while (Serial.available())
    Serial.read();

  while (!Serial.available())
    ;

  return Serial.parseInt();
}

void loop()
{
  driver->readShadowRegisters();
  driver->printAddressMap();
  driver->printRegisters();
  delay(1000000);
}

/*
Sketch uses 7646 bytes (46%) of program storage space. Maximum is 16384 bytes.
Global variables use 811 bytes (39%) of dynamic memory, leaving 1237 bytes for local variables. Maximum is 2048 bytes.

Sketch uses 6556 bytes (40%) of program storage space. Maximum is 16384 bytes.
Global variables use 248 bytes (12%) of dynamic memory, leaving 1800 bytes for local variables. Maximum is 2048 bytes
*/