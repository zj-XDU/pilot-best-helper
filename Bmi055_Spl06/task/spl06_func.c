#include "main.h"
#include "stm32f0xx_it.h"
#include <stdio.h>
#include "SPL06_001.h"
#include "Cmath.h"
#include "tim.h"


#ifdef temprature_control_open
#include "TempControl.h"
extern PidClass TempPid;
extern float x1,x2;
extern int test1,test2;
uint16_t tempControl = 300;
#endif

struct
{
	float temperature,temperature_filter,temperature_last;//读取的温度值 单位℃摄氏度
	float presure;//温度补偿后的气压值 单位mpar 毫帕
	float baro_height;//解算后的气压高度值，单位cm毫米
	float height_cm_filter,height_cm_filter_last;
}heightManager;



//10ms
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim3);
//		TIM14->CNT = 0;
		
		float temp_temp = 0;
		temp_temp = user_spl0601_get_temperature();
		if(f_abs(temp_temp)<100)
			heightManager.temperature = temp_temp;
		LowPassFilter_RC_1order(&heightManager.temperature, &heightManager.temperature_filter, &heightManager.temperature_last, 128 ,0.1);
		
		
		heightManager.presure = user_spl0601_get_presure(heightManager.temperature_filter);			 
		heightManager.baro_height = (float)((102000.0f	- heightManager.presure) * 78.740f)/10;  //每1mpar平均海拔高度为78.740mm
		LowPassFilter_RC_1order(&heightManager.baro_height, &heightManager.height_cm_filter, &heightManager.height_cm_filter_last, 128 ,0.1);

		
		#ifdef temprature_control_open
			tempControl = TempPidCal(&TempPid,36,heightManager.temperature);
			TIM1->CCR1 = tempControl;
		#endif
		
//		uint16_t run_time_temp = TIM14->CNT;	
//		printf("run_us=%d\n",run_time_temp);
//		printf("%f,%f,%f,%f\n",heightManager.height_cm_filter,heightManager.baro_height,heightManager.temperature,heightManager.temperature_filter);


}