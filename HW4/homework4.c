//
// File;	homework4.c
//
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 4
//
// This file contains a program that calculates the solutions to the
// problems of homework 4.

#include"ODE.h"
#include<stdio.h> //for input and output
#include<math.h>

double prob1f(double t, double y)
{
 return t*exp(3*t)-2*y;
}
double prob2f(double t, double y)
{
 return 1+ y/t;

}
double prob3f(double t, double y)
{
 return pow(t,-2)*(sin(2*t)-2*t*y);
}

int main()
{




 return 0;
}
