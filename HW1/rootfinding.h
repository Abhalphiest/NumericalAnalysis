//
// File:	rootfinding.h
// 
//
//

#include<stdio.h>
#include<math.h>

#define ACC .000000001 //8 digits
#define MAX_ITER 500 //maximum number of iterations we'll allow

double bisection(double(*f)(double),double a, double b);
double secant(double(*f)(double),double a, double b);
double FPI(double (*g)(double),double a);
double falseposition(double(*f)(double),double a, double b);
double newton1D();
double newton2d();
void header(char* name);
