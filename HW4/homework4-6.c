// File:	homework4-6.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 4 Problem 6
//

#include"ODE.h"
#include<stdio.h>
#include<math.h>

#define h .05

double f(double t, double y)
{
 return t*exp(3*t)-2*y;
}

double solution(double t)
{
 return 1.0/5.0*t*exp(3*t)-1.0/25.0*exp(3*t)+1.0/25.0*exp(-2*t);

}
int main()
{
 double t0 = 0, y0 = 0;
 double solY[5];
 for(int i = 0; i< 5; i++)
 {
  solY[i] = solution(t0+i*h);
 }
 double rkResult = AdamsMoulton(f,t0, y0, 2, h);
 double solResult = AdamsMoultonInit(f,t0,solY,2,h);
  
 printf("RK4 Initialization:\t%.9lf\n",rkResult);
 printf("Solution Initialization:\t%.9lf\n",solResult);
 printf("Actual Value:\t%.9lf\n",solution(2));
 return 0;

}
