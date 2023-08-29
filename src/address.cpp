#include "address.hpp"

extern "C"
{
#ifdef __AVR__
#include <avr/pgmspace.h>
#else
#define PROGMEM
#define memcpy_P memcpy
#define pgm_read_word
#define strcpy_P strcpy
#endif
}

#ifdef VSCODE
#include <ioavr128da32.h>
#include "iotn1627.h"
#include <Wire/src/Wire.h>
#else
#include <Wire.h>
#endif

// -----------------------------------------------------------------------------
//                         >---- Address map ----<
// -----------------------------------------------------------------------------
namespace A89307
{
    const Address Address::DefaultAddressMap[ADDRESS_COUNT] PROGMEM = {
        {0x08, SHADOW_ADDRESS(0x08), 0x00},
        {0x09, SHADOW_ADDRESS(0x09), 0x00},
        {0x0A, SHADOW_ADDRESS(0x0A), 0x00},
        {0x0B, SHADOW_ADDRESS(0x0B), 0x00},
        {0x0C, SHADOW_ADDRESS(0x0C), 0x00},
        {0x0D, SHADOW_ADDRESS(0x0D), 0x00},
        {0x0E, SHADOW_ADDRESS(0x0E), 0x00},
        {0x0F, SHADOW_ADDRESS(0x0F), 0x00},
        {0x10, SHADOW_ADDRESS(0x10), 0x00},
        {0x11, SHADOW_ADDRESS(0x11), 0x00},
        {0x12, SHADOW_ADDRESS(0x12), 0x00},
        {0x13, SHADOW_ADDRESS(0x13), 0x00},
        {0x14, SHADOW_ADDRESS(0x14), 0x00},
        {0x15, SHADOW_ADDRESS(0x15), 0x00},
        {0x16, SHADOW_ADDRESS(0x16), 0x00},
        {0x17, SHADOW_ADDRESS(0x17), 0x00},
        {0x18, SHADOW_ADDRESS(0x18), 0x00},
        {0x19, SHADOW_ADDRESS(0x19), 0x00},
        {0x1A, SHADOW_ADDRESS(0x1A), 0x00},
        {0x1B, SHADOW_ADDRESS(0x1B), 0x00},
        {0x1C, SHADOW_ADDRESS(0x1C), 0x00},
        {0x1D, SHADOW_ADDRESS(0x1D), 0x00},
        {0x1E, SHADOW_ADDRESS(0x1E), 0x00},
        {0x1F, SHADOW_ADDRESS(0x1F), 0x00}};
}

// -----------------------------------------------------------------------------
//                         >---- Address class ----<
// -----------------------------------------------------------------------------
namespace A89307
{

    void Address::fillAddressMapDefault(Address *addressMap)
    {
        memcpy_P(addressMap, DefaultAddressMap, sizeof(DefaultAddressMap));
    }
}