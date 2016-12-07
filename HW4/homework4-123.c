//
// File;	homework4-123.c
//
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 4
//
// This file contains a program that calculates the solutions to the first 3
// problems of homework 4.

#include"ODE.h"
#include<stdio.h> //for input and output
#include<math.h>

double prob1f(double t, double y)
{
 return t*exp(3*t)-2*y;
}
double prob2f(double t, double y)
{
 return 1+ y/t;

}
double prob3f(double t, double y)
{
 return pow(t,-2)*(sin(2*t)-2*t*y);
}
//exact solutions for the ODEs to check error
double prob1sol(double t)
{
	return 1/25.0*(exp(-2*t)*(exp(5*t)*(5*t - 1) + 1));
}
double prob2sol(double t)
{
	return 2*t + t*log(t);
	
}
double prob3sol(double t)
{
	return .5*pow(t,-2)*(-cos(2*t)+4+cos(2));
}
int main()
{
	double errbound = pow(10,-6);
	double x,y,step;
	int flag = 0;
	//eq 1
	int nEuler_1, nRK2_1, nRK4_1;	
	//euler
	nEuler_1 = 4580600;
	while(flag == 0)
	{
		flag = 1;
		nEuler_1++;
		step = 1.0/nEuler_1;
		y = Euler(prob1f,0,0,1,step);
		if(fabs(y-prob1sol(1))>errbound)
			flag = 0;
	}
	
	flag = 0;
//	printf("RK2\n");	
	//RK2
	nRK2_1 = 0;
	while(flag == 0)
	{
	  nRK2_1++;
	  step = 1.0/nRK2_1;
	  flag = 1;
	  y = RK2(prob1f,0,0,1,step);
	  if(fabs(y-prob1sol(1))>errbound)
	    flag = 0;
	}
		
	
	flag =0;
	//RK4
//	printf("RK4\n");
	nRK4_1 = 0;
	while(flag == 0)
	{
		nRK4_1 ++;
		step = 1.0/nRK4_1;
		flag = 1;
		y = RK4(prob1f,0,0,1,step);
		if(fabs(y-prob1sol(1))>errbound)
		  flag = 0;
		
	}
	
	flag = 0;
	//eq 2
	int nEuler_2, nRK2_2, nRK4_2;	
	//euler
	nEuler_2 = 500000;
	while(flag == 0)
	{
		flag = 1;
		nEuler_2++;
		step = 1.0/nEuler_2;
		y = Euler(prob2f,1,2,2,step);
		if(fabs(y-prob2sol(2))>errbound)
			flag = 0;
	}
	
	flag = 0;
//	printf("RK2\n");	
	//RK2
	nRK2_2 = 0;
	while(flag == 0)
	{
	  nRK2_2++;
	  step = 1.0/nRK2_2;
	  flag = 1;
	  y = RK2(prob2f,1,2,2,step);
	  if(fabs(y-prob2sol(2))>errbound)
	    flag = 0;
	}
		
	
	flag =0;
	//RK4
//	printf("RK4\n");
	nRK4_2 = 0;
	while(flag == 0)
	{
		nRK4_2 ++;
		step = 1.0/nRK4_2;
		flag = 1;
		y = RK4(prob2f,1,2,2,step);
		if(fabs(y-prob2sol(2))>errbound)
		  flag = 0;
		
	}
	
	
	flag = 0;
	//eq 3
	int nEuler_3, nRK2_3, nRK4_3;	
	//euler
	nEuler_3 = 535400;
	while(flag == 0)
	{
		flag = 1;
		nEuler_3++;
		step = 1.0/nEuler_3;
		y = Euler(prob3f,1,2,2,step);
		if(fabs(y-prob3sol(2))>errbound)
			flag = 0;
	}
	
	flag = 0;
	//RK2
	nRK2_3 = 0;
	while(flag == 0)
	{
	  nRK2_3++;
	  step = 1.0/nRK2_3;
	  flag = 1;
	  y = RK2(prob3f,1,2,2,step);
	  if(fabs(y-prob3sol(2))>errbound)
	    flag = 0;
	}
		
	
	flag =0;
	//RK4
	nRK4_3 = 0;
	while(flag == 0)
	{
		nRK4_3 ++;
		step = 1.0/nRK4_3;
		flag = 1;
		y = RK4(prob3f,1,2,2,step);
		if(fabs(y-prob3sol(2))>errbound)
		  flag = 0;
		
	}
 printf("Equation 1: \n");
 printf("Euler: %d \t RK2: %d \t RK4: %d \n\n",nEuler_1,nRK2_1,nRK4_1);
 printf("Equation 2: \n");
 printf("Euler: %d \t RK2: %d \t RK4: %d \n\n",nEuler_2,nRK2_2,nRK4_2);
 printf("Equation 3: \n");
 printf("Euler: %d \t RK2: %d \t RK4: %d \n",nEuler_3,nRK2_3,nRK4_3);
 return 0;
}