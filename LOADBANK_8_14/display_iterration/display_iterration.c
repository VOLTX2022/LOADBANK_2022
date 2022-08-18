
#include "display_iterration.h"
#include "hmi_communication.h"

#define hmi_iteration_rows  (6)

//iteration_display iteration_array[6] = { {0,0,0,0} , {0,0,0,0} , {0,0,0,0} , {0,0,0,0} };




void display_iteration(iteration_display iteration_iformation)
{
	iteration_display iteration_array[hmi_iteration_rows] = {0};
	/* shift iterations */
	for(int i=hmi_iteration_rows-1;i>0;i--)
	{
		iteration_array[i].step_num =iteration_array[i-1].step_num;
		iteration_array[i].current  =iteration_array[i-1].current;
		iteration_array[i].duration =iteration_array[i-1].duration;
		iteration_array[i].time_left=iteration_array[i-1].time_left;
		iteration_array[i].capacity =iteration_array[i-1].capacity;
	}
	
	/* assign to the first iteration */
	iteration_array[0].step_num=iteration_iformation.step_num;
	iteration_array[0].current=iteration_iformation.current;
	iteration_array[0].duration=iteration_iformation.duration;
	iteration_array[0].time_left=iteration_iformation.time_left;
	iteration_array[0].capacity=iteration_iformation.capacity;
	
	
	for(int i=0;i<hmi_iteration_rows;i++)
	{
		SEND_TO_HMI((int)(STEP_BASE_ADDRESS+i),iteration_array[i].step_num);
		SEND_TO_HMI((int)(CURRENT_BASE_ADDRESS+i),iteration_array[i].current);
		SEND_TO_HMI((int)(DURATION_BASE_ADDRESS+i),iteration_array[i].duration);
		SEND_TO_HMI((int)(TIME_LEFT_BASE_ADDRESS+i),iteration_array[i].time_left);
		SEND_TO_HMI((int)(CAPACITY_BASE_ADDRESS+i),iteration_array[i].capacity);
	}
	
	
}

void clear_iteration_display(void)
{
	for(int i=0;i<hmi_iteration_rows;i++)
	{
		SEND_TO_HMI((int)(STEP_BASE_ADDRESS+i),0);
		SEND_TO_HMI((int)(CURRENT_BASE_ADDRESS+i),0);
		SEND_TO_HMI((int)(DURATION_BASE_ADDRESS+i),0);
		SEND_TO_HMI((int)(TIME_LEFT_BASE_ADDRESS+i),0);
		SEND_TO_HMI((int)(CAPACITY_BASE_ADDRESS+i),0);
	}
}
