
#ifndef __arrays_calibration_firing_H
#define __arrays_calibration_firing_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "configration.h"
#define firing_array_size (3698-229+1)
#if(use_flash_memory==without)
extern uint16_t firing_arr[firing_array_size];
#endif
	 
extern double calibration_adc_array_volt[no_of_calibration_values_ch0];
extern double calibration_array_in_voltage[no_of_calibration_values_ch0];
	 
extern double calibration_array_in_ampere[no_of_calibration_values_ch1];
extern double calibration_adc_array_current[no_of_calibration_values_ch1];

	 
	 #ifdef __cplusplus
}
#endif
#endif /*__ arrays_calibration_firing_H */
