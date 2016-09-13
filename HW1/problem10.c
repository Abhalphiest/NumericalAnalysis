/* 
 * File:	problem10.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 10
 *
 * This file contains a c program that finds the maximum value for spectral
 * energy density for a given temperature T.
 *
 */

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are


double f(double x)
{
 //first derivative equation
 return v*(B+w)*(B+w) - S*(B+2*w)/(w*w) - Q;
}
int main()
{
 double x_0;
 printf("Enter the initial guess for the root:");
 scanf("%lf",&x_0);
 header("1D Newton's Method");
 double w =  newton1D(&g,&g_prime,x_0,1000);

 return 0; //exit success
}



