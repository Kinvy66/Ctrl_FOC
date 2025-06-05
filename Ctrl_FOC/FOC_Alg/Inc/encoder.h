#ifndef __ENCODER_H
#define __ENCODER_H

#include "stdint.h"

typedef struct Encoder
{
    uint8_t offline;            // 编码器是否离线
    float angle;                // 当前的机械角度值(不带圈数)，以弧度为单位
    int32_t full_rotations; 		// 累计的完整旋转次数，表示编码器已经完整旋转了多少次
    int32_t vel_full_rotations; // 速度相关的完整旋转次数，用于计算编码器的旋转速度
    float angle_prev; 			    // 上一次测量的角度值，用于计算角度变化
    uint32_t angle_prev_ts;     // 上一次测量角度的时间戳，用于计算采样时间
    float vel_angle_prev; 	    // 上一次速度测量的角度值，用于计算速度
    uint32_t vel_angle_prev_ts; // 上一次速度测量的时间戳，用于计算速度采样时间

} Encoder_t;

/* 全局变量 */
extern Encoder_t   encoder;


void Encoder_init(void);
void Encoder_update(void);
float Encoder_getMechanicalAngle(void);
float Encoder_getAngle(void);
float Encoder_getVelocity(void);
float Encoder_electrical_angle(void);

#endif //__ENCODER_H
