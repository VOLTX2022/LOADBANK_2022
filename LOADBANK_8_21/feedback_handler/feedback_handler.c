//#include "feedback_handler.h"

////void take_feedback(void)
////{
////	if((current_setting>0)&&(START_FLAG==1)&&(mode==Auto))
////      {
////				if(complete_measure_flag_for_pid==1)
////				{complete_measure_flag_for_pid=0;
////				 correction_value=PIDController_Update(&pid, current_setting, AVERAGE_ADC_IN_REEL_UNIT[ampere]);
////				 update_steps_and_pwm(correction_value);
////		    }
////			}
////}



///*
//	Between Cells -->  0x09 
//	Between Rows --> 0x0A, 0x0D
//*/ 


///* Acess Mechanism 
//************************************************************************************************************************************************************/
////	uint16_t Upload_Data_From_SdCard_To_Array (uint16_t * PTR_arr, uint16_t * PTR_FileName, uint16_t MAX_LOCATIONS);
////	{
////		//
////		//
////		//
////		//
////		
////	}
////	Needs -> static uint16_t * Data_Arr[]; 
////	static uint16_t File_Name[];
////	extern uint16_t MAX_Locations; 
////	static uint16_t Actual_Locations_Number; 
////			Some functions form standard library 
////	Return ->  Actual_Locations_Number; 
/////************************************************************************************************************************************************************/
////	static uint16_t * Get_Data_Cell(uint16_t * PTR_arr, uint16_t Row, uint16_t Column); 
////	Needs ->  static uint16_t * Data_Arr[]; uint16_t Row, uint16_t Column;  static uint16_t Data_Cell 
////	Return -> Data_Cell 
/////************************************************************************************************************************************************************/	
////	 void Get_Actual_Data (struct * Data[]); 
////	 needs Get_Data_Cell(), extern struct; 
////	return void; 
////// To filter Between Cells -->  0x09 Between Rows --> 0x0A, 0x0D
/////************************************************************************************************************************************************************/
/////************************************************************************************************************************************************************/	
////	 uint16_t * Get_Data_Step (step,struct * Data[]); 
////	 needs extern struct;extern step;  
////	 return address of current; 
/////************************************************************************************************************************************************************/
