#include "pid.h"


#define UNPUSHED 0

/*
this function init the pid firing with array values
*/
PIDController pid ;	
void PIDController_Init(PIDController *pid)
{
		
  pid->integrator = 0;
	pid->prevError  = 0.0f;

	pid->differentiator  = 0.0f;
	pid->prevMeasurement = 0.0f;

	pid->out = 0;

}
/*

this function update the pid values depending on kp ki kd 
arguments:
1-pid structure which determine pid parameter like kp ki kd 
2-setpoint  user input SETTING (required value)
3-measurement

return pid output at pid_timer_steps to be used in the firring


*/
float PIDController_Update(PIDController *pid, float setpoint, float measurement) {
	
	
//	if(CURRENT_PROCEED_FLAG==UNPUSHED)
//	{
//	  setpoint=0;
//	
//	}

	/*
	* Error signal
	*/
    float error = setpoint - measurement;

	

	/*
	* Proportional
	*/
    float proportional = pid->Kp * error;
/*

	*/
	/*
	* Integral
	*/
    pid->integrator = pid->integrator + 0.5f * pid->Ki * pid->T * (error + pid->prevError);

	/* Anti-wind-up via integrator clamping */
    if (pid->integrator > pid->limMaxInt) {

        pid->integrator = pid->limMaxInt;

    } else if (pid->integrator < pid->limMinInt) {

        pid->integrator = pid->limMinInt;

    }


	/*
	* Derivative (band-limited differentiator)
	*/
		
    pid->differentiator = -(2.0f * pid->Kd * (measurement - pid->prevMeasurement)	/* Note: derivative on measurement, therefore minus sign in front of equation! */
                        + (2.0f * pid->tau - pid->T) * pid->differentiator)
                        / (2.0f * pid->tau + pid->T);


	/*
	* Compute output and apply limits
	*/
    pid->out = proportional + pid->integrator + pid->differentiator;

    if (pid->out > pid->limMax) {

        pid->out = pid->limMax;

    } else if (pid->out < pid->limMin) {

        pid->out = pid->limMin;

    }

	/*	int modulus= error;
	if (modulus<0)
		{
			modulus=modulus*(-1);
		}
		if (modulus<=4)
		{
			error=error+error*0.5;
			measurement=AC_Current_Setting;
		}*/
		
	/* Store error and measurement for later use */
    pid->prevError       = error;
    pid->prevMeasurement = measurement;

	/* Return controller output */
    return pid->out;

}
