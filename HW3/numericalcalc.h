//
//
// File:	numericalcalc.h
//
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 3
//

#include<math.h>
#include<stdio.h>

void fivePointStencil(double* x, double* y, int n);
double simpson(double (*f)(double), double a, double b, int n);
double trapezoid(double (*f) (double), double a, double b, int n);
double romberg(double (*f)(double), double a, double b, int n, int m);
