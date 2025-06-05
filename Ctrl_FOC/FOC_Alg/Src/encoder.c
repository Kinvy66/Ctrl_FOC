#include "encoder.h"
#include <stdbool.h>
#include "arm_math.h"
#include "mt6816.h"

#define M_PI                                          (3.14159265358f)
#define M_2PI                                         (6.28318530716f)
#define FOC_ABS(x)                                    ((x) > 0 ? (x) : -(x))

Encoder_t   encoder;
static inline void encoder_get_mechanical_angle(void)
{
    encoder.offline = mt6816_get_angle(&encoder.angle);
}


/*
*********************************************************************************************************
*	函 数 名: Encoder_init
*	功能说明: 初始化编码器
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void Encoder_init(void)
{
  encoder.offline = true; /* 初始化Encoder状态为离线 */
  encoder.angle = 0.0f;
  encoder.full_rotations = 0;		/* 初始 当前位置 圈数为0 */
  encoder.vel_full_rotations = 0; /* 初始 速度计算起点 相关的圈数为0 */
  /* 获取 速度计算起点 相关的初始角度值，并记录当前的时间戳 */
  encoder_get_mechanical_angle();
  encoder.vel_angle_prev = encoder.angle;
  // encoder.vel_angle_prev_ts = HAL_GetTick();
  /* 获取 当前位置 的初始角度值，并记录当前的时间戳 */
  encoder_get_mechanical_angle();
  encoder.angle_prev = encoder.angle;
  // encoder.angle_prev_ts = HAL_GetTick();
}

/*
*********************************************************************************************************
*	函 数 名: Encoder_update
*	功能说明: 更新编码器状态
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void Encoder_update(void)
{
  encoder_get_mechanical_angle();
  float val = encoder.angle;
  // encoder.angle_prev_ts = HAL_GetTick();
  float d_angle = val - encoder.angle_prev;
  // 圈数检测
  if(FOC_ABS(d_angle) > (0.8f*M_PI) ) encoder.full_rotations += ( d_angle > 0 ) ? -1 : 1;
  encoder.angle_prev = val;
}

/*
*********************************************************************************************************
*	函 数 名: Encoder_getMechanicalAngle
*	功能说明: 获取编码器机械角度(不带圈数)
*	形    参: 无
*	返 回 值: 返回编码器的角度值，单位为弧度
*********************************************************************************************************
*/
float Encoder_getMechanicalAngle(void)
{
  return encoder.angle;
}

/*
*********************************************************************************************************
*	函 数 名: Encoder_getAngle
*	功能说明: 获取编码器多圈角度
*	形    参: 无
*	返 回 值: 返回编码器的多圈角度值，单位为弧度
*********************************************************************************************************
*/
float Encoder_getAngle(void)
{
  return (float)encoder.full_rotations * M_2PI + encoder.angle_prev;
}

/*
*********************************************************************************************************
*	函 数 名: Encoder_getVelocity
*	功能说明: 获取编码器的速度
*	形    参: 无
*	返 回 值: 返回编码器的速度值，单位为弧度/秒
*********************************************************************************************************
*/
float Encoder_getVelocity(void)
{
	float Ts;

  // // 计算采样时间
  // Ts = (encoder.angle_prev_ts - encoder.vel_angle_prev_ts)*1e-3;
  // // 如果溢出则设置Ts为1ms
  // if(Ts <= 0) Ts = 1e-3f;

  /* 编码器采样频率 */
  // TODO: Ts
  // Ts = 1.0f / PWM_FREQUENCY;

  // 速度计算
  float vel = ( (float)(encoder.full_rotations - encoder.vel_full_rotations)*M_2PI +
    (encoder.angle_prev - encoder.vel_angle_prev) ) / Ts;
  // 保存变量以待将来使用
  encoder.vel_angle_prev = encoder.angle_prev;
  encoder.vel_full_rotations = encoder.full_rotations;
  encoder.vel_angle_prev_ts = encoder.angle_prev_ts;
  return vel;
}

/*
*********************************************************************************************************
*	函 数 名: Encoder_electrical_angle
*	功能说明: 获取编码器电角度
*	形    参: 无
*	返 回 值: 返回编码器的电角度值
*********************************************************************************************************
*/
inline float Encoder_electrical_angle(void)
{
	// return  normalize_angle((float)(UsrConfig.encoder_dir * UsrConfig.motor_pole_pairs)
 //                      * Encoder_getMechanicalAngle() - UsrConfig.zero_electric_angle);
  return 0;
}
