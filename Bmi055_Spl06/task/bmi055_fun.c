#include "main.h"
#include "stm32f0xx_it.h"
#include <stdio.h>
#include "tim.h"
#include "Bmi055.h"
#include "MahonyAHRS.h"

uint16_t run_time_imu;
float ACC_deal[3],GYRO_deal[3];
#define Gravity 0.98f

//5ms
void TIM16_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim16);
	
		TIM14->CNT = 0;
		AccRead(ACC_deal);
		GyroRead(GYRO_deal);
//		MahonyAHRSupdateIMU(GYRO_deal[0],GYRO_deal[1],GYRO_deal[2],ACC_deal[0],ACC_deal[1],ACC_deal[2]);
		kf_imu(ACC_deal,GYRO_deal);
//		delayMicroseconds(1000);

		run_time_imu = TIM14->CNT;	
//		printf("run_us=%d\n",run_time_temp);
} 







