#include "measurement.h"
#include "math.h"
#include "adc.h"
#include "tim.h"
#include "configration.h"
#include "firing.h"
#include "hmi_handler.h"
#include "application.h"
#include "time_handler.h"
//#include "manual_mode.h"
#include "arrays_calibration_firing.h"
#define PUSHED              1

uint16_t samples_counter=0; 
double accumlated_samples_per_channel=0;
uint8_t start_calculating_flag=0;
uint16_t x[no_of_channels]={0};//
uint64_t sum_sample[no_of_channels]={0};//
uint32_t offset[no_of_channels]={0};//
int32_t sample[no_of_channels];													//S_V for measur 1 ADC , then accumlate it in sum_v
uint64_t accumlated_summtion[no_of_channels]={0};       // accumulated_summtion_v for accumlation volt adc    
uint32_t AVERAGE_ADC[no_of_channels]={0};
uint16_t AVERAGE_ADC_IN_REEL_UNIT[no_of_channels]={0};
double measure_accumulator_value[no_of_channels]={0};
uint8_t complete_measure_flag_for_display=0;
uint8_t complete_measure_flag_for_end_voltage=0;

uint8_t complete_measure_flag_for_pid=0;
double calibration_factor=0;
extern uint8_t Input_Array[no_of_steps];
extern double R[no_of_steps];
 uint8_t  counter_display=0    ;
	  uint32_t  accumulator_display[no_of_channels]={0};
	uint16_t	total_measured_ampere_for_display=0;
	uint32_t	accumulator_total_measured_ampere_for_display=0;
	float R_MEASURED_FINE_TUNE=0;
uint16_t total_measured_ampere=0;
uint16_t value_for_diplay;	 		
float fixed_steps_measured_currents[no_of_steps]={0};
 
	uint64_t difference_time=0;
	uint64_t prev_measure=0;
	uint64_t biggest=0;
	uint64_t biggest_in_msec=0;
 

  
uint16_t auto_calibration(uint8_t no_calibration_values, double *external_measurement_array,double*corresponding_adc_values_array,uint16_t adc_rms)
{ //we must make the arrays in ascending order
	double ratio_1=0;
	double ratio_2=0;
	double delta_ratios=0;
	double first_adc_value=0;
	double sec_adc_value=0;
	double delta_adc_values=0;
	double minimum_adc_value=0;
	double max_adc_value=0;
	uint16_t measurement=0;
	uint8_t k=0;
	uint8_t i=0;
	
	
	minimum_adc_value=corresponding_adc_values_array[0];
	 max_adc_value=corresponding_adc_values_array[no_calibration_values-1];
	if(adc_rms<=minimum_adc_value)
	{
	 ratio_1=external_measurement_array[0]/minimum_adc_value;
		measurement =ratio_1*adc_rms;
		
	
	}
	else if ((adc_rms>=max_adc_value))
	{
	  ratio_1=external_measurement_array[no_calibration_values-1]/ max_adc_value;
		measurement =ratio_1*adc_rms;
	}
	else
	{
	for(k=1;k<=(no_calibration_values-1);k++)
	{ 
		if(adc_rms<=corresponding_adc_values_array[k])
		{
			i=k-1;
			break;
		}
		
	}
    
	ratio_1=external_measurement_array[i]/corresponding_adc_values_array[i];
	ratio_2=external_measurement_array[i+1]/corresponding_adc_values_array[i+1];
	 delta_ratios=ratio_2-ratio_1;//delta_ratios could be postive or negative
	 first_adc_value=corresponding_adc_values_array[i];
	 sec_adc_value=corresponding_adc_values_array[i+1];
	 delta_adc_values=sec_adc_value-first_adc_value;//postive 
	measurement=adc_rms*(ratio_1+(delta_ratios *((adc_rms-first_adc_value)/delta_adc_values)));
	 
  }
	return measurement;

}

void measure_start_dma_adc(void)
{
	  HAL_ADCEx_Calibration_Start(&adc_def);
    HAL_TIM_Base_Start_IT(&hal_measurement_timer);
 	HAL_ADC_Start_DMA(&adc_def,(uint32_t*)x,no_of_channels);            //  2 as i use two channels IN1,In2
}


