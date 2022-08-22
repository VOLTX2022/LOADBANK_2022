#include "hmi_communication.h"
#include "usart.h"
#include "main.h"
#include "hmi_handler.h"
#include "configration.h"
#include "queue_dgus_rx.h"
#include "hmi_handler.h"
//Start of HMI UART part

//End of HMI UART part

//Start of HMI UART part

volatile uint8_t FRAMES_RX_FLAG=0        ;
 int     Address = 0             ;
volatile int     Value   = 0             ;
volatile uint8_t rx_buff=0               ;
volatile uint8_t rx_array[arraywidth]={0};
volatile uint8_t write                   ;
volatile uint8_t rx_flag                 ;
volatile uint8_t rx_state                ;
volatile uint8_t rx_value                ;
volatile uint32_t i                      ;
volatile uint8_t UART_SendValue          ; 
volatile uint8_t read=0                  ;
volatile uint8_t	tx_buff=0               ;
uint8_t text_array[]={"                       Input Current :"};
int tx_adr_val_2d_array[max_no_of_message][2];
uint8_t prevent_sending_to_hmi_flag=0;

                                             
/*******                      (START)                     ********* */

/*********                      OF                         **********/
/********                                                 ***********/
/*                           (HMI PART)                            */
  

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{ 
	static uint8_t messege_arranger_flag=0;
	static uint8_t  messege_arranger_arr_1=0;
	static uint8_t  messege_arranger_arr_2=1;
	 
	 	rx_array[write]= rx_buff;	
	

	  rx_flag++;
	
		 
	 write++;
	 
	 
if(messege_arranger_flag==0)
{messege_arranger_arr_1=rx_buff;	
messege_arranger_flag=1;
}
else
{messege_arranger_arr_2=rx_buff;	
messege_arranger_flag=0;
}
	
	
	
	 if(((messege_arranger_arr_1==0xA5)&&(messege_arranger_arr_2==0x5A))||((messege_arranger_arr_2==0xA5)&&(messege_arranger_arr_1==0x5A)))
	 { 
		 write=2;
	   rx_array[0]=0xA5;
		 rx_array[1]=0x5A;
	   rx_flag=2;
		 read=0;
	 
	 }
	  //
	 	 if (write>=9 )
	 {
		 FRAMES_RX_FLAG=1;
	
	 }
	}

	void SerialEvent(void)
{
  int iLen;
  uint8_t iData[255];
  int iTmp;
  int iAdr, iVal;
	
  if (rx_flag > 8)
  {    read=0;
      if (rx_array[read] == 0xA5)
			{rx_flag--;
				read++;

      if (rx_array[read]== 0x5A)
      { rx_flag--;
				read++;

        iLen =rx_array[read];
				 rx_flag--;
				read++;

        iTmp = 0;
				
        // while (rx_flag < iLen) to Wait for all frame !!!! Blocking procedure

        while (iTmp < iLen) //Compile all frame
        {
          iData[iTmp] = rx_array[read];
					rx_flag--;
				 	read++;
          iTmp++;
        }

        iAdr = (iData[1] << 8) + iData[2];
        iVal = (iData[4] << 8) + iData[5];

        Address = iAdr;
        Value = iVal;
  
        displayed_hmi_values[Address]= Value;
	    
			HMI_Addresses();

      }
		}
  }
}








/***********************************************************/
//uint8_t beep_transmitter_buff[6]={0xA5,0x5A,0x03,0x80,0x02,100};
//void DGUS_Beep(uint8_t bTime) // Beep generate bTime*10ms
//{
//	
//	beep_transmitter_buff[5]=bTime;
//	HAL_UART_Transmit_DMA(&hal_hmi_uart,beep_transmitter_buff,6); 	
//  HAL_Delay(2);
//}



////////////////////////////
// void DGUS_SendVal ----> is used in the following macros
/*
SEND_TO_HMI(addr1,val1)
SEND_TO_HMI(addr1,val1,addr2,val2)  
HMI_DISPLAY_3(addr1,val1,addr2,val2,addr3,val3)   
HMI_DISPLAY_4(addr1,val1,addr2,val2,addr3,val3,addr4,val4)  
HMI_DISPLAY_5(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5)   
HMI_DISPLAY_6(addr1,val1,addr2,val2,addr3,val3,addr4,val4,addr5,val5,addr6,val6) 
*/

/*
void DGUS_SendVal(int(*iAdr)[2], uint8_t x) //Send iVal for VP= iAdr to DGUS
{// int i=0;
//if(prevent_sending_to_hmi_flag==0)
	uint8_t send_dma_buff[max_no_of_message*message_size]={0};
{
	if (x>max_no_of_message)
	{ 
		x=max_no_of_message;
	}
  uint8_t bAdrL[x];
	uint8_t bAdrH[x];
	uint8_t bValL[x];
	uint8_t bValH[x];
	for(int i=0;i<x;i++)
	{
  bAdrL[i] = iAdr[i][0] & 0xFF;
  bAdrH[i] = (iAdr[i][0] >> 8) & 0xFF;
  bValL[i] = iAdr[i][1] & 0xFF;
  bValH[i] = (iAdr[i][1] >> 8) & 0xFF;
	
	
  send_dma_buff[0+(message_size*i)]=0xA5;
  send_dma_buff[1+(message_size*i)]=0x5A;
  send_dma_buff[2+(message_size*i)]=0x05;
  send_dma_buff[3+(message_size*i)]=0x82;
  send_dma_buff[4+(message_size*i)]=bAdrH[i];
  send_dma_buff[5+(message_size*i)]=bAdrL[i];
  send_dma_buff[6+(message_size*i)]=bValH[i];
  send_dma_buff[7+(message_size*i)]=bValL[i];
	}
		HAL_UART_Transmit_DMA(&hal_hmi_uart,send_dma_buff,8*x);
	  HAL_Delay(2);
}
}
*/

