/**
* @file trans.h
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/20 
* @description: 坐标变换
**/

#ifndef __TRANS_H
#define __TRANS_H

#include "arm_math.h"

/* sqrt(3) */
#define SQRT3            1.73205080757f
/* sqrt(3)/2 */
#define SQRT3_BY_TWO     0.86602540378f
/* 1/sqrt(3)  */
#define ONE_BY_SQRT3     0.57735026919f
/* 2/sqrt(3)  */
#define TWO_BY_SQRT3     1.15470053838f

#define PI               3.14159265358979f

/* defin sin cons function */
#define sinf(x)      arm_sin_f32(x)
#define cosf(x)      arm_cos_f32(x)

/**
 * @brief clarke 变换
 * @param[in] Ia a 轴电流
 * @param[in] Ib b 轴电流
 * @param[in] Ic c 轴电流
 * @param[out] Ialpha 转换后 alpha 轴的值
 * @param[out] Ibeta  转换后 beta 轴的值
 */
void clark_transform(float Ia, float Ib, float Ic, float *Ialpha, float *Ibeta);

/**
 * @brief park 变换
 * @param[in] Ialpha alpha 轴电流
 * @param[in] Ibeta beta 轴电流
 * @param[in] theta 旋转角度
 * @param[out] Id 转换后的d轴
 * @param[out] Iq 转换后的q轴
 */
void park_transform(float Ialpha, float Ibeta, float theta, float* Id, float* Iq);

/**
 * @brief 反park变换
 * @param[in] Id
 * @param[in] Iq
 * @param[in] theta
 * @param[out]  Ialpha
 * @param[out]  Ibeta
 */
void inv_park_transform(float Id, float Iq, float theta, float* Ialpha, float* Ibeta);

/**
 * @brief 反clarke变换
 * @param[in] Ialpha
 * @param[in] Ibeta
 * @param[out]  Ia
 * @param[out]  Ib
 * @param[out]  Ic
 */
void inv_clark_transform(float Ialpha, float Ibeta, float *Ia, float *Ib, float *Ic);

/**
 * @brief svpmw生成
 * @param[in] Ua
 * @param[in] Ub
 * @param[in] Uc
 * @param[out]  svm_a
 * @param[out]  svm_b
 * @param[out]  svm_c
 */
void svpwm_generte(float Ua, float Ub, float Uc, float *svm_a, float *svm_b, float *svm_c);

/**
 * @brief 坐标变换测试
 */
void transform_test();

#endif //__TRANS_H
