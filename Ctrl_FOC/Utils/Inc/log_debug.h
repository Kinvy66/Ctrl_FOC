#ifndef __LOG_DEBUG_H
#define __LOG_DEBUG_H

#include "stdint.h"

/******************************************************************************
*                                   debug                                    *
******************************************************************************/
/*! ----------------------------------------------------------------------------
 * @brief
 *
 */
#define M_LOGWARNING( ...)   do{printf("[W %s:%-4d]", __func__, __LINE__);printf(__VA_ARGS__);}while(0)
#define M_LOGERROR(...)      do{printf("[E %s:%-4d]", __func__, __LINE__);printf(__VA_ARGS__);}while(0)
#define M_LOGDEBUG( ...)     do{printf("[D %s:%-4d]", __func__, __LINE__);printf(__VA_ARGS__);}while(0)
#define M_DEBUG( ...)        do{printf(__VA_ARGS__);printf("\r\n");}while(0)
#define M_PRINT_DATA(info ,data, len)    do{\
printf("%s",info);uint8_t *__P_MD__ = (uint8_t *)(data);\
for (unsigned short _nI_ = 0; _nI_ < (len); _nI_++){printf("%02X", __P_MD__[_nI_]);}printf("\r\n");\
}while(0)

#endif //__LOG_DEBUG_H
