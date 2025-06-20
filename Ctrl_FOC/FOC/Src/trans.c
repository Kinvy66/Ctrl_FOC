/**
* @file trans.c
* @author Kinvy
* @email kinvy66@163.com
* @date: 2025/6/20 14:52
* @description: 坐标变换
**/
#include "trans.h"

/**
 * @brief clarke 变换
 * @param[in] Ia a 轴电流
 * @param[in] Ib b 轴电流
 * @param[in] Ic c 轴电流
 * @param[out] Ialpha 转换后 alpha 轴的值
 * @param[out] Ibeta  转换后 beta 轴的值
 */
void clark_transform(float Ia, float Ib, float Ic,
    float *Ialpha, float *Ibeta)
{
    *Ialpha = (Ia - 0.5f*(Ib+Ic)) * 2.0f/3.0f;
    *Ibeta = (Ia - 0.5f*(Ib-Ic)) * 2.0f/3.0f;

    /* 另一种计算方式 Ia+Ib+Ic = 0, 非正交形式 */
    // *Ialpha = Ia;
    /* Calculate pIbeta using the equation, pIbeta = (1/sqrt(3)) * Ia + (2/sqrt(3)) * Ib */
    // *Ibeta =  ONE_BY_SQRT3 * Ia +  TWO_BY_SQRT3 * Ib;
}

/**
 * @brief park 变换
 * @param[in] Ialpha alpha 轴电流
 * @param[in] Ibeta beta 轴电流
 * @param[in] theta 旋转角度
 * @param[out] Id 转换后的d轴
 * @param[out] Iq 转换后的q轴
 */
void park_transform(float Ialpha, float Ibeta, float theta,
    float* Id, float* Iq)
{
    *Id = Ialpha * cosf(theta) + Ibeta * sinf(theta);
    *Iq = -Ialpha * sinf(theta) + Ibeta * cosf(theta);
}

/**
 * @brief 反park变换
 * @param[in] Id
 * @param[in] Iq
 * @param[in] theta
 * @param[out]  Ialpha
 * @param[out]  Ibeta
 */
void inv_park_transform(float Id, float Iq, float theta,
    float* Ialpha, float* Ibeta)
{
    *Ialpha = Iq * cosf(theta) - Iq * sinf(theta);
    *Ibeta = Iq * sinf(theta) + Iq * cosf(theta);
}

/**
 * @brief 反clarke变换
 * @param[in] Ialpha
 * @param[in] Ibeta
 * @param[out]  Ia
 * @param[out]  Ib
 * @param[out]  Ic
 */
void inv_clark_transform(float Ialpha, float Ibeta,
    float *Ia, float *Ib, float *Ic)
{
    *Ia = Ialpha;
    *Ib = -0.5f*Ialpha + SQRT3_BY_TWO*Ibeta;
    *Ic = -0.5f*Ialpha - SQRT3_BY_TWO*Ibeta;
}

/**
 * @brief svpmw生成
 * @param[in] Ua
 * @param[in] Ub
 * @param[in] Uc
 * @param[out]  svm_a
 * @param[out]  svm_b
 * @param[out]  svm_c
 */
void svpwm_generte(float Ua, float Ub, float Uc,
    float *svm_a, float *svm_b, float *svm_c)
{

}

/**
 * @brief 坐标变换测试
 */
void transform_test()
{

}
