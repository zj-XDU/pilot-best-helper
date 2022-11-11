#ifndef _SPI_SOFT_H
#define	_SPI_SOFT_H

#include "stm32f0xx_hal.h"
#include "main.h"


#define BMI055_CS_GPIO	GPIOB
#define Acc_CS_PIN		GPIO_PIN_1
#define Gyro_CS_PIN		GPIO_PIN_0

#define Acc_CS_H         HAL_GPIO_WritePin(BMI055_CS_GPIO, Acc_CS_PIN, GPIO_PIN_SET)
#define Acc_CS_L         HAL_GPIO_WritePin(BMI055_CS_GPIO, Acc_CS_PIN, GPIO_PIN_RESET)

#define Gyro_CS_H         HAL_GPIO_WritePin(BMI055_CS_GPIO, Gyro_CS_PIN, GPIO_PIN_SET)
#define Gyro_CS_L         HAL_GPIO_WritePin(BMI055_CS_GPIO, Gyro_CS_PIN, GPIO_PIN_RESET)

#define BMI055_GPIO	GPIOA
#define BMI_SCK		GPIO_PIN_5
#define BMI_MI		GPIO_PIN_6
#define BMI_MO		GPIO_PIN_7

#define BMI_SCK_H         HAL_GPIO_WritePin(BMI055_GPIO, BMI_SCK, GPIO_PIN_SET)
#define BMI_SCK_L         HAL_GPIO_WritePin(BMI055_GPIO, BMI_SCK, GPIO_PIN_RESET)

#define BMI_MI_STATE      HAL_GPIO_ReadPin(BMI055_GPIO, BMI_MI)


#define BMI_MO_H         HAL_GPIO_WritePin(BMI055_GPIO, BMI_MO, GPIO_PIN_SET)
#define BMI_MO_L         HAL_GPIO_WritePin(BMI055_GPIO, BMI_MO, GPIO_PIN_RESET)
#define BMI_MO_STATE     HAL_GPIO_ReadPin(BMI055_GPIO, BMI_MO)


void softSpiReadSingle(uint8_t reg,uint8_t *rcData);
void softSpiReadMulti(uint8_t reg,uint8_t *rcData,uint8_t length);
#endif
