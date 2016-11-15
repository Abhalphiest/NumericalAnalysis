// 
// File:	problem2.c
//
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 3 Problem 2

#include<stdio.h>
#include<stdlib.h> //for rand
#include<math.h> //for trig
#include<numericalcalc.h>
#define PI 3.14159265359

const double a = 0;
const double b = PI;
const double h;

double f(double x){return sin(x)*exp(cos(x));}

double g(double x)
{
 
}

double* constructData(int n, double left, double right);
int main ()
{
 int n;
 printf("n: ");
 scanf("%d", &n);
 
 double testpoints = constructData(n,0,PI);
 double sresult = simpson(testpoints, testpoints+n, n);
 printf("Simpson's Method: %lf \n",sresult);
 if(n < 5)
 {
  printf("Need at least 5 points to use 5 point stencil");
  return -1;
 }
 printf("Five Point Stencil Differentiation: \n");
 fivePointStencil(testpoints, testpoints+n, n);

 
 return 0;
}
