#ifndef __application_H
#define __application_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
	 
//extern uint8_t ZERO_CROSS_COUNTER;
//extern int32_t postive; 
//extern uint16_t pid_timer_steps;
	 
void Process_Runing(void);
void ILLUMINATE_STEPS_ON_HMI(void);
	 uint8_t all_contactors_updated(void);
uint8_t search_if_any_step_on(void);
#define Step1_START                HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,GPIO_PIN_SET)
#define Step2_START                HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,GPIO_PIN_SET) 
#define Step3_START                HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,GPIO_PIN_SET)
#define Step4_START                HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,GPIO_PIN_SET)
#define Step5_START                HAL_GPIO_WritePin(R5_GPIO_Port,R5_Pin,GPIO_PIN_SET)
#define Step6_START                HAL_GPIO_WritePin(R6_GPIO_Port,R6_Pin,GPIO_PIN_SET) 
#define Step7_START                HAL_GPIO_WritePin(R7_GPIO_Port,R7_Pin,GPIO_PIN_SET)
#define Step8_START                HAL_GPIO_WritePin(R8_GPIO_Port,R8_Pin,GPIO_PIN_SET) 

#define Step1_STOP                 HAL_GPIO_WritePin(R1_GPIO_Port,R1_Pin,GPIO_PIN_RESET)
#define Step2_STOP                 HAL_GPIO_WritePin(R2_GPIO_Port,R2_Pin,GPIO_PIN_RESET)
#define Step3_STOP                 HAL_GPIO_WritePin(R3_GPIO_Port,R3_Pin,GPIO_PIN_RESET)
#define Step4_STOP                 HAL_GPIO_WritePin(R4_GPIO_Port,R4_Pin,GPIO_PIN_RESET)
#define Step5_STOP                 HAL_GPIO_WritePin(R5_GPIO_Port,R5_Pin,GPIO_PIN_RESET) 
#define Step6_STOP                 HAL_GPIO_WritePin(R6_GPIO_Port,R6_Pin,GPIO_PIN_RESET) 
#define Step7_STOP                 HAL_GPIO_WritePin(R7_GPIO_Port,R7_Pin,GPIO_PIN_RESET)
#define Step8_STOP                 HAL_GPIO_WritePin(R8_GPIO_Port,R8_Pin,GPIO_PIN_RESET)
	 



#define Step1                            0
#define Step2                            1
#define Step3                            2
#define Step4                            3
#define Step5                            4
#define Step6                            5
#define Step7                            6
#define Step8                            7


#define Auto         0
#define manual       1


#define step_start(x)   				   do{switch (x){\
						 case Step1: \
		Step1_START ;\
	break;\
						 case Step2: \
		Step2_START ;\
	break;\
						 case Step3 :\
		Step3_START ;\
	break;\
						 case Step4 :\
		Step4_START ;\
	break;\
						 case Step5 :\
		Step5_START ;\
	break;\
						 case Step6 :\
		Step6_START ;\
	break;\
						 case Step7 :\
		Step7_START ;\
	break;\
						 case Step8 :\
		Step8_START ;\
	break;\
}\
}while(0)
 


#define step_stop(x)   				   do{switch (x){\
						 case Step1: \
		Step1_STOP ;\
	break;\
						 case Step2: \
		Step2_STOP ;\
	break;\
						 case Step3 :\
		Step3_STOP ;\
	break;\
						 case Step4 :\
		Step4_STOP ;\
	break;\
						 case Step5 :\
		Step5_STOP ;\
	break;\
						 case Step6 :\
		Step6_STOP ;\
	break;\
						 case Step7 :\
		Step7_STOP ;\
	break;\
						 case Step8 :\
		Step8_STOP ;\
	break;\
}\
}while(0)

	
	                          



#define read_fb1  (HAL_GPIO_ReadPin(FB1_GPIO_Port,FB1_Pin))//ack
#define read_fb2  (HAL_GPIO_ReadPin(FB2_GPIO_Port,FB2_Pin))//ack
#define read_fb3  (HAL_GPIO_ReadPin(FB3_GPIO_Port,FB3_Pin))//ack
#define read_fb4  (HAL_GPIO_ReadPin(FB4_GPIO_Port,FB4_Pin))//ack
#define read_fb5  (HAL_GPIO_ReadPin(FB5_GPIO_Port,FB5_Pin))//ack
#define read_fb6  (HAL_GPIO_ReadPin(FB6_GPIO_Port,FB6_Pin))//ack
#define read_fb7  (HAL_GPIO_ReadPin(FB7_GPIO_Port,FB7_Pin))//ack
#define read_fb8  (HAL_GPIO_ReadPin(FB8_GPIO_Port,FB8_Pin))//ack






#define read_fb(x,y)   				   {switch (x){\
						 case Step1: \
		y=read_fb1; \
	break;\
						 case Step2: \
		y=read_fb2; \
	break;\
						 case Step3 :\
		y=read_fb3 ;\
	break;\
						 case Step4 :\
		y=read_fb4 ;\
	break;\
						 case Step5 :\
		y=read_fb5; \
	break;\
						 case Step6 :\
		y=read_fb6;\
	break;\
						 case Step7 :\
		y=read_fb7 ;\
	break;\
						 case Step8 :\
		y=read_fb8 ;\
	break;\
}\
}
extern  uint8_t  STOP_FIXED_STEPS_FLAG;	
#ifdef __cplusplus
}
#endif
#endif /*__ application_H */
