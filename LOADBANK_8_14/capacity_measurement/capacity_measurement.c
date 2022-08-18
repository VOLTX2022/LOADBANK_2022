#include "capacity_measurement.h"
#include "configration.h"


static uint32_t capacity_current_accumulator=0;
static uint8_t start_flag_iteration_capacity_calculations=0;
static uint32_t _10mils_counter=0;

static float total_capacity=0;
static uint8_t start_flag_total_capacity_calculations=0;

extern uint16_t total_measured_ampere;

/******************************* iteration capacity ******************************************/

void capacity_start_calculations(void)
{
	capacity_current_accumulator = 0;
	start_flag_iteration_capacity_calculations=1;
}


/* it will be called every 10 ms */
void calculate_capacity(void)
{
	if(start_flag_iteration_capacity_calculations==1)
	{
		capacity_current_accumulator+=total_measured_ampere;
		_10mils_counter++;
	}
}


float get_capacity_and_stop_calculations(void)
{
	float capacity=0.0f;
	float time_in_sec=(float)(_10mils_counter *10)/1000; 
	float average_current=(float)capacity_current_accumulator/_10mils_counter;
	capacity=(float)(average_current*time_in_sec)/(60*60);
	calculate_total_capacity(capacity);
	start_flag_iteration_capacity_calculations=0;
	return capacity;
}


void capacity_pause_calculations(void)
{
	start_flag_iteration_capacity_calculations=0;
	start_flag_total_capacity_calculations=0;
}


void capacity_resume_calculations(void)
{
	start_flag_iteration_capacity_calculations=1;
	start_flag_total_capacity_calculations=1;
}


void clear_capacity_history(void)
{
	start_flag_iteration_capacity_calculations=0;
	capacity_current_accumulator=0;
	start_flag_total_capacity_calculations=0;
	total_capacity=0;
}



/********************************************************************************************/

/******************************* total capacity ******************************************/




void start_total_capacity_calculations(void)
{
	total_capacity=0;
	start_flag_total_capacity_calculations=1;
} 

void calculate_total_capacity(float iteration_capacity)
{
	if(start_flag_total_capacity_calculations==1)
	{
		total_capacity+=iteration_capacity;
	}
}

float get_total_capacity(void)
{
	start_flag_total_capacity_calculations=0;
	float local_total_capacity=total_capacity;
	total_capacity=0;
	return local_total_capacity;
}







