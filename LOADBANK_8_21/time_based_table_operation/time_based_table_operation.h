/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Operation.h
  * @brief   This file contains all the function prototypes for
  *          the Operation.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __time_based_table_operation_H__
#define __time_based_table_operation_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
struct Setting_Data
{
	uint8_t Interval_ID;
	uint8_t Start_ID;
	uint8_t End_ID;
	uint8_t Intervals_Number;
  uint8_t Current_Setting;
	uint16_t Duration_Setting;
	uint16_t Duration_collapsed;
};
typedef struct Setting_Data Setting_Data_Typedef;

typedef struct table 
{
	uint16_t current;
	uint16_t duration;
	uint32_t iteration_capacity;
	uint32_t total_capacity;
}s_table_typedef ; 
enum Actions_Statues_Enum{ SET_ID , CONTINUE_PROGRESS , FINISHED , NOTFINISHED };
/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */
void Pass_Intervals_Data(  s_table_typedef *Current_Duration_Table  );
void Interval_Switching_Action( enum Actions_Statues_Enum Interval_Action_Type );
void Start_Operation ( uint8_t Start_ID , uint8_t End_ID , s_table_typedef *Current_Duration_Table);
void Stop_Operation (void);
void Resume_Operation (void);
void Pause_Operation (void);
Setting_Data_Typedef Get_Interval_Currentstatus ( void );
void Duration_Counter_Process(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ time_based_table_operation_H__ */

