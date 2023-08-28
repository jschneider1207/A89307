#ifndef __A89307_ADDRESS_H__
#define __A89307_ADDRESS_H__

#include "defines.hpp"

namespace A89307
{
  class Address
  {
  public:
    uint8_t eepromAddr;
    AddressRegisters registerIds;
    uint8_t shadowAddr() const;
    static uint8_t copyRegistersForAddress(uint8_t shadowAddr, RegisterId *registerIds);

  private:
    static const Address AddressMap[ADDRESS_COUNT];
  };
}

#endif // __A89307_ADDRESS_H__
