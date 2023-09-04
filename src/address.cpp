#include "address.hpp"

// -----------------------------------------------------------------------------
//                         >---- Address map ----<
// -----------------------------------------------------------------------------
namespace A89307
{
    const Address Address::DefaultAddressMap[ADDRESS_COUNT] = {
        {0x08, SHADOW_ADDRESS(0x08), {0xF2, 0xC2, 0x00, 0x00}},
        {0x09, SHADOW_ADDRESS(0x09), {0xCA, 0x62, 0x00, 0x00}},
        {0x0A, SHADOW_ADDRESS(0x0A), {0xDF, 0x61, 0x00, 0x00}},
        {0x0B, SHADOW_ADDRESS(0x0B), {0x90, 0xD4, 0x00, 0x00}},
        {0x0C, SHADOW_ADDRESS(0x0C), {0xEF, 0x7F, 0x00, 0x00}},
        {0x0D, SHADOW_ADDRESS(0x0D), {0x04, 0x41, 0x00, 0x00}},
        {0x0E, SHADOW_ADDRESS(0x0E), {0x1C, 0x0E, 0x00, 0x00}},
        {0x0F, SHADOW_ADDRESS(0x0F), {0xBD, 0x49, 0x00, 0x00}},
        {0x10, SHADOW_ADDRESS(0x10), {0x6C, 0x2A, 0x00, 0x00}},
        {0x11, SHADOW_ADDRESS(0x11), {0xFF, 0x25, 0x00, 0x00}},
        {0x12, SHADOW_ADDRESS(0x12), {0x0D, 0x0E, 0x00, 0x00}},
        {0x13, SHADOW_ADDRESS(0x13), {0x29, 0x78, 0x00, 0x00}},
        {0x14, SHADOW_ADDRESS(0x14), {0x78, 0x13, 0x00, 0x00}},
        {0x15, SHADOW_ADDRESS(0x15), {0x60, 0x41, 0x00, 0x00}},
        {0x16, SHADOW_ADDRESS(0x16), {0x1E, 0xF4, 0x00, 0x00}},
        {0x17, SHADOW_ADDRESS(0x17), {0x86, 0x00, 0x00, 0x00}},
        {0x18, SHADOW_ADDRESS(0x18), {0x76, 0x00, 0x00, 0x00}},
        {0x19, SHADOW_ADDRESS(0x19), {0x96, 0x03, 0x00, 0x00}},
        {0x1A, SHADOW_ADDRESS(0x1A), {0x0A, 0x00, 0x00, 0x00}},
        {0x1B, SHADOW_ADDRESS(0x1B), {0x00, 0x00, 0x00, 0x00}},
        {0x1C, SHADOW_ADDRESS(0x1C), {0xC6, 0x8D, 0x01, 0x00}},
        {0x1D, SHADOW_ADDRESS(0x1D), {0x13, 0x00, 0x00, 0x00}},
        {0x1E, SHADOW_ADDRESS(0x1E), {0x00, 0x00, 0x00, 0x00}},
        {0x1F, SHADOW_ADDRESS(0x1F), {0x5D, 0x02, 0x00, 0x00}},
    };
}

// -----------------------------------------------------------------------------
//                         >---- Address class ----<
// -----------------------------------------------------------------------------
namespace A89307
{

    void Address::fillAddressMapDefault(Address *addressMap)
    {
        memcpy(addressMap, DefaultAddressMap, sizeof(DefaultAddressMap));
    }
}