#include "hmi_handler.h"
#include "hmi_communication.h"
#include "measurement_history.h"
#include "auto_mode.h"
#include "measurement.h"
#include "tim.h"
#include "time_based_table_operation.h"
#include "application.h"
#include "firing.h"
#include "configration.h"	 
#include "time_handler.h"
#define max_no_of_flashing_addresses 32
#define add_nothing  0
#define add_address  1
#define NULL_ADDRESS 0
int steps_hmi_addresses_array[no_of_steps]={STEP1_ADDRESS, STEP2_ADDRESS ,STEP3_ADDRESS ,STEP4_ADDRESS ,STEP5_ADDRESS,STEP6_ADDRESS ,STEP7_ADDRESS ,STEP8_ADDRESS};//,FINE_TUNE_ON_OFF_ADDRESS};// ,STEP6_ADDRESS };//,STEP7_ADDRESS ,STEP8_ADDRESS };
extern uint16_t manual_fine_tune_step_value;
extern  s_table_typedef current_and_time_values_array[max_no_of_members];
int16_t displayed_hmi_values[no_of_addresses]={0};//this will make a problem if i want to changge any initiated value from hmi to 0

//#define EMERGENCY_ADDRESS                       0x19
//End of HMI user interfacing part//Start of HMI user interfacing part



uint8_t beepbeep_time=0;
uint8_t  STEP_STATE_ARRAY[no_of_steps]={0};
extern uint8_t diagnosing_arr[20];
extern uint16_t value_for_diplay;
extern uint16_t AVERAGE_ADC_IN_REEL_UNIT[no_of_channels];
extern int Value;
extern int Address;
extern uint8_t mode;
extern uint8_t UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE;
extern uint8_t STOP_FIXED_STEPS_FLAG;
extern uint16_t Input_Volt_Limit_Setting;
extern uint8_t hmi_auto_mode_flag;
extern uint8_t sd_card_auto_mode_flag;
uint8_t new_current_unpushed_flag=0;

