#ifndef __A89307_DEFINES_H__
#define __A89307_DEFINES_H__

#if defined(__cplusplus)
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#if defined(__cplusplus)
}
#endif

#include <Arduino.h>
#include <Wire.h>

#if defined(ARDUINO_SAMD_ADAFRUIT)
#define SCL_PIN PIN_WIRE_SCL
#define SDA_PIN PIN_WIRE_SDA
#endif

/**
 * @brief Use this to tune DELAY()'s duration
 * to w/e frame of reference you want.
 *
 * @note From quick test a single nop is ~120ns. We
 * want DELAY to be in terms of microseconds so x8 is close enough.
 */
#define NOP_MULTIPLIER 8

#define _DELAY(x)                          \
  const uint32_t lim = x * NOP_MULTIPLIER; \
  for (uint32_t i = 0; i < lim; i++)       \
  {                                        \
    asm("nop");                            \
  }

// #define NOP_TUNING

/**
 * @brief delay() does some dumb usb shit idk I just want to sit there
 * quietly and wait.
 *
 * @note use NOP_MULTIPLER to tune the duration of this.
 */
#if defined(NOP_TUNING)
#define DELAY(x)                               \
  uint32_t start = micros();                   \
  _DELAY(x)                                    \
  uint32_t end = micros();                     \
  Serial.print("DEBUG: DELAY(#x) duration: "); \
  Serial.print((end - start));                 \
  Serial.println("us");
#else
#define DELAY(x) _DELAY(x)
#endif

#define DEBUG

#define ADDRESS_START 0x08                              // 8
#define ADDRESS_END 0x1F                                // 31
#define ADDRESS_COUNT (ADDRESS_END - ADDRESS_START + 1) // 24
#define SHADOW_ADDRESS(x) x + 64

#define Serial Serial1

namespace A89307
{
  union DataWord
  {
    uint8_t bytes[4];
    uint32_t value;

    // DataWord() { {0x00, 0x00, 0x00, 0x00}; }
    // DataWord(uint32_t v) { v; }
    // DataWord(uint8_t v) { (uint32_t) v; }
    // DataWord(int v) { (uint32_t) v; }
    // DataWord(uint8_t b[4]) { b; }
  };

  /* Register ids */
  enum RegisterId
  {
    Rated_Speed,
    Clock_Pwm,
    Accelerate_Range,
    Direction,
    Pwmin_Range,
    Acceleration,
    I_Limit_Slope_1,
    Rated_Current,
    Spd_Mode,
    Startup_Current,
    Fg_Standb_En,
    Open_Drive,
    Open_Ph_Protection,
    Max_Curr_Start,
    Speed_2,
    Pid_P,
    Pwm_Output_Frequency,
    Open_Window,
    Pid_I,
    Power_Ctr_En,
    Startup_Mode,
    Delay_Start,
    Angle_Error_Lock,
    Soft_Off,
    Soft_On,
    Deadtime_Setting,
    Safe_Brake_Thrd,
    Ocp_Enable,
    Ocp_Reset_Mode,
    Ocp_Masking,
    First_Cycle_Speed,
    Accelerate_Buffer,
    Decelerate_Buffer,
    Bemf_Lock_Filter,
    Speed_Demand,
    I2_C_Speed_Mode,
    Ipd_Current_Thr,
    Drive_Gate_Slew,
    Inductance_Shift,
    Gd_Pulsecurrent,
    Gdpulse,
    Mosfet_Comp_Rising,
    Mosfet_Comp_Falling,
    Brake_Control,
    Rated_Voltage,
    Sense_Resistor,
    Dir_From_Reg,
    Brake_Input,
    Two_Slope_M,
    Speed_Input_Off_Threshold,
    Slight_Mv_Demand,
    I_Limit_Slope_2,
    Clock_Speed_Ratio,
    Restart_Attempt,
    Brake_Mode,
    Soft_Off_4S,
    Vibration_Lock,
    Lock_Restart_Set,
    Deadtime_Comp,
    Vds_Threshold_Sel,
    Parameterfull,
    Operation_Mode,
    Speed_Cur_Bidir,
    Check_Curve,
    Motor_Resistor,
    Inductance,
    Powcon_Vol_Lim,
    Strp_Lock_Rtry_Curr_Lvl_En,
    Startup_Current_Lvl2,
    Startup_Current_Lvl3,
    Kt_Set,
    Current_Loop_P,
    Speed_Loop_P,
    Power_Loop_P,
    Current_Loop_I,
    Speed_Loop_I,
    Power_Loop_I,
    First_Cycle_Speed_1,
    First_Cycle_Speed_2,
    First_Cycle_Speed_3,
    Lock_Restart_Cm,
    Ocp_Rst_Cnt,
    Startup_Current_Lvl1,
    Powcon_Dccur_Lim,
    Reg_No
  };

  struct Write
  {
    uint8_t address;
    DataWord data;
  };

#if defined(DEBUG)
#define D(x)                 \
  do                         \
  {                          \
    Serial.print("DEBUG: "); \
    x                        \
  } while (0);
#else
#define D(X) \
  do         \
  {          \
  } while (0);

#endif
}
#endif // __A89307_DEFINES_H__