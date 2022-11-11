#include "Cmath.h"
#include "lut.h"
#include "stdio.h"
#include <math.h>
int M;
const int Val = Lut_Num/4;
float SinTable(float theta)
{
	while(theta > PI2)
	{
		theta -= PI2;
	}
	M = (int)(theta/PI2*Lut_Num);
	return sinlut1[M];
}


float CosTable(float theta)
{
	while(theta > PI2)
	{
		theta -= PI2;
	}
	return SinTable(theta + 1.57079632679f);
}

float fmaxf(float x, float y){
    /// Returns maximum of x, y ///
    return (((x)>(y))?(x):(y));
    }

float fminf(float x, float y){
    /// Returns minimum of x, y ///
    return (((x)<(y))?(x):(y));
    }

float fmaxf3(float x, float y, float z){
    /// Returns maximum of x, y, z ///
    return (x > y ? (x > z ? x : z) : (y > z ? y : z));
    }

float fminf3(float x, float y, float z){
    /// Returns minimum of x, y, z ///
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
    }


void limit_norm(float *x, float *y, float limit){
    float norm = sqrt(*x * *x + *y * *y);
    if(norm > limit){
        *x = *x * limit/norm;
        *y = *y * limit/norm;
        }
    }

void LowPassFilter_RC_1order(float *Vi, float *Vo, float *Vo_p, float sampleFrq ,float CutFrq)
{
  float  RC, Cof1;
    
  //low pass filter @cutoff frequency = 1 Hz    
  RC = (float)1.0f/2.0f/PI/CutFrq;
  Cof1 = 1/(1+RC*sampleFrq);
  //Cof2 = RC*sampleFrq/(1+RC*sampleFrq);// no problem
  *Vo = Cof1 * (*Vi) + (1.0f-Cof1) * (*Vo_p);    
  
  //update  
  *Vo_p = *Vo;    
}

int float_to_uint(float x, float x_min, float x_max, int bits){
  /// Converts a float to an unsigned int, given range and number of bits ///
  float span = x_max - x_min;
  float offset = x_min;
  return (int) ((x-offset)*((float)((1<<bits)-1))/span);
}

float uint_to_float(int x_int, float x_min, float x_max, int bits){
  /// converts unsigned int to float, given range and number of bits ///
  float span = x_max - x_min;
  float offset = x_min;
  return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}

float uint8_to_float(uint8_t *BUFFER)
{
	uint8_t lenght = 2;
	uint16_t mask = 1<<(lenght*8-1);
	uint16_t Total = BUFFER[0]|(BUFFER[1]<<8);
	printf("%x",Total);
	float ret;
	if(mask&Total)
	{
		Total ^= mask;
		ret = -(float)Total;
	}else{
		ret = (float)Total;
	}
	return ret;
}

//CRC8校验
//ptr:要校验的数组
//len:数组长度
//返回值:CRC8码
//多项式0X31,LSB First，初始值0X00
uint8_t Get_Crc8(uint8_t *ptr,uint16_t len)
{
  uint8_t crc;
  uint8_t i;
  crc=0;
  while(len--)
  {
    crc^=*ptr++;
    for(i=0;i<8;i++)
    {
      if(crc&0x01)crc=(crc>>1)^0x8C;
      else crc >>= 1;
    }
  }
  return crc;
}

float f_abs(float temp)
{
	if(temp<0)
		return -temp;
	else
		return temp;
}

float SquareRootFloat(float number)

{
    long i;
    float x, y;
    const float f = 1.5F;

    x = number * 0.5F;

    y  = number;

    i  = * ( long * ) &y;

    i  = 0x5f3759df - ( i >> 1 );  //卡马克

  //i  = 0x5f375a86 - ( i >> 1 );  //Lomont

    y  = * ( float * ) &i;

    y  = y * ( f - ( x * y * y ) );

    y  = y * ( f - ( x * y * y ) );

    return number * y;
}

//float atan2f(float y, float x, int infNum)  
//{  
//    int i;  
//    float z = y / x, sum = 0.0f,temp;  
//    float del = z / infNum;  
//      
//    for (i = 0; i < infNum;i++)  
//    {  
//        z = i*del;  
//        temp = 1 / (z*z + 1) * del;  
//        sum += temp;  
//    }  
//              
//    if (x>0)  
//    {  
//        return sum;  
//    }  
//    else if (y >= 0 && x < 0)  
//    {  
//        return sum + PI;  
//    }  
//    else if (y < 0 && x < 0)  
//    {  
//        return sum - PI;  
//    }  
//    else if (y > 0 && x == 0)  
//    {  
//        return PI / 2;  
//    }  
//    else if (y < 0 && x == 0)  
//    {  
//        return -1 * PI / 2;  
//    }  
//    else  
//    {  
//        return 0;  
//    }  
//}  

float fsign(float x)
{
	if(x>0)
		return 1;
	else if(x == 0)
		return 0;
	else
		return -1;
}