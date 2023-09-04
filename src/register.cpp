#include "register.hpp"

// -----------------------------------------------------------------------------
//                         >---- Default registers ----<
// -----------------------------------------------------------------------------

namespace A89307
{
  const Register Register::DefaultRegs[] = {
      {RegisterId::Rated_Speed, 0x08, SHADOW_ADDRESS(0x08), 0xFFFFFFFF, 0x00, 0x0B},
      {RegisterId::Clock_Pwm, 0x08, SHADOW_ADDRESS(0x08), 0xFFFFFFFF, 0x0B, 0x02},
      {RegisterId::Accelerate_Range, 0x08, SHADOW_ADDRESS(0x08), 0xFFFFFFFF, 0x0D, 0x01},
      {RegisterId::Direction, 0x08, SHADOW_ADDRESS(0x08), 0xFFFFFFFF, 0x0E, 0x01},
      {RegisterId::Pwmin_Range, 0x08, SHADOW_ADDRESS(0x08), 0xFFFFFFFF, 0x0F, 0x01},
      {RegisterId::Acceleration, 0x09, SHADOW_ADDRESS(0x09), 0xFFFFFFFF, 0x00, 0x08},
      {RegisterId::I_Limit_Slope_1, 0x09, SHADOW_ADDRESS(0x09), 0xFFFFFFFF, 0x08, 0x0A},
      {RegisterId::Rated_Current, 0x0A, SHADOW_ADDRESS(0x0A), 0xFFFFFFFF, 0x00, 0x0B},
      {RegisterId::Spd_Mode, 0x0A, SHADOW_ADDRESS(0x0A), 0xFFFFFFFF, 0x0B, 0x01},
      {RegisterId::Startup_Current, 0x0A, SHADOW_ADDRESS(0x0A), 0xFFFFFFFF, 0x0D, 0x03},
      {RegisterId::Fg_Standb_En, 0x0B, SHADOW_ADDRESS(0x0B), 0xFFFFFFFF, 0x00, 0x01},
      {RegisterId::Open_Drive, 0x0B, SHADOW_ADDRESS(0x0B), 0xFFFFFFFF, 0x03, 0x01},
      {RegisterId::Open_Ph_Protection, 0x0B, SHADOW_ADDRESS(0x0B), 0xFFFFFFFF, 0x04, 0x01},
      {RegisterId::Max_Curr_Start, 0x0B, SHADOW_ADDRESS(0x0B), 0xFFFFFFFF, 0x06, 0x01},
      {RegisterId::Speed_2, 0x0B, SHADOW_ADDRESS(0x0B), 0xFFFFFFFF, 0x07, 0x0B},
      {RegisterId::Pid_P, 0x0C, SHADOW_ADDRESS(0x0C), 0xFFFFFFFF, 0x00, 0x05},
      {RegisterId::Pwm_Output_Frequency, 0x0C, SHADOW_ADDRESS(0x0C), 0xFFFFFFFF, 0x05, 0x0B},
      {RegisterId::Open_Window, 0x0C, SHADOW_ADDRESS(0x0C), 0xFFFFFFFF, 0x10, 0x01},
      {RegisterId::Pid_I, 0x0D, SHADOW_ADDRESS(0x0D), 0xFFFFFFFF, 0x00, 0x03},
      {RegisterId::Power_Ctr_En, 0x0D, SHADOW_ADDRESS(0x0D), 0xFFFFFFFF, 0x03, 0x01},
      {RegisterId::Startup_Mode, 0x0D, SHADOW_ADDRESS(0x0D), 0xFFFFFFFF, 0x06, 0x02},
      {RegisterId::Delay_Start, 0x0D, SHADOW_ADDRESS(0x0D), 0xFFFFFFFF, 0x0E, 0x01},
      {RegisterId::Angle_Error_Lock, 0x0F, SHADOW_ADDRESS(0x0F), 0xFFFFFFFF, 0x02, 0x02},
      {RegisterId::Soft_Off, 0x0F, SHADOW_ADDRESS(0x0F), 0xFFFFFFFF, 0x06, 0x01},
      {RegisterId::Soft_On, 0x0F, SHADOW_ADDRESS(0x0F), 0xFFFFFFFF, 0x07, 0x01},
      {RegisterId::Deadtime_Setting, 0x0F, SHADOW_ADDRESS(0x0F), 0xFFFFFFFF, 0x08, 0x06},
      {RegisterId::Safe_Brake_Thrd, 0x0F, SHADOW_ADDRESS(0x0F), 0xFFFFFFFF, 0x0E, 0x02},
      {RegisterId::Ocp_Enable, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x00, 0x03},
      {RegisterId::Ocp_Reset_Mode, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x03, 0x01},
      {RegisterId::Ocp_Masking, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x04, 0x02},
      {RegisterId::First_Cycle_Speed, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x06, 0x02},
      {RegisterId::Accelerate_Buffer, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x08, 0x02},
      {RegisterId::Decelerate_Buffer, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x0A, 0x02},
      {RegisterId::Bemf_Lock_Filter, 0x10, SHADOW_ADDRESS(0x10), 0xFFFFFFFF, 0x0C, 0x02},
      {RegisterId::Speed_Demand, 0x11, SHADOW_ADDRESS(0x11), 0xFFFFFFFF, 0x00, 0x09},
      {RegisterId::I2_C_Speed_Mode, 0x11, SHADOW_ADDRESS(0x11), 0xFFFFFFFF, 0x09, 0x01},
      {RegisterId::Ipd_Current_Thr, 0x12, SHADOW_ADDRESS(0x12), 0xFFFFFFFF, 0x08, 0x06},
      {RegisterId::Drive_Gate_Slew, 0x12, SHADOW_ADDRESS(0x12), 0xFFFFFFFF, 0x0E, 0x02},
      {RegisterId::Inductance_Shift, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x00, 0x03},
      {RegisterId::Gd_Pulsecurrent, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x03, 0x02},
      {RegisterId::Gdpulse, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x05, 0x03},
      {RegisterId::Mosfet_Comp_Rising, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x08, 0x04},
      {RegisterId::Mosfet_Comp_Falling, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x0C, 0x04},
      {RegisterId::Brake_Control, 0x13, SHADOW_ADDRESS(0x13), 0xFFFFFFFF, 0x10, 0x01},
      {RegisterId::Rated_Voltage, 0x14, SHADOW_ADDRESS(0x14), 0xFFFFFFFF, 0x00, 0x08},
      {RegisterId::Sense_Resistor, 0x14, SHADOW_ADDRESS(0x14), 0xFFFFFFFF, 0x08, 0x08},
      {RegisterId::Dir_From_Reg, 0x14, SHADOW_ADDRESS(0x14), 0xFFFFFFFF, 0x10, 0x01},
      {RegisterId::Brake_Input, 0x14, SHADOW_ADDRESS(0x14), 0xFFFFFFFF, 0x11, 0x01},
      {RegisterId::Two_Slope_M, 0x15, SHADOW_ADDRESS(0x15), 0xFFFFFFFF, 0x02, 0x01},
      {RegisterId::Speed_Input_Off_Threshold, 0x15, SHADOW_ADDRESS(0x15), 0xFFFFFFFF, 0x03, 0x02},
      {RegisterId::Slight_Mv_Demand, 0x15, SHADOW_ADDRESS(0x15), 0xFFFFFFFF, 0x05, 0x03},
      {RegisterId::I_Limit_Slope_2, 0x15, SHADOW_ADDRESS(0x15), 0xFFFFFFFF, 0x08, 0x0A},
      {RegisterId::Clock_Speed_Ratio, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x00, 0x06},
      {RegisterId::Restart_Attempt, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x06, 0x02},
      {RegisterId::Brake_Mode, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x08, 0x01},
      {RegisterId::Soft_Off_4S, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x09, 0x01},
      {RegisterId::Vibration_Lock, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x0A, 0x01},
      {RegisterId::Lock_Restart_Set, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x0B, 0x01},
      {RegisterId::Deadtime_Comp, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x0C, 0x01},
      {RegisterId::Vds_Threshold_Sel, 0x16, SHADOW_ADDRESS(0x16), 0xFFFFFFFF, 0x0F, 0x01},
      {RegisterId::Parameterfull, 0x17, SHADOW_ADDRESS(0x17), 0xFFFFFFFF, 0x00, 0x0B},
      {RegisterId::Operation_Mode, 0x17, SHADOW_ADDRESS(0x17), 0xFFFFFFFF, 0x0B, 0x02},
      {RegisterId::Speed_Cur_Bidir, 0x17, SHADOW_ADDRESS(0x17), 0xFFFFFFFF, 0x10, 0x01},
      {RegisterId::Check_Curve, 0x17, SHADOW_ADDRESS(0x17), 0xFFFFFFFF, 0x11, 0x01},
      {RegisterId::Motor_Resistor, 0x18, SHADOW_ADDRESS(0x18), 0xFFFFFFFF, 0x00, 0x08},
      {RegisterId::Inductance, 0x19, SHADOW_ADDRESS(0x19), 0xFFFFFFFF, 0x00, 0x08},
      {RegisterId::Powcon_Vol_Lim, 0x19, SHADOW_ADDRESS(0x19), 0xFFFFFFFF, 0x08, 0x02},
      {RegisterId::Strp_Lock_Rtry_Curr_Lvl_En, 0x19, SHADOW_ADDRESS(0x19), 0xFFFFFFFF, 0x0B, 0x01},
      {RegisterId::Startup_Current_Lvl2, 0x19, SHADOW_ADDRESS(0x19), 0xFFFFFFFF, 0x0C, 0x03},
      {RegisterId::Startup_Current_Lvl3, 0x19, SHADOW_ADDRESS(0x19), 0xFFFFFFFF, 0x0F, 0x03},
      {RegisterId::Kt_Set, 0x1A, SHADOW_ADDRESS(0x1A), 0xFFFFFFFF, 0x00, 0x09},
      {RegisterId::Current_Loop_P, 0x1C, SHADOW_ADDRESS(0x1C), 0xFFFFFFFF, 0x00, 0x05},
      {RegisterId::Speed_Loop_P, 0x1C, SHADOW_ADDRESS(0x1C), 0xFFFFFFFF, 0x05, 0x05},
      {RegisterId::Power_Loop_P, 0x1C, SHADOW_ADDRESS(0x1C), 0xFFFFFFFF, 0x0A, 0x05},
      {RegisterId::Current_Loop_I, 0x1C, SHADOW_ADDRESS(0x1C), 0xFFFFFFFF, 0x0F, 0x03},
      {RegisterId::Speed_Loop_I, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x00, 0x03},
      {RegisterId::Power_Loop_I, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x03, 0x03},
      {RegisterId::First_Cycle_Speed_1, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x09, 0x02},
      {RegisterId::First_Cycle_Speed_2, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x0B, 0x02},
      {RegisterId::First_Cycle_Speed_3, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x0D, 0x02},
      {RegisterId::Lock_Restart_Cm, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x0F, 0x01},
      {RegisterId::Ocp_Rst_Cnt, 0x1D, SHADOW_ADDRESS(0x1D), 0xFFFFFFFF, 0x10, 0x01},
      {RegisterId::Startup_Current_Lvl1, 0x1E, SHADOW_ADDRESS(0x1E), 0xFFFFFFFF, 0x04, 0x03},
      {RegisterId::Powcon_Dccur_Lim, 0x1E, SHADOW_ADDRESS(0x1E), 0xFFFFFFFF, 0x07, 0x0B}};
}

