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

double* magToLuminosity(double* x, double* y, int n);

int main()
{
 //get data
 int n;
 printf("n: ");
 scanf("%d", &n);
 double* x, y;
 x = (double*) malloc(sizeof(double)*n);
 y = (double*) malloc(sizeof(double)*n);
 for(int i = 0; i < n; i++)
 {
   scanf("%lf %lf",x+i,y+i);
 }

 //numerically integrate
 double simpresult, trapresult;
 simpresult = simpson(x,y,n);
 trapresult = trapezoid(x,y,n);

 printf("Simpson's: %lf \t Trapezoid: %lf \n");

 //construct natural cubic spline



 //print out spline function


 //convert data to luminosities
 double* luminosities;
 luminosities = magtoLuminosity(x,y,n);
 

 //make cubic spline


 //print out spline function


}
