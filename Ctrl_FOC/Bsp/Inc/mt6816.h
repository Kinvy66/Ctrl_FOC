#ifndef __MT6816_H
#define __MT6816_H

#include  "main.h"

/**
 * @brief 读取mt6816角度，单位rad
 * @param [out] angle
 * @return 0, 成功  1,失败
 */
uint8_t mt6816_get_angle(float *_angle);

#endif //__MT6816_H
