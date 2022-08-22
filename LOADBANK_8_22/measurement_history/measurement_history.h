#ifndef __measurement_history_H
#define __measurement_history_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

extern uint8_t start_record_flag ;
extern uint8_t record_on_flag;
extern uint8_t counter_next_prev;
	   
void Store_Value (void);
void display_measure_history (uint8_t history_page_number);
#ifdef __cplusplus
}
#endif
#endif /*__ measurement_history_H */
