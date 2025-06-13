#ifndef __DEBUG_USART_H
#define __DEBUG_USART_H
#define CH_COUNT 10
struct Frame
{
    float fdata[CH_COUNT];
    unsigned char tail[4];
};
extern volatile struct Frame vofaFrame;
extern SemaphoreHandle_t xTxSemaphore;  // 用于发送完成的信号量
extern SemaphoreHandle_t xUartMutex;    // 用于保护串口资源的互斥锁
/* 供外部调用的函数声明 */
void debug_print(const char *const fmt, ...);
void vofa_print(void);

#endif //__DEBUG_USART_H
