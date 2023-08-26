#ifndef __A89307_REGISTERS_H__
#define __A89307_REGISTERS_H__

namespace A89307_Reg
{

  /*
   * Bit positions
   */

  /* Register 8 / 72 */
  const uint32_t RATED_SPEED_pos = 0;
  const uint32_t CLOCK_PWM_pos = 11;
  const uint32_t ACCELERATE_RANGE_pos = 13;
  const uint32_t DIRECTION_pos = 14;
  const uint32_t PWMIN_RANGE_pos = 15;

  /* Register 9 / 73 */
  const uint32_t ACCELERATION_pos = 8;
  const uint32_t I_LIMIT_SLOPE_1_pos = 0;

  const uint32_t RATED_CURRENT_pos = 0;
  const uint32_t SPD_MODE_pos = 11;
  const uint32_t STARTUP_CURRENT_pos = 13;

  const uint32_t FG_STANDB_EN_pos = 0;
  const uint32_t OPEN_DRIVE_pos = 3;
  const uint32_t OPEN_PH_PROTECTION_pos = 4;
  const uint32_t MAX_CURR_START_pos = 6;
  const uint32_t SPEED_2_pos = 7;

  const uint32_t PID_P_pos = 0;
  const uint32_t PWM_OUTPUT_FREQUENCY_pos = 5;
  const uint32_t OPEN_WINDOW_pos = 16;

  const uint32_t PID_I_pos = 0;
  const uint32_t POWER_CTR_EN_pos = 3;
  const uint32_t STARTUP_MODE_pos = 6;
  const uint32_t DELAY_START_pos = 14;

  const uint32_t ANGLE_ERROR_LOCK_pos = 2;
  const uint32_t SOFT_OFF_pos = 6;
  const uint32_t SOFT_ON_pos = 7;
  const uint32_t DEADTIME_SETTING_pos = 8;
  const uint32_t SAFE_BRAKE_THRD_pos = 14;

  const uint32_t OCP_ENABLE_pos = 0;
  const uint32_t OCP_RESET_MODE_pos = 3;
  const uint32_t OCP_MASKING_pos = 4;
  const uint32_t FIRST_CYCLE_SPEED_pos = 6;
  const uint32_t ACCELERATE_BUFFER_pos = 8;
  const uint32_t DECELERATE_BUFFER_pos = 10;
  const uint32_t BEMF_LOCK_FILTER_pos = 12;

  const uint32_t SPEED_DEMAND_pos = 0;
  const uint32_t I2C_SPEED_MODE_pos = 9;

  const uint32_t IPD_CURRENT_THR_pos = 8;
  const uint32_t DRIVE_GATE_SLEW_pos = 14;

  const uint32_t INDUCTANCE_SHIFT_pos = 0;
  const uint32_t GD_PULSECURRENT_pos = 3;
  const uint32_t GDPULSE_pos = 5;
  const uint32_t MOSFET_COMP_RISING_pos = 8;
  const uint32_t MOSFET_COMP_FALLING_pos = 12;
  const uint32_t BRAKE_CONTROL_pos = 16;

  const uint32_t RATED_VOLTAGE_pos = 0;
  const uint32_t SENSE_RESISTOR_pos = 8;
  const uint32_t DIR_FROM_REG_pos = 16;
  const uint32_t BRAKE_INPUT_pos = 17;

  const uint32_t TWO_SLOPE_M_pos = 2;
  const uint32_t SPEED_INPUT_OFF_THRESHOLD_pos = 3;
  const uint32_t SLIGHT_MV_DEMAND_pos = 5;
  const uint32_t I_LIMIT_SLOPE_2_pos = 8;

  const uint32_t CLOCK_SPEED_RATIO_pos = 0;
  const uint32_t RESTART_ATTEMPT_pos = 6;
  const uint32_t BRAKE_MODE_pos = 8;
  const uint32_t SOFT_OFF_4S_pos = 9;
  const uint32_t VIBRATION_LOCK_pos = 10;
  const uint32_t LOCK_RESTART_SET_pos = 11;
  const uint32_t DEADTIME_COMP_pos = 12;
  const uint32_t VDS_THRESHOLD_SEL_pos = 15;

  const uint32_t PARAMETERFULL_pos = 0;
  const uint32_t OPERATION_MODE_pos = 11;
  const uint32_t SPEED_CUR_BIDIR_pos = 16;
  const uint32_t CHECK_CURVE_pos = 17;

  const uint32_t MOTOR_RESISTOR_pos = 0;

