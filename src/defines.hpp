#ifndef __DEFINES_H__
#define __DEFINES_H__

namespace A89307_Defines
{

#define EXTRACT_BITS(val, x) (val >> x##_pos) & x##_bm

  enum I2CResult
  {
    /*
     *            0 for success,
     *            2 for when the address was NACK'd
     *            3 for when the data was NACK'd
     *            4 for unknown error
     *            5 for timeout on the bus
     *           16 for TWI is in a bad state
     *           17 for the pull ups likely missing
     *           18 for a bus arbitration/bus fault
     *           20 for likely a slave holding the clock low
     *          255 (-1) for TWI not initialized (begin not called) or bus somehow in "unknown" state.
     */
    Success = 0,
    AddressNack = 2,
    DataNack = 3,
    UnknownError = 4,
    BusTimeout = 5,
    TWIBadState = 16,
    PullupMissing = 17,
    BusFault = 18,
    ClkStuckLow = 20,
    TWINotInitialized = 255

  };

  /* Configuration options */
  enum ConfigurationName
  {
    RATED_SPEED,
    CLOCK_PWM,
    ACCELERATE_RANGE,
    DIRECTION,
    PWMIN_RANGE,
    ACCELERATION,
    I_LIMIT_SLOPE_1,
    RATED_CURRENT,
    SPD_MODE,
    STARTUP_CURRENT,
    FG_STANDB_EN,
    OPEN_DRIVE,
    OPEN_PH_PROTECTION,
    MAX_CURR_START,
    SPEED_2,
    PID_P,
    PWM_OUTPUT_FREQUENCY,
    OPEN_WINDOW,
    PID_I,
    POWER_CTR_EN,
    STARTUP_MODE,
    DELAY_START,
    ANGLE_ERROR_LOCK,
    SOFT_OFF,
    SOFT_ON,
    DEADTIME_SETTING,
    SAFE_BRAKE_THRD,
    OCP_ENABLE,
    OCP_RESET_MODE,
    OCP_MASKING,
    FIRST_CYCLE_SPEED,
    ACCELERATE_BUFFER,
    DECELERATE_BUFFER,
    BEMF_LOCK_FILTER,
    SPEED_DEMAND,
    I2C_SPEED_MODE,
    IPD_CURRENT_THR,
    DRIVE_GATE_SLEW,
    INDUCTANCE_SHIFT,
    GD_PULSECURRENT,
    GDPULSE,
    MOSFET_COMP_RISING,
    MOSFET_COMP_FALLING,
    BRAKE_CONTROL,
    RATED_VOLTAGE,
    SENSE_RESISTOR,
    DIR_FROM_REG,
    BRAKE_INPUT,
    TWO_SLOPE_M,
    SPEED_INPUT_OFF_THRESHOLD,
    SLIGHT_MV_DEMAND,
    I_LIMIT_SLOPE_2,
    CLOCK_SPEED_RATIO,
    RESTART_ATTEMPT,
    BRAKE_MODE,
    SOFT_OFF_4S,
    VIBRATION_LOCK,
    LOCK_RESTART_SET,
    DEADTIME_COMP,
    VDS_THRESHOLD_SEL,
    PARAMETERFULL,
    OPERATION_MODE,
    SPEED_CUR_BIDIR,
    CHECK_CURVE,
    MOTOR_RESISTOR,
    INDUCTANCE,
    POWCON_VOL_LIM,
    STRP_LOCK_RTRY_CURR_LVL_EN,
    STARTUP_CURRENT_LVL2,
    STARTUP_CURRENT_LVL3,
    KT_SET,
    CURRENT_LOOP_P,
    SPEED_LOOP_P,
    POWER_LOOP_P,
    CURRENT_LOOP_I,
    SPEED_LOOP_I,
    POWER_LOOP_I,
    FIRST_CYCLE_SPEED_1,
    FIRST_CYCLE_SPEED_2,
    FIRST_CYCLE_SPEED_3,
    LOCK_RESTART_CM,
    OCP_RST_CNT,
    STARTUP_CURRENT_LVL1,
    POWCON_DCCUR_LIM,
    Y_INTERPOLATION_POINT,
    X_INTERPOLATION_POINT,
  };

  struct ConfigValue
  {
    const ConfigurationName name;
    uint32_t value;
  };

  struct DriverConfiguration
  {
  };
}
#endif __DEFINES_H__