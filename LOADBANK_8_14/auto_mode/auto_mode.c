#include "auto_mode.h"
#include "hmi_handler.h"
#include "math.h"
#include "application.h"
#include "firing.h"
#include "configration.h"	
#include "time_based_table_operation.h"
#include "measurement.h"
#include "hmi_handler.h"
#include "firing.h"
#include "hmi_communication.h"
uint16_t pid_fine_tune_value=0;
s_table_typedef current_and_time_values_array[max_no_of_members]={0};
uint16_t FINE_TUNE_WANTED_CURRENT=0;
uint8_t  single_setpoint_flag=0;
float array_of_currents[no_of_steps]={0};
uint16_t array_of_possible_probabilities[_2_power_no_of_steps]={0};
float  array_of_diffirence[_2_power_no_of_steps]={0};
extern   uint16_t pid_fine_tune_value;
float I_fine_tune_total=0;
extern   uint8_t STEP_STATE_ARRAY[no_of_steps];
extern   uint16_t AVERAGE_ADC_IN_REEL_UNIT[no_of_channels];
uint8_t user_defined_process_begining=1;
uint8_t user_defined_process_ending=max_no_of_members;
uint16_t current_setting=0;
uint8_t multi_set_point_status_flag=stop;
uint8_t counter_of_no_of_entered_process=0;
uint8_t START_FINE_TUNE_OPERATION_IN_AUTO_MODE=0;
uint8_t mode=manual;
uint8_t process_begin=0;
uint8_t process_end=0;
uint8_t limit_of_end_voltage=0;
uint8_t minimum_current_limit_flag=0;

//////////////////////////////////////
extern uint16_t current_setting;
//uint16_t measured_volt=50;
//double R[no_of_steps]={3.405,5.518,6.907,6.898,5.188,5.556,3.527,5.071};
double R[no_of_steps]={3.360,5.429,6.816,6.723,5.188,5.533,3.490,5.070};
double R_fine_tune_total= R_total_fine_tune_ohm_value;

void calculate_array_of_currents()
{
	for(int i=0;i<no_of_steps;i++)
	{
	  array_of_currents[i]=(float)AVERAGE_ADC_IN_REEL_UNIT[volt]/R[i];
	}
    I_fine_tune_total=(float)AVERAGE_ADC_IN_REEL_UNIT[volt]/R_fine_tune_total;
}
void calculate_possible_probabilities()
{ 
	//array_of_possible_probabilities[0]=0;
	for(int i =0;i<_2_power_no_of_steps;i++)
	{ float summator=0;
		for(int j=0;j<no_of_steps;j++)
		{
     summator=summator+(((i>>j)&1)*array_of_currents[j]);
		}
		array_of_possible_probabilities[i]=summator;
	}

}
void initiate_multiset_point_mode()
{ HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);
		for(int i =0;i<max_no_of_members;i++)
	{
  		current_and_time_values_array[i].duration = 60 ;
	}
	for(int i=first_durations_address_in_multi_mode;i<(first_durations_address_in_multi_mode+max_no_of_members);i++)
					{
						SEND_TO_HMI(i,1);
					}
					
					SEND_TO_HMI(MULTI_MODE_PAGE_NO_ADDRESS,1);
}
int8_t prev_id=-1;
//uint16_t xx=0;
void update_operation()
{
	Setting_Data_Typedef setpoint_setting;
	
//  static int32_t prev_time_consumed=0;
	setpoint_setting=Get_Interval_Currentstatus();
	
	if(setpoint_setting.Interval_ID>(process_end-1))
	{//xx=setpoint_setting.Interval_ID;
		 SEND_TO_HMI(time_consumed_address(prev_id),(current_and_time_values_array[prev_id].duration)/60.0);
		 flashing_registeration(pointer_to_the_running_process_address(prev_id),cancel_the_address);
		
	   multi_set_point_status_flag=stop;
	}
	else
	{
	 if(prev_id!=setpoint_setting.Interval_ID)
	  { 
			if(prev_id!=-1)
		 {
		  SEND_TO_HMI(time_consumed_address(prev_id),(current_and_time_values_array[prev_id].duration)/60.0);
			 flashing_registeration(pointer_to_the_running_process_address(prev_id),cancel_the_address);
			 
		 }
		 flashing_registeration(pointer_to_the_running_process_address(setpoint_setting.Interval_ID),register_the_address);
		  START_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
		  prev_id=setpoint_setting.Interval_ID;
		  auto_operation(setpoint_setting.Current_Setting);
			
	  }
			SEND_TO_HMI(time_consumed_address(prev_id),(setpoint_setting.Duration_collapsed)/60.0);
  }
	
//	else
//	{ if(((setpoint_setting.Duration_collapsed%60)==0))
//		{
//			prev_time_consumed=(setpoint_setting.Duration_collapsed/60.0);
//			if(prev_id!=-1)
//		{
//			SEND_TO_HMI(time_consumed_address(prev_id),prev_time_consumed);
//		}
//		}
//	 
//	}
	
	
}

