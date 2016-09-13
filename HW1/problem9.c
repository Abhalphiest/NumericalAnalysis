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

//left as a system for the 2D solution
double f_1(double v, double w)
{
 //first equation
 return v*(B+w)*(B+w) - S*(B+2*w)/(w*w) - Q;
}
double f_1_v(double v, double w)
{
	//derivative of first equation wrt v
	return (B+w)*(B+w);
}
double f_1_w(double v, double w)
{
	//derivative of first equation wrt w
	return 2*(B*v*pow(w,3)+v*pow(w,4)+B*S+S*w)/pow(w,3);
}
double f_2(double v, double w)
{
 //second equation
 return -B*.5*(1+v)+ S*.5*pow(w,-2.0) - w + .5*((1-v)*w - D*pow(1-v,.5)) - N;
}
double f_2_v(double v, double w)
{
 //derivative of second equation wrt v
 double root = sqrt(1-v);
 return -.25*(2*B*root + 2*W*root-D)/root;	
}
double f_2_w(double v, double w)
{
  //derivative of second equation wrt w
  return -.5*(v*pow(w,3)+pow(w,3)+2*S)/pow(w,3);
}

//for the 1D solution

//from solving first equation for v
double v(double w)
{
  return (Q*w*w+B*S+2*S*w)/(w*w*(B+w)*(B+w));
}
double v_w(double w)
{ 
  //differentiated v(w) wrt w
  return -2*(Q*pow(w,3)+B*B*S+3*B*S*w+3*s*w*w)/(pow(w,3)*pow(B+w,3));
}
//reduced to 1 equation
double g(double w)
{
 //substitution of v(w) into the second equation with some simplification
 return -B*.5*(1+v(w))+ S*.5*pow(w,-2.0) - w + 
 	.5*((1-v(w))*w - D*pow(1-v(w),.5)) - N;
}
double g_prime(double w)
{
 //used some chain rule and product rule to skirt around the full expression
 return -.5*(B*v_w(w)-.5*D*v_w(w)/sqrt(v(w))+w*v_w(w)+v(w)+B+w-(S/pow(w,2)))-D;	
}

int main()
{
 double v_0,w_0;
 printf("Enter the initial guess for the 2D system, as \"v w\":");
 scanf("%lf %lf",&v_0,&w_0);

 

 return 0; //exit success
}



