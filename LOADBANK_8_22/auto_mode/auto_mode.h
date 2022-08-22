
#ifndef __auto_mode_H
#define __auto_mode_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void auto_operation(uint16_t );
extern uint8_t counter_of_no_of_entered_process;	 
#define idle   0
#define pause  1
#define resume 2
#define start  3
#define stop   4 

#define not_selected    		 0
#define sd_card_auto_mode    1
#define hmi_auto_mode    		 2

#define hmi_max_no_of_members 36
#define sd_card_max_no_of_members 100	 


#define	hmi_current_address(x)  					(hmi_first_current_address_in_multi_mode+x)//starting from x =0 not 1
#define	hmi_duration_address(x)  					(hmi_first_duration_address_in_multi_mode+x)//starting from x =0 not 1
#define	hmi_time_consumed_address(x)  		(hmi_first_time_consumed_address_in_multi_mode+x)	 
#define	hmi_capacity_address(x)  					(hmi_first_capacity_address_in_multi_mode+x)//starting from x =0 not 1
#define	hmi_pointer_to_the_running_process_address(x)  (hmi_first_pointer_to_the_running_process_address+x)		


#define	sd_card_id_address(x)  						(sd_card_first_id_address_in_multi_mode+x)//starting from x =0 not 1
#define	sd_card_current_address(x)  			(sd_card_first_current_address_in_multi_mode+x)//starting from x =0 not 1
#define	sd_card_duration_address(x)  			(sd_card_first_duration_address_in_multi_mode+x)//starting from x =0 not 1
#define	sd_card_time_consumed_address(x)  (sd_card_first_time_consumed_address_in_multi_mode+x)
#define	sd_card_capacity_address(x)  			(sd_card_first_capacity_address_in_multi_mode+x)//starting from x =0 not 1
#define	sd_card_pointer_to_the_running_process_address(x)  (sd_card_first_pointer_to_the_running_process_address+x)	


void check_end_voltage_limitation(void);
void initiate_multiset_point_mode(void);
	 void single_set_point_order(void);
	 void multi_set_point_operation(void);
	 void step8_volt_check(void);
extern uint8_t multi_set_point_status_flag;
extern uint8_t mode;
	 extern uint8_t UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE;
	 extern uint8_t single_setpoint_flag;
	 extern uint16_t pid_fine_tune_value;
	 extern uint16_t current_setting;
	 extern uint8_t user_defined_process_begining;
	 extern uint8_t limit_of_end_voltage;
extern uint8_t user_defined_process_ending;
extern uint8_t 	minimum_current_limit_flag;
uint16_t  check_input_current_limits(uint16_t input_current,uint16_t address);
#ifdef __cplusplus
}
#endif
#endif /*__ auto_mode_H */
//
