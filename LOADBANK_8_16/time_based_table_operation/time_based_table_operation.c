/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    Operation.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "time_based_table_operation.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint16_t Duration_Counter ;
static enum Actions_Statues_Enum Interval_Process_Status ;
static enum Actions_Statues_Enum Interval_Action_Type ;
static enum Actions_Statues_Enum Overall_Process_Status ;

s_table_typedef *Current_Duration_Data;
static Setting_Data_Typedef Setting_Data ;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/





void Duration_Counter_Process(void)
{
	if(Overall_Process_Status == NOTFINISHED )
	{
		Duration_Counter++;
		Setting_Data.Duration_collapsed = Duration_Counter ;
		if( Duration_Counter >= Setting_Data.Duration_Setting )
		{
			Interval_Process_Status = FINISHED ;
		}
		else
		{
			Interval_Process_Status = NOTFINISHED ;
		}
		
		Interval_Switching_Action(CONTINUE_PROGRESS);
	}
	
}
/***********************************************************************/
void Interval_Switching_Action( enum Actions_Statues_Enum Interval_Action_Type )
{

	if( Interval_Action_Type == SET_ID )
	{	
		Setting_Data.Current_Setting = Current_Duration_Data[Setting_Data.Interval_ID].current;   			
		Setting_Data.Duration_Setting = Current_Duration_Data[Setting_Data.Interval_ID].duration;				
		Interval_Action_Type = CONTINUE_PROGRESS;
	}

	else if ( Interval_Action_Type == CONTINUE_PROGRESS && Overall_Process_Status == NOTFINISHED )
	{
		if(Interval_Process_Status == FINISHED )
		{	
			Duration_Counter = 0 ;
			Setting_Data.Duration_collapsed = Duration_Counter ;
			Setting_Data.Interval_ID++;
			
			if( Setting_Data.Interval_ID <= Setting_Data.End_ID  )
			{
				Setting_Data.Current_Setting = Current_Duration_Data[Setting_Data.Interval_ID].current;   			
				Setting_Data.Duration_Setting = Current_Duration_Data[Setting_Data.Interval_ID].duration;	
			}
			else
			{	
				Stop_Operation() ;
			}
		
		}
	}
	
}


/*****************************************************************************************/
void Start_Operation ( uint8_t Start_ID , uint8_t End_ID,  s_table_typedef *Current_Duration_Table  )
{ 
	Current_Duration_Data = Current_Duration_Table;
	Setting_Data.Start_ID = Start_ID;
	Setting_Data.Interval_ID = Start_ID;
	Setting_Data.End_ID = End_ID ;
	Interval_Action_Type = SET_ID ;
	Overall_Process_Status = NOTFINISHED;
	Interval_Switching_Action( Interval_Action_Type );
	 
		
}


/*****************************************************************************************/
void Pass_Intervals_Data(  s_table_typedef *Current_Duration_Table  )
{
	
	
}


Setting_Data_Typedef Get_Interval_Currentstatus ( void )
{
	return Setting_Data ;
}


void Pause_Operation (void)
{
	Overall_Process_Status = FINISHED;
}

void Resume_Operation (void)
{
	Overall_Process_Status = NOTFINISHED;
}

void Stop_Operation (void)
{
	Overall_Process_Status = FINISHED;
	//Restore to the initial condition
	Duration_Counter = 0 ;
	Setting_Data.Duration_collapsed = Duration_Counter;
	Setting_Data.Current_Setting = 0;   			
	Setting_Data.Duration_Setting = 0;	
			

}

/* USER CODE END 0 */


/* USER CODE BEGIN 1 */

/* USER CODE END 1 */




/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
