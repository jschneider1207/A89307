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
  uint8_t readShadowRegisters();

  void printRegister(RegisterId id);
  void printRegisters();
  void printAddressMap();

private:
  static const uint8_t DELAY = 5;
  static const uint8_t TIMEOUT = 100;

  TwoWire *_wire;
  Register _registers[RegisterId::Reg_No];
  Address _addressMap[ADDRESS_COUNT];

  uint8_t beginRead(uint8_t address);
  uint8_t readNext(uint8_t *data, bool sendStop = false);
};

#endif // __A89307_H__