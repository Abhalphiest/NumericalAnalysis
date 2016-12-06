// File:	homework4-4.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 4 Problem 4
//

#include"ODE.h"
#include<stdio.h>
#include<math.h>

void system(double t, double y, double z, double* y_out, double* z_out)
{
	*y_out = z;
	*z_out = 2*t*z - 2* y;
	
}

double calcRelError(double approx, double actual)
{
	return (approx - actual)/actual;
}

int main()
{
 double errlimit = pow(10, -8);
 double solution = 1.5366381359854324545862339712537521842841999519459 * pow(10,9);
	
 int numsteps = 0;
 double step, y;
 int flag = 0;
 while(flag == 0)
 {
	flag = 1;
	numsteps++;
	step = 1.0/numsteps;
	y = RK4_2(system,0,1,1,5,step);
	if(calcRelError(y,solution) > errlimit)
	{
	 flag = 0;	
	}
 }
 printf("y is calculated as %lf in %d steps.\n",y,numsteps);
	
 return 0;	
}