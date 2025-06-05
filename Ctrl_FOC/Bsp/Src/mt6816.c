#include "mt6816.h"
#include "spi.h"
#include "arm_math.h"

#define MT6816_CS_0()	    MT6816_CS_GPIO_Port->BSRR = ((uint32_t)MT6816_CS_Pin << 16U)
#define MT6816_CS_1()		MT6816_CS_GPIO_Port->BSRR = MT6816_CS_Pin
#define MT6816_SPI          hspi1

/**
 * @brief 通过SPI从MT6816获取角度数据并转换为弧度 [0, 2π]
 * @param [out] _angle
 * @return  0: 成功，1: 失败
 */
uint8_t mt6816_get_angle(float *_angle)
{
    uint16_t sample_data;  // 从传感器获取的原始数据
    float angle = 0.0f;    // 经过处理后得到的弧度 [0, 2π]
    uint8_t pc_flag = 0;   // 奇偶校验标志位
    uint8_t no_mag_flag = 0; // 弱磁报警, 太弱为1
    UNUSED(no_mag_flag);
    uint16_t data_t[2] = {0x8300, 0x8400};
    uint16_t data_r[2];
    HAL_StatusTypeDef state = HAL_OK;
    // 尝试最多3次读取数据，直到奇偶校验通过
    for (uint8_t i = 0; i < 3; i++)
    {
        MT6816_CS_0();  // 使能片选
        __NOP();
        state |= HAL_SPI_TransmitReceive(&MT6816_SPI, (uint8_t*)&data_t[0], (uint8_t*)&data_r[0], 1, 100);
        MT6816_CS_1();  // 禁能片选
        __NOP();
        MT6816_CS_0();  // 使能片选
        __NOP();
        state |= HAL_SPI_TransmitReceive(&MT6816_SPI, (uint8_t*)&data_t[1], (uint8_t*)&data_r[1], 1, 100);
        MT6816_CS_1();  // 禁能片选
        __NOP();
        /* 检查SPI传输状态 */
        if (state != HAL_OK)
        {
            *_angle = angle;  // 返回默认角度值
            return 1;  // 失败
        }
        // 合并接收到的数据
        sample_data = ((data_r[0] & 0x00FF) << 8) | (data_r[1] & 0x00FF);
        /* 没有检测到磁信号 */
        if (sample_data == 0x0000)
        {
            *_angle = angle;  // 返回默认角度值
            return 1;  // 失败
        }
        // 奇偶校验
        if (!(__builtin_popcount(sample_data) & 0x01))
        {
            pc_flag = 1;
            break;  // 校验通过，退出循环
        }
    }
    if (pc_flag)
    {
        // 计算角度并转换为弧度
        angle = (float)(sample_data >> 2) * 360.0f / 16384.0f * M_PI / 180.0f;
        no_mag_flag = (uint8_t)(sample_data & (0x0001 << 1));
        *_angle = angle;
        return 0;  // 成功
    }
    else
    {
        *_angle = angle;  // 返回默认角度值
        return 1;  // 失败
    }
}
