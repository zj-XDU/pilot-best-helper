#include "TempControl.h"
#include "Cmath.h"
#include <math.h>


float x1,x2;
int test1 = 0,test2 = 0;
float err,errLast;
uint32_t output_temp = 0;
uint16_t TempPidCal(PidClass *tempCal,float set,float ref)
{
	
	static float inter_err = 0;
	{
			err = set - ref;
//			output_temp += (tempCal->kp + err * 100)*err + tempCal->kd * (err - errLast);
			TD2_Track(err);
//			inter_err+=x1;
//			if(inter_err>100)
//				inter_err = 100;
//			else if(inter_err<-100)
//				inter_err = -100;
		
//			//Êä³öÏÞ·ù
//			if(x1> 0.0f)
//			{
//				if(x1 > 2.0f)
//					output_temp = tempCal->maxOutput;
//				else if(x1>1.0f)
//					output_temp = tempCal->maxOutput*0.75;
//				else if(x1 > 0.2)
//				{	
//					output_temp = tempCal->maxOutput;
//				}
//				else
//				{
//					
//					if(x2>0)
//						test1 = -10*tempCal->kd;
//					else
//						test1 = 10*tempCal->kd;
////					output_temp = 4700;
////					test1 = (err - errLast)*tempCal->kd ;
//					output_temp += tempCal->kp * x1 +test1;
//					
//					if(output_temp > tempCal->maxOutput)
//					{
//							output_temp = tempCal->maxOutput;
//					}	
//					else if(output_temp < 100.0f)
//					{
//							output_temp = 100.0f;
//					}

//				}
//			}
//			else 
//			{
//				if(x1 < -2.0f)
//					output_temp = 100;
//				else if(x1<-1.0f)
//					output_temp = 100;	
//				else if(x1<-0.2f)
//				{
//					output_temp = 100;
//				}
//				else
//				{
//					if(x2>0)
//						test2 = -10*tempCal->kd;
//					else
//						test2 = 10*tempCal->kd;
////						output_temp = 4400;
////					test2 = *tempCal->kd;
//					output_temp += tempCal->kp * x1 + test2;
//					
//					if(output_temp > tempCal->maxOutput*0.65)
//					{
//							output_temp = tempCal->maxOutput*0.65;
//					}	
//					else if(output_temp < 100.0f)
//					{
//							output_temp = 100.0f;
//					}	
//				}
//			}	
			
			
//					if(x2>0)
						test1 = x2*tempCal->kd;
//					else
//						test1 = -10*tempCal->kd;

					output_temp += tempCal->kp * x1 +test1;
					
					if(output_temp > tempCal->maxOutput)
					{
							output_temp = tempCal->maxOutput;
					}	
					else if(output_temp < 100.0f)
					{
							output_temp = 100.0f;
					}		
					
					if(x1>1.5)
						output_temp = tempCal->maxOutput;

			tempCal->output = output_temp;
			errLast = err;
			
	}
	
	
	return tempCal->output;
}


#define H 0.012
float fsg(float x,float dd)
{
	return (fsign(x + dd) - fsign(x - dd))/2;
}


float fhan(float x1,float x2,float r,float h)
{
	float d  =  r*h*h;
	float a0 = h * (x2);
	float y = x1 + a0;
	float a1 = SquareRootFloat(d*d + 8 * d * f_abs(y));
	float a2 = a0 + fsign(y)*(a1 - d)/2;
	float a = (a0 + y) * fsg(y,d) + a2 * (1 - fsg(y,d)); 
	return -r * (a/d) *fsg(a,d) - r * fsign(a) *(1 - fsg(a,d));
};



void TD2_Track(float temp_ref)
{
	float fh = fhan(x1 - temp_ref,x2,1,H);
	x1 = x1 + H * x2;
	x2 = x2 + H *fh;


}