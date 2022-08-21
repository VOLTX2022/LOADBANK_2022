#ifndef __measurement_H
#define __measurement_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#define no_of_channels no_of_measurement_channel
#include "configration.h"
#define volt 1
#define ampere_fixed_steps 2	 
#define ampere_fine_tune_step 0	
	 
#define total_fine_tune_step_value       7.9
#define R_total_fine_tune_ohm_value       3.45

void new_setting_pushed_measurement_action(void);
void calculate_average_for_display(void);
void check_end_voltage_limitation(void); 
extern int32_t   S_0;		
	 extern uint16_t total_measured_ampere;
	 extern uint16_t total_measured_ampere_for_display;
	extern uint8_t complete_measure_flag_for_end_voltage;
	 extern double measure_accumulator_value[no_of_channels];

//extern uint32_t AVERAGE_ADC[no_of_channels];	 
//extern double measure_accumulator_value[no_of_channels]; 
//extern uint16_t AVERAGE_ADC_IN_REEL_UNIT[no_of_channels];



void measurement_for_display(void);

void measure_timer_it(void);
void measure_10_msec(void);
void measure_start_dma_adc(void);
void MEASUREMENT_CALCULATION(void);//CONVERT ADC_To_VOLT_&_CURRENT
void Calibration_Init(void);
void reset_accumulator(void); 
void Offset_calculation(void);
	 
	 #ifdef __cplusplus
}
#endif
#endif /*__measurement_H*/
