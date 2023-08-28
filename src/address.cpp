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

  const Address Address::AddressMap[ADDRESS_COUNT] = {
      // const Address Address::AddressMap[] PROGMEM = {
      {8, (RegisterId[5]){
              RegisterId::Rated_Speed,
              RegisterId::Clock_Pwm,
              RegisterId::Accelerate_Range,
              RegisterId::Direction,
              RegisterId::Pwmin_Range,
          }},
      {9, (RegisterId[2]){
              RegisterId::Acceleration,
              RegisterId::I_Limit_Slope_1,
          }},
      {10, (RegisterId[3]){
               RegisterId::Rated_Current,
               RegisterId::Spd_Mode,
               RegisterId::Startup_Current,
           }},
      {11, (RegisterId[5]){
               RegisterId::Fg_Standb_En,
               RegisterId::Open_Drive,
               RegisterId::Open_Ph_Protection,
               RegisterId::Max_Curr_Start,
               RegisterId::Speed_2,
           }},
      {12, (RegisterId[3]){
               RegisterId::Pid_P,
               RegisterId::Pwm_Output_Frequency,
               RegisterId::Open_Window,
           }},
      {13, (RegisterId[4]){
               RegisterId::Pid_I,
               RegisterId::Power_Ctr_En,
               RegisterId::Startup_Mode,
               RegisterId::Delay_Start,
           }},
      {15, (RegisterId[5]){
               RegisterId::Angle_Error_Lock,
               RegisterId::Soft_Off,
               RegisterId::Soft_On,
               RegisterId::Deadtime_Setting,
               RegisterId::Safe_Brake_Thrd,
           }},
      {16, (RegisterId[7]){
               RegisterId::Ocp_Enable,
               RegisterId::Ocp_Reset_Mode,
               RegisterId::Ocp_Masking,
               RegisterId::First_Cycle_Speed,
               RegisterId::Accelerate_Buffer,
               RegisterId::Decelerate_Buffer,
               RegisterId::Bemf_Lock_Filter,
           }},
      {17, (RegisterId[2]){
               RegisterId::Speed_Demand,
               RegisterId::I2_C_Speed_Mode,
           }},
      {18, (RegisterId[2]){
               RegisterId::Ipd_Current_Thr,
               RegisterId::Drive_Gate_Slew,
           }},
      {19, (RegisterId[6]){
               RegisterId::Inductance_Shift,
               RegisterId::Gd_Pulsecurrent,
               RegisterId::Gdpulse,
               RegisterId::Mosfet_Comp_Rising,
               RegisterId::Mosfet_Comp_Falling,
               RegisterId::Brake_Control,
           }},
      {20, (RegisterId[4]){
               RegisterId::Rated_Voltage,
               RegisterId::Sense_Resistor,
               RegisterId::Dir_From_Reg,
               RegisterId::Brake_Input,
           }},
      {21, (RegisterId[4]){
               RegisterId::Two_Slope_M,
               RegisterId::Speed_Input_Off_Threshold,
               RegisterId::Slight_Mv_Demand,
               RegisterId::I_Limit_Slope_2,
           }},
      {22, (RegisterId[8]){
               RegisterId::Clock_Speed_Ratio,
               RegisterId::Restart_Attempt,
               RegisterId::Brake_Mode,
               RegisterId::Soft_Off_4S,
               RegisterId::Vibration_Lock,
               RegisterId::Lock_Restart_Set,
               RegisterId::Deadtime_Comp,
               RegisterId::Vds_Threshold_Sel,
           }},
      {23, (RegisterId[4]){
               RegisterId::Parameterfull,
               RegisterId::Operation_Mode,
               RegisterId::Speed_Cur_Bidir,
               RegisterId::Check_Curve,
           }},
      {
          24,
          (RegisterId[1]){
              RegisterId::Motor_Resistor,
          },
      },
      {25, (RegisterId[5]){
               RegisterId::Inductance,
               RegisterId::Powcon_Vol_Lim,
               RegisterId::Strp_Lock_Rtry_Curr_Lvl_En,
               RegisterId::Startup_Current_Lvl2,
               RegisterId::Startup_Current_Lvl3,
           }},
      {26, (RegisterId[1]){
               RegisterId::Kt_Set,
           }},
      {28, (RegisterId[4]){
               RegisterId::Current_Loop_P,
               RegisterId::Speed_Loop_P,
               RegisterId::Power_Loop_P,
               RegisterId::Current_Loop_I,
           }},
      {29, (RegisterId[7]){
               RegisterId::Speed_Loop_I,
               RegisterId::Power_Loop_I,
               RegisterId::First_Cycle_Speed_1,
               RegisterId::First_Cycle_Speed_2,
               RegisterId::First_Cycle_Speed_3,
               RegisterId::Lock_Restart_Cm,
               RegisterId::Ocp_Rst_Cnt,
           }},
      {30, (RegisterId[2]){
               RegisterId::Startup_Current_Lvl1,
               RegisterId::Powcon_Dccur_Lim,
           }}};
}

// -----------------------------------------------------------------------------
//                         >---- Address class ----<
// -----------------------------------------------------------------------------
namespace A89307
{
  uint8_t Address::shadowAddr() const
  {
    return eepromAddr + 64;
  }

  uint8_t Address::copyRegistersForAddress(uint8_t shadowAddr, RegisterId *registerIds)
  {
    for (uint8_t i = 0; i < ADDRESS_COUNT; i++)
    {
      if (AddressMap[i].shadowAddr() == shadowAddr)
      {
        for (RegisterId id : AddressMap[i].registerIds)
        {
          (*registerIds++) = id;
        }
        return (uint8_t)(AddressMap[i].registerIds.size());
      }
    }
    return -1;
  }
}