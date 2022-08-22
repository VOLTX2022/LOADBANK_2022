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
#include "capacity_measurement.h"
#include "display_iterration.h"
uint16_t pid_fine_tune_value=0;
s_table_typedef hmi_current_time_and_capacity_values_array[hmi_max_no_of_members]={0};
s_table_typedef sd_card_current_time_and_capacity_values_array[sd_card_max_no_of_members]={0};

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
uint8_t sd_card_user_defined_process_begining=1;

uint8_t user_defined_process_ending=hmi_max_no_of_members;
uint16_t current_setting=0;
uint8_t multi_set_point_status_flag=stop;
uint8_t counter_of_no_of_entered_process=0;
uint8_t UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE=0;
uint8_t mode=manual;
uint8_t hmi_process_begin=0;
uint8_t hmi_process_end=0;
uint8_t sd_card_process_begin=0;
uint8_t sd_card_process_end=0;
uint8_t limit_of_end_voltage=0;
uint8_t minimum_current_limit_flag=0;
uint8_t auto_mode_data_source=0;
uint8_t steps_number=8;
uint16_t _2_power_of_steps=256;


//////////////////////////////////////
extern uint16_t current_setting;
//uint16_t measured_volt=50;
//double R[no_of_steps]={3.405,5.518,6.907,6.898,5.188,5.556,3.527,5.071};
double R[no_of_steps]={3.360,5.429,6.816,6.723,5.188,5.533,3.490,5.070};
double R_fine_tune_total= R_total_fine_tune_ohm_value;

void step8_volt_check(void)
{
	Setting_Data_Typedef setpoint_setting;
	static uint8_t flag=0;
	if((AVERAGE_ADC_IN_REEL_UNIT[volt]>=130))
	{
		flag=1;
		STEP_STATE_ARRAY[7]=OFF;
		steps_number=7;
		_2_power_of_steps=128;
		setpoint_setting=Get_Interval_Currentstatus();
		current_setting=setpoint_setting.Current_Setting;
		auto_operation(current_setting);
	}
	else
	{
		steps_number=8;
		_2_power_of_steps=256;
		if(flag==1)
		{
			flag=0;
			setpoint_setting=Get_Interval_Currentstatus();
			current_setting=setpoint_setting.Current_Setting;
			auto_operation(current_setting);
		}
	}
}

