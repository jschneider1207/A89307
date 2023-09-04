#ifndef __A89307_ADDRESS_H__
#define __A89307_ADDRESS_H__

#include "private\defines.hpp"

namespace A89307
{
  class Address
  {
  public:
    uint8_t eepromAddress;
    uint8_t shadowAddress;
    DataWord data;
    static void fillAddressMapDefault(Address *addressMap);

  private:
    static const Address DefaultAddressMap[ADDRESS_COUNT];
  };
}
#endif // __A89307_ADDRESS_H__
