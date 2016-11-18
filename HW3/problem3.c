// 
// File:	problem3.c
//
// Author:	Margaret Dorsey
//
// MATH411 Homework 3 Problem 3
//

#include"numericalcalc.h"
#include"approximations.h"
#include<stdio.h>

double* magToLuminosity( double* y, int n);

double* x;
double* y;
int n;

double f(double val)
{
 for(int i = 0; i < n; i++)
 {
  if(fabs(val-x[i]) < .00001)
	return y[i];
 }
 //shouldn't ever fire ideally
 printf("non-data value requested \n");
 return 0; //garbage value
}

int main()
{
 //get data
 printf("n: ");
 scanf("%d", &n);
 x = (double*) malloc(sizeof(double)*n);
 y = (double*) malloc(sizeof(double)*n);
 for(int i = 0; i < n; i++)
 {
   scanf("%lf %lf",x+i,y+i);
 }

 //numerically integrate
 double simpresult, trapresult;
 simpresult = simpson(f,0,1,5);
 trapresult = trapezoid(f,0,1,10);

 printf("Simpson's: %lf \t Trapezoid: %lf \n");

 //construct natural cubic spline



 //integrate numerically
 

 //convert to luminosity

 
 //convert data to luminosities
 double* luminosities;
 luminosities = magtoLuminosity(y,n);
 

 //make cubic spline


 //integrate numerically

 
 //print results
}
