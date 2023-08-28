#include "register.hpp"

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

namespace A89307
{

}

// -----------------------------------------------------------------------------
//                         >---- Default registers ----<
// -----------------------------------------------------------------------------

namespace A89307
{
  const Register Register::DefaultRegs[] PROGMEM = {
      {RegisterId::Rated_Speed, 8, -1, 0, 11},
      {RegisterId::Clock_Pwm, 8, -1, 11, 2},
      {RegisterId::Accelerate_Range, 8, -1, 13, 1},
      {RegisterId::Direction, 8, -1, 14, 1},
      {RegisterId::Pwmin_Range, 8, -1, 15, 1},
      {RegisterId::Acceleration, 9, -1, 0, 8},
      {RegisterId::I_Limit_Slope_1, 9, -1, 8, 10},
      {RegisterId::Rated_Current, 10, -1, 0, 11},
      {RegisterId::Spd_Mode, 10, -1, 11, 1},
      {RegisterId::Startup_Current, 10, -1, 13, 3},
      {RegisterId::Fg_Standb_En, 11, -1, 0, 1},
      {RegisterId::Open_Drive, 11, -1, 3, 1},
      {RegisterId::Open_Ph_Protection, 11, -1, 4, 1},
      {RegisterId::Max_Curr_Start, 11, -1, 6, 1},
      {RegisterId::Speed_2, 11, -1, 7, 11},
      {RegisterId::Pid_P, 12, -1, 0, 5},
      {RegisterId::Pwm_Output_Frequency, 12, -1, 5, 11},
      {RegisterId::Open_Window, 12, -1, 16, 1},
      {RegisterId::Pid_I, 13, -1, 0, 3},
      {RegisterId::Power_Ctr_En, 13, -1, 3, 1},
      {RegisterId::Startup_Mode, 13, -1, 6, 2},
      {RegisterId::Delay_Start, 13, -1, 14, 1},
      {RegisterId::Angle_Error_Lock, 15, -1, 2, 2},
      {RegisterId::Soft_Off, 15, -1, 6, 1},
      {RegisterId::Soft_On, 15, -1, 7, 1},
      {RegisterId::Deadtime_Setting, 15, -1, 8, 6},
      {RegisterId::Safe_Brake_Thrd, 15, -1, 14, 2},
      {RegisterId::Ocp_Enable, 16, -1, 0, 3},
      {RegisterId::Ocp_Reset_Mode, 16, -1, 3, 1},
      {RegisterId::Ocp_Masking, 16, -1, 4, 2},
      {RegisterId::First_Cycle_Speed, 16, -1, 6, 2},
      {RegisterId::Accelerate_Buffer, 16, -1, 8, 2},
      {RegisterId::Decelerate_Buffer, 16, -1, 10, 2},
      {RegisterId::Bemf_Lock_Filter, 16, -1, 12, 2},
      {RegisterId::Speed_Demand, 17, -1, 0, 9},
      {RegisterId::I2_C_Speed_Mode, 17, -1, 9, 1},
      {RegisterId::Ipd_Current_Thr, 18, -1, 8, 6},
      {RegisterId::Drive_Gate_Slew, 18, -1, 14, 2},
      {RegisterId::Inductance_Shift, 19, -1, 0, 3},
      {RegisterId::Gd_Pulsecurrent, 19, -1, 3, 2},
      {RegisterId::Gdpulse, 19, -1, 5, 3},
      {RegisterId::Mosfet_Comp_Rising, 19, -1, 8, 4},
      {RegisterId::Mosfet_Comp_Falling, 19, -1, 12, 4},
      {RegisterId::Brake_Control, 19, -1, 16, 1},
      {RegisterId::Rated_Voltage, 20, -1, 0, 8},
      {RegisterId::Sense_Resistor, 20, -1, 8, 8},
      {RegisterId::Dir_From_Reg, 20, -1, 16, 1},
      {RegisterId::Brake_Input, 20, -1, 17, 1},
      {RegisterId::Two_Slope_M, 21, -1, 2, 1},
      {RegisterId::Speed_Input_Off_Threshold, 21, -1, 3, 2},
      {RegisterId::Slight_Mv_Demand, 21, -1, 5, 3},
      {RegisterId::I_Limit_Slope_2, 21, -1, 8, 10},
      {RegisterId::Clock_Speed_Ratio, 22, -1, 0, 6},
      {RegisterId::Restart_Attempt, 22, -1, 6, 2},
      {RegisterId::Brake_Mode, 22, -1, 8, 1},
      {RegisterId::Soft_Off_4S, 22, -1, 9, 1},
      {RegisterId::Vibration_Lock, 22, -1, 10, 1},
      {RegisterId::Lock_Restart_Set, 22, -1, 11, 1},
      {RegisterId::Deadtime_Comp, 22, -1, 12, 1},
      {RegisterId::Vds_Threshold_Sel, 22, -1, 15, 1},
      {RegisterId::Parameterfull, 23, -1, 0, 11},
      {RegisterId::Operation_Mode, 23, -1, 11, 2},
      {RegisterId::Speed_Cur_Bidir, 23, -1, 16, 1},
      {RegisterId::Check_Curve, 23, -1, 17, 1},
      {RegisterId::Motor_Resistor, 24, -1, 0, 8},
      {RegisterId::Inductance, 25, -1, 0, 8},
      {RegisterId::Powcon_Vol_Lim, 25, -1, 8, 2},
      {RegisterId::Strp_Lock_Rtry_Curr_Lvl_En, 25, -1, 11, 1},
      {RegisterId::Startup_Current_Lvl2, 25, -1, 12, 3},
      {RegisterId::Startup_Current_Lvl3, 25, -1, 15, 3},
      {RegisterId::Kt_Set, 26, -1, 0, 9},
      {RegisterId::Current_Loop_P, 28, -1, 0, 5},
      {RegisterId::Speed_Loop_P, 28, -1, 5, 5},
      {RegisterId::Power_Loop_P, 28, -1, 10, 5},
      {RegisterId::Current_Loop_I, 28, -1, 15, 3},
      {RegisterId::Speed_Loop_I, 29, -1, 0, 3},
      {RegisterId::Power_Loop_I, 29, -1, 3, 3},
      {RegisterId::First_Cycle_Speed_1, 29, -1, 9, 2},
      {RegisterId::First_Cycle_Speed_2, 29, -1, 11, 2},
      {RegisterId::First_Cycle_Speed_3, 29, -1, 13, 2},
      {RegisterId::Lock_Restart_Cm, 29, -1, 15, 1},
      {RegisterId::Ocp_Rst_Cnt, 29, -1, 16, 1},
      {RegisterId::Startup_Current_Lvl1, 30, -1, 4, 3},
      {RegisterId::Powcon_Dccur_Lim, 30, -1, 7, 11},
  };
}

