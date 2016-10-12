// 
// File:	approximations.h
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis HW 2
//
// This is a header file for a set of functions that calculate
// various approximations for a set of 2D points
//

#include<math.h>
#include<stdlib.h>
#include <gsl/gsl_linalg.h> //for cubic spline linear algebra solver

#define NATURAL 1
#define CURVEADJUSTED 2
#define CLAMPED 3
#define PARABOLIC 4
#define NOTAKNOT 5

typedef struct point{double x,y;} Point;

void cubicSpline(int n, int boundcondition, double c1, double c2, Point* points);

double Tnx(int n, double x){return cos(n*acos(x));}
void chebyshev(int n);

double lagrangePoly(int n, Point* points, double xval);

double bezier(int n, Point* points, double tval);
