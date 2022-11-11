#include "Bmi055.h"
#include "spi.h"
#include "string.h"
#include "SPI_soft.h"
#include "stdio.h"
#include <math.h>
#include "Cmath.h"

#define KF_IMU_DT    0.005f

/*private variable define*/
struct 
{
	float pit,rol,yaw;
	float rate_pit,rate_rol,rate_yaw;
	int16_t ACC_raw[3],GYRO_raw[3];
}imu_data;
float GYRO_bias[3],ACC_bias[3];
uint8_t Acc_id,Gyro_Id,cali_status = 1;
//imu kf used data
typedef struct
{
	float Q_angle,Q_gyro,R_angle;
	float Q_bias[2];
	float pk[2][2];
	float K[2];

}kf_imu_Data;
//view for kf imu data
kf_imu_Data kf_pit,kf_rol;
/*private variable define*/


/*private function define*/
static void DecodeAcc(int16_t *accData,uint16_t *dataAccRaw);
static void imu_cali();
/*private function define*/



//imu configure
void Bmi055Configure()
{
	Gyro_CS_H;
	//ACC range config
	Acc_CS_L;
	Bmi055WriteReg(ACC_RANGE,ACC_RANGE_2G);
	Acc_CS_H;
	
	//ACC Baudwidth config
	Acc_CS_L;
	Bmi055WriteReg(ACC_BW,ACC_BW_125HZ);
	Acc_CS_H;
	
//	Acc_CS_L;
//	Bmi055WriteReg(0x13,0x80);
//	Acc_CS_H;
		
	Acc_CS_L;
	Bmi055ReadSingleReg(0x00,&Acc_id);
	Acc_CS_H;
	
	HAL_Delay(100);
		
	Acc_CS_H;
	Gyro_CS_L;
	//GYRO range config
	Bmi055WriteReg(GYRO_RANGE,GYRO_RANGE_2000);
	Gyro_CS_H;
	
	//GYRO Baudwidth config
	Gyro_CS_L;
	Bmi055WriteReg(GYRO_BW,GYRO_BW_400HZ);
	Gyro_CS_H;
	
	Gyro_CS_L;
	Bmi055ReadSingleReg(GYRO_CHIP,&Gyro_Id);
	Gyro_CS_H;	
	
	HAL_Delay(100);
	imu_cali();
	
	
	memset(&imu_data,0,sizeof(imu_data));
	memset(&kf_pit,0,sizeof(kf_imu_Data));
	memset(&kf_rol,0,sizeof(kf_imu_Data));
	kf_pit.Q_angle = 0.07;
	kf_pit.Q_gyro = 0.07;
	kf_pit.R_angle = 0.07;
	kf_rol.Q_angle = 0.07;
	kf_rol.Q_gyro = 0.07;
	kf_rol.R_angle = 0.07;
}

static uint8_t IMU_temprature;
void AccRead(float *ACC_deal)
{
		uint8_t ACC_data[7];
		Gyro_CS_H;
		Acc_CS_L;
		Bmi055ReadMultiReg(ACC_X_LSB, ACC_data,6);
		Acc_CS_H;
		
		static uint16_t ACC_raw_temp[3];
    ACC_raw_temp[0] = (uint16_t)ACC_data[2]<<4 | ACC_data[1]>>4;
    ACC_raw_temp[1] = (uint16_t)ACC_data[4]<<4 | ACC_data[3]>>4;
    ACC_raw_temp[2] = (uint16_t)ACC_data[6]<<4 | ACC_data[5]>>4;	
	
		DecodeAcc(imu_data.ACC_raw,ACC_raw_temp);
	
		for(uint8_t i=0;i<3;i++)
		{
			ACC_deal[i] = (float)imu_data.ACC_raw[i]/1024.0f;
		}
//		Acc_CS_L;
//		Bmi055ReadSingleReg(0x08, &IMU_temprature);
//		Acc_CS_H;
} 

void GyroRead(float *GYRO_deal)
{
		uint8_t GYRO_data[7];
		Acc_CS_H;
		Gyro_CS_L;
		Bmi055ReadMultiReg(GYRO_X_LSB, GYRO_data,6);
		Gyro_CS_H;
		memcpy(imu_data.GYRO_raw,&GYRO_data[1],6);
		float GYRO_temp[3];
		for(uint8_t i=0;i<3;i++)
		{
			GYRO_temp[i] = (float)imu_data.GYRO_raw[i] * 2000 / 32768 - GYRO_bias[i];
			
			if(!cali_status)
			{
				//非校准模式
				//陀螺仪测量不可信死区
				if(f_abs(GYRO_temp[i])>1.0f)
					GYRO_deal[i] = GYRO_temp[i];
				else
					GYRO_deal[i] = 0;			
			}
			else
					//校准模式
					GYRO_deal[i] = GYRO_temp[i];
		}
}

#define cali_length  30000
float gyro_cali[3],gyro_cali_total[3];
static void imu_cali()
{
	
	for(uint16_t i=0;i<cali_length;i++)
	{
		GyroRead(gyro_cali);
		for(uint8_t j=0;j<3;j++)
			gyro_cali_total[j] += gyro_cali[j];
	}
	cali_status = 0;
	
	for(uint8_t i=0;i<3;i++)
		GYRO_bias[i] = gyro_cali_total[i]/cali_length;

};