// -----------------------------------------------------------------------------
//                         >---- Register names ----<
// -----------------------------------------------------------------------------

namespace A89307
{
  const char RegNameRatedSpeed[] PROGMEM = "RatedSpeed";
  const char RegNameClockPwm[] PROGMEM = "ClockPwm";
  const char RegNameAccelerateRange[] PROGMEM = "AccelerateRange";
  const char RegNameDirection[] PROGMEM = "Direction";
  const char RegNamePwminRange[] PROGMEM = "PwminRange";
  const char RegNameAcceleration[] PROGMEM = "Acceleration";
  const char RegNameILimitSlope_1[] PROGMEM = "ILimitSlope_1";
  const char RegNameRatedCurrent[] PROGMEM = "RatedCurrent";
  const char RegNameSpdMode[] PROGMEM = "SpdMode";
  const char RegNameStartupCurrent[] PROGMEM = "StartupCurrent";
  const char RegNameFgStandbEn[] PROGMEM = "FgStandbEn";
  const char RegNameOpenDrive[] PROGMEM = "OpenDrive";
  const char RegNameOpenPhProtection[] PROGMEM = "OpenPhProtection";
  const char RegNameMaxCurrStart[] PROGMEM = "MaxCurrStart";
  const char RegNameSpeed_2[] PROGMEM = "Speed_2";
  const char RegNamePidP[] PROGMEM = "PidP";
  const char RegNamePwmOutputFrequency[] PROGMEM = "PwmOutputFrequency";
  const char RegNameOpenWindow[] PROGMEM = "OpenWindow";
  const char RegNamePidI[] PROGMEM = "PidI";
  const char RegNamePowerCtrEn[] PROGMEM = "PowerCtrEn";
  const char RegNameStartupMode[] PROGMEM = "StartupMode";
  const char RegNameDelayStart[] PROGMEM = "DelayStart";
  const char RegNameAngleErrorLock[] PROGMEM = "AngleErrorLock";
  const char RegNameSoftOff[] PROGMEM = "SoftOff";
  const char RegNameSoftOn[] PROGMEM = "SoftOn";
  const char RegNameDeadtimeSetting[] PROGMEM = "DeadtimeSetting";
  const char RegNameSafeBrakeThrd[] PROGMEM = "SafeBrakeThrd";
  const char RegNameOcpEnable[] PROGMEM = "OcpEnable";
  const char RegNameOcpResetMode[] PROGMEM = "OcpResetMode";
  const char RegNameOcpMasking[] PROGMEM = "OcpMasking";
  const char RegNameFirstCycleSpeed[] PROGMEM = "FirstCycleSpeed";
  const char RegNameAccelerateBuffer[] PROGMEM = "AccelerateBuffer";
  const char RegNameDecelerateBuffer[] PROGMEM = "DecelerateBuffer";
  const char RegNameBemfLockFilter[] PROGMEM = "BemfLockFilter";
  const char RegNameSpeedDemand[] PROGMEM = "SpeedDemand";
  const char RegNameI2CSpeedMode[] PROGMEM = "I2CSpeedMode";
  const char RegNameIpdCurrentThr[] PROGMEM = "IpdCurrentThr";
  const char RegNameDriveGateSlew[] PROGMEM = "DriveGateSlew";
  const char RegNameInductanceShift[] PROGMEM = "InductanceShift";
  const char RegNameGdPulsecurrent[] PROGMEM = "GdPulsecurrent";
  const char RegNameGdpulse[] PROGMEM = "Gdpulse";
  const char RegNameMosfetCompRising[] PROGMEM = "MosfetCompRising";
  const char RegNameMosfetCompFalling[] PROGMEM = "MosfetCompFalling";
  const char RegNameBrakeControl[] PROGMEM = "BrakeControl";
  const char RegNameRatedVoltage[] PROGMEM = "RatedVoltage";
  const char RegNameSenseResistor[] PROGMEM = "SenseResistor";
  const char RegNameDirFromReg[] PROGMEM = "DirFromReg";
  const char RegNameBrakeInput[] PROGMEM = "BrakeInput";
  const char RegNameTwoSlopeM[] PROGMEM = "TwoSlopeM";
  const char RegNameSpeedInputOffThreshold[] PROGMEM = "SpeedInputOffThreshold";
  const char RegNameSlightMvDemand[] PROGMEM = "SlightMvDemand";
  const char RegNameILimitSlope_2[] PROGMEM = "ILimitSlope_2";
  const char RegNameClockSpeedRatio[] PROGMEM = "ClockSpeedRatio";
  const char RegNameRestartAttempt[] PROGMEM = "RestartAttempt";
  const char RegNameBrakeMode[] PROGMEM = "BrakeMode";
  const char RegNameSoftOff_4S[] PROGMEM = "SoftOff_4S";
  const char RegNameVibrationLock[] PROGMEM = "VibrationLock";
  const char RegNameLockRestartSet[] PROGMEM = "LockRestartSet";
  const char RegNameDeadtimeComp[] PROGMEM = "DeadtimeComp";
  const char RegNameVdsThresholdSel[] PROGMEM = "VdsThresholdSel";
  const char RegNameParameterfull[] PROGMEM = "Parameterfull";
  const char RegNameOperationMode[] PROGMEM = "OperationMode";
  const char RegNameSpeedCurBidir[] PROGMEM = "SpeedCurBidir";
  const char RegNameCheckCurve[] PROGMEM = "CheckCurve";
  const char RegNameMotorResistor[] PROGMEM = "MotorResistor";
  const char RegNameInductance[] PROGMEM = "Inductance";
  const char RegNamePowconVolLim[] PROGMEM = "PowconVolLim";
  const char RegNameStrpLockRtryCurrLvlEn[] PROGMEM = "StrpLockRtryCurrLvlEn";
  const char RegNameStartupCurrentLvl2[] PROGMEM = "StartupCurrentLvl2";
  const char RegNameStartupCurrentLvl3[] PROGMEM = "StartupCurrentLvl3";
  const char RegNameKtSet[] PROGMEM = "KtSet";
  const char RegNameCurrentLoopP[] PROGMEM = "CurrentLoopP";
  const char RegNameSpeedLoopP[] PROGMEM = "SpeedLoopP";
  const char RegNamePowerLoopP[] PROGMEM = "PowerLoopP";
  const char RegNameCurrentLoopI[] PROGMEM = "CurrentLoopI";
  const char RegNameSpeedLoopI[] PROGMEM = "SpeedLoopI";
  const char RegNamePowerLoopI[] PROGMEM = "PowerLoopI";
  const char RegNameFirstCycleSpeed_1[] PROGMEM = "FirstCycleSpeed_1";
  const char RegNameFirstCycleSpeed_2[] PROGMEM = "FirstCycleSpeed_2";
  const char RegNameFirstCycleSpeed_3[] PROGMEM = "FirstCycleSpeed_3";
  const char RegNameLockRestartCm[] PROGMEM = "LockRestartCm";
  const char RegNameOcpRstCnt[] PROGMEM = "OcpRstCnt";
  const char RegNameStartupCurrentLvl1[] PROGMEM = "StartupCurrentLvl1";
  const char RegNamePowconDccurLim[] PROGMEM = "PowconDccurLim";

