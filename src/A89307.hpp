#ifndef __A89307_H__
#define __A89307_H__

#include "register.hpp"
#include "address.hpp"
#include "private\driver.hpp"
#include "programmer\eepromProgrammer.hpp"

namespace A89307
{
  class A89307Chip
  {

  public:
    A89307Chip(I2CDriver *driver = &Driver);
    ~A89307Chip();

    bool begin(void);
    bool end(void);

    /**
     * @brief Writes all addresses in memory to the A89307.
     * @note Best way to make use of this is to set the config
     * you want to use as the address' default value.
     */
    void writeAddressMap(void);
    /**
     * @brief Compares in-memory addresses against values read
     * off the chip.
     *
     * @param outOfSync Pointer for list of addresses
     * that are out of sync.
     * @return Number of addresses that are out of sync.
     */
    uint8_t syncStatus(uint8_t *outOfSync);

    uint8_t readShadowRegistersSequentially(void);
    uint8_t readShadowRegisters(void);
    uint8_t updateRegister(RegisterId id, uint32_t value);

    void printRegister(RegisterId id);
    void printRegisters(void);
    void printAddressMap(void);

  private:
    I2CDriver *_driver;
    Register _registers[RegisterId::Reg_No];
    Address _addressMap[ADDRESS_COUNT];
  };
}
#endif // __A89307_H__