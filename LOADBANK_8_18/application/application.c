#include  "application.h"
#include  "tim.h"
#include "math.h"
#include "time_handler.h"
#include "auto_mode.h"
#include "measurement.h" 
#include "hmi_handler.h"
#include "hmi_communication.h"
#include "pid.h"
#include "firing.h"
#include "configration.h"
#include "auto_mode.h"
//#include "manual_mode.h"
void Read_All_Signals(void);

void  RELAYS_OPERATION(void);
extern uint16_t current_setting;

uint16_t correction_value=0;
extern uint16_t AVERAGE_ADC_IN_REEL_UNIT[no_of_channels];
extern int steps_hmi_addresses_array[no_of_steps];
extern uint8_t complete_measure_flag_for_display;
extern uint8_t complete_measure_flag_for_pid;
extern PIDController pid ;	
	uint8_t test =9;
	extern uint8_t diagnosing_arr[20];

extern uint8_t UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE;
uint8_t STOP_FIXED_STEPS_FLAG=1;
uint16_t Input_Volt_Limit_Setting=1000;
extern uint8_t  STEP_STATE_ARRAY[no_of_steps];
extern uint16_t current_setting;




extern uint32_t Mesurement_RMS[6];
uint8_t Input_Array[no_of_steps]={0};
void update_steps_and_pwm(int16_t corriction);
void RELAYS_OPERATION(void);
void Read_All_Signals(void);
void ILLUMINATE_STEPS_ON_HMI(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
 { 
		 
		
			
}
// 
//void check_new_setting_pushed(void)//it must be moved from here and split it some staty and aome move to app
//{
//			if(new_setting_pushed_flag==1)
//		{  new_setting_pushed_flag=0;
//			
//       flashing_registeration(CAN_NOT_REACH_SETTING_VALUE_ADDRESS,cancel_the_address);
//		   flashing_registeration(NO_TRIPPING_OCCURE_ADDRESS,cancel_the_address);
//       SEND_TO_HMI(TRIPPING_MILES_ADDRESS,0);
//       SEND_TO_HMI(TRIPPING_SECONDS_ADDRESS,0);			
//			 defualt_setting_switch_off_timer();
//			 new_setting_pushed_measurement_action();
//				if(CURRENT_PROCEED_FLAG==PUSHED)
//			{
//		  	make_meaure_euqal_setting_flag=0;
//	      restart_timer_filter_display=1;
//				start_timer_filter_display=1;
//			}
//			 
//		}

//}
//uint32_t pid_counter=0;
//uint32_t no_of_pid_count=0;
void Process_Runing(void)
{    
	
	RELAYS_OPERATION();
	if(1==FRAMES_RX_FLAG)
		{
		  FRAMES_RX_FLAG=0;
	    SerialEvent();
		}
    MULTI_PURPOSE_TIMER();			    
    MEASUREMENT_CALCULATION ();

		if(	complete_measure_flag_for_display==1)
			{
	     	complete_measure_flag_for_display=0;
				calculate_average_for_display();
		  }
			if((current_setting>0)&&(UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE==1)&&(mode==Auto))
      {
				if(complete_measure_flag_for_pid==1)
				{complete_measure_flag_for_pid=0;
				 correction_value=PIDController_Update(&pid, current_setting,total_measured_ampere);
				 update_steps_and_pwm(correction_value);
		    }
			}
    Read_All_Signals();	
		
}

void RELAYS_OPERATION()
{
if  (STOP_FIXED_STEPS_FLAG==1)
    {
			for(int i=first_step;i<=last_step;i++)
			{ 	
				step_stop(i);
			  STEP_STATE_ARRAY[i]=0;
			
			}
     
			STOP_FIXED_STEPS_FLAG =   0 ;                   

    }

   else
	 {  for(int i=first_step;i<=last_step;i++)
		 {
      if (STEP_STATE_ARRAY[i] == 1 )
        {
          step_start(i);
        }
			else 
			  {
			    step_stop(i);
		   	}
	    }

	 }


}
void Read_All_Signals()
{ int feedback_value=0;
	
	for(int i=first_step;i<=last_step;i++)
	{ 
		read_fb(i,feedback_value);
	  if(feedback_value==0)
		{
			Input_Array[i]=1;
    }
			else 
		{
		  Input_Array[i]=0;
		}
}
	
	
}
 uint8_t old_inputs[no_of_steps]={0};
void ILLUMINATE_STEPS_ON_HMI()
{//  SEND_TO_HMI(STEP3_ADDRESS,1);
	
	for(int i =0;i<no_of_steps;i++)
	{ //if(old_inputs[i]!=Input_Array[i])
		{
		if(Input_Array[i]==1) 
     { 
			 SEND_TO_HMI(steps_hmi_addresses_array[i],1);
	   }
		 else
     {
		   SEND_TO_HMI(steps_hmi_addresses_array[i],0);
		 }
		 old_inputs[i]=Input_Array[i];
	 }
	}
	 if(pwm_value==0)
		{
			SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,0);	
		}
		else
    {
		 SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,1);	
		}
	    

} 
 
uint8_t all_contactors_updated()
{
for(int i =0;i<no_of_steps;i++)
	{
		if(Input_Array[i]!=STEP_STATE_ARRAY[i])
		{
		 return 0;
		}
	}
	return 1;
}
uint8_t search_if_any_step_on()
{
for(int i =0;i<no_of_steps;i++)
	{
		if(Input_Array[i]==1)
		{
		 return 1;
		}
	}
	return 0;
}
void update_steps_and_pwm(int16_t corriction)
{int error=0;
  static uint16_t old_setting=0;
	static uint16_t after_pid_setting=0;
	if(current_setting!=old_setting)
	{

		old_setting=current_setting;
		
		
		if (((corriction>=0)&&(corriction<=1000)))

{
pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
}
else if((corriction>1000)&&(corriction<=1050))
{
corriction=1000;
	pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
}
else	if((corriction>=-50)&&(corriction<0))
{
	corriction=0;
	pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
	
}
else 
{

	auto_operation(current_setting);//set the setting=17

}
}
	else
	{
	if (((corriction>=0)&&(corriction<=1000)))

{
pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
}
else if((corriction>1000)&&(corriction<=1050))
{
corriction=1000;
	pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
}
else	if((corriction>=-50)&&(corriction<0))
{
	corriction=0;
	pid_fine_tune_value=corriction;
	 new_firing_order_flag=1;
	
}
else 
{
if(current_setting> total_measured_ampere)//for example set=10 measure =3
{
 error=after_pid_setting- total_measured_ampere;//error =7 
	after_pid_setting=after_pid_setting+error;
	auto_operation(after_pid_setting);//set the setting=17
	
}
else
{ error= total_measured_ampere-after_pid_setting;//error =7 
	after_pid_setting=after_pid_setting-error;
	auto_operation(after_pid_setting);//set the setting=3
	

}
}


}

}
/**/
