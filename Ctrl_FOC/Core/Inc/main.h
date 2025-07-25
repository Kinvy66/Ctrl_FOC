/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
uint32_t DWT_Delay_Init(void);
void DWT_Delay_us(volatile uint32_t microseconds);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_15
#define LED3_GPIO_Port GPIOC
#define IC_Pin GPIO_PIN_0
#define IC_GPIO_Port GPIOA
#define IB_Pin GPIO_PIN_1
#define IB_GPIO_Port GPIOA
#define IA_Pin GPIO_PIN_2
#define IA_GPIO_Port GPIOA
#define ADSPE_Pin GPIO_PIN_4
#define ADSPE_GPIO_Port GPIOC
#define LIN1_Pin GPIO_PIN_13
#define LIN1_GPIO_Port GPIOB
#define LIN2_Pin GPIO_PIN_14
#define LIN2_GPIO_Port GPIOB
#define LIN3_Pin GPIO_PIN_15
#define LIN3_GPIO_Port GPIOB
#define KEY4_Pin GPIO_PIN_6
#define KEY4_GPIO_Port GPIOC
#define KEY3_Pin GPIO_PIN_7
#define KEY3_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_8
#define KEY2_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOC
#define HIN1_Pin GPIO_PIN_8
#define HIN1_GPIO_Port GPIOA
#define HIN2_Pin GPIO_PIN_9
#define HIN2_GPIO_Port GPIOA
#define HIN3_Pin GPIO_PIN_10
#define HIN3_GPIO_Port GPIOA
#define LCD_RES_Pin GPIO_PIN_15
#define LCD_RES_GPIO_Port GPIOA
#define LCD_SCK_Pin GPIO_PIN_10
#define LCD_SCK_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_11
#define LCD_DC_GPIO_Port GPIOC
#define LCD_SDA_Pin GPIO_PIN_12
#define LCD_SDA_GPIO_Port GPIOC
#define MT6816_CS_Pin GPIO_PIN_2
#define MT6816_CS_GPIO_Port GPIOD
#define LCD_CS_Pin GPIO_PIN_6
#define LCD_CS_GPIO_Port GPIOB
#define LCD_BLK_Pin GPIO_PIN_7
#define LCD_BLK_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define PWM_PERIOD_CYCLES (uint16_t)((TIMER1_CLK_MHz * (uint32_t) 1000000u / ((uint32_t) (PWM_FREQUENCY))) & 0xFFFE)
#define PWM_FREQUENCY 20000
#define TIMER1_CLK_MHz 170
#define HALF_PWM_PERIOD_CYCLES (uint16_t)(PWM_PERIOD_CYCLES / 2U)
#define TIM7_PERIOD_CYCLES (uint16_t)((TIMER7_CLK_MHz * (uint32_t) 1000000u / ((uint32_t) (TIM7_FREQUENCY))) & 0xFFFE)
#define TIM7_FREQUENCY 20000
#define TIMER7_CLK_MHz 170

#define HAL_Delay_us(us)   DWT_Delay_us(us)

#include "log_debug.h"
#include "led.h"
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
