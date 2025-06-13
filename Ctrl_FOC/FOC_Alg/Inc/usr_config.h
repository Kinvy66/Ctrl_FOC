#ifndef __USR_CONFIG_H
#define __USR_CONFIG_H

#include "stdint.h"

/* 电机控制模式枚举 */
typedef enum {
    CONTROL_MODE_TORQUE_RAMP      = 1, // 电流环
    CONTROL_MODE_VELOCITY_RAMP    = 2, // 速度-电流环
    CONTROL_MODE_POSITION_RAMP    = 3, // 角度-电流环
    CONTROL_MODE_POSITION_PROFILE = 4  // 角度-速度-电流环
} tControlMode;

typedef struct sUsrConfig
{
    // Motor
    uint8_t motor_pole_pairs;       // [PP]                 (2~30)
    float   motor_phase_resistance; // [R]                  (0~10)
    float   motor_phase_inductance; // [H]                  (0~10)
    float   current_limit;          // [A]                  (0~45)
    float   velocity_limit;         // [turn/s]             (0~100)
    // Calibration
    uint8_t is_calibrated;
    float zero_electric_angle;      // []
    // Controller
    int32_t control_mode;           // [Ctr_Mode]           (0~4)
    float   current_ctrl_bw;        //                      (2~60000)

    // Protect
    float protect_under_voltage;    // [V]                  (0~50)
    float protect_over_voltage;     // [V]                  (0~50)
    // COMM
    // Encoder
    int32_t encoder_dir;            // [CW/CCW]
    float encoder_offset;           // []

} tUsrConfig;

/* 全局变量 */
extern tUsrConfig   UsrConfig;

/* 提供给其他C文件调用的函数 */
void USR_CONFIG_set_default_config(void);

#endif //__USR_CONFIG_H
