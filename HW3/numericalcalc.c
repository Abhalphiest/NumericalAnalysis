//
// File:	numericalcalc.c
//
// Author:	Margaret Dorsey
//
// This file implements the functions in numericalcalc.h
//
// MATH 411 Numerical Analysis Homework 3
//
#include"numericalcalc.h"
#include<stdlib.h>
//prints its own output for now, for simplicity
void fivePointStencil(double* x, double* y, int n)
{
 if(n < 5) return; //can't do anything
 double h = fabs(x[1] - x[0]); //evenly spaced points
 double fprime;
 for(int i = 2; i + 2 < n; i++)
 {
  fprime = (-y[i+2] + 8*y[i+1] - 8*y[i-1] + y[i-2])/(12*h);
  printf("x:\t %lf \t f(x): \t %lf \t f'(x) \t %lf \n",x[i], y[i],fprime);
 }
 return;
}

void fivePointStencil2(double*x, double* y, int n)
{
 if(n<5) return;
 double h = fabs(x[1]-x[0]);
 double fprime;
 for(int i = 2; i + 2 < n; i++)
 {
  fprime = (-y[i+2]+16*y[i+1] - 30*y[i]  + 16*y[i-1] - y[i-2])/(12*h*h);
  printf("x:\t %lf \t f(x): \t %lf \t f''(x) \t %lf \n",x[i],y[i],fprime);
 }

 

}

double simpson(double (*f)(double), double a, double b, int n)
{
  if(n%2)
  {
   printf("n must be even for simpson's method \n");
   return 0;
  }
  double h = (b-a)/n;
  double s = f(a) + f(b);

  for(int i = 1; i < n; i+=2)
	s+= 4*f(a+i*h);
  for(int i = 2; i < n-1; i+=2)
	s+= 2*f(a+i*h);

  return s*h/3.0;
	
}

double trapezoid(double (*f)(double),double a, double b, int n)
{
 double h = (b-a)/n;
 double s = f(a)+f(b);
 for(int i = 1; i < n-1; i++)
	s+=f(a+i*h);
 s*= h/2;
 return s;
}

double romberg(double (*f)(double), double a, double b, int n, int m)
{
 //bad space complexity but our problems will be small
 //we technically only ever need to store two rows at a time
 double** T = (double**) malloc(sizeof(double*)*n+1);
 for(int i = 0; i <= n; i++)
   T[i] = (double*) malloc(sizeof(double)*m+1);

 
 double h = (b-a);
 T[0][0] = h*.5*(f(a)+f(b));
 int sumupper = 1;
 for(int i = 1; i <= n; i++)
 {
  T[i][0] = 0;
  h*=.5;
  for(int k = 1; k < sumupper; k++)
  {
   T[i][0] += f(a+(2*k-1)*h);
  }
  T[i][0]*=h;
  T[i][0]+= .5*T[i-1][0];
  
  for(int j = 1; j <= m; j++)
  {
   T[i][j] = T[i][j-1] + (T[i][j-1] - T[i-1][j-1])*(1/((2<<(m+1))-1));
  }
  sumupper*=2;
 }
 double result = T[n][m];
 for(int i = 0; i <= n; i++)
  free(T[i]);
 free(T);
 return T[n][m];
}


