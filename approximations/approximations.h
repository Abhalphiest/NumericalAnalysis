// 
// File:	approximations.h
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis HW 2
//
// This is a header file for a set of functions that calculate
// various approximations for a set of 2D points
//

#ifndef APPROXIMATION
#define APPROXIMATION

#define pi 3.141592653589793

#include<math.h>
#include<stdlib.h>
#include <gsl/gsl_linalg.h> //for cubic spline linear algebra solver
#include<string.h>

#define NATURAL 1
#define CURVEADJUSTED 2
#define CLAMPED 3
#define PARABOLIC 4
#define NOTAKNOT 5

typedef struct point{double x,y;} Point;

double* cubicSpline(int n, int boundcondition, 
		double c1, double c2, Point* points);
double splint(double* y_p, int n, Point* points, double xval);

double Tnx(int n, double x);
double* chebyshev_coeff(double a, double b, int n, double (*f)(double));
double chebyshev(double a, double b, int n, double* c, double x);

double lagrangePoly(int n, Point* points, double xval);

Point bezier(int n, Point* points, double t);

#endif
