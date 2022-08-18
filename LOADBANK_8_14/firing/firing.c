 #include "firing.h"
 #include "main.h"
 #include "pid_handler.h"
 #include "hmi_handler.h"
 #include "measurement.h"
 #include "tim.h"
 #include "configration.h"
 #include "auto_mode.h"
 #include "application.h"
 #include "hmi_communication.h"
 #include "pid.h"
 #include "pid_handler.h"
 #include "configration.h"	
 #include "arrays_calibration_firing.h"
 uint8_t new_firing_order_flag=0;
 uint16_t manual_fine_tune_step_value=0;
 uint16_t pwm_value=0;
 uint8_t START_FINE_TUNE_OPERATION_IN_MANUAL_MODE=0;
 extern uint16_t pid_fine_tune_value;
 extern uint16_t timer_steps_constant_for_breaker_mode;
 extern uint32_t AVERAGE_ADC[no_of_channels];
 extern uint8_t start_timer_filter_display;
 extern uint8_t restart_timer_filter_display;
 extern uint8_t mode;
	extern uint8_t      make_meaure_euqal_setting_flag;
	extern uint8_t STOP_FIXED_STEPS_FLAG;
 //extern uint8_t constant_firing_flag;
uint8_t emergency_pressed=0;
uint8_t trip_flags[4];
uint8_t open_circuit_alarm_flag=0;
uint8_t control_cable_alarm_flag=0;

// void firing(void)			 
//	{		
// 	TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=9890;
//							  	  HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);
//	}
extern uint8_t problem;

void firing(void)			 
	{		   
		if(all_contactors_updated())
		{ new_firing_order_flag=0;
			if(search_if_any_step_on())
			{
		if(mode==manual)
	      	{  
						 if((START_FINE_TUNE_OPERATION_IN_MANUAL_MODE==1)&&(manual_fine_tune_step_value >0) )//total_fine_tune_ step_value xxx
						     {  
									 pwm_value=((float)(manual_fine_tune_step_value*1000)/(10*total_fine_tune_step_value));
									 
								   if(pwm_value>0)
							 {
						     TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=pwm_value;	
						     //TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=9800;
						     HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);
							 }
							 else
               {  
							  	HAL_TIM_PWM_Stop(&hal_firing_timer ,FIRING_TIME_CHANNEL);
							 }
									 //SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,1);
									 //TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=9800;
									// HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);	
						     }
								 	  else
                 {  
									  pwm_value=0;
						      		HAL_TIM_PWM_Stop(&hal_firing_timer ,FIRING_TIME_CHANNEL);
									 //SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,0);
							  	// HAL_TIM_Base_Stop(&hal_firing_timer);
						     }		
					
				 }
					else
         {
					  
					 
					 if(START_FINE_TUNE_OPERATION_IN_AUTO_MODE==1)
				     {//auto_operation(current_setting);
							 pwm_value=pid_fine_tune_value;
							 if(pwm_value>0)
							 {
						 TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=pwm_value;	
						 //TIM_FIRING->FIRING_COUNTER_REG_CHANNEL=9800;
						 HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);
							 }
							 else
               {
							  	HAL_TIM_PWM_Stop(&hal_firing_timer ,FIRING_TIME_CHANNEL);
							 }
//							 if(pwm_value>0)
//							 {
//							// SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,1);
//							 }
							}
						 else
							 {
								 //auto_operation(0);
							  pwm_value=0;
						   	HAL_TIM_PWM_Stop(&hal_firing_timer ,FIRING_TIME_CHANNEL);
							// SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,0);
						 }	 
							
					}
				 
				
				}
			 else
        {  
						pwm_value=0;
						HAL_TIM_PWM_Stop(&hal_firing_timer ,FIRING_TIME_CHANNEL);
				  	START_FINE_TUNE_OPERATION_IN_MANUAL_MODE=0;
					START_FINE_TUNE_OPERATION_IN_AUTO_MODE=0;
					//	contactor_fine_tune_off;
					//	SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,0);
					problem=3;
				}		
		}
	}

void OFF_CURRENT(void)
{
	 //HAL_TIM_Base_Stop(&hal_firing_timer);
	 STOP_FIXED_STEPS_FLAG=1;
	START_FINE_TUNE_OPERATION_IN_AUTO_MODE = UNPUSHED ;	
	//contactor_fine_tune_off;
	new_firing_order_flag=1;//to enter firing function
}
