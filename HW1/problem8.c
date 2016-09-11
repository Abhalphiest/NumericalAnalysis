/*
 * File:	problem8.c
 * Course:	MATH 411, Fall 2016
 * Author:	Margaret Dorsey
 * 
 * Homework 1 Problem 8
 *
 *
 * This file contains a program that attempts to approximate e^(3x) at 
 * a given point using the taylor series expansion.
 *
 */

#define TOL1 .000000001
#define TOL2 .000000000000001
#define MAXITER 100

#include<stdio.h>
#include<math.h>

void taylor(double x, int opt);

int main(int argc, char** argv)
{
 double x;
 printf("Enter the x value to approximate at: ");
 scanf("%lf",&x);
 printf("Actual value: %.12lf \n", exp(3*x));
 if(argc > 1) //flag for increased precision
  taylor(x,1);
 else
  taylor(x,0);
 return 0; //exit success
}


void taylor(double x, int opt)
{
 double value = exp(3*x);
 double sum = 0;
 double term = 1;
 int n = 0;
 if(opt == 0)
 {
  while(n < MAXITER && fabs(value - sum) > TOL1)
  {
	sum+=term;
	n++;
	term*=3*x/n;
	printf("n: %d\tvalue: %.12lf\n",n,sum);
  }
 }
 else
 {
  double prev = -1;
  while(fabs(prev - sum) > TOL2)
  {	
	prev = sum;
	sum+=term;
	n++;
	term*=3*x/n;
	printf("n: %d\tvalue: %.12lf\n",n,sum);
  }
 }
 
}
