


#ifndef __queue_dgus_rx_H
#define __queue_dgus_rx_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
struct messege 
{
	int address;
	int value;
}; 
	 
struct messege Dequeue(void);
void Enqueue(int,int);
char IsEmpty(void);
		struct messege read_next_address_without_dequeue(void); 
	 	 #ifdef __cplusplus
}
#endif
#endif /*__queue_dgus_rx__H*/


 
