#ifndef __hmi_handler_H
#define __hmi_handler_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
	 
//	 #include "hmi_handler.h"
#define cancel_the_address   0
#define register_the_address 1

	 
#define beepbeep -9	 
#define text     -7	  
	 
 
	 

void HMI_Addresses(void);
void DISPLAY_MEASUREMENT (void);
void flashing_registeration(int16_t ,uint8_t);
void FLASH_ON_HMI(void);
void beep_flashing(uint8_t ,uint8_t )  ;
void refresh_hmi_screen_while_unpushed(void);

	 
#define ON                                      0x01
#define OFF                                     0x00
#define PUSHED                                  1
#define UNPUSHED                                0


#define ACK0_ 1
#define ACK1_ 2
	
#define ACK2_ 3
#define ACK3_ 4
#define ACK4_ 5
#define ACK5_ 6
#define ACK6_ 7

 

//Start of HMI user interfacing part
#define no_of_addresses                         							0x93
#define text_notification_window_address        							2*no_of_addresses  //not used 
#define STEP1_ADDRESS                           							0X01
#define STEP2_ADDRESS                           							0X02
#define STEP3_ADDRESS                           							0X03
#define STEP4_ADDRESS                           							0X04
#define STEP5_ADDRESS                           							0X05
#define STEP6_ADDRESS                           							0X06
#define STEP7_ADDRESS                           							0X07 
#define STEP8_ADDRESS                           							0X08 
#define FINE_TUNE_ON_OFF_ADDRESS                							0X09 
#define FINE_TUNE_SETTING_ADDRESS               							0X0A 
#define STOP_ALL_ADDRESS                        							0x0B
#define Automatic_Mode_Address                  							0X0C
#define Manual_Mode_Address                     							0X0D
#define Volt_Measure_Address                    							0x0E
#define Current_Measure_Address                 							0x0F
#define VOLT_LIMIT_SETTING_ADDRESS              							0x10
#define CURRENT_SETTING_SINGLE_SET_POINT_ADDRESS							 0x11
#define START_BUTTON_ADDRESS                    							0X12
#define NEXT_PREV_ADDRESS                       							0x13
#define start_volt_history_ADDRESS              							0X14   //10 
#define end_volt_history_ADDRESS                							0X19  // 27  
#define start_current_history_ADDRESS           							0X1A  // 96 
#define end_current_history_ADDRESS             							0X1F  // 113 
#define START_RECORD_ADDRESS                    							0x20
#define CURRENT_START_SINGLE_SET_POINT_ADDRESS  							0X21
#define START_MULTI_SETPOINT_ADDRESS            							0X22
#define PAUSE_MULTI_SETPOINT_ADDRESS            							0X23
#define hmi_first_current_address_in_multi_mode     					0x24
#define hmi_last_current_address_in_multi_mode      					0x47
#define hmi_first_duration_address_in_multi_mode    					0x48
#define hmi_last_duration_address_in_multi_mode     					0x6B
#define hmi_first_time_consumed_address_in_multi_mode         0x6C  
#define hmi_last_time_consumed_address_in_multi_mode          0x8f  
#define MULTI_MODE_PAGE_NO_ADDRESS              							0x90
#define USER_PROCESS_BEGINING_ADDRESS           							0X91
#define USER_PROCESS_ENDING_ADDRESS             							0X92
							
#define EXIT_MULTIMODE                          							0x93
#define VOLTX_ADDRESS                           							0x94
#define first_pointer_to_the_running_process_address 					0x95
#define last_pointer_to_the_running_process_address  					0xB8


#define sd_card_first_id_address_in_multi_mode     						0XB9
#define sd_card_last_id_address_in_multi_mode      						0XBE
#define sd_card_first_current_address_in_multi_mode     			0XBF
#define sd_card_last_current_address_in_multi_mode      			0XC4
#define sd_card_first_duration_address_in_multi_mode    			0XC5
#define sd_card_last_duration_address_in_multi_mode     			0XCA
#define sd_card_first_time_consumed_address_in_multi_mode     0XCB
#define sd_card_last_time_consumed_address_in_multi_mode      0XD0
#define sd_card_first_capacity_address_in_multi_mode          0XD1
#define sd_card_last_capacity_address_in_multi_mode           0XD6

#define hmi_first_capacity_address_in_multi_mode         			0xD7  
#define hmi_last_capaciyy_address_in_multi_mode          			0xDC

#define insert_data_from_sd_card_in_auto_mode_ADDRESS					0XDD
#define insert_data_using_hmi_screen_in_auto_mode_ADDRESS			0XDE

#define sd_card_start_process_number_address									0XDF




#define LIMIT_OF_END_VOLTAGE_ADDRESS 0x119
  extern int16_t displayed_hmi_values[no_of_addresses];    
//#define HOURS_DISPLAY_ADDRESS   0x0006
//#define MINUTES_DISPLAY_ADDRESS 0x0007
//#define DC_VOLTAGE_MEASURING_ADDRESS     0x38
//#define DC_CURRENT_MEASURING_ADDRESS     0x39

//#define BACK_ADDRESS                   0x05
//#define MEASUREMEMTS_HISTORY_ADDRESS   0X35
//#define PREV_ADDRESS                   0X02
//#define start_volt_history_ADDRESS   0X14   //10 
//#define end_volt_history_ADDRESS      0X5B  // 27  
//#define start_current_history_ADDRESS 0X5C  // 96 
//#define end_current_history_ADDRESS   0XA3  // 113 

extern uint8_t new_current_unpushed_flag;

	 #ifdef __cplusplus
}
#endif
#endif /*__hmi_handler__H*/