void HMI_Addresses()
{ 

//Address=Address+5;
	
	for(int i =0;i<no_of_steps;i++)
	{
     if (Address==steps_hmi_addresses_array[i])
	    {
        STEP_STATE_ARRAY[i] = !(STEP_STATE_ARRAY[i]) ;
				mode=manual;
				new_firing_order_flag=1;//TO CHECH IF THIS FUNCTION CLOSE ALL THE STEPS MAKE IT CLOSE THE FIRING ALSON FOR SAFETY
	    }

  }	
	
//	if(((Address>=hmi_current_address(0))&&(Address<=hmi_current_address(max_no_of_members)))||((Address>=hmi_duration_address(0))&&(Address<=hmi_duration_address(max_no_of_members))))
	{		for(int i =0;i<max_no_of_members;i++)
	 {
  		if (Address==hmi_current_address(i))
	    {
       	current_and_time_values_array[i].current = check_input_current_limits(Value,Address) ;
				if((i+1)>counter_of_no_of_entered_process)
				{
					counter_of_no_of_entered_process=(i+1);
	      }
	  	}
			else if (Address==hmi_duration_address(i))
	    {
				current_and_time_values_array[i].duration=Value;
			}

   }	
  }
/*************************************************/			
   switch (Address)
   {case Automatic_Mode_Address:
				 
		   if(mode ==manual)
			 {
				
						new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
			      OFF_CURRENT();
					  
				    //reset_switch_off_timer_flag=1;
				    //send_setting_switch_off_timer_flag=1;
			 }
			   //FINE_TUNE_RELAY_ON
			  hmi_auto_mode_flag=0;
				sd_card_auto_mode_flag=0;  
			  mode=Auto;
//			 open_circuit_alarm_flag=disappear; 
//					 input_current_exceed_max_limit_alarm_flag=disappear;
//					 injection_time_over_alarm_flag=disappear;
//			page_of_input_current_flag=0;
			break;
			 
		 case insert_data_from_sd_card_in_auto_mode_ADDRESS:
			 
				sd_card_auto_mode_flag=1;
				mode=Auto;
			 
			break;
		 
		 case insert_data_using_hmi_screen_in_auto_mode_ADDRESS:
			 
				hmi_auto_mode_flag=1;
				mode=Auto;
			 
			break;
			 
		
    case START_MULTI_SETPOINT_ADDRESS:
      if (Value == ON)
					
      {   multi_set_point_status_flag=start;
				        
				      
					
						  mode=Auto;
      }
      else
      { multi_set_point_status_flag=stop;
		    mode=Auto;
	  ///firing              //must be unremoved 
								
    //    reset_switch_off_timer_flag=1;

			}
      break ;
			
			 case PAUSE_MULTI_SETPOINT_ADDRESS:
      if (Value == ON)
				
      {   multi_set_point_status_flag=pause;
			//	Pause_Operation ();
				 mode=Auto;
				       
//                UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = PUSHED ;
						  	//auto_operation(current_setting);//check if needed
             //   HAL_TIM_Base_Start(&hal_firing_timer);
     		 
      }
      else
      { 
				multi_set_point_status_flag=resume;
				 mode=Auto;
//				new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
//			  OFF_CURRENT();  
				///firing              //must be unremoved 
			
			}
      break ;
	
    case STOP_ALL_ADDRESS:
      STOP_FIXED_STEPS_FLAG =1;
		  new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
			OFF_CURRENT();
	
      break ;
		
		case FINE_TUNE_SETTING_ADDRESS:
				manual_fine_tune_step_value=Value;
		
		   new_firing_order_flag=1;
      break ;
		case FINE_TUNE_ON_OFF_ADDRESS:
			 if (Value == ON)
				
      {  //FINE_TUNE_RELAY_ON
				  contactor_fine_tune_on;
				 HAL_Delay(100); 
				START_FINE_TUNE_OPERATION_IN_MANUAL_MODE=1;
		    new_firing_order_flag=1;
			}
			else
			{
			  //HAL_TIM_Base_Stop(&hal_firing_timer);
           contactor_fine_tune_off;
				
			START_FINE_TUNE_OPERATION_IN_MANUAL_MODE=0;
				 new_firing_order_flag=1;
			}
		  break ;
			

			 case VOLTX_ADDRESS:
			 if(  mode==Auto)
			 {
				UPDATE_FINE_TUNE_OPERATION_IN_AUTO_MODE = UNPUSHED ;
				new_current_unpushed_flag=1;    //to send 0 in measurement,send off flashing ,of proceed light 
			  OFF_CURRENT();
			 }
			 break;
			 




       
  case START_RECORD_ADDRESS:
    {
       if (Value==ON)
      {
				record_on_flag=1;
       
        set_half_sec_counter(ten_minutes_count-1);
      
      }
       else 
		  {
			 record_on_flag=0;
			}
    
    }
    
    break;
		
	case LIMIT_OF_END_VOLTAGE_ADDRESS:
	  	limit_of_end_voltage=Value;
		break;
	case USER_PROCESS_BEGINING_ADDRESS:
		user_defined_process_begining=Value;
		break;
		case USER_PROCESS_ENDING_ADDRESS:
		user_defined_process_ending=Value;
		break;
//   case MEASUREMEMTS_HISTORY_ADDRESS:
//           { 
//						// rise a Flag to call diplay values
//           }
//     
//      break ;
  	 case NEXT_PREV_ADDRESS :
    { counter_next_prev=Value;
     
      }
      break;
 
  

   
  
  
 
	 }
		
}



		
//Start of HMI user interfacing part

void DISPLAY_MEASUREMENT (void)
{
	
		// measurement_for_display();
	  
     SEND_TO_HMI(Volt_Measure_Address ,measure_accumulator_value[volt]);
	   SEND_TO_HMI(Current_Measure_Address,total_measured_ampere_for_display);
	

}	


   uint8_t counter_of_flashing_addresses=0;
	 int16_t array_of_flashing_adresses[max_no_of_flashing_addresses];
