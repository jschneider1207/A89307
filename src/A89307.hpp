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

class A89307
{
  static const uint8_t deviceAddress = 0x55;

public:
  A89307();
  ~A89307();

private:
};

#endif __A89307_H__