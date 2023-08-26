#ifndef __A89307_H__
#define __A89307_H__

#ifdef VSCODE
#include <ioavr128da32.h>
#include "iotn1627.h"
#include <Wire/src/Wire.h>
#else
#include <Wire.h>
#endif

#include <A89307_registers.hpp>
#include <defines.hpp>

class A89307
{
  static const uint8_t deviceAddress = 0x55;

public:
  A89307(TwoWire *wire = &Wire);
  ~A89307();

  bool begin();
  bool loadRegisters();
  void printRegisters();

private:
  const uint8_t DELAY = 100;

  TwoWire *_wire;
  A89307_Reg::Register _registers[21] = {
      {8},
      {9},
      {10},
      {11},
      {12},
      {13},
      {15},
      {16},
      {17},
      {18},
      {19},
      {20},
      {21},
      {22},
      {23},
      {24},
      {25},
      {26},
      {28},
      {29},
      {30}};

  bool readRegister(A89307_Reg::Register *reg);
  uint8_t beginRead(uint8_t address);
  bool finishRead(uint8_t *data);
};

#endif __A89307_H__