// -----------------------------------------------------------------------------
//                         >---- Register names ----<
// -----------------------------------------------------------------------------

namespace A89307
{
  const char RegNameRatedSpeed[] = "RatedSpeed";
  const char RegNameClockPwm[] = "ClockPwm";
  const char RegNameAccelerateRange[] = "AccelerateRange";
  const char RegNameDirection[] = "Direction";
  const char RegNamePwminRange[] = "PwminRange";
  const char RegNameAcceleration[] = "Acceleration";
  const char RegNameILimitSlope_1[] = "ILimitSlope_1";
  const char RegNameRatedCurrent[] = "RatedCurrent";
  const char RegNameSpdMode[] = "SpdMode";
  const char RegNameStartupCurrent[] = "StartupCurrent";
  const char RegNameFgStandbEn[] = "FgStandbEn";
  const char RegNameOpenDrive[] = "OpenDrive";
  const char RegNameOpenPhProtection[] = "OpenPhProtection";
  const char RegNameMaxCurrStart[] = "MaxCurrStart";
  const char RegNameSpeed_2[] = "Speed_2";
  const char RegNamePidP[] = "PidP";
  const char RegNamePwmOutputFrequency[] = "PwmOutputFrequency";
  const char RegNameOpenWindow[] = "OpenWindow";
  const char RegNamePidI[] = "PidI";
  const char RegNamePowerCtrEn[] = "PowerCtrEn";
  const char RegNameStartupMode[] = "StartupMode";
  const char RegNameDelayStart[] = "DelayStart";
  const char RegNameAngleErrorLock[] = "AngleErrorLock";
  const char RegNameSoftOff[] = "SoftOff";
  const char RegNameSoftOn[] = "SoftOn";
  const char RegNameDeadtimeSetting[] = "DeadtimeSetting";
  const char RegNameSafeBrakeThrd[] = "SafeBrakeThrd";
  const char RegNameOcpEnable[] = "OcpEnable";
  const char RegNameOcpResetMode[] = "OcpResetMode";
  const char RegNameOcpMasking[] = "OcpMasking";
  const char RegNameFirstCycleSpeed[] = "FirstCycleSpeed";
  const char RegNameAccelerateBuffer[] = "AccelerateBuffer";
  const char RegNameDecelerateBuffer[] = "DecelerateBuffer";
  const char RegNameBemfLockFilter[] = "BemfLockFilter";
  const char RegNameSpeedDemand[] = "SpeedDemand";
  const char RegNameI2CSpeedMode[] = "I2CSpeedMode";
  const char RegNameIpdCurrentThr[] = "IpdCurrentThr";
  const char RegNameDriveGateSlew[] = "DriveGateSlew";
  const char RegNameInductanceShift[] = "InductanceShift";
  const char RegNameGdPulsecurrent[] = "GdPulsecurrent";
  const char RegNameGdpulse[] = "Gdpulse";
  const char RegNameMosfetCompRising[] = "MosfetCompRising";
  const char RegNameMosfetCompFalling[] = "MosfetCompFalling";
  const char RegNameBrakeControl[] = "BrakeControl";
  const char RegNameRatedVoltage[] = "RatedVoltage";
  const char RegNameSenseResistor[] = "SenseResistor";
  const char RegNameDirFromReg[] = "DirFromReg";
  const char RegNameBrakeInput[] = "BrakeInput";
  const char RegNameTwoSlopeM[] = "TwoSlopeM";
  const char RegNameSpeedInputOffThreshold[] = "SpeedInputOffThreshold";
  const char RegNameSlightMvDemand[] = "SlightMvDemand";
  const char RegNameILimitSlope_2[] = "ILimitSlope_2";
  const char RegNameClockSpeedRatio[] = "ClockSpeedRatio";
  const char RegNameRestartAttempt[] = "RestartAttempt";
  const char RegNameBrakeMode[] = "BrakeMode";
  const char RegNameSoftOff_4S[] = "SoftOff_4S";
  const char RegNameVibrationLock[] = "VibrationLock";
  const char RegNameLockRestartSet[] = "LockRestartSet";
  const char RegNameDeadtimeComp[] = "DeadtimeComp";
  const char RegNameVdsThresholdSel[] = "VdsThresholdSel";
  const char RegNameParameterfull[] = "Parameterfull";
  const char RegNameOperationMode[] = "OperationMode";
  const char RegNameSpeedCurBidir[] = "SpeedCurBidir";
  const char RegNameCheckCurve[] = "CheckCurve";
  const char RegNameMotorResistor[] = "MotorResistor";
  const char RegNameInductance[] = "Inductance";
  const char RegNamePowconVolLim[] = "PowconVolLim";
  const char RegNameStrpLockRtryCurrLvlEn[] = "StrpLockRtryCurrLvlEn";
  const char RegNameStartupCurrentLvl2[] = "StartupCurrentLvl2";
  const char RegNameStartupCurrentLvl3[] = "StartupCurrentLvl3";
  const char RegNameKtSet[] = "KtSet";
  const char RegNameCurrentLoopP[] = "CurrentLoopP";
  const char RegNameSpeedLoopP[] = "SpeedLoopP";
  const char RegNamePowerLoopP[] = "PowerLoopP";
  const char RegNameCurrentLoopI[] = "CurrentLoopI";
  const char RegNameSpeedLoopI[] = "SpeedLoopI";
  const char RegNamePowerLoopI[] = "PowerLoopI";
  const char RegNameFirstCycleSpeed_1[] = "FirstCycleSpeed_1";
  const char RegNameFirstCycleSpeed_2[] = "FirstCycleSpeed_2";
  const char RegNameFirstCycleSpeed_3[] = "FirstCycleSpeed_3";
  const char RegNameLockRestartCm[] = "LockRestartCm";
  const char RegNameOcpRstCnt[] = "OcpRstCnt";
  const char RegNameStartupCurrentLvl1[] = "StartupCurrentLvl1";
  const char RegNamePowconDccurLim[] = "PowconDccurLim";

  const char *const RegisterNames[] = {
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
  uint32_t Register::bitMask() const
  {
    return (1UL << size) - 1;
  }

  void Register::copyRegisterName(RegisterId id, char *name)
  {
    // const char *string = (const char *)pgm_read_word(&RegisterNames[id]);
    strcpy(name, *&RegisterNames[id]);
  }

  void Register::fillAllRegsWithDefault(Register *allRegs)
  {
    memcpy(allRegs, DefaultRegs, sizeof(DefaultRegs));
  }
}