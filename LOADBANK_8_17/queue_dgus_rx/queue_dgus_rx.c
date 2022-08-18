#include "queue_dgus_rx.h"
#define MAX_SIZE_OF_QUEUE 101  //maximum size of the array that will store Queue. 
#define true  1
#define false 0
uint8_t error_flag=0;	

struct messege A[MAX_SIZE_OF_QUEUE];
int messeges_count=0;

// Constructor - set front and rear_flashing as -1. 
// We are assuming that for an empty Queue, both front and rear_flashing will be -1.

	int front=-1;
  int rear=-1;
	

	// To check wheter Queue is empty or not
	char IsEmpty()
	{ if (messeges_count==0)
		{return 1;}
			else
			{return 0;} 
	}

	// To check whether Queue is full or not
	char IsFull()
	{if (messeges_count==MAX_SIZE_OF_QUEUE)
		{return 1;}
			else
			{return 0;} 
	}

	
	int search_on_queue(int x,int y)
	{ 
		if(front<rear)
		{
		   for(int i =front;i<=rear;i++)
		  {
		   if((A[i].address == x)&&(A[i].value == y))
			 {
			  return 1;
			 }
		  }
			  return 0;
		}
		else if(front>rear)
		{
			   for(int i =0;i<=rear;i++)
		  {
		   if((A[i].address == x)&&(A[i].value == y))
			 {
			  return 1;
			 }
		  }
			
			   for(int i =front;i<MAX_SIZE_OF_QUEUE;i++)
		  {
		   if((A[i].address == x)&&(A[i].value == y))
			 {
			  return 1;
			 }
		  }
			  return 0;
		
		}
		else //front = rear
    {
		  if((A[front].address == x)&&(A[front].value == y))
			 {
			  return 1;
			 }
			 else
       {
			 return 0;
			 }
		}
	
	}
	uint8_t block=0;
	// Inserts an element in queue at rear end
	void Enqueue(int x,int y)//x address and y value
	{block=1;
	if(0== search_on_queue(x,y))
	{if(IsFull()==1)
		{
		//	while(1);//error
			error_flag=1;
		}
		else if (IsEmpty()==1)
		{ 
			front =0;
			rear = 0; 
			messeges_count++;
			 A[rear].address = x;
		   A[rear].value = y;
		}
		else
		{ 
		    rear = (rear+1)%MAX_SIZE_OF_QUEUE;
				messeges_count++;
			 A[rear].address = x;
		   A[rear].value = y;
		}
		
	
		  
		
	
//		for(int f=front;f<messeges_count;f++) // PROTECTION AGAINST STUPID PEOPLE OR CODER
//		{
//		  if((A[f].address)==x)
//		  {messeges_count--;
//			 // A[f].address = x;
//		   A[f].value = y;
//				
//				
//		  }
//		 
//	   }
//	 
//		if(front>rear)
//		{
//		
//		
//		 for(int f=0;f<=rear;f++) // PROTECTION AGAINST STUPID PEOPLE OR CODER
//		{
//		  if((A[f].address)==x)
//		  {messeges_count--;
//			//  A[f].address = x;
//		   A[f].value = y;
//		  }
//		  
//	   }
//		}
	}
	block=0;
	}

	// Removes an element in Queue from front end.
  // Returns element at front of queue. 	
	struct messege Dequeue(void)
	{
		struct messege ELEMENT_TO_DEQUEUE;
		
		if(IsEmpty()==0)
		{
			
	
		 if(messeges_count==1) 
		{messeges_count--;
			ELEMENT_TO_DEQUEUE.address=A[front].address;
			ELEMENT_TO_DEQUEUE.value=A[front].value;
			rear = front = -1;
		}
		else
		{ messeges_count--;
			ELEMENT_TO_DEQUEUE.address=A[front].address;
			ELEMENT_TO_DEQUEUE.value=A[front].value;
			front = (front+1)%MAX_SIZE_OF_QUEUE;
		}
		
		
	}
		else
   {
	  ELEMENT_TO_DEQUEUE.address=0;
		 ELEMENT_TO_DEQUEUE.value=0;
	 }

			return ELEMENT_TO_DEQUEUE;
	}
	
	
		struct messege read_next_address_without_dequeue(void)
	{
		struct messege ELEMENT_TO_READ;
		
		if(IsEmpty()==0)
		{
			
	
			ELEMENT_TO_READ.address=A[front].address;
			ELEMENT_TO_READ.value=A[front].value;
		
		
	
		
	}
		else
   {
	  ELEMENT_TO_READ.address=0;
		 ELEMENT_TO_READ.value=0;
	 }

			return ELEMENT_TO_READ;
	}
