#include "IIC.h"


void delayMicroseconds(uint32_t us)
{
    __IO uint32_t currentTicks = SysTick->VAL;
  /* Number of ticks per millisecond */
  const uint32_t tickPerMs = SysTick->LOAD + 1;
  /* Number of ticks to count */
  const uint32_t nbTicks = ((us - ((us > 0) ? 1 : 0)) * tickPerMs) / 1000;
  /* Number of elapsed ticks */
  uint32_t elapsedTicks = 0;
  __IO uint32_t oldTicks = currentTicks;
  do {
    currentTicks = SysTick->VAL;
    elapsedTicks += (oldTicks < currentTicks) ? tickPerMs + oldTicks - currentTicks :
                    oldTicks - currentTicks;
    oldTicks = currentTicks;
  } while (nbTicks > elapsedTicks);
}

//�޸���ʱ��Сͨ���ӳ�
void I2c_Soft_delay()
{ 
//	for(int i=0;i<1;i++);
	delayMicroseconds(3);
}



int I2c_Soft_Start()
{
	SDA_H;
	SCL_H;
	I2c_Soft_delay();
	if(!SDA_read)return 0;	//SDA��Ϊ�͵�ƽ������æ,�˳�
	SDA_L;
	I2c_Soft_delay();
	if(SDA_read) return 0;	//SDA��Ϊ�ߵ�ƽ�����߳���,�˳�
	SDA_L;
	I2c_Soft_delay();
	return 1;	

}

void I2c_Soft_Stop()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_L;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SDA_H;
	I2c_Soft_delay();
}

void I2c_Soft_Ask()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_L;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SCL_L;
	I2c_Soft_delay();
}

void I2c_Soft_NoAsk()
{
	SCL_L;
	I2c_Soft_delay();
	SDA_H;
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	SCL_L;
	I2c_Soft_delay();
}

int I2c_Soft_WaitAsk(void) 	 //����Ϊ:=1��ASK,=0��ASK
{
  uint8_t ErrTime = 0;
	SCL_L;
	I2c_Soft_delay();
	SDA_H;			
	I2c_Soft_delay();
	SCL_H;
	I2c_Soft_delay();
	if(SDA_read)
	{
		ErrTime++;
		if(ErrTime>200)
		{
			I2c_Soft_Stop();
			return 1;
		}
	}
	SCL_L;
	I2c_Soft_delay();
	return 0;
}

void I2c_Soft_SendByte(uint8_t SendByte) //���ݴӸ�λ����λ//
{
    uint8_t i=8;
    while(i--)
    {
        SCL_L;
        I2c_Soft_delay();
      if(SendByte&0x80)
        SDA_H;  
      else 
        SDA_L;   
        SendByte<<=1;
        I2c_Soft_delay();
				SCL_H;
				I2c_Soft_delay();
    }
    SCL_L;
}  

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
uint8_t I2c_Soft_ReadByte(uint8_t ask)  //���ݴӸ�λ����λ//
{ 
    uint8_t i=8;
    uint8_t ReceiveByte=0;

    SDA_H;				
    while(i--)
    {
      ReceiveByte<<=1;      
      SCL_L;
      I2c_Soft_delay();
			SCL_H;
      I2c_Soft_delay();	
      if(SDA_read)
      {
        ReceiveByte|=0x01;
      }
    }
    SCL_L;

	if (ask)
		I2c_Soft_Ask();
	else
		I2c_Soft_NoAsk();  
    return ReceiveByte;
} 

// IICдһ���ֽ�����
uint8_t IIC_Write_1Byte(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t REG_data)
{
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1);   
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address);       
	I2c_Soft_WaitAsk();	
	I2c_Soft_SendByte(REG_data);
	I2c_Soft_WaitAsk();   
	I2c_Soft_Stop(); 
	return 0;
}

// IIC��1�ֽ�����
uint8_t IIC_Read_1Byte(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t *REG_data)
{      		
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address);     
	I2c_Soft_WaitAsk();
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1 | 0x01);
	I2c_Soft_WaitAsk();
	*REG_data= I2c_Soft_ReadByte(0);
	I2c_Soft_Stop();
	return 0;
}	

// IICдn�ֽ�����
uint8_t IIC_Write_nByte(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t len, uint8_t *buf)
{	
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address); 
	I2c_Soft_WaitAsk();
	while(len--) 
	{
		I2c_Soft_SendByte(*buf++); 
		I2c_Soft_WaitAsk();
	}
	I2c_Soft_Stop();
	return 0;
}
uint8_t mpu_test;
// IIC��n�ֽ�����
uint8_t IIC_Read_nByte(uint8_t SlaveAddress, uint8_t REG_Address, uint8_t len, uint8_t *buf)
{	
	mpu_test = I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1); 
	if(I2c_Soft_WaitAsk())
	{
		I2c_Soft_Stop();
		return 1;
	}
	I2c_Soft_SendByte(REG_Address); 
	I2c_Soft_WaitAsk();
	
	I2c_Soft_Start();
	I2c_Soft_SendByte(SlaveAddress<<1 | 0x01); 
	I2c_Soft_WaitAsk();
	while(len) 
	{
		if(len == 1)
		{
			*buf = I2c_Soft_ReadByte(0);
		}
		else
		{
			*buf = I2c_Soft_ReadByte(1);
		}
		buf++;
		len--;
	}
	I2c_Soft_Stop();
	return 0;
}


