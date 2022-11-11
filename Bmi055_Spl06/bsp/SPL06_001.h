#ifndef SPL06_01_H
#define SPL06_01_H

#include "stm32f0xx_hal.h"


unsigned char spl0601_init(void);

float user_spl0601_get_presure(float temprature);
float user_spl0601_get_temperature(void);
#endif

