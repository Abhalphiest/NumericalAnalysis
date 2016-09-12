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

#define B .004
#define S 0.0011111
#define Q .083333
#define D 1.29074
#define N -1.774598

//left as a system
double f_1(double v, double w)
{
 return v*(B+w)*(B+w) - S*(B+2*w)/(w*w) - Q;
}
double f_1_v(double v, double w)
{
	return (B+w)*(B+w);
}
double f_1_w(double v, double w)
{
	return 2*B*v + 2*v*w + 2*S*B/pow(w,3) +2*S/pow(w,2);
}
double f_2(double v, double w)
{
 return -B*.5*(1+v)+ S*.5*pow(w,-2.0) - w + .5*((1-v)*w - D*pow(1-v,.5)) - N;
}
double f_2_v(double x)
{
 return 0;	
}
double f_2_w(double v, double w)
{
	return 0;
}

//from first equation
double v(double w)
{
	return B*S+w*(Q*w + 2*S)/(w*w*(B+w)*(B+w));
}
double v_w(double w)
{
	return 0;
}
//reduced to 1 equation
double g(double w)
{
 return -B*.5*(1+v(w))+ S*.5*pow(w,-2.0) - w + .5*((1-v(w))*w - D*pow(1-v(w),.5)) - N;
}
double g_prime(double w)
{
 return 0;	
}

int main()
{
 

 return 0; //exit success
}



