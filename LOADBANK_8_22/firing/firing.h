#ifndef __firing_H
#define __firing_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define cores_ON  HAL_GPIO_WritePin(cores_contactor_port, cores_contactor_pin, GPIO_PIN_SET) 
#define cores_OFF HAL_GPIO_WritePin(cores_contactor_port, cores_contactor_pin, GPIO_PIN_RESET)
#define read_second_core    (HAL_GPIO_ReadPin(second_core_indication_port,second_core_indication_pin))
#define read_frist_core (HAL_GPIO_ReadPin(first_core_indication_port,first_core_indication_pin))
		 
	 
#define no_action_open_circuit_alarm_icon   0	
#define display_open_circuit_alarm_icon     1
#define disappear_open_circuit_alarm_icon   2
	 
#define no_action_control_cable_alarm_icon   0	
#define display_control_cable_alarm_icon     1
#define disappear_control_cable_alarm_icon   2
#define	contactor_fine_tune_off  HAL_GPIO_WritePin(fine_tune_relay_GPIO_Port,fine_tune_relay_Pin,GPIO_PIN_RESET)
	 #define	contactor_fine_tune_on  HAL_GPIO_WritePin(fine_tune_relay_GPIO_Port,fine_tune_relay_Pin,GPIO_PIN_SET)
void firing(void);
void OFF_CURRENT(void); 
void SAFETY_CHECK_LOAD_WIRING(void);
void SAFETY_CHECK_CONTROL_CABLE_WIRING(void);
 extern uint8_t stop_firing_automode;
extern uint8_t emergency_pressed;
extern uint8_t open_circuit_alarm_flag;
extern uint8_t control_cable_alarm_flag;
extern uint8_t new_firing_order_flag;
extern uint16_t pwm_value;
extern  uint8_t START_FINE_TUNE_OPERATION_IN_MANUAL_MODE;
 extern TIM_HandleTypeDef hal_firing_timer;
#ifdef __cplusplus
}
#endif
#endif /*__ firing_H */
