#ifndef _BMI055_H
#define _BMI055_H

#include "stm32f0xx_hal.h"
#include "main.h"



//base configure parameter
#define ACC_CHIP	0XFA
#define GYRO_CHIP 0X0F
#define ACC_RANGE_2G 	0X03
#define ACC_RANGE_4G 	0X05
#define ACC_RANGE_8G 	0X08
#define ACC_RANGE_16G 0X0C
#define ACC_BW_125HZ 	0X0C
#define ACC_BW_250HZ 	0X0D
#define ACC_BW_500HZ 	0X0E
#define ACC_BW_1000HZ 0X0F

#define GYRO_RANGE_2000 	0X00
#define GYRO_RANGE_1000 	0X01
#define GYRO_RANGE_500 		0X02
#define GYRO_RANGE_250 		0X03
#define GYRO_BW_200HZ 	0X04
#define GYRO_BW_400HZ 	0X03
#define GYRO_BW_1000HZ 	0X02
#define GYRO_BW_2000HZ 	0X01


//ACC REG
//Read only
#define ACC_CHIP_ID 		0x00
#define ACC_X_LSB 			0x02 
#define ACC_X_MSB 			0x03
#define ACC_Y_LSB 			0x04
#define ACC_Y_MSB 			0x05
#define ACC_Z_LSB 			0x06
#define ACC_Z_MSB 			0x07
#define ACC_TEMP 				0x08
//read and write
#define ACC_RANGE 			0x0F					//加速度计量程
#define ACC_BW 					0x10					//加速度计滤波器带宽
#define ACC_MODE 				0x11					//加速度计运行模式 



//GYRO REG
//Read only
#define GYRO_CHIP_ID 		0x00
#define GYRO_X_LSB 			0x02 
#define GYRO_X_MSB 			0x03
#define GYRO_Y_LSB 			0x04
#define GYRO_Y_MSB 			0x05
#define GYRO_Z_LSB 			0x06
#define GYRO_Z_MSB 			0x07
#define GYRO_TEMP 			0x08
//read and write
#define GYRO_RANGE 			0x0F					//陀螺仪量程
#define GYRO_BW 				0x10					//陀螺仪滤波器带宽
#define GYRO_MODE 			0x11					//陀螺仪运行模式 


void Bmi055Configure();
void AccRead();
void GyroRead();
void Bmi055WriteReg(uint8_t reg,uint8_t data);
void Bmi055ReadSingleReg(uint8_t reg,uint8_t *data);
void Bmi055ReadMultiReg(uint8_t reg,uint8_t *data,uint8_t length);
void kf_imu(float *Acc,float *Gyro);

#endif