void measure_timer_it(void)
{
	samples_counter++;

		for(int s=0;s<no_of_channels;s++)
		{
				sample[s]=x[s];
				sum_sample[s] = sum_sample[s] + sample[s] ;	
		}  
}



void measure_10_msec(void)
{	
			for(int l=0;l<no_of_channels;l++)
			{
					accumlated_summtion[l]=sum_sample[l];
			}
			accumlated_samples_per_channel=samples_counter;
			
			
			//clear old accumulation samples array
			for(int l=0;l<no_of_channels;l++)
			{
					sum_sample[l]=0;
			}
			
		//	ZERO_CROSS_COUNTER=0;
			samples_counter=0;
			start_calculating_flag=1;
			// prev_measure=funcution_time_counter;
		
}
//CONVERT ADC_To_VOLT_&_CURRENT

	 
			 
		

void MEASUREMENT_CALCULATION (void)
{   //   static uint8_t tog=0;
	float currents_summator=0;
	if(start_calculating_flag==1)		
	{  
		
		
//		tog++;
//		if(tog==2)
//     	tog=0;

//		if(tog==0) // to make sure there is an output
//			{ 
//			  prev_measure=funcution_time_counter;
//				
//			
//			
//			}
//			else
//      { if(funcution_time_counter>prev_measure)
//			  difference_time=funcution_time_counter-prev_measure;
//				if(difference_time>biggest)
//				{
//				 biggest=difference_time;
//					biggest_in_msec=biggest*25;
//					biggest_in_msec=(double)biggest_in_msec/1000.0;
//				}
//			}
		
		start_calculating_flag=0;

		
		for(int channel=0;channel<no_of_channels;channel++)
		{

			AVERAGE_ADC[channel]=(double)accumlated_summtion[channel]/(double)accumlated_samples_per_channel;
			
			
		}
		
		
	
		
			AVERAGE_ADC_IN_REEL_UNIT[volt]=auto_calibration(  no_of_calibration_values_ch0 , calibration_array_in_voltage,calibration_adc_array_volt,AVERAGE_ADC[volt]); 
if(AVERAGE_ADC_IN_REEL_UNIT[volt]<=9)
{
  AVERAGE_ADC_IN_REEL_UNIT[volt]=0;
}

		for(int i=0;i<no_of_steps;i++)
	{
	  fixed_steps_measured_currents[i]=(Input_Array[i]*((double)AVERAGE_ADC_IN_REEL_UNIT[volt]/R[i]));
		currents_summator+=fixed_steps_measured_currents[i];
	}
	
		
	AVERAGE_ADC_IN_REEL_UNIT[ampere_fixed_steps]=currents_summator;	 
	 R_MEASURED_FINE_TUNE=R_total_fine_tune_ohm_value/((float)pwm_value/1000.0);
if((uint8_t)(100*R_MEASURED_FINE_TUNE)>0)//multiplied by 100 to take it and prevent custing from cacelling it if it is  value smaller than one equal 0.5 ohm or 0.01 ohm for example.
{
AVERAGE_ADC_IN_REEL_UNIT[ampere_fine_tune_step]=(float)AVERAGE_ADC_IN_REEL_UNIT[volt]/R_MEASURED_FINE_TUNE;
total_measured_ampere=	currents_summator+AVERAGE_ADC_IN_REEL_UNIT[ampere_fine_tune_step];
}
else
{
	AVERAGE_ADC_IN_REEL_UNIT[ampere_fine_tune_step]=0;
	total_measured_ampere=	currents_summator;
}
			//AVERAGE_ADC_IN_REEL_UNIT[volt]=AVERAGE_ADC[1]*calibration_ratio_for_input_current;;
		         
		// total_measured_ampere=	auto_calibration(  no_of_calibration_values_ch1 , calibration_array_in_ampere,calibration_adc_array_current,AVERAGE_ADC[1]); 

		complete_measure_flag_for_display=1;
complete_measure_flag_for_end_voltage=1;



			// pid_timer_steps=PIDController_Update(&pid, AC_Current_Setting,AVERAGE_ADC_IN_REEL_UNIT[volt]);

	}
}


