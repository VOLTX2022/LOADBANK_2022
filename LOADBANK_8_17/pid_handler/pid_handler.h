#ifndef __pid_handler_H
#define __pid_handler_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define PUSHED 1


uint16_t get_pid_timer_delay(void);
void PID_Initiation(void);
void PID_Parameter_values(void);

	 

	 
#ifdef __cplusplus
}
#endif
#endif /*__ pid_handler_H */
