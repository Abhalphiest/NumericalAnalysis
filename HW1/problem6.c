/* 
 * File:	problem6.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 6
 *
 * This file contains a c program that finds all 3 roots of the cubic
 * x^3 - 8x - 1 with FPI and 3 different functions g(x).
 *
*/

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are



double function(double x)
{
 //x^3 - 8x - 1
 return pow(x,3) - 8*x - 1 ;
}
double g1(double x) //for first root
{
 return (-1/14.5)*(function(x))+x;
}
double g2(double x) //for second root
{
 return (1/8.0)*(function(x))+x;
}
double g3(double x) //for third root
{
 return (1/17.5)*function(x)+x;
}


int main()
{
 double fpi1, fpi2, fpi3,x;

 //FPI 1
 printf(" \n\n Enter the FPI guess: ");
 scanf("%lf", &x);

 header("FALSE POSITION METHOD FIRST ROOT");
 fpi1 = FPI(&g1,&function,x);
 //FPI 2
 header("FALSE POSITION METHOD SECOND ROOT");
 fpi2 = FPI(&g2,&function,x);
 //FPI 3
 header("FALSE POSITION METHOD THIRD ROOT");
 fpi3 = FPI(&g3,&function,x);

 return 0; //exit success
}