//void MEASUREMENT_CALCULATION (void)
//{      static uint8_t tog=0;
//	if(start_calculating_flag==1)		
//	{  
//		
//		
//	 if(funcution_time_counter>prev_measure)
//	 { difference_time=funcution_time_counter-prev_measure;
//				if(difference_time>biggest)
//				{
//				 biggest=difference_time;
//					biggest_in_msec=biggest*25;
//					biggest_in_msec=(double)biggest_in_msec/1000.0;
//				}
//		
//			}
//		
//		
//		start_calculating_flag=0;

//		
//		for(int channel=0;channel<no_of_channels;channel++)
//		{
//			d_accumulated_summtion[channel]= accumlated_summtion[channel];
//			d_accumulated_summtion[channel]= d_accumulated_summtion[channel]/(double)accumlated_samples_per_channel;
//			AVERAGE_ADC[channel]=sqrt(d_accumulated_summtion[channel]); 
//			
//		}
//		
//		
//		
//	//un//	AVERAGE_ADC_IN_REEL_UNIT[volt]=auto_calibration( 13, calibration_array_in_voltage,calibration_adc_array_volt,AVERAGE_ADC[0]); 
//			AVERAGE_ADC_IN_REEL_UNIT[volt]=500;
//		         
//		 total_measured_ampere=auto_calibration( 10, calibration_current_input_array,calibration_adc_array_input,AVERAGE_ADC[1]);   //calibrate input current
//		


//			 

//	}
//}



//void new_setting_pushed_measurement_action(void)//it must be moved from here and split it some staty and aome move to app
//{
//	for(int channel=0;channel<no_of_channels;channel++)
//			 {
//				 accumulator[channel]=0;
//				 measure_accumulator_value[channel]=AVERAGE_ADC_IN_REEL_UNIT[channel];
//			 }
//		   counter=0;
//}




void calculate_average_for_display(void)
{ static 	uint16_t contactors_response_COUNTER=0;
	 static 	uint16_t max=0;
			 if(1==all_contactors_updated())
		   {
		for(int channel=0;channel<no_of_channels;channel++)
		{
			accumulator_display[channel]=AVERAGE_ADC_IN_REEL_UNIT[channel]+accumulator_display[channel];
			
		}
		accumulator_total_measured_ampere_for_display+=total_measured_ampere;
	  counter_display++;
    if (counter_display==10)
	  {   
			 for(int channel=0;channel<no_of_channels;channel++)
			 {
				 measure_accumulator_value[channel]=(double)(accumulator_display[channel])/(float)counter_display;
				accumulator_display[channel]=0;
				
				
			 }
			 	 total_measured_ampere_for_display=accumulator_total_measured_ampere_for_display/counter_display;
			 
	      	complete_measure_flag_for_pid=1;
	     	
				 accumulator_total_measured_ampere_for_display=0;
		     counter_display=0;
		}
contactors_response_COUNTER=0;
	}
			 else
			 {
			  contactors_response_COUNTER++;
				 if(contactors_response_COUNTER>max)
				 {
				 max=contactors_response_COUNTER;
					 
					 if(max>500)
					 {
					 //alarm
					 }
				 }
			 }
}





void DGUS_SendVal(int(*iAdr)[2], uint8_t);
extern int tx_adr_val_2d_array[10][2];
//#define SEND_TO_HMI(addr1,val1)                                    do{ tx_adr_val_2d_array[0][0]=addr1;\
//	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
//                                                                     DGUS_SendVal(&tx_adr_val_2d_array[0],1);}while(0)		


// WE CAN PUT THIS IN CONFIGURATION FILE UNDER CONTIOUS MEASURE OR CALIBRATION MODE
void measurement_for_display__()
{ value_for_diplay=measure_accumulator_value[0];
}


void measurement_for_display()
{// value_for_diplay=  AVERAGE_ADC_IN_REEL_UNIT[volt];
	 //SEND_TO_HMI(0xBB ,AVERAGE_ADC[0]);            //?????????
	


//	   {
//			value_for_diplay=measure_accumulator_value[0];
//			}
//	
//		

//	if(value_for_diplay<5)
//	{
//	 value_for_diplay=0;
//	}
	
	
	  
	
		

	if(measure_accumulator_value[0]<5)
	{
	 measure_accumulator_value[0]=0;
	}
		
	
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{ 
	measure_timer_it();
}


