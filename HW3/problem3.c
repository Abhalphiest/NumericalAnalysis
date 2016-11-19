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

Point* magtoLuminosity( Point* points, int n);

double* x;
double* y;
double* magnitudespline;
double* luminosityspline;
Point* points;
Point* luminosities;
int n;

double f(double val)
{
 for(int i = 0; i < n; i++)
 {
  if(fabs(val-x[i]) < .00001)
	return y[i];
 }
 //shouldn't ever fire ideally
 printf("non-data value requested \n");
 return 0; //garbage value
}

double magf(double val)
{
 double mag = splint(magnitudespline,n,points,val);
 return 85.5*pow(10,-.4*mag);
}

double lumf(double val)
{
 return splint(luminosityspline,n,luminosities,val);
}

int main()
{
 //get data
 printf("n: ");
 scanf("%d", &n);
 x = (double*) malloc(sizeof(double)*n);
 y = (double*) malloc(sizeof(double)*n);
 for(int i = 0; i < n; i++)
 {
   scanf("%lf %lf",x+i,y+i);
 }

 //numerically integrate
 double simpresult, trapresult;
 simpresult = simpson(f,0,1,5);
 trapresult = trapezoid(f,0,1,10);

 printf("Simpson's: %lf \t Trapezoid: %lf \n",simpresult, trapresult);

 points = (Point*) malloc(sizeof(Point)*n);
 for(int i = 0; i < n; i++)
 {
  points[i].x = x[i];
  points[i].y = y[i];
 }
 //construct natural cubic spline
 magnitudespline = cubicSpline(n, NATURAL, 0,0, points);
 //converted to luminosity in the function given to simpson
 //integrate numerically
 double magnituderesult = simpson(magf,0,1,20);
 
 //convert data to luminosities
 luminosities = magtoLuminosity(points,n);
  
 //make cubic spline
 luminosityspline = cubicSpline(n,NATURAL,0,0,luminosities);
 //integrate numerically
 double luminosityresult = simpson(lumf,0,1,20);
 //print results
 printf("Total Emitted Energy from Magnitude Spline: %lf\n",magnituderesult);
 printf("Total Emitted Energy from Luminosity Spline: %lf\n",luminosityresult);

 //free memory
 free(x);
 free(y);
 free(points);
 free(luminosities);
 free(magnitudespline);
 free(luminosityspline);
}

Point* magtoLuminosity(Point* points, int n)
{
 Point* luminosities = (Point*) malloc(sizeof(Point)*n);
 for(int i = 0; i < n; i++)
 {
  luminosities[i].x = points[i].x;
  luminosities[i].y = 85.5*pow(10,-.4*points[i].y);
 }
 return luminosities;
}
