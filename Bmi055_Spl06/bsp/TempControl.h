#ifndef _TEMPCONTROL_H
#define _TEMPCONTROL_H


#include "stm32f0xx.h"


typedef struct
{
	uint16_t output,maxOutput;
	float kp;
	uint32_t kd;
}PidClass;


uint16_t TempPidCal(PidClass *tempCal,float set,float ref);
void TD2_Track(float temp_ref);


#endif