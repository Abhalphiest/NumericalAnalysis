// File:	homework4-5.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 4 Problem 5
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
 double rkResult = AdamsBashforth(f,t0, y0, 2, h);
 double solResult = AdamsBashforthInit(f,t0,solY,2,h);
 printf("%lf\n",RK4(f,t0,y0,2,h)); 
 printf("RK4 Initialization:\t%lf\n",rkResult);
 printf("Solution Initialization:\t%lf\n",solResult);
 printf("Actual Value:\t%lf\n",solution(2));
 return 0;

}
