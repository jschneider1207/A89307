#ifndef __EEPROM_PROGRAMMER_H__
#define __EEPROM_PROGRAMMER_H__

#include "../private/defines.hpp"
#include "../private/driver.hpp"

namespace A89307
{

  class EEPROMProgrammer
  {
  public:
    EEPROMProgrammer(Write writes[], uint8_t count, I2CDriver *driver = &Driver);
    ~EEPROMProgrammer();

    void begin();
    void end();
    uint8_t writeNext(void);

  private:
    void enableEEPROM(void);
    void disableEEPROM(void);
    void clearEEPROM(uint8_t addr);
    void writeEEPROM(uint8_t addr, DataWord data);

    I2CDriver *_driver;
    Write *_writes;
    uint8_t _count;
    uint8_t _writesRemaining;
    uint8_t _writeIdx;
  };

#endif
}