  const char *const RegisterNames[] PROGMEM = {
      RegNameRatedSpeed,
      RegNameClockPwm,
      RegNameAccelerateRange,
      RegNameDirection,
      RegNamePwminRange,
      RegNameAcceleration,
      RegNameILimitSlope_1,
      RegNameRatedCurrent,
      RegNameSpdMode,
      RegNameStartupCurrent,
      RegNameFgStandbEn,
      RegNameOpenDrive,
      RegNameOpenPhProtection,
      RegNameMaxCurrStart,
      RegNameSpeed_2,
      RegNamePidP,
      RegNamePwmOutputFrequency,
      RegNameOpenWindow,
      RegNamePidI,
      RegNamePowerCtrEn,
      RegNameStartupMode,
      RegNameDelayStart,
      RegNameAngleErrorLock,
      RegNameSoftOff,
      RegNameSoftOn,
      RegNameDeadtimeSetting,
      RegNameSafeBrakeThrd,
      RegNameOcpEnable,
      RegNameOcpResetMode,
      RegNameOcpMasking,
      RegNameFirstCycleSpeed,
      RegNameAccelerateBuffer,
      RegNameDecelerateBuffer,
      RegNameBemfLockFilter,
      RegNameSpeedDemand,
      RegNameI2CSpeedMode,
      RegNameIpdCurrentThr,
      RegNameDriveGateSlew,
      RegNameInductanceShift,
      RegNameGdPulsecurrent,
      RegNameGdpulse,
      RegNameMosfetCompRising,
      RegNameMosfetCompFalling,
      RegNameBrakeControl,
      RegNameRatedVoltage,
      RegNameSenseResistor,
      RegNameDirFromReg,
      RegNameBrakeInput,
      RegNameTwoSlopeM,
      RegNameSpeedInputOffThreshold,
      RegNameSlightMvDemand,
      RegNameILimitSlope_2,
      RegNameClockSpeedRatio,
      RegNameRestartAttempt,
      RegNameBrakeMode,
      RegNameSoftOff_4S,
      RegNameVibrationLock,
      RegNameLockRestartSet,
      RegNameDeadtimeComp,
      RegNameVdsThresholdSel,
      RegNameParameterfull,
      RegNameOperationMode,
      RegNameSpeedCurBidir,
      RegNameCheckCurve,
      RegNameMotorResistor,
      RegNameInductance,
      RegNamePowconVolLim,
      RegNameStrpLockRtryCurrLvlEn,
      RegNameStartupCurrentLvl2,
      RegNameStartupCurrentLvl3,
      RegNameKtSet,
      RegNameCurrentLoopP,
      RegNameSpeedLoopP,
      RegNamePowerLoopP,
      RegNameCurrentLoopI,
      RegNameSpeedLoopI,
      RegNamePowerLoopI,
      RegNameFirstCycleSpeed_1,
      RegNameFirstCycleSpeed_2,
      RegNameFirstCycleSpeed_3,
      RegNameLockRestartCm,
      RegNameOcpRstCnt,
      RegNameStartupCurrentLvl1,
      RegNamePowconDccurLim,
  };
}

// -----------------------------------------------------------------------------
//                         >---- Register class ----<
// -----------------------------------------------------------------------------

namespace A89307
{
  uint8_t Register::shadowAddr() const
  {
    return addr + 64;
  }

  uint32_t Register::bitMask() const
  {
    return (1UL << size) - 1;
  }

  uint8_t Register::copyRegisterName(RegisterId id, char *name)
  {
    const char *string = (const char *)pgm_read_word(&RegisterNames[id]);
    return (uint8_t)strcpy_P(name, string);
  }

  void Register::fillAllRegsWithDefault(Register *allRegs)
  {
    memcpy_P(allRegs, DefaultRegs, sizeof(DefaultRegs));
  }
}