  const uint32_t INDUCTANCE_pos = 0;
  const uint32_t POWCON_VOL_LIM_pos = 8;
  const uint32_t STRP_LOCK_RTRY_CURR_LVL_EN_pos = 11;
  const uint32_t STARTUP_CURRENT_LVL2_pos = 12;
  const uint32_t STARTUP_CURRENT_LVL3_pos = 15;

  const uint32_t KT_SET_pos = 0;

  const uint32_t CURRENT_LOOP_P_pos = 0;
  const uint32_t SPEED_LOOP_P_pos = 5;
  const uint32_t POWER_LOOP_P_pos = 10;
  const uint32_t CURRENT_LOOP_I_pos = 15;

  const uint32_t SPEED_LOOP_I_pos = 0;
  const uint32_t POWER_LOOP_I_pos = 3;
  const uint32_t FIRST_CYCLE_SPEED_1_pos = 9;
  const uint32_t FIRST_CYCLE_SPEED_2_pos = 11;
  const uint32_t FIRST_CYCLE_SPEED_3_pos = 13;
  const uint32_t LOCK_RESTART_CM_pos = 15;
  const uint32_t OCP_RST_CNT_pos = 16;

  const uint32_t STARTUP_CURRENT_LVL1_pos = 4;
  const uint32_t POWCON_DCCUR_LIM_pos = 7;

  const uint32_t Y_INTERPOLATION_POINT_pos = 0;
  const uint32_t X_INTERPOLATION_POINT_pos = 9;

  /*
   * Bit masks
   */

#define BIT_MASK(size) ~(0xFFFFFF << size)

