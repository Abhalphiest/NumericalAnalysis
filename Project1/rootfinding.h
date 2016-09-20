//
// File:	rootfinding.h
// 
//
//

#include<stdio.h>
#include<math.h>

#define ACC .00000000001 //10 digits
#define MAX_ITER 50000 //maximum number of iterations we'll allow

double bisection(double(*f)(double),double a, double b);
double secant(double(*f)(double),double a, double b);
double FPI(double (*g)(double),double a);
double falseposition(double(*f)(double),double a, double b);
double newton1D(double(*f)(double),double(*f_prime)(double), double x,int max_iter);
void newton2D(double(*f)(double, double),double(*f_x)(double, double), 
		double(*f_y)(double, double), double(*g)(double, double),
		double(*g_x)(double, double),double(*g_y)(double, double),
		double x, double y, int max_iter);
void header(char* name);
