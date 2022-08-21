/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __capacity_measurement_H
#define __capacity_measurement_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/******************************* iteration capacity ******************************************/

void capacity_start_calculations(void);

void calculate_capacity(void);

uint32_t get_capacity_and_stop_calculations(void);

void capacity_pause_calculations(void);

void capacity_resume_calculations(void);

void clear_capacity_history(void);


/********************************************************************************************/


/******************************* total capacity ******************************************/

void start_total_capacity_calculations(void);

void calculate_total_capacity(float iteration_capacity);

uint32_t get_total_capacity(void);

/********************************************************************************************/






#ifdef __cplusplus
}
#endif
#endif /*__ capacity_measurement_H */

