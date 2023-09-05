#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "defines.hpp"
#include "I2C_DMAC.h"

namespace A89307
{
  class I2CDriver
  {
  public:
    I2CDriver(I2C_DMAC *wire = &I2C);
    ~I2CDriver(void);

    void begin(void);
    void end(void);
    void flushBus(void);

    void readAddress(uint8_t address, DataWord *data);
    void writeAddress(uint8_t address, DataWord *data);

    void enable(void);
    void ping(void);

  private:
    static const uint8_t DEVICE_ADDRESS = 0x55;
    static const uint8_t DMAC_PRIORITY = 0x03;
    I2C_DMAC *_wire;
    bool _begun;

    inline void waitForRead(void);
    inline void waitForWrite(void);
  };

  extern I2CDriver Driver;
}
#endif