uint8_t problem=0;
void start_hmi_uart(void)
{
  HAL_UART_Receive_DMA(&hal_hmi_uart,(uint8_t*)&rx_buff,sizeof(rx_buff)); 
}
// uint8_t block_enqueue=0;
extern uint8_t enque_counter;
 void SEND_TO_HMI (int tx_adr,int tx_val)
 {  
	 if((tx_adr==beepbeep)||(tx_adr==text))
	 {
	 enque_counter++;
	
	
   Enqueue(tx_adr,tx_val);
	
	

   }
	 else if (displayed_hmi_values[tx_adr]!= tx_val)
	  {
	 enque_counter++;
	
	{
   Enqueue(tx_adr,tx_val);
	
	}

}
	 
 }
 
 uint8_t block_sending=0;
 	uint8_t no_of_messeges=1;
void send_tx_queue_hmi_communication()//time based
{ 
	static   uint8_t send_dma_buff[100]; //it must be static or global
  struct messege messege;
	 struct messege READ;

	if(IsEmpty()!=1)
	{ 
	 messege= Dequeue();
		if(messege.address!=0)
		{
	 if(messege.address==beepbeep)
	   {
		   send_dma_buff[0]=0xA5;
       send_dma_buff[1]=0x5A;
       send_dma_buff[2]=0x03;
       send_dma_buff[3]=0x80;
       send_dma_buff[4]=0x02;
       send_dma_buff[5]=messege.value;//beep value
			 
			 HAL_UART_Transmit_DMA(&hal_hmi_uart,send_dma_buff,6);
		
		 }
		 else if(messege.address==text)
		 { uint8_t bAdrL=0;
	     uint8_t bAdrH=0;
			 bAdrL = text_notification_window_address & 0xFF;
       bAdrH = (text_notification_window_address >> 8) & 0xFF;
			 send_dma_buff[0]=0xA5;                      //welcome msg
	     send_dma_buff[1]=0x5A;                      //welcome msg
	     send_dma_buff[2]=6+sizeof(text_array) ;     //length of the msg
	     send_dma_buff[3]=0x82;                      //writing a string into DGUS SRAM
			 send_dma_buff[4]=bAdrH;                     //Address is divided into 2 bytes 
       send_dma_buff[5]=bAdrL;                     //the second half of the address
			 for(int i =6;i<(6+sizeof(text_array));i++)
			 {
				 send_dma_buff[i]=text_array[i-6];
			 }
			 HAL_UART_Transmit_DMA(&hal_hmi_uart,send_dma_buff,sizeof(send_dma_buff));
			 
			 // i think it is enogh to send  (sizeof(text_array) + 6) but iwill not change it without trying or check which is smaller like this
			 //if ((sizeof(text_array) + 6)< sizeof(send_dma_buff) ) send (sizeof(text_array) + 6)
			 //if ((sizeof(text_array) + 6)> sizeof(send_dma_buff) ) send sizeof(send_dma_buff) 
			
		 }
	 else
		 {
	     uint8_t bAdrL=0;
	     uint8_t bAdrH=0;
       uint8_t bValL=0;
	     uint8_t bValH=0;
       bAdrL = messege.address & 0xFF;
       bAdrH = ( messege.address >> 8) & 0xFF;
       bValL =  messege.value & 0xFF;
       bValH= (messege.value>> 8) & 0xFF;
	     send_dma_buff[0]=0xA5;
       send_dma_buff[1]=0x5A;
       send_dma_buff[2]=0x05;
       send_dma_buff[3]=0x82;
       send_dma_buff[4]=bAdrH;
       send_dma_buff[5]=bAdrL;
       send_dma_buff[6]=bValH;
       send_dma_buff[7]=bValL;
			 displayed_hmi_values[messege.address]=messege.value;
			 READ= read_next_address_without_dequeue(); //dnot read( after dequeue && before sending) but read before dequeue.
			 for(int i=0;i<6;i++)// dont increase 10 as send_dma_buff has 100 element
			 {
			 if((IsEmpty()==0)&&(READ.address!=beepbeep)&&(READ.address!=text))
			 {
	      messege= Dequeue();
				
				
			 bAdrL = messege.address & 0xFF;
       bAdrH = ( messege.address >> 8) & 0xFF;
       bValL =  messege.value & 0xFF;
       bValH= (messege.value>> 8) & 0xFF;
	     send_dma_buff[0+(8*no_of_messeges)]=0xA5;
       send_dma_buff[1+(8*no_of_messeges)]=0x5A;
       send_dma_buff[2+(8*no_of_messeges)]=0x05;
       send_dma_buff[3+(8*no_of_messeges)]=0x82;
       send_dma_buff[4+(8*no_of_messeges)]=bAdrH;
       send_dma_buff[5+(8*no_of_messeges)]=bAdrL;
       send_dma_buff[6+(8*no_of_messeges)]=bValH;
       send_dma_buff[7+(8*no_of_messeges)]=bValL;
				 no_of_messeges++; 
				 displayed_hmi_values[messege.address]=messege.value;
		   
			 }
			 else
       {
			   break;
			 }
		  }
			 HAL_UART_Transmit_DMA(&hal_hmi_uart,send_dma_buff,8*no_of_messeges);
			 no_of_messeges=1;
		 }
	 
	 }
	}
	


}



// End of HMI UART part
