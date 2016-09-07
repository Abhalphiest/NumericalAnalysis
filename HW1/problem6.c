/* 
 * File:	problem6.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 6
 *
 * This file contains a c program that finds all 3 roots of the cubic
 * 2x^3 - 8x - 1 with FPI and 3 different functions g(x).
 *
*/

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are



double function(double x)
{
 //2*x^3 - 8x - 1
 return 2*pow(x,3) - 8*x - 1 ;
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
 return (1/16.0)*function(x)+x;
}


int main()
{
 double fpi1, fpi2, fpi3,x;

 //FPI 1
 printf(" \n\n Enter the FPI guess: ");
 scanf("%lf", &x);

 header("FALSE POSITION METHOD G_1");
 fpi1 = FPI(&g1,x);
 //FPI 2
 header("FALSE POSITION METHOD G_2");
 fpi2 = FPI(&g2,x);
 //FPI 3
 header("FALSE POSITION METHOD G_3");
 fpi3 = FPI(&g3,x);

 return 0; //exit success
}



