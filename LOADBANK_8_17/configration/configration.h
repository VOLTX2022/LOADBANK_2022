#ifndef __configration_H
#define __configration_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
	 
#define board f1
	 
#define with    1	 
#define without 0		 
//#include "configration.h"	 
	 
#if(board==f4) 	 
////-----------------------------------------------f4 
	 /*
#define oc_check_saftey                            with
#define input_measuring                            with
#define control_cable_detection                    with 
#define use_flash_memory                           without
#define adc_def                                    hadc1 
#define _100_micro_timer                            TIM2  
#define hal_100_micro_timer                         htim2
#define hal_measurement_timer                      htim2  
#define hal_firing_timer                           htim3
#define zero_cross_pin                             GPIO_PIN_3   
#define breaker_tripping_pin	                     Trip2_Pin
#define TIM_FIRING                                 TIM3
#define FIRING_COUNTER_REG_CHANNEL    	           CCR1
#define FIRING_TIME_CHANNEL                        TIM_CHANNEL_1
#define hal_hmi_uart                               huart4                                    
#define second_core_indication_port	               core2_connection_signal_GPIO_Port            
#define second_core_indication_pin                 core2_connection_signal_Pin                  
#define first_core_indication_port	               core1_connection_signal_GPIO_Port            
#define first_core_indication_pin                  core1_connection_signal_Pin                  
#define cores_contactor_port                       CONTACTOR_2_GPIO_Port
#define cores_contactor_pin                        CONTACTOR_2_Pin      	
#define no_of_channels                             2
#define no_of_calibration_values                   15
*/
#endif


#include "tim.h"



#if(board==f1) 	 

////---------------------------------------------- f0
#define use_flash_memory                           without
#define adc_def                                    hadc                            
#define _100_micro_timer                            TIM3
#define hal_100_micro_timer                         htim3	 
#define hal_measurement_timer                      hal_100_micro_timer                	 
#define hal_firing_timer                           htim1
#define TIM_FIRING                                 TIM1
#define FIRING_COUNTER_REG_CHANNEL    	           CCR1   
#define FIRING_TIME_CHANNEL                        TIM_CHANNEL_1
#define hal_hmi_uart                               huart1 
#define no_of_calibration_values_ch0                10
#define no_of_calibration_values_ch1                5 
#define no_of_channels                              3
#define max_allowed_input_current                   200
#define first_step                                  Step1
#define last_step                                   Step8 
#define no_of_steps                                 last_step+1   
#define _2_power_no_of_steps                        256

#endif

//	 
#if(board==f0) 
//-------------------------------------------------f0
/*
#define oc_check_saftey                            without
#define input_measuring                            without
#define control_cable_detection                    without
#define use_flash_memory                           without
#define adc_def                                    hadc
#define _100_micro_timer                            TIM1
#define hal_100_micro_timer                         htim1 
#define hal_measurement_timer                      hal_100_micro_timer
#define hal_firing_timer                           htim3
#define zero_cross_pin                             GPIO_PIN_13     
#define breaker_tripping_pin	                     0
#define TIM_FIRING                                 TIM3
#define FIRING_COUNTER_REG_CHANNEL    	           CCR3
#define FIRING_TIME_CHANNEL                        TIM_CHANNEL_3
#define hal_hmi_uart                               huart1                                     
#define second_core_indication_port	               core2_connection_signal_GPIO_Port           
#define second_core_indication_pin                 core2_connection_signal_Pin                 
#define first_core_indication_port	               core1_connection_signal_GPIO_Port            
#define first_core_indication_pin                  core1_connection_signal_Pin                        
#define cores_contactor_port                       GPIOC
#define cores_contactor_pin                        GPIO_PIN_13	 
#define no_of_calibration_values                   37 
#define no_of_channels                             1
*/
#endif

//-------------------------------------------------------------------------------------------	 
	 #ifdef __cplusplus
}                                      
#endif
#endif /*__configration__H*/