void calculate_array_of_currents()
{
	for(int i=0;i<steps_number;i++)
	{
	  array_of_currents[i]=(float)AVERAGE_ADC_IN_REEL_UNIT[volt]/R[i];
	}
    I_fine_tune_total=(float)AVERAGE_ADC_IN_REEL_UNIT[volt]/R_fine_tune_total;
}
void calculate_possible_probabilities()
{ 
	//array_of_possible_probabilities[0]=0;
	for(int i =0;i<_2_power_of_steps;i++)
	{ float summator=0;
		for(int j=0;j<steps_number;j++)
		{
     summator=summator+(((i>>j)&1)*array_of_currents[j]);
		}
		array_of_possible_probabilities[i]=summator;
	}

}
void initiate_multiset_point_mode()
{ HAL_TIM_PWM_Start(&hal_firing_timer ,FIRING_TIME_CHANNEL);
		for(int i =0;i<hmi_max_no_of_members;i++)
	{
  		hmi_current_time_and_capacity_values_array[i].duration = 1 ;
	}
	for(int i=hmi_first_duration_address_in_multi_mode;i<(hmi_first_duration_address_in_multi_mode+hmi_max_no_of_members);i++)
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
	
	if (auto_mode_data_source==hmi_auto_mode)
	{
			
			if(setpoint_setting.Interval_ID>(hmi_process_end-1))
			{//xx=setpoint_setting.Interval_ID;
				 SEND_TO_HMI(hmi_time_consumed_address(prev_id),(hmi_current_time_and_capacity_values_array[prev_id].duration));
				 flashing_registeration(hmi_pointer_to_the_running_process_address(prev_id),cancel_the_address);
				
				 hmi_current_time_and_capacity_values_array[prev_id].iteration_capacity=get_capacity_and_stop_calculations();
					// send capacity value to the completed iteration
				SEND_TO_HMI(hmi_capacity_address(prev_id),(hmi_current_time_and_capacity_values_array[prev_id].iteration_capacity));
				
				 multi_set_point_status_flag=stop;
			}
			else
			{
			 if(prev_id!=setpoint_setting.Interval_ID)
				{ 
					if(prev_id!=-1)
					 {
						SEND_TO_HMI(hmi_time_consumed_address(prev_id),(hmi_current_time_and_capacity_values_array[prev_id].duration));
						 flashing_registeration(hmi_pointer_to_the_running_process_address(prev_id),cancel_the_address);
							// get capacity value to the completed iteration
						 hmi_current_time_and_capacity_values_array[prev_id].iteration_capacity=get_capacity_and_stop_calculations();
							// start capacity calculations for the next iteration
						 capacity_start_calculations();
							// send capacity value to the completed iteration
						SEND_TO_HMI(hmi_capacity_address(prev_id),(hmi_current_time_and_capacity_values_array[prev_id].iteration_capacity));
						 
					 }
					 else if(prev_id==-1)
					 {
						capacity_start_calculations();
					 }
					 flashing_registeration(hmi_pointer_to_the_running_process_address(setpoint_setting.Interval_ID),register_the_address);
						UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
						prev_id=setpoint_setting.Interval_ID;
						auto_operation(setpoint_setting.Current_Setting);
						
				}
					SEND_TO_HMI(hmi_time_consumed_address(prev_id),(setpoint_setting.Duration_collapsed));
			}
		
	}
	
	else if (auto_mode_data_source==sd_card_auto_mode)
	{
		if(setpoint_setting.Interval_ID>(sd_card_process_end-1))  //when i will know sd card process end
			{//xx=setpoint_setting.Interval_ID;
				 SEND_TO_HMI(sd_card_time_consumed_address(0),(sd_card_current_time_and_capacity_values_array[prev_id].duration));
				 flashing_registeration(sd_card_pointer_to_the_running_process_address(prev_id),cancel_the_address);
				
				 sd_card_current_time_and_capacity_values_array[prev_id].iteration_capacity=get_capacity_and_stop_calculations();
					// send capacity value to the completed iteration
				SEND_TO_HMI(sd_card_capacity_address(0),(sd_card_current_time_and_capacity_values_array[prev_id].iteration_capacity));
				
				 multi_set_point_status_flag=stop;
			}
			else
			{
			 if(prev_id!=setpoint_setting.Interval_ID)
				{ 
					if(prev_id!=-1)
					 {
						 
						SEND_TO_HMI(sd_card_time_consumed_address(0),(sd_card_current_time_and_capacity_values_array[prev_id].duration));
						 flashing_registeration(sd_card_pointer_to_the_running_process_address(0),cancel_the_address);
							// get capacity value to the completed iteration
						 sd_card_current_time_and_capacity_values_array[prev_id].iteration_capacity=get_capacity_and_stop_calculations();
							// start capacity calculations for the next iteration
						 capacity_start_calculations();
							// send capacity value to the completed iteration
						SEND_TO_HMI(sd_card_capacity_address(0),(sd_card_current_time_and_capacity_values_array[prev_id].iteration_capacity));
						 
						 iteration_display iteration_info={sd_card_current_time_and_capacity_values_array[prev_id].id , 
						 sd_card_current_time_and_capacity_values_array[prev_id].current ,
						 sd_card_current_time_and_capacity_values_array[prev_id].duration ,
						 sd_card_current_time_and_capacity_values_array[prev_id].duration ,
						 sd_card_current_time_and_capacity_values_array[prev_id].iteration_capacity };
						 
						 display_iteration(iteration_info);
					 }
					 if(prev_id==-1)
					 {
						capacity_start_calculations();
					 }
					 flashing_registeration(hmi_pointer_to_the_running_process_address(0),register_the_address);
						UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
						prev_id=setpoint_setting.Interval_ID;
						auto_operation(setpoint_setting.Current_Setting);
						
				}
					SEND_TO_HMI(hmi_time_consumed_address(0),(setpoint_setting.Duration_collapsed));
			}
	}

	
//	else
//	{ if(((setpoint_setting.Duration_collapsed%60)==0))
//		{
//			prev_time_consumed=(setpoint_setting.Duration_collapsed/60.0);
//			if(prev_id!=-1)
//		{
//			SEND_TO_HMI(hmi_time_consumed_address(prev_id),prev_time_consumed);
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
	UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
	auto_operation(current_setting);
  HAL_TIM_Base_Start(&hal_firing_timer);
}
else
{
	UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = UNPUSHED ;
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
					 hmi_process_begin=user_defined_process_begining;
					}
					else
					{
					 hmi_process_begin=1;
					}
					if(user_defined_process_ending<=counter_of_no_of_entered_process)
					{
					 hmi_process_end=user_defined_process_ending;
					}
					else
          {
					 hmi_process_end=counter_of_no_of_entered_process;
					}
					if(hmi_process_end<hmi_process_begin)
					{
           replace(&hmi_process_begin,&hmi_process_end);					
					}
					
	 if(sd_card_user_defined_process_begining>1)
					{
					 sd_card_process_begin=sd_card_user_defined_process_begining;
					}
					else
					{
					 sd_card_process_begin=1;
					}
}

uint16_t  check_input_current_limits(uint16_t input_current,uint16_t address)
{
	uint16_t allowed_current=0;
	uint16_t max=0;
	//get_max_resitance
	
	for(int i =0;i<steps_number;i++)
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
       UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = 1 ;	
				for(int i=hmi_first_pointer_to_the_running_process_address;i<(hmi_first_pointer_to_the_running_process_address+hmi_max_no_of_members);i++)
					{
						SEND_TO_HMI(i,0);
					}
			 	prev_id=-1;
       //HAL_TIM_Base_Start(&hal_firing_timer);
       mode=Auto;
					
				if (auto_mode_data_source==hmi_auto_mode)
				{
					Start_Operation ((hmi_process_begin-1) , (hmi_process_end-1),hmi_current_time_and_capacity_values_array);
				}
				
				else if (auto_mode_data_source==sd_card_auto_mode)
				{
					Start_Operation ((sd_card_process_begin-1) , (sd_card_process_end-1),sd_card_current_time_and_capacity_values_array);
				}
				
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
				
		flashing_registeration(hmi_pointer_to_the_running_process_address(prev_id),cancel_the_address);
		 flashing_registeration(hmi_pointer_to_the_running_process_address(setpoint_setting.Interval_ID),cancel_the_address);
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
					
		           UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = 1 ;	
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
       UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = 1 ;	
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
	for(int i=0;i<_2_power_of_steps;i++)
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
   for (i = 0; i < _2_power_of_steps; i++)
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
  	/*turn off step 8 if voltage is more than 130*/
	
		for(int j=0;j<steps_number;j++)
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
