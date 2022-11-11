#ifndef __CMATH_H
#define __CMATH_H

#include "main.h"

#define Lut_Num 512									
#define PI 3.14159265358979f
#define PI2 (PI*2)							
#define PI23 (PI2/3)						
#define Fast_fabs(a)  a*(1-2*(a<0))

/**
 * @brief   Sin function look up table
 * @param   theta:angle value in radius
 * @note
 */
float SinTable(float theta);

/**
 * @brief   Cos function look up table
 * @param   theta:angle value in radius
 * @note
 */
float CosTable(float theta);

/**
 * @brief   find the minium value among the three
 * @param   [x,y,z] is the three compare value
 * @note
 */
float fminf3(float x, float y, float z);

/**
 * @brief find the maximum value in two
 * @param
 * @note
 */
float fmaxf(float x, float y);

/**
 * @brief   find the minimum value in two
 * @param
 * @note
 */
float fminf(float x, float y);

/**
 * @brief   find the maximum value among three
 * @param
 * @note
 */
float fmaxf3(float x, float y, float z);

/**
 * @brief   one level digital lowpast filter
 * @param   vi:input value
 * @param   Vo:value after filting
 * @param   Vo_p:past value of output,just for update
 * @param   sampleFrq:Sample Frquency of sampler
 * @param   CutFrq:stop freqnency
 * @note
 */
void LowPassFilter_RC_1order(float *Vi, float *Vo, float *Vo_p, float sampleFrq ,float CutFrq);

/**
 * @brief   Scales the lenght of vector (x, y) to be <= limit
 * @param   x:x value
 * @param   y:y value
 * @param   limit:the maximum value of the sum of x and y
 * @note
 */
void limit_norm(float *x, float *y, float limit);

/**
 * @brief   in words
 * @param
 * @note
 */
float uint8_to_float(uint8_t *BUFFER);

float uint_to_float(int x_int, float x_min, float x_max, int bits);

int float_to_uint(float x, float x_min, float x_max, int bits);

uint8_t Get_Crc8(uint8_t *ptr,uint16_t len);
float f_abs(float temp);
float SquareRootFloat(float number);
float fsign(float x);
#endif