void single_set_point_order()
{
	mode=Auto;
	
if(single_setpoint_flag==1)
{
	START_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
	auto_operation(current_setting);
  HAL_TIM_Base_Start(&hal_firing_timer);
}
else
{
	START_FINE_TUNE_OPERATION_IN_AUTO_MODE = UNPUSHED ;
	new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
  OFF_CURRENT();   ///firing              //must be unremoved 
}	
    //    reset_switch_off_timer_flag=1;

}
void replace(uint8_t * x,uint8_t * y)
{
  uint8_t buffer =0;
	buffer=*x;
  *x=*y;
	*y=buffer;
}

void calculate_process_begin_end()
{
	if(user_defined_process_begining>1)
					{
					 process_begin=user_defined_process_begining;
					}
					else
					{
					 process_begin=1;
					}
					if(user_defined_process_ending<=counter_of_no_of_entered_process)
					{
					 process_end=user_defined_process_ending;
					}
					else
          {
					 process_end=counter_of_no_of_entered_process;
					}
					if(process_end<process_begin)
					{
           replace(&process_begin,&process_end);					
					}
}

uint16_t  check_input_current_limits(uint16_t input_current,uint16_t address)
{
	uint16_t allowed_current=0;
	uint16_t max=0;
	//get_max_resitance
	
	for(int i =0;i<no_of_steps;i++)
	{
	  if((100*R[i])>max)
	  {
	  max=100*R[i];
	  }
  }
  if(input_current<((uint16_t)((100*measure_accumulator_value[volt])/max)))//max = 100*R[i]
  {
    allowed_current=0; 
		SEND_TO_HMI(beepbeep,150);
			SEND_TO_HMI(address,allowed_current);
  	
  }
  else if (input_current>max_allowed_input_current)
  {
   allowed_current=max_allowed_input_current;
		SEND_TO_HMI(beepbeep,150);
			SEND_TO_HMI(address,allowed_current);
  }
  else
  {
   allowed_current=input_current;
  }
  return allowed_current;

}

void multi_set_point_operation(void)//each 1 sec
{ 

	static int8_t status=stop;
	Setting_Data_Typedef setpoint_setting;
	
	setpoint_setting=Get_Interval_Currentstatus();
	calculate_process_begin_end();
	
	

	
	
	if(multi_set_point_status_flag!=idle)
	{
	switch(multi_set_point_status_flag)
		{ case start:
          contactor_fine_tune_on;//although if i will not on the pwm to be able to make a delay to secure pid operation if it used
        HAL_Delay(100); 		   
			if(status==pause)
			{
		    SEND_TO_HMI(PAUSE_MULTI_SETPOINT_ADDRESS,0);
			}
       START_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;	
				for(int i=first_pointer_to_the_running_process_address;i<(first_pointer_to_the_running_process_address+max_no_of_members);i++)
					{
						SEND_TO_HMI(i,0);
					}
			 	prev_id=-1;
       //HAL_TIM_Base_Start(&hal_firing_timer);
       mode=Auto;
					
					
	     Start_Operation ((process_begin-1) , (process_end-1),current_and_time_values_array);
			 setpoint_setting=Get_Interval_Currentstatus();
			 current_setting=setpoint_setting.Current_Setting;
		 auto_operation(current_setting);
		 new_firing_order_flag=1;
		 status=start;
		 multi_set_point_status_flag=idle;
		 break;
		case stop:
			   	if(status==pause)
			{
				SEND_TO_HMI(PAUSE_MULTI_SETPOINT_ADDRESS,0);
			}
			SEND_TO_HMI(START_MULTI_SETPOINT_ADDRESS,0);
				
		flashing_registeration(pointer_to_the_running_process_address(prev_id),cancel_the_address);
		 flashing_registeration(pointer_to_the_running_process_address(setpoint_setting.Interval_ID),cancel_the_address);
		    Stop_Operation ();
			 
		    	current_setting=0;
			
					 auto_operation(current_setting);
			new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
			  OFF_CURRENT();
		 status=stop;
		 multi_set_point_status_flag=idle;
		
		 break;
		case pause:
			if(status==start)
			{Pause_Operation();
				new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
			  OFF_CURRENT(); 
					
		    
				current_setting=0;
				auto_operation(current_setting);
				new_firing_order_flag=1;
		    status=pause;
			}
			else
      {
			 SEND_TO_HMI(PAUSE_MULTI_SETPOINT_ADDRESS,0);
			}
		 multi_set_point_status_flag=idle;
		 break;
			case resume :
			if(status==pause)
			{	
		   contactor_fine_tune_on;
				 HAL_Delay(200); 	
       START_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;	
			  Resume_Operation();
			 setpoint_setting=Get_Interval_Currentstatus();
			  current_setting=setpoint_setting.Current_Setting;
						 auto_operation(current_setting);
					new_firing_order_flag=1;
			 status=start;
			}
			else
      {
			 SEND_TO_HMI(PAUSE_MULTI_SETPOINT_ADDRESS,0);
			}
		 multi_set_point_status_flag=idle;
		 break;
		
	  }
		

	}
	else if	(status==start)//running case
	{
	update_operation();
	}
	//if new start flag=1 set first =0; last counter of steps size //(make a counter calculate biggest addtress entered)// prev_id=-1; time_consumed=0; status=start;new start flag=0;
	//if new stop flag=1 set first =0; last counter of steps //(make a counter calculate biggest addtress entered) new_stop =0; if status=stop
	//if new buase_flag=1 if status = stop do nothing and change button update_current id and time cosumed and send time consumed set status buase ,buase_flag=0;call buase _function ;
  //get current set operation if not equal change call auto_opertion and update time consumed =0;and send time consumed =duration at the previous id and update time_consumed_variable to be 0
	//else if read time and convert it to minutes then check if minutes changed
	//if it was changed send time consumed to this id  and update time_consumed_variable

}
void calculate_difference_array(uint16_t value_to_reach)
{
	for(int i=0;i<_2_power_no_of_steps;i++)
	{
		array_of_diffirence[i]=value_to_reach-array_of_possible_probabilities[i];
	 
	}
}
uint16_t find_best_choice()
{ int i=0;
	float smallest=0;
	uint16_t best_choice_index=0;
   //Consider first element as smallest
   smallest = array_of_diffirence[0];
   best_choice_index=0;//dont use any fixed step
   for (i = 0; i < _2_power_no_of_steps; i++)
	{
      if (((int32_t)(100*array_of_diffirence[i]) < (int32_t)(100*smallest)) &&((int32_t)(array_of_diffirence[i])>=0))
				{
         smallest = array_of_diffirence[i];
					best_choice_index=i;
        }
   }
	return best_choice_index;
}
float yy,yyy;
void determine_pwm_value(uint16_t index)
{
	yy=array_of_diffirence[index];
	yyy=index;
	if((int32_t)(10*array_of_diffirence[index])==0)
	{
	 pid_fine_tune_value=0;
	}
	else 
	{
    pid_fine_tune_value=1000*(array_of_diffirence[index]/(float)I_fine_tune_total);
		
		if(pid_fine_tune_value>1000)
			pid_fine_tune_value=1000;
	}
	// pid_fine_tune_value=0;
}
void on_the_suitable_steps(uint16_t index)
{
  	
	
		for(int j=0;j<no_of_steps;j++)
		{
     if((uint8_t)((index>>j)&1)==1)
		 {
			 STEP_STATE_ARRAY[j]=ON;
		 }
		 else
     {
			 STEP_STATE_ARRAY[j]=OFF;
		 }
		}
determine_pwm_value(index);
	 
		new_firing_order_flag=1;
  
}
uint16_t best_index=0;
void auto_operation(uint16_t value_to_reach)
{
	if(value_to_reach>0)
	{
 calculate_array_of_currents();
 calculate_possible_probabilities();
 calculate_difference_array(value_to_reach);
 best_index=	find_best_choice();
	
 on_the_suitable_steps(best_index);
		

}
	else
  {
		STOP_FIXED_STEPS_FLAG=1;
	  pid_fine_tune_value=0;
			new_firing_order_flag=1;
	}
}
/**/

void check_end_voltage_limitation(void)
{
	 
	static uint8_t  max_input_count=0;

	
 if(AVERAGE_ADC_IN_REEL_UNIT[volt]<limit_of_end_voltage)	
      { 
				max_input_count++;
	        if(max_input_count == 3)//send a notification
		    { OFF_CURRENT();
	      	new_current_unpushed_flag=1;
					multi_set_point_status_flag=stop;
			  }
		  }
			else 
			{
			      max_input_count=0;

			}
			
	
	\
			
		
			
	 
}
//
