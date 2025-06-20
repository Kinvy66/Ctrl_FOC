#ifndef __DEBUG_USART_H
#define __DEBUG_USART_H
#define CH_COUNT 10
struct Frame
{
    float fdata[CH_COUNT];
    unsigned char tail[4];
};
extern volatile struct Frame vofaFrame;
/* 供外部调用的函数声明 */
void debug_print(const char *const fmt, ...);
void vofa_print(void);

#endif //__DEBUG_USART_H
