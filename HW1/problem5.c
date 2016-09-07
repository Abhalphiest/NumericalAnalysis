/* 
 * File:	problem5.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 5
 *
 * This file contains a c program that tries a variety of root finding
 * methods for the calculation of the cube root of 2.
 *
*/

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are


#define ALPHA .25


double function(double x)
{
 return pow(x,3) - 2.0f;
}
double g1(double x)
{
 return x/2.0 + 1/(pow(x,2));
}
double g2(double x)
{
 return 2*x/3.0 + 2/(3*pow(x,2));
}
double g3(double x)
{
 return x - ALPHA*(pow(x,3) - 2);
}


int main()
{
 double x1, x2;
 printf("Enter the x values of the brackets separated by a space: ");
 scanf("%lf %lf", &x1, &x2);

 if(function(x1)*function(x2) > 0) //input validation
 {
  printf("Invalid brackets. \n");
  return 1; //exit failure
 }

 double bisectionResult, secantResult, falsePositionResult;

 //bisection, secant, and false position methods
 if(function(x1) < 0)
 {
	 	header("BISECTION METHOD");
 		bisectionResult = bisection(&function,x1, x2);
	 	header("SECANT METHOD");
        secantResult = secant(&function,x1,x2);
	 	header("FIXED POINT ITERATION");
        falsePositionResult = falseposition(&function,x1,x2);
 }
 else
 {		
	 	header("BISECTION METHOD");
		bisectionResult = bisection(&function,x2, x1);
	 	header("SECANT METHOD");
    secantResult = secant(&function,x2,x1);
	 	header("FIXED POINT ITERATION");
    falsePositionResult = falseposition(&function,x1,x2);
 }



 double fpi1, fpi2, fpi3;

 //FPI 1
 printf(" \n\n Enter the FPI guess: ");
 scanf("%lf", &x1);

 header("FALSE POSITION METHOD 1");
 fpi1 = FPI(&g1,x1);
 //FPI 2
 header("FALSE POSITION METHOD 2");
 fpi2 = FPI(&g2,x1);
 //FPI 3
 header("FALSE POSITION METHOD 3");
 fpi3 = FPI(&g3,x1);

 return 0; //exit success
}



