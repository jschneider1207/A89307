#ifndef __EEPROM_PROGRAMMER_H__
#define __EEPROM_PROGRAMMER_H__

#include "../defines.hpp"
#ifdef VSCODE
#include <ioavr128da32.h>
// #include "iotn1627.h"
#include <Wire/src/Wire.h>
#else
#include <Wire.h>
#include <Arduino.h>
#endif

#define DEVICE_ADDRESS 0x55

typedef union
{
  uint8_t bits[3];
  uint32_t value;
} AddrValue;

struct Write
{
  const uint8_t address;
  const AddrValue data;
};

class EEPROMProgrammer
{
public:
  EEPROMProgrammer(const Write writes[], const uint8_t count, TwoWire *wire = &Wire);
  ~EEPROMProgrammer();

  void begin(uint8_t sdaPin, uint8_t sclPin);
  void programDevice(void);

private:
  uint32_t readInteger(void);
  void flushBus(uint8_t sdaPin, uint8_t sclPin);
  void pingDriver(void);
  void enableEEPROM(void);
  void disableEEPROM(void);
  void clearEEPROM(uint8_t addr);
  void writeEEPROM(uint8_t addr, uint8_t data[3]);
  void readEEPROM(uint8_t addr, uint8_t data[3]);

  void blockingWrite(uint8_t addr, uint8_t data[3]);

  TwoWire *_wire;
  const Write *_writes;
  const uint8_t _count;
};

#endif