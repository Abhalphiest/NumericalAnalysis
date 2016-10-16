#include<stdio.h>
#include <stdlib.h> //for quick sort

void evenPoints(double xstart, double xend);
void printPoints(Point* points, int n);
Point* findActual(Point* points, int n);
Point* makePoints(double xstart,double xend, int npoints);
double* chebyshevMidpoints(double xstart,double xend, int n);