  const uint32_t RATED_SPEED_bm = BIT_MASK(11);
  const uint32_t CLOCK_PWM_bm = BIT_MASK(2);
  const uint32_t ACCELERATE_RANGE_bm = BIT_MASK(1);
  const uint32_t DIRECTION_bm = BIT_MASK(1);
  const uint32_t PWMIN_RANGE_bm = BIT_MASK(1);
  const uint32_t ACCELERATION_bm = BIT_MASK(8);
  const uint32_t I_LIMIT_SLOPE_1_bm = BIT_MASK(10);
  const uint32_t RATED_CURRENT_bm = BIT_MASK(11);
  const uint32_t SPD_MODE_bm = BIT_MASK(1);
  const uint32_t STARTUP_CURRENT_bm = BIT_MASK(3);
  const uint32_t FG_STANDB_EN_bm = BIT_MASK(1);
  const uint32_t OPEN_DRIVE_bm = BIT_MASK(1);
  const uint32_t OPEN_PH_PROTECTION_bm = BIT_MASK(1);
  const uint32_t MAX_CURR_START_bm = BIT_MASK(1);
  const uint32_t SPEED_2_bm = BIT_MASK(11);
  const uint32_t PID_P_bm = BIT_MASK(5);
  const uint32_t PWM_OUTPUT_FREQUENCY_bm = BIT_MASK(11);
  const uint32_t OPEN_WINDOW_bm = BIT_MASK(1);
  const uint32_t PID_I_bm = BIT_MASK(3);
  const uint32_t POWER_CTR_EN_bm = BIT_MASK(1);
  const uint32_t STARTUP_MODE_bm = BIT_MASK(2);
  const uint32_t DELAY_START_bm = BIT_MASK(1);
  const uint32_t ANGLE_ERROR_LOCK_bm = BIT_MASK(2);
  const uint32_t SOFT_OFF_bm = BIT_MASK(1);
  const uint32_t SOFT_ON_bm = BIT_MASK(1);
  const uint32_t DEADTIME_SETTING_bm = BIT_MASK(6);
  const uint32_t SAFE_BRAKE_THRD_bm = BIT_MASK(2);
  const uint32_t OCP_ENABLE_bm = BIT_MASK(3);
  const uint32_t OCP_RESET_MODE_bm = BIT_MASK(1);
  const uint32_t OCP_MASKING_bm = BIT_MASK(2);
  const uint32_t FIRST_CYCLE_SPEED_bm = BIT_MASK(2);
  const uint32_t ACCELERATE_BUFFER_bm = BIT_MASK(2);
  const uint32_t DECELERATE_BUFFER_bm = BIT_MASK(2);
  const uint32_t BEMF_LOCK_FILTER_bm = BIT_MASK(2);
  const uint32_t SPEED_DEMAND_bm = BIT_MASK(9);
  const uint32_t I2C_SPEED_MODE_bm = BIT_MASK(1);
  const uint32_t IPD_CURRENT_THR_bm = BIT_MASK(6);
  const uint32_t DRIVE_GATE_SLEW_bm = BIT_MASK(2);
  const uint32_t INDUCTANCE_SHIFT_bm = BIT_MASK(3);
  const uint32_t GD_PULSECURRENT_bm = BIT_MASK(2);
  const uint32_t GDPULSE_bm = BIT_MASK(3);
  const uint32_t MOSFET_COMP_RISING_bm = BIT_MASK(4);
  const uint32_t MOSFET_COMP_FALLING_bm = BIT_MASK(4);
  const uint32_t BRAKE_CONTROL_bm = BIT_MASK(1);
  const uint32_t RATED_VOLTAGE_bm = BIT_MASK(8);
  const uint32_t SENSE_RESISTOR_bm = BIT_MASK(8);
  const uint32_t DIR_FROM_REG_bm = BIT_MASK(1);
  const uint32_t BRAKE_INPUT_bm = BIT_MASK(1);
  const uint32_t TWO_SLOPE_M_bm = BIT_MASK(1);
  const uint32_t SPEED_INPUT_OFF_THRESHOLD_bm = BIT_MASK(2);
  const uint32_t SLIGHT_MV_DEMAND_bm = BIT_MASK(3);
  const uint32_t I_LIMIT_SLOPE_2_bm = BIT_MASK(10);
  const uint32_t CLOCK_SPEED_RATIO_bm = BIT_MASK(6);
  const uint32_t RESTART_ATTEMPT_bm = BIT_MASK(2);
  const uint32_t BRAKE_MODE_bm = BIT_MASK(1);
  const uint32_t SOFT_OFF_4S_bm = BIT_MASK(1);
  const uint32_t VIBRATION_LOCK_bm = BIT_MASK(1);
  const uint32_t LOCK_RESTART_SET_bm = BIT_MASK(1);
  const uint32_t DEADTIME_COMP_bm = BIT_MASK(1);
  const uint32_t VDS_THRESHOLD_SEL_bm = BIT_MASK(1);
  const uint32_t PARAMETERFULL_bm = BIT_MASK(11);
  const uint32_t OPERATION_MODE_bm = BIT_MASK(2);
  const uint32_t SPEED_CUR_BIDIR_bm = BIT_MASK(1);
  const uint32_t CHECK_CURVE_bm = BIT_MASK(1);
  const uint32_t MOTOR_RESISTOR_bm = BIT_MASK(8);
  const uint32_t INDUCTANCE_bm = BIT_MASK(8);
  const uint32_t POWCON_VOL_LIM_bm = BIT_MASK(2);
  const uint32_t STRP_LOCK_RTRY_CURR_LVL_EN_bm = BIT_MASK(1);
  const uint32_t STARTUP_CURRENT_LVL2_bm = BIT_MASK(3);
  const uint32_t STARTUP_CURRENT_LVL3_bm = BIT_MASK(3);
  const uint32_t KT_SET_bm = BIT_MASK(9);
  const uint32_t CURRENT_LOOP_P_bm = BIT_MASK(5);
  const uint32_t SPEED_LOOP_P_bm = BIT_MASK(5);
  const uint32_t POWER_LOOP_P_bm = BIT_MASK(5);
  const uint32_t CURRENT_LOOP_I_bm = BIT_MASK(3);
  const uint32_t SPEED_LOOP_I_bm = BIT_MASK(3);
  const uint32_t POWER_LOOP_I_bm = BIT_MASK(3);
  const uint32_t FIRST_CYCLE_SPEED_1_bm = BIT_MASK(2);
  const uint32_t FIRST_CYCLE_SPEED_2_bm = BIT_MASK(2);
  const uint32_t FIRST_CYCLE_SPEED_3_bm = BIT_MASK(2);
  const uint32_t LOCK_RESTART_CM_bm = BIT_MASK(1);
  const uint32_t OCP_RST_CNT_bm = BIT_MASK(1);
  const uint32_t STARTUP_CURRENT_LVL1_bm = BIT_MASK(3);
  const uint32_t POWCON_DCCUR_LIM_bm = BIT_MASK(11);
  const uint32_t Y_INTERPOLATION_POINT_bm = BIT_MASK(9);
  const uint32_t X_INTERPOLATION_POINT_bm = BIT_MASK(9);

  struct Register
  {
    const uint8_t address;
    const uint8_t shadowAddress = address + 64;
    uint32_t value = 0;
    boolean initialized = false;
  };
}

#endif __A89307_REGISTERS_H__