//////////////////////////////////////////////////////////////////////////////////
//#define MAX_SIZE_OF_FLASHING_QUEUE 20  //maximum size of the array that will store Queue. 
//#define true 1
//#define false 0
//int flashing_messeges_count=0;

//	struct messege A_FLASHING[MAX_SIZE_OF_FLASHING_QUEUE];
//  	// Constructor - set front and rear as -1. 
//	// We are assuming that for an empty Queue, both front and rear will be -1.

//	int front_of_flashing=-1;
//  int rear_of_flashing=-1;
//	





//	// To check wheter Queue is empty or not
//	char IsEmpty_Flashing()
//	{ if (flashing_messeges_count==0)
//		{return 1;}
//			else
//			{return 0;} 
//	}

//	// To check whether Queue is full or not
//	char IsFull_Flashing()
//	{if (flashing_messeges_count==MAX_SIZE_OF_FLASHING_QUEUE)
//		{return 1;}
//			else
//			{return 0;} 
//	}

//	// Inserts an element in queue at rear_of_flashing end
//	void Enqueue(int x,int y)//x address and y value
//	{
//	
//		if(IsFull_Flashing()==1)
//		{
//			while(1);//error
//		}
//		else if (IsEmpty_Flashing()==1)
//		{ flashing_messeges_count++;
//			front_of_flashing =0;
//			rear_of_flashing = 0; 
//		}
//		else
//		{  flashing_messeges_count++;
//		    rear_of_flashing = (rear_of_flashing+1)%MAX_SIZE_OF_FLASHING_QUEUE;
//		}
//		
//		for(int f=0;f<flashing_messeges_count;f++)
//		{
//		 if(A_FLASHING[f].address==x)
//		 {messeges_count--;
//			 A_FLASHING[f].address = x;
//		   A_FLASHING[f].value = y;
//		 }
//		 else
//		 {
//		   A_FLASHING[rear_of_flashing].address = x;
//		   A_FLASHING[rear_of_flashing].value = y;
//		 }
//	}
//	}

//	// Removes an element in Queue from front_of_flashing end.
//  // Returns element at front_of_flashing of queue. 	
//	struct messege Dequeue_Flashing(void)
//	{
//		struct messege ELEMENT_TO_DEQUEUE;
//		
//		if(IsEmpty_Flashing()==0)
//		{
//			
//	
//		 if(flashing_messeges_count==1) 
//		{
//			ELEMENT_TO_DEQUEUE.address=A_FLASHING[front_of_flashing].address;
//			ELEMENT_TO_DEQUEUE.value=A_FLASHING[front_of_flashing].value;
//			rear_of_flashing = front_of_flashing = -1;
//		}
//		else
//		{ 
//			ELEMENT_TO_DEQUEUE.address=A_FLASHING[front_of_flashing].address;
//			ELEMENT_TO_DEQUEUE.value=A_FLASHING[front_of_flashing].value;
//			front_of_flashing = (front_of_flashing+1)%MAX_SIZE_OF_FLASHING_QUEUE;
//		}
//		flashing_messeges_count--;
//		
//	}
//	else 
//	{
//		 while(1);
//	}
//			return ELEMENT_TO_DEQUEUE;
//	}


/************************ (C)*END OF FILE****/
