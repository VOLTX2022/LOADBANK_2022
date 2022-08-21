#include "time_handler.h"
#include "firing.h"
#include "measurement.h"
#include "hmi_handler.h"
#include "configration.h"
#include "hmi_communication.h"
#include "application.h"
#include "measurement_history.h"
#include "auto_mode.h"
#include "time_based_table_operation.h"
#include "capacity_measurement.h"
#define three_seconds 6
#define two_seconds 4
#define one_second     2	
#define one__and_half_second     3	
#define eight_seconds  16
#define no_of_miles(x)   ((1000/100)*x) //x timer step duration in micros timer
volatile uint8_t _500miles_flag=0;
volatile uint8_t _1mile_flag=0;
volatile uint8_t _3mile_flag=0;
volatile uint8_t _10miles_flag=0;
volatile uint8_t _100miles_flag=0;
volatile uint8_t _40miles_flag=0;
volatile uint8_t _43miles_flag=0;
 uint16_t half_seconds_counter=0;
volatile uint32_t  counter_of_100_micros_for_general_use=0;
volatile uint64_t funcution_time_counter=0;
extern void hmi_simulation(int Adr , int Val);
extern uint8_t diagnosing_arr[20];
void set_half_sec_counter(uint16_t value)
{
half_seconds_counter=value;
}
uint8_t enque_counter=0;
uint16_t FAN_STOP_counter=0;
	void	MULTI_PURPOSE_TIMER(void)
{		
	//SEND_TO_HMI(beepbeep,50);
		 if(_500miles_flag==1)
	{_500miles_flag=0;
		  half_seconds_counter++;
      refresh_hmi_screen_while_unpushed();
		ILLUMINATE_STEPS_ON_HMI();
		if(search_if_any_step_on()||(pwm_value>0))
		{
      HAL_GPIO_WritePin(fan_GPIO_Port,fan_Pin,GPIO_PIN_SET);//if any step on __ close after 6min all steps off
			FAN_STOP_counter=0;
		}
		else
		{ 
			FAN_STOP_counter++;
			if((120*6)==FAN_STOP_counter)
			{FAN_STOP_counter=0;
		  HAL_GPIO_WritePin(fan_GPIO_Port,fan_Pin,GPIO_PIN_RESET);
			}
		}
		
    //	 DISPLAY_MEASUREMENT();
    //		 	   if(0==(half_seconds_counter%one_second))
	  {
		 FLASH_ON_HMI();
	  }
	  if(0==(half_seconds_counter%one__and_half_second))
		 {
			 static int x=0;
			if(x==0)
			{
        //hmi_simulation(STEP6_ADDRESS,1);
        //hmi_simulation(STEP7_ADDRESS,1);
        //hmi_simulation(STEP8_ADDRESS,1);
			}
			x=1;
		
      }
	
		  if(0==(half_seconds_counter%one_second))
	   { 
       //  multi_set_point_operation();
			  
      DISPLAY_MEASUREMENT();	
		  display_measure_history (counter_next_prev);
			  if(new_firing_order_flag==1)
				 {
				  firing();
				 }
     }
     Store_Value();
		  if(half_seconds_counter==ten_minutes_count)
	   {	
		
		 half_seconds_counter=0;
	   }
    }
		 	 if(_100miles_flag==1) //if 500 come this will wate to 501 or between 500 and 501
		 {	_100miles_flag=0;
			 Duration_Counter_Process();
			 multi_set_point_operation();
		 }
		 
     if(_10miles_flag==1) //if 500 come this will wate to 501 or between 500 and 501
		 {
			 _10miles_flag=0;
		   measure_10_msec();
			 calculate_capacity();
	
	    }
		 
		  if(_3mile_flag==1)
		 {
			 _3mile_flag=0;
       send_tx_queue_hmi_communication();
			 enque_counter=0;
     }
     if(_1mile_flag==1)
		 {
			 _1mile_flag=0;
      start_hmi_uart();//r&d
			 if(1== complete_measure_flag_for_end_voltage)
			 {
        check_end_voltage_limitation();
				 complete_measure_flag_for_end_voltage=0;
			 }
			 
     }

		 
		 
		 
		 
		 
		 	 
//		 if(_10miles_flag==1) //if 500 come this will wate to 501 or between 500 and 501
//		 {
//			 _10miles_flag=0;
//		   measure_10_msec();
//	    }
//		
//    else  if(_500miles_flag==1)
//	{_500miles_flag=0;
		 
		//SEND_TO_HMI(beepbeep,50);
//		  half_seconds_counter++;
//  
//		ILLUMINATE_STEPS_ON_HMI();
// 
//    //	 DISPLAY_MEASUREMENT();
//    //		 	   if(0==(half_seconds_counter%one_second))
//	  {
//		 FLASH_ON_HMI();
//	  }
//	  if(0==(half_seconds_counter%one__and_half_second))
//		 {
//			 static int x=0;
//			if(x==0)
//			{
//        //hmi_simulation(STEP6_ADDRESS,1);
//        //hmi_simulation(STEP7_ADDRESS,1);
//        //hmi_simulation(STEP8_ADDRESS,1);
//			}
//			x=1;
//		
//      }
//	
//		  if(0==(half_seconds_counter%one_second))
//	   {  	
//      DISPLAY_MEASUREMENT();	
//		  display_measure_history (counter_next_prev);
//     }

//		  if(half_seconds_counter==ten_minutes_count)
//	   {	
//		 Store_Value ();
//		 half_seconds_counter=0;
//	   }
//    }
//		 
//		 
//		else   if(_3mile_flag==1)
//		 {
//			 _3mile_flag=0;
//       send_tx_queue_hmi_communication();
//     }
//    else  if(_1mile_flag==1)
//		 {
//			 _1mile_flag=0;
//      start_hmi_uart();
//     }
		 
		 

	 
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	   if(htim->Instance ==_100_micro_timer )// IWANT TO STOP ADC INTERRUPT AND TRY TO USE THIS INSTEAD 
	 {
		 // counter_of_25_micros_for_tripping++;
		  counter_of_100_micros_for_general_use++;
		  //funcution_time_counter++;
		 
			   if((uint16_t)(counter_of_100_micros_for_general_use%no_of_miles(1))==0)//////////////////////////////////////////////////
  { 
		_1mile_flag=1;
	}
			   if((uint16_t)(counter_of_100_micros_for_general_use%no_of_miles(3))==0)//////////////////////////////////////////////////
  { 
		_3mile_flag=1;
	}
				   if((uint16_t)(counter_of_100_micros_for_general_use%no_of_miles(10))==0)//////////////////////////////////////////////////
  { 
		_10miles_flag=1;
	}	 
					 if((uint16_t)(counter_of_100_micros_for_general_use%no_of_miles(100))==0)//////////////////////////////////////////////////
  { 
	 _100miles_flag=1;
	}
	 if(counter_of_100_micros_for_general_use==no_of_miles(500))//40 count equal 1_msec so that this is equal 500_msec
   { 
		 _500miles_flag=1;
		 counter_of_100_micros_for_general_use=0;
	 }
	 }
	
}