void Bmi055WriteReg(uint8_t reg,uint8_t data)
{
	uint8_t dataSend[2] = {reg,data};
	HAL_SPI_Transmit(&hspi1, dataSend, 2,0x4);
}


void Bmi055ReadSingleReg(uint8_t reg,uint8_t *data)
{
	reg = 0x80|reg;
	uint8_t dataTemp[2];
	HAL_SPI_TransmitReceive(&hspi1, &reg, dataTemp,2,0x4);
	*data = dataTemp[1];
}

void Bmi055ReadMultiReg(uint8_t reg,uint8_t *data,uint8_t length)
{
	reg = 0x80|reg;
	HAL_SPI_TransmitReceive(&hspi1,&reg,data,length+1,0x4);
}



//12位二进制补码转十进制数字
static void DecodeAcc(int16_t *accData,uint16_t *dataAccRaw)
{
	uint16_t accDataTemp[3];
	
	//判断是否为正数
	for(uint8_t i=0;i<3;i++)
	{
		if(*dataAccRaw&2048)
		{
			//负数
			*accData = -(~*dataAccRaw - 61439);
		}
		else
		{
			//正数
			*accData = *dataAccRaw;
		}
		accData++;
		dataAccRaw++;
	}
	
}



void kf_imu(float *Acc,float *Gyro)
{
		//predict
		//角度
		float pit_p,rol_p;
		pit_p = imu_data.pit + (Gyro[0] - kf_pit.Q_bias[0])*KF_IMU_DT;
		rol_p = imu_data.rol + (Gyro[1] - kf_rol.Q_bias[1])*KF_IMU_DT;
		imu_data.yaw = imu_data.yaw + (Gyro[2])*KF_IMU_DT;
	
		//加速度计观测得到pit and rol
		float R_pit,R_rol;
		R_pit = (-atan2f(Acc[0],SquareRootFloat(Acc[1]*Acc[1] + Acc[2]*Acc[2])))*180/3.1415;
		R_rol = atan2f(Acc[1],Acc[2])*180/3.1415;
		
	
		//协方差
		kf_pit.pk[0][0] += (kf_pit.Q_angle - kf_pit.pk[0][1] - kf_pit.pk[1][0]) * KF_IMU_DT;
		kf_pit.pk[0][1] += (- kf_pit.pk[1][1]) * KF_IMU_DT;
		kf_pit.pk[1][0] += (- kf_pit.pk[1][1]) * KF_IMU_DT;
		kf_pit.pk[1][1] += (kf_pit.Q_gyro) * KF_IMU_DT;
	
		kf_rol.pk[0][0] += (kf_rol.Q_angle - kf_rol.pk[0][1] - kf_rol.pk[1][0]) * KF_IMU_DT;
		kf_rol.pk[0][1] += (- kf_rol.pk[1][1]) * KF_IMU_DT;
		kf_rol.pk[1][0] += (- kf_rol.pk[1][1]) * KF_IMU_DT;
		kf_rol.pk[1][1] += (kf_rol.Q_gyro) * KF_IMU_DT;	

		
		//KF增益
		kf_pit.K[0] = kf_pit.pk[0][0] / (kf_pit.R_angle + kf_pit.pk[0][0]);
		kf_pit.K[1] = kf_pit.pk[1][0] / (kf_pit.R_angle + kf_pit.pk[0][0]);
		kf_rol.K[0] = kf_rol.pk[0][0] / (kf_rol.R_angle + kf_rol.pk[0][0]);
		kf_rol.K[1] = kf_rol.pk[1][0] / (kf_rol.R_angle + kf_rol.pk[0][0]);
	
	
		//update
		//协方差
		kf_pit.pk[0][0] -= kf_pit.K[0]*kf_pit.pk[0][0];
		kf_pit.pk[0][1] -= kf_pit.K[0]*kf_pit.pk[0][1];
		kf_pit.pk[1][0] -= kf_pit.K[1]*kf_pit.pk[0][0];
		kf_pit.pk[1][1] -= kf_pit.K[1]*kf_pit.pk[0][1];

		kf_rol.pk[0][0] -= kf_rol.K[0]*kf_rol.pk[0][0];
		kf_rol.pk[0][1] -= kf_rol.K[0]*kf_rol.pk[0][1];
		kf_rol.pk[1][0] -= kf_rol.K[1]*kf_rol.pk[0][0];
		kf_rol.pk[1][1] -= kf_rol.K[1]*kf_rol.pk[0][1];

		//状态量
		imu_data.pit += kf_pit.K[0]*(R_pit - pit_p);
		imu_data.rol += kf_rol.K[0]*(R_rol - rol_p);
		kf_pit.Q_bias[0] += kf_pit.K[1]*(R_pit - pit_p);
		kf_rol.Q_bias[0] += kf_rol.K[1]*(R_rol - rol_p);
		
//		printf("%f,%f,%f\n",imu_data.pit,imu_data.rol,imu_data.yaw);
		
}