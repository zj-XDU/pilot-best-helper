#ifndef _I2C_H
#define	_I2C_H

#include "stm32f0xx_hal.h"
#include "main.h"

/***************I2C GPIO¶¨Òå******************/
#define IIC_GPIO	GPIOB
#define SCL_PIN		GPIO_PIN_13
#define SDA_PIN		GPIO_PIN_12
/*********************************************/
//#define SCL_H         IIC_GPIO->BSRR = SCL_PIN
//#define SCL_L         IIC_GPIO->BRR  = SCL_PIN
//#define SDA_H         IIC_GPIO->BSRR = SDA_PIN
//#define SDA_L         IIC_GPIO->BRR  = SDA_PIN
//#define SCL_read      IIC_GPIO->IDR  & SCL_PIN
//#define SDA_read      IIC_GPIO->IDR  & SDA_PIN

#define SCL_H         HAL_GPIO_WritePin(IIC_GPIO, SCL_PIN, GPIO_PIN_SET)
#define SCL_L         HAL_GPIO_WritePin(IIC_GPIO, SCL_PIN, GPIO_PIN_RESET)
#define SDA_H         HAL_GPIO_WritePin(IIC_GPIO, SDA_PIN, GPIO_PIN_SET)
#define SDA_L         HAL_GPIO_WritePin(IIC_GPIO, SDA_PIN, GPIO_PIN_RESET)
#define SCL_read      HAL_GPIO_ReadPin(IIC_GPIO, SCL_PIN)
#define SDA_read      HAL_GPIO_ReadPin(IIC_GPIO, SDA_PIN)



void IIC_Init(void);
uint8_t IIC_Write_1Byte(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t REG_data);
uint8_t IIC_Read_1Byte(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t *REG_data);
uint8_t IIC_Write_nByte(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t len, uint8_t *buf);
uint8_t IIC_Read_nByte(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t len, uint8_t *buf);
void I2c_Soft_delay();



#endif
