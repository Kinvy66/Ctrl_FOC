#ifndef __BSP_H
#define __BSP_H

#define USE_FreeRTOS 0	/* 使能FreeRTOS */

/* 包含FreeRTOS头文件 */
#if USE_FreeRTOS == 1
    #include "FreeRTOS.h"
    #include "task.h"
    #include "event_groups.h"
    #include "queue.h"
    #include "semphr.h"
    #define DISABLE_INT()	taskENTER_CRITICAL() /* 禁止全局中断 */
    #define ENABLE_INT()	taskEXIT_CRITICAL()  /* 使能全局中断 */
#else
    #define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */
    #define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#endif


#include "main.h"

/* 包含标准库头文件 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifndef TRUE
    #define TRUE  1
#endif

#ifndef FALSE
    #define FALSE 0
#endif


#include "led.h"
#include "key.h"
#include "lcd.h"
#include "debug_usart.h"
#include "chry_ringbuffer.h"
// #include "shell_port.h"


#endif //__BSP_H
