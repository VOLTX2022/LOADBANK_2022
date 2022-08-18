#ifndef __time_handler_H
#define __time_handler_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define	one_minute_count  120
#define	ten_minutes_count  1200
//#define max_input_tim     5
 
	 
	 
//extern uint8_t  tim_general_overflow_flag;
extern uint16_t half_seconds_counter;
extern uint32_t counter_of_25_micros_for_tripping;
volatile extern	 uint32_t counter_of_50_micros_for_general_use;
extern volatile	 uint64_t funcution_time_counter;
extern uint8_t	 can_not_reach_setting_value_flag;
	 extern uint32_t seconds_counter_of_tripping;
void run_switch_off_timer(void);
void MULTI_PURPOSE_TIMER(void);
void reset_half_seconds_counter(void);

void set_half_sec_counter(uint16_t value);
	 
	 #ifdef __cplusplus
}
#endif
#endif /*__ time_handler_H */
