#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "defines.hpp"
namespace A89307
{
  class I2CDriver
  {
  public:
    I2CDriver(TwoWire *wire = &Wire);
    ~I2CDriver(void);

    void begin(void);
    void end(void);
    void flushBus(void);

    uint8_t readAddress(uint8_t address, DataWord *data);
    uint8_t writeAddress(uint8_t address, DataWord *data);
    uint8_t requestAddress(uint8_t address);
    uint8_t readNext(DataWord *data, bool sendStop = true);

    void enable(void);
    void ping(void);

  private:
    static const uint8_t DEVICE_ADDRESS = 0x55;
    static const uint32_t CLK_SPEED = 10000;
    TwoWire *_wire;
    bool _begun;

    void beginTransmission(void);
    uint8_t endTransmission(bool sendStop = true);
    uint8_t request(size_t quantity, bool sendStop = true);
    uint8_t read(void);
    size_t write(uint8_t byte);
    inline void pause(void);
    inline void longPause(void);
  };

  extern I2CDriver Driver;
}
#endif