void flashing_registeration(int16_t ICON_ADDRESS,uint8_t status)             
{  
	
	 uint8_t array_action=0;
	
	if(status==cancel_the_address)
	{ 
	  for(int i=0;i<max_no_of_flashing_addresses;i++)
		{
		 if(array_of_flashing_adresses[i]==ICON_ADDRESS)
		 { 
			 SEND_TO_HMI(ICON_ADDRESS,0);
			 
			 if(counter_of_flashing_addresses>=2)
			 {   if((counter_of_flashing_addresses-1)==i) //last place 
				 {
				  array_of_flashing_adresses[i]=NULL_ADDRESS;
					 counter_of_flashing_addresses--;
				 }
					else
				 {
			     array_of_flashing_adresses[i]=array_of_flashing_adresses[counter_of_flashing_addresses-1];
					 array_of_flashing_adresses[counter_of_flashing_addresses-1]=NULL_ADDRESS;
			     counter_of_flashing_addresses--;
				 }
			
			 }
			  else if(counter_of_flashing_addresses==1)//just one element counter_of_flashing_addresses==1 
				 {
				  array_of_flashing_adresses[i]=NULL_ADDRESS;
					 counter_of_flashing_addresses--;
				 }
			
		   
		 }
		}
	
	
	
	}

	 
	else if(status==register_the_address)
	{ 
		
		if(counter_of_flashing_addresses<max_no_of_flashing_addresses)
		{
	  for(int i=0;i<max_no_of_flashing_addresses;i++)//8 max no of flashing addresses
		{
		 if(array_of_flashing_adresses[i]==ICON_ADDRESS)
		 { 
			
			 array_action=add_nothing; //address already exist 
		 }
		 else
		 { 
			 array_action=add_address;
			 
		 }
		}
	
	
		if(array_action==add_address)
		{
	
			
			array_of_flashing_adresses[counter_of_flashing_addresses]=ICON_ADDRESS; //address already exist 
		 counter_of_flashing_addresses++;
	  }
		
		}
	
	 }
	else
   {
	   while(1);//error
	 }
 }

 void beep_flashing(uint8_t status,uint8_t duration)             
{  if(status==ON)
	{
		beepbeep_time=duration;
   flashing_registeration(beepbeep,register_the_address);
	}
	else
  {
	  flashing_registeration(beepbeep,cancel_the_address);
	}

}
void FLASH_ON_HMI()
	{ static uint8_t tog=0;
		tog++;
		if(tog==2)
     	tog=0;

		if(tog==0) // to make sure there is an output
			{   
			 if(counter_of_flashing_addresses>0)
	     {
						 for(int m=0;m<counter_of_flashing_addresses;m++)
	      	 {
						 if(array_of_flashing_adresses[m]==beepbeep)
						 {
						  SEND_TO_HMI(beepbeep , beepbeep_time);
						 }
						 else
						 {
						 SEND_TO_HMI(array_of_flashing_adresses[m] , 1);
						 }
					 }
			}
		}
		 
		
			else 
			{
				  if(counter_of_flashing_addresses>0)
	      	{
						 for(int m=0;m<counter_of_flashing_addresses;m++)
	      	 {
						 SEND_TO_HMI(array_of_flashing_adresses[m] , OFF);
					 }
						
				
			    }
				
		}
	
}


//void refresh_hmi_screen_while_unpushed(void)
// {  
//	   if((CURRENT_PROCEED_FLAG==UNPUSHED)&&(new_current_unpushed_flag==1))
//				{ 
//					new_current_unpushed_flag=0;
//          SEND_TO_HMI(CURRENT_AC_FLASHING_ADDRESS,0);
//					SEND_TO_HMI(CURRENT_AC_PROCEED_ADDRESS,0);
//					SEND_TO_HMI(VOLT_MEASURING_ADDRESS,0);
//					
//					
//				//	DGUS_Beep(50);
//				}	
////				if(mode_flag==manual)
////				{
////				  SEND_TO_HMI(CURRENT_AC_SETTING_ADDRESS,0);
////				}
// }
		


void refresh_hmi_screen_while_unpushed(void)
 {  
	   if(new_current_unpushed_flag==1)
				{ 
					new_current_unpushed_flag=0;
          SEND_TO_HMI(Current_Measure_Address,0);
					SEND_TO_HMI(CURRENT_START_SINGLE_SET_POINT_ADDRESS,0);
				
			//	SEND_TO_HMI(FINE_TUNE_ON_OFF_ADDRESS,0);	
				}	
//				if(mode_flag==manual)
//				{
//				  SEND_TO_HMI(CURRENT_AC_SETTING_ADDRESS,0);
//				}
 }
