/* 
 * File:	problem7.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 7
 *
 * This file contains a c program that tries (and fails) to find the
 * intersection of two functions using the secant method.
 *
 */

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are




double function(double x)
{
 return 1/(pow(x,2.0)+1.5*x-0.25) - 1/(4*pow(x,2.0) - 6.4*x + 1.5);
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

 double secantResult;

 //secant method
 if(function(x1) < 0)
 {
	 	header("SECANT METHOD");
  	        secantResult = secant(&function,x1,x2);
		
 }
 else
 {
	 	header("SECANT METHOD");
    		secantResult = secant(&function,x2,x1);
 }

 return 0; //exit success
}



