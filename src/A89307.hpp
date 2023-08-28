#ifndef __A89307_H__
#define __A89307_H__

#ifdef VSCODE
#include <ioavr128da32.h>
#include "iotn1627.h"
#include <Wire/src/Wire.h>
#else
#include <Wire.h>
#endif

#include <register.hpp>
#include <address.hpp>
#include <defines.hpp>

using namespace A89307;
class A89307Driver
{
  static const uint8_t DEVICE_ADDRESS = 0x55;
  static const uint32_t CLK_SPEED = 0xC350; // 50kHz, chip seems flaky af at normal speed.

public:
  A89307Driver(TwoWire *wire = &Wire);
  ~A89307Driver();

  bool begin();
  int32_t getRegister(RegisterId id, Register **reg, bool forceRefresh = false);
  uint8_t readRegister(RegisterId id);
  uint8_t readRegisters();
  void printRegister(RegisterId id);
  void printRegisters();

private:
  static const uint8_t DELAY = 5;
  static const uint8_t TIMEOUT = 100;
  static const uint8_t EEPROM_ADDRESS_LIST[ADDRESS_COUNT];
  static const uint8_t SHADOW_ADDRESS_LIST[ADDRESS_COUNT];

  TwoWire *_wire;
  Register _registers[RegisterId::Reg_No];

  uint8_t readAddress(RegisterId id);
  uint8_t readAddress(Register *reg);
  uint8_t readAddress(uint8_t address);
  uint8_t beginRead(uint8_t address);
  bool finishRead(uint8_t *word);
  int32_t validateRead(uint8_t word[3]);
};

#endif // __A89307_H__