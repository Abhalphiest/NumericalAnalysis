/* 
 * File:	problem9.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 9
 *
 * This file contains a c program that solves a system of equations with two
 * different implementations of a newton-raphson solver.
 *
 */

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are

double f_1(double v, double w)
{
 //first equation
 return v+w-2;
}
double f_1_v(double v, double w)
{
 //derivative of first equation wrt v
 return 1;
}
double f_1_w(double v, double w)
{
 //derivative of first equation wrt w
 return 1;
}
double f_2(double v, double w)
{
 //second equation
 return v-w;
}
double f_2_v(double v, double w)
{
 //derivative of second equation wrt v
 return 1;	
}
double f_2_w(double v, double w)
{
  //derivative of second equation wrt w
  return -1;
}

int main()
{
 double v_0,w_0;
 printf("Enter the initial guess for the 2D system, as \"v w\":");
 scanf("%lf %lf",&v_0,&w_0);
 header("2D Newton's Method");
 newton2D(&f_1,&f_1_v,&f_1_w,&f_2,&f_2_v,&f_2_w,v_0,w_0,40);
 return 0; //exit success
}



