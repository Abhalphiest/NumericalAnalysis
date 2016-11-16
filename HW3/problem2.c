// 
// File:	problem2.c
//
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 3 Problem 2

#include<stdio.h>
#include<stdlib.h> //for rand
#include<math.h> //for trig
#include"numericalcalc.h"
#define PI 3.14159265359

double* data;
int n;

double f(double x){return sin(x)*exp(cos(x));}

double g(double x) //kind of a hacky way to add noise, but..
{
 for(int i = 0; i < n; i++) 
 {
  if(fabs(x - data[i]) < .0000001) //account for floating point error
	return data[i+n];
 }
 return f(x); //we weren't at any of the noisy data points
}

double* constructData(int n, double left, double right);
int main ()
{
 printf("n: ");
 scanf("%d", &n);
 
 data = constructData(n,0,PI);
 double sresult = simpson(g,0,PI, n);
 printf("Simpson's Method: %lf \n",sresult);
 if(n < 5)
 {
  printf("Need at least 5 points to use 5 point stencil");
  return -1;
 }
 printf("Five Point Stencil Differentiation: \n");
 fivePointStencil(data, data+n, n);

 free(data);
 return 0;
}

double* constructData(int n, double left, double right)
{
 double h = (right - left)/n;
 double* data = (double*)malloc(sizeof(double)*2*n);
 double x = left;
 for(int i = 0; i < n; i++)
 {
  data[i] = x;
  data[i+n] = f(x)+rand();
  x+=h;
 }
 return data;
}
