/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __display_iterration_H
#define __display_iterration_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define	STEP_BASE_ADDRESS					(1)
#define	CURRENT_BASE_ADDRESS			(7)
#define	DURATION_BASE_ADDRESS			(13)
#define	TIME_LEFT_BASE_ADDRESS		(19)
#define	CAPACITY_BASE_ADDRESS			(25)



typedef struct 
{
	int step_num;
	int current;
	int duration;
	int time_left;
	float capacity;
	
}iteration_display;



void display_iteration(iteration_display iteration_iformation);


void clear_iteration_display(void);









#ifdef __cplusplus
}
#endif
#endif /*__ display_iterration_H */

