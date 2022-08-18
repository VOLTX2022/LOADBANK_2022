#include "pid_handler.h"
#include "pid.h"
#include "configration.h"
#include "hmi_handler.h"
#include "arrays_calibration_firing.h"
//#include "firing.h"

extern double R_fine_tune_total;
extern uint16_t max_allowed_voltage;

extern PIDController pid ;	

uint8_t new_pid_entry;

void PID_Parameter_values()
{

	pid.Kp=0.1f;// 1.2f;
	pid.Ki=0.01f;
	pid.Kd= 250.0f;
//		pid.Kp=pid_kp; 
//	  pid.Ki=pid_ki;
//	  pid.Kd=pid_kd;


	/* Derivative low-pass filter time constant */
	pid.tau=0.01f;//50hz 10ms =0.02 sec

	/* Output limits */
	pid.limMin=-300.0f;
	pid.limMax=1300.0f;
	
	/* Integrator limits */
	pid.limMinInt=-300.0f;
	pid.limMaxInt=1300.0f;


	/* Sample time (in seconds) */
	pid.T= 1.0/100.0f ; 

	


}



/*

this function call the pid and give it the
arguments:
1-pid structure which determine pid parameter like kp ki kd 
2-user input SETTING (required value)
3-current measurement
and store pid output at pid_timer_steps to be used in the firring

*/


	 

		
void PID_Initiation()
{
		PID_Parameter_values();
	  PIDController_Init(&pid);

}



 //
