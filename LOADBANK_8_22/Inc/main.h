/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f0xx_hal.h"

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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define R7_Pin GPIO_PIN_13
#define R7_GPIO_Port GPIOC
#define R6_Pin GPIO_PIN_14
#define R6_GPIO_Port GPIOC
#define R5_Pin GPIO_PIN_15
#define R5_GPIO_Port GPIOC
#define R4_Pin GPIO_PIN_3
#define R4_GPIO_Port GPIOC
#define R3_Pin GPIO_PIN_0
#define R3_GPIO_Port GPIOA
#define R2_Pin GPIO_PIN_1
#define R2_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_4
#define R1_GPIO_Port GPIOF
#define R8_Pin GPIO_PIN_5
#define R8_GPIO_Port GPIOF
#define fine_tune_relay_Pin GPIO_PIN_4
#define fine_tune_relay_GPIO_Port GPIOA
#define fan_Pin GPIO_PIN_4
#define fan_GPIO_Port GPIOC
#define FB14_Pin GPIO_PIN_14
#define FB14_GPIO_Port GPIOB
#define FB13_Pin GPIO_PIN_15
#define FB13_GPIO_Port GPIOB
#define LD4_Pin GPIO_PIN_8
#define LD4_GPIO_Port GPIOC
#define LD3_Pin GPIO_PIN_9
#define LD3_GPIO_Port GPIOC
#define FB12_Pin GPIO_PIN_9
#define FB12_GPIO_Port GPIOA
#define FB11_Pin GPIO_PIN_10
#define FB11_GPIO_Port GPIOA
#define FB_fan_Pin GPIO_PIN_11
#define FB_fan_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define FB_fine_tune_Pin GPIO_PIN_6
#define FB_fine_tune_GPIO_Port GPIOF
#define FB8_Pin GPIO_PIN_7
#define FB8_GPIO_Port GPIOF
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define FB7_Pin GPIO_PIN_10
#define FB7_GPIO_Port GPIOC
#define FB6_Pin GPIO_PIN_11
#define FB6_GPIO_Port GPIOC
#define FB5_Pin GPIO_PIN_12
#define FB5_GPIO_Port GPIOC
#define FB4_Pin GPIO_PIN_4
#define FB4_GPIO_Port GPIOB
#define FB3_Pin GPIO_PIN_5
#define FB3_GPIO_Port GPIOB
#define FB2_Pin GPIO_PIN_8
#define FB2_GPIO_Port GPIOB
#define FB1_Pin GPIO_PIN_9
#define FB1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
