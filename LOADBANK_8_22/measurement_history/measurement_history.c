#include "measurement_history.h"
#include "hmi_communication.h"
#include "hmi_handler.h"
#include "measurement.h"

#include "configration.h"

/******************************************************
  DWIN ADRRESSES
*******************************************************/





/*******************************************************/
#define PUSHED   1
#define UNPUSHED 0
#define ENABLE   1
#define DISABLE  0

#define ON  0x01
#define OFF 0x00




uint8_t counter_next_prev =0;
extern double measure_accumulator_value[no_of_channels];


//history 0x40 to 0x48 for left hrs values
//history 0x49 to 0x57 for right hrs values  






uint16_t array_current[72]={0};
uint16_t array_volt[72]={0};
uint32_t start_time=0;

/******************************************************
 
  ARDUINO ADRRESSES
*******************************************************/
#define PUSHED                1
#define UNPUSHED              0
 

 uint8_t start_record_flag      = UNPUSHED     ;
 uint8_t record_on_flag=0;






/***************INITIATION****************************************/






/*********************************************************
   Measuring Variables
 *********************************************************/

int DC_Voltage_Reading = 0 ;
double DC_Current_Measurment = 0 ;
double DC_Current_Avarage = 0 ;
double DC_Current_Reading = 0 ;

int Measuring_Counter = 0 ;
int Measuring_Statues = UNPUSHED ;
int bluetooth_timer = 0 ;
int memory_timer = 0 ;

/*********************************************************/



int Voltage_Reading = 0;
int Current_Reading = 0;


/******************************************************/



void Store_Value(void);

void display_measure_history (uint8_t);

#define no_of_rows_per_page 6
#define page_offset(page_no) (no_of_rows_per_page*(page_no))//page_no start from page 1 

//void diplay_timer_of_history(double total_ms)
//{
//  uint16_t hours,total_minutes,minutes;
//  if(start_record_flag==1)
// {
//  total_minutes =total_ms/60000;
//  hours=((float)total_minutes)/60;
//  minutes= total_minutes-hours*60;
//  SEND_TO_HMI (MINUTES_DISPLAY_ADDRESS,minutes);
//  SEND_TO_HMI(HOURS_DISPLAY_ADDRESS ,hours);
// }
//}
void display_measure_history (uint8_t history_page_number)
{
  uint8_t m=0,i=0;

       m=0;
       for(i=start_volt_history_ADDRESS;i<=end_volt_history_ADDRESS ;i++)
      {
      SEND_TO_HMI(i, array_volt[m+page_offset(history_page_number)]);
       m++;
      }
       m=0;
      for(i=start_current_history_ADDRESS;i<=end_current_history_ADDRESS ;i++)
     {
      SEND_TO_HMI(i, array_current[m+page_offset(history_page_number)]);
       m++;
     }
 }






void display_hours(void)
{  
   display_measure_history (counter_next_prev);
}
//void loop ()
//{
//  Store_Value();


//  display_hours();
//  

//}


   
          // i want to send zero at the 8 positions of volt & current .









uint8_t variable=0;
 void  clear_all_history(void)
	{
	for(int i=0;i<72;i++)	
  {
   array_current[i]=0  ;
   array_volt[i]   =0 ;
	}
	 variable=0;
	}
	 
uint16_t half_sec_count_history=0;
void Store_Value (void)//must be called each 10 min
{
	  
 

  if(record_on_flag==1)
 { 
	 if((half_sec_count_history==1200)||(half_sec_count_history==0))
	{half_sec_count_history=0;
 if (variable<72)
 {

	 

   array_current[variable]=total_measured_ampere_for_display  ;
   array_volt[variable]   =measure_accumulator_value[volt] ;
	 variable++;
   }
 else
  {
	 variable=73;
	}
 
   
 /*Serial.println(variable);
 Serial.println(ten_minutes)   ;
  Serial.println(Value)    ;*/
}
 half_sec_count_history++;

  }
  else
  {  half_sec_count_history=0;
       array_current[variable]=0;
       array_volt[variable]   =0;
    
    }
 
}






