#ifndef __hmi_communication_H
#define __hmi_communication_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
	 
	 
//Start of HMI UART part
#define max_no_of_message        10
#define message_size             8																																				 

#define arraywidth               24


#define HMI_DISPLAY_1(addr1,val1)                                    do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
                                                                     DGUS_SendVal(&tx_adr_val_2d_array[0],1);}while(0)
#define HMI_DISPLAY_2(addr1,val1,addr2,val2)                         do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
  	                                                                     tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;\
                                                                         DGUS_SendVal(&tx_adr_val_2d_array[0],2);}while(0)

#define HMI_DISPLAY_3(addr1,val1,addr2,val2,addr3,val3)                    do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
  	                                                                     tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;\
		                                                                     tx_adr_val_2d_array[2][0]=addr3;\
		                                                                     tx_adr_val_2d_array[2][1]=val3;\
                                                                     DGUS_SendVal(&tx_adr_val_2d_array[0],3);}while(0)

#define HMI_DISPLAY_4( addr1, val1, addr2, val2, addr3, val3, addr4, val4)  do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
  	                                                                     tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;\
		                                                                     tx_adr_val_2d_array[2][0]=addr3;\
		                                                                     tx_adr_val_2d_array[2][1]=val3;\
	                                                                       tx_adr_val_2d_array[3][0]=addr4;\
		                                                                     tx_adr_val_2d_array[3][1]=val4;\
                                                                     DGUS_SendVal(&tx_adr_val_2d_array[0],4);}while(0)

#define HMI_DISPLAY_5(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5)  do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
  	                                                                     tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;\
		                                                                     tx_adr_val_2d_array[2][0]=addr3;\
		                                                                     tx_adr_val_2d_array[2][1]=val3;\
	                                                                       tx_adr_val_2d_array[3][0]=addr4;\
		                                                                     tx_adr_val_2d_array[3][1]=val4;\
                                                                         tx_adr_val_2d_array[4][0]=addr5;\
		                                                                     tx_adr_val_2d_array[4][1]=val5;\
                                                                         DGUS_SendVal(&tx_adr_val_2d_array[0],5);}while(0)
#define HMI_DISPLAY_6(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5,addr6,val6)  do{ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;\
  	                                                                     tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;\
		                                                                     tx_adr_val_2d_array[2][0]=addr3;\
		                                                                     tx_adr_val_2d_array[2][1]=val3;\
	                                                                       tx_adr_val_2d_array[3][0]=addr4;\
		                                                                     tx_adr_val_2d_array[3][1]=val4;\
                                                                         tx_adr_val_2d_array[4][0]=addr5;\
		                                                                     tx_adr_val_2d_array[4][1]=val5;\
	                                                                       tx_adr_val_2d_array[5][0]=addr6;\
		                                                                     tx_adr_val_2d_array[5][1]=val6;\
                                                                         DGUS_SendVal(&tx_adr_val_2d_array[0],6);}while(0)

																																				 
#define HMI_DISPLAY_4_if( cond1,addr1, val1,cond2, addr2, val2,cond3, addr3, val3,cond4, addr4, val4)  do{ \
	                                                                      if(cond1){ tx_adr_val_2d_array[0][0]=addr1;\
	                                                                 	     tx_adr_val_2d_array[0][1]=val1;}\
                                                                         else { tx_adr_val_2d_array[0][0]=0xf;\
	                                                                 	     tx_adr_val_2d_array[0][1]=0;}\
  	                                                                    if(cond2){ tx_adr_val_2d_array[1][0]=addr2;\
		                                                                     tx_adr_val_2d_array[1][1]=val2;}\
																																				else{ tx_adr_val_2d_array[1][0]=0xf;\
		                                                                     tx_adr_val_2d_array[1][1]=0;}\
		                                                                     if(cond3){tx_adr_val_2d_array[2][0]=addr3;\
		                                                                     tx_adr_val_2d_array[2][1]=val3;}\
																																				 else{tx_adr_val_2d_array[2][0]=0xf;\
		                                                                     tx_adr_val_2d_array[2][1]=0;}\
	                                                                       if(cond4){tx_adr_val_2d_array[3][0]=addr4;\
		                                                                     tx_adr_val_2d_array[3][1]=val4;}\
																																				 else{tx_adr_val_2d_array[3][0]=0xf;\
		                                                                     tx_adr_val_2d_array[3][1]=0;}\
                                                                     DGUS_SendVal(&tx_adr_val_2d_array[0],4);}while(0)
  /*
																																			 
#define HMI_DISPLAY_1(addr1,val1)                                     do{}while(0)	
#define HMI_DISPLAY_2(addr1,val1,addr2,val2)                          do{}while(0)	

#define HMI_DISPLAY_3(addr1,val1,addr2,val2,addr3,val3)                     do{}while(0)	

#define HMI_DISPLAY_4( addr1, val1, addr2, val2, addr3, val3, addr4, val4)   do{}while(0)	

#define HMI_DISPLAY_5(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5)   do{}while(0)	
#define HMI_DISPLAY_6(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5,addr6,val6)   do{}while(0)	
*/
extern volatile uint8_t FRAMES_RX_FLAG;
extern int tx_adr_val_2d_array[max_no_of_message][2];	
extern uint8_t prevent_sending_to_hmi_flag;																																		 
void SerialEvent(void)              ;
void DGUS_Beep(uint8_t bTime)        ;
void DGUS_LED_Bright(uint8_t bVal)   ;
void DGUS_SendVal(int (*)[2],uint8_t );
void Delay (uint16_t delay_beeb);
void set_full_messege_rx(uint8_t);
uint8_t get_full_messege_rx(void);
void start_hmi_uart(void);
 void SEND_TO_HMI(int tx_adr,int tx_val);
 void SEND_TO_HMI_(int tx_adr,int tx_val);
 void send_tx_queue_hmi_communication(void);



																																				 #ifdef __cplusplus
}
#endif
#endif /*__dguscommunication_H*/
