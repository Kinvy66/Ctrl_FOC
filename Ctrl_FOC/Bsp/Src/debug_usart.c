#include "bsp.h"
#include "usart.h"
#include "usbd_cdc_if.h"
volatile struct Frame vofaFrame = {
	.tail = {0x00, 0x00, 0x80, 0x7f}
};

/*
*********************************************************************************************************
*	函 数 名: debug_print
*	功能说明: 格式化并通过UART发送调试信息。该函数接受一个格式化字符串和可变数量的参数，
*            将它们格式化为一个字符串，然后通过UART发送出去。
*	形    参：
*           fmt: 格式化字符串，类似于printf的格式。
*           ...: 可变数量的参数，与fmt中的格式说明符对应。
*	返 回 值: 无
* 注意事项：传入参数不要超过255个字节，否则会导致数据丢失。
*						本函数进行了线程安全保护。(不要在中断调用本函数)
*********************************************************************************************************
*/
void debug_print(const char *const fmt, ...)
{
	// char str[256];
	// uint16_t len;
	// va_list args;
 //
	// memset((char *)str, 0, sizeof(char)*256);
	// va_start(args, fmt);
	// vsnprintf((char *)str, 255, (char const *)fmt, args);
	// va_end(args);
 //
	// len = strlen((char *)str);
	// // 获取互斥锁，保护串口资源
 //  xSemaphoreTake(xUartMutex, portMAX_DELAY);
	// HAL_UART_Transmit_DMA(&huart3, (uint8_t*)str, len);
	// // 等待发送完成信号量
 //  xSemaphoreTake(xTxSemaphore, portMAX_DELAY);
	// // 释放互斥锁
 //  xSemaphoreGive(xUartMutex);
}


/*
*********************************************************************************************************
*	函 数 名: vofa_print
*	功能说明: 发送vfoa数据帧
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void vofa_print(void)
{
	// HAL_UART_Transmit_DMA(&huart3, (uint8_t *) (&vofaFrame), sizeof(vofaFrame));
	CDC_Transmit_FS((uint8_t *) (&vofaFrame), sizeof(vofaFrame));
}
