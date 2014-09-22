#include "safwat_math.h"
#include <stdio.h>
double pi=3.1415926535897;
double tau=2*3.1415926535897;
double atseret_5=1.0*2*3*4*5;
double atseret_9=1.0* 2*3*4*5*6*7*8*9;
double atseret_13=1.0* 2*3*4*5*6*7*8*9*10*11*12*13;



void safwat_math_init_cyclic_map()
{
	cyclic[0]=0;
	cyclic[1]=1;
	int i,n;
	int current_power;
	for (i=1;i<8;i++)
	{
		current_power=safwat_pow(2,i);
		for (n=0;n<current_power;n++)
		{
			cyclic[current_power+n]=cyclic[current_power-n-1]+current_power;
			
		}
	}

}
int safwat_pow(int base,int power)
{
	int i;
	int num=1;
	for (i=0;i<power;i++)
	{
		num*=base;
	}
	return num;
}
double safwat_sin(double x)
{
	if (x>tau)
	{
		int rotations=(int)(x/tau); 
		x=x-tau*rotations;
	}
	else if (x<tau)
	{
		x=x*-1;
		int rotations=(int)(x/tau); 
		x=x-tau*rotations;
		x=x*-1;
	}
	double x2 = x*x;
	double x4 = x2*x2;
	double t1 = x * (1.0 - x2 / (2*3));
	double x5 = x * x4;
	double t2 = x5 * (1.0 - x2 / (6*7)) / (atseret_5);
	double x9 = x5 * x4;
	double t3 = x9 * (1.0 - x2 / (10*11)) / (atseret_9);
	double x13 = x9 * x4;
	double t4 = x13 * (1.0 - x2 / (14*15)) / (atseret_13);
	double result = t4;
	result += t3;
	result += t2;
	result += t1;
	return result;
}
double safwat_abs(double num)
{
	if (num<0) return -num;
	return num;
}
