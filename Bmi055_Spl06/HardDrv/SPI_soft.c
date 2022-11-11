#include "SPI_soft.h"




//work in model 4:	idle clock is high and collect data in up edge

//work in 16 bits data model
//data transmit in MSB
void softSpiWriteSingle(uint8_t reg,uint8_t Txdata)
{
	BMI_SCK_H;
	
	//send reg
	for(uint8_t i=0;i<8;i++)
	{
		BMI_SCK_L;
		if(0x80&reg)
			BMI_MO_H;
		else
			BMI_MO_L;
		
		reg = reg<<1;
		BMI_SCK_H;
	}
	//send data
	for(uint8_t i=0;i<8;i++)
	{
		BMI_SCK_L;
		if(0x80&Txdata)
			BMI_MO_H;
		else
			BMI_MO_L;
		
		Txdata = Txdata<<1;
		BMI_SCK_H;		
	}	
}


void softSpiReadSingle(uint8_t reg,uint8_t *rcData)
{
	reg = 0x80|reg;
	BMI_SCK_H;
//	GPIOA->MODER &= 0<<7;
	//send reg
	for(uint8_t i=0;i<8;i++)
	{
		BMI_SCK_L;
		if(0x80&reg)
			BMI_MO_H;
		else
			BMI_MO_L;
		
		reg = reg<<1;
		BMI_SCK_H;
	}
	//read data
//	GPIOA->MODER |= 1<<7;
	uint8_t dataTemp = 0;
	for(uint8_t i=0;i<8;i++)
	{
		BMI_SCK_L;
		if(BMI_MO_STATE)
			dataTemp+=1;
		else
			dataTemp+=0;
		
		if(i<7)
			dataTemp = dataTemp<<1;
		BMI_SCK_H;		
	}	
	//update data
	*rcData = dataTemp;
}

void softSpiReadMulti(uint8_t reg,uint8_t *rcData,uint8_t length)
{
	
	if(length == 0)
		return ;
	
	
	reg = 0x80|reg;
	BMI_SCK_H;
//	GPIOA->MODER &= 0<<7;
	//send reg
	for(uint8_t i=0;i<8;i++)
	{
		BMI_SCK_L;
		if(0x80&reg)
			BMI_MO_H;
		else
			BMI_MO_L;
		
		reg = reg<<1;
		BMI_SCK_H;
	}

	//read data
//	GPIOA->MODER |= 1<<7;
	for(uint8_t j=0;j<length;j++)
	{
		uint8_t dataTemp = 0;
		for(uint8_t i=0;i<8;i++)
		{
			BMI_SCK_L;
			if(BMI_MO_STATE)
				dataTemp+=1;
			else
				dataTemp+=0;
			
			if(i<7)
				dataTemp = dataTemp<<1;
			BMI_SCK_H;		
		}	
		//update data
		*rcData = dataTemp;	
		rcData ++;
	}

	
}








