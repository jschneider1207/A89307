#ifndef __DEFINES_H__
#define __DEFINES_H__

#if defined(__cplusplus)
extern "C"
{
#endif

#include <stdint.h>
#include <string.h>

#if defined(__cplusplus)
}
#endif

#include <Array.h>
#define MAX_REGISTERS_PER_ADDRESS 8
#define ADDRESS_COUNT 21

#define ADDRESS_START 0x08                              // 8
#define ADDRESS_END 0x1F                                // 31
#define ADDRESS_COUNT (ADDRESS_END - ADDRESS_START + 1) // 24
#define SHADOW_ADDRESS(x) (x + 0x40)                    // x + 64

namespace A89307
{
  // enum I2CResult
  // {
  //   /*
  //    *            0 for success,
  //    *            2 for when the address was NACK'd
  //    *            3 for when the data was NACK'd
  //    *            4 for unknown error
  //    *            5 for timeout on the bus
  //    *           16 for TWI is in a bad state
  //    *           17 for the pull ups likely missing
  //    *           18 for a bus arbitration/bus fault
  //    *           20 for likely a slave holding the clock low
  //    *          255 (-1) for TWI not initialized (begin not called) or bus somehow in "unknown" state.
  //    */
  //   Success = 0,
  //   AddressNack = 2,
  //   DataNack = 3,
  //   UnknownError = 4,
  //   BusTimeout = 5,
  //   TWIBadState = 16,
  //   PullupMissing = 17,
  //   BusFault = 18,
  //   ClkStuckLow = 20,
  //   TWINotInitialized = 255

  // };" 	"

  enum ReadError
  {
    Success = 0x00,
    ReadInitFailed,
    NoReply,
    InvalidData,
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

  typedef Array<RegisterId, MAX_REGISTERS_PER_ADDRESS> AddressRegisters;

}

#endif // __DEFINES_H__