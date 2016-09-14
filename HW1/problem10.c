/* 
 * File:	problem10.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1 Problem 10
 *
 * This file contains a c program that finds the x that generates maximum value for spectral
 * energy density.
 *
 */

#include<stdio.h>
#include<math.h>
#include"rootfinding.h" //where all the actual rootfinding functions are


double f(double x)
{
 //first derivative equation
 return -(exp(x)*(x-3)+3)*x*x/pow((exp(x)-1),2);
}
double f_prime(double x)
{
 //second derivative equation
 return (2*exp(x)*(exp(x)*(x-3)+3)*x*x)/pow(exp(x)-1,3)-
		((exp(x)*(x-3)+exp(x))*x*x)/pow(exp(x)-1,2)-
		(2*(exp(x)*(x-3)+3)*x)/pow(exp(x)-1,2);
}
double u(double x)
{
 return x*x*x/(exp(x) - 1);
}
double fwhm(double x)
{
 return u(x)/1.4214354727477 - .5;

}
int main(int argc, char** argv)
{
 if(argc ==1){ //part iv
  double x_0;
  printf("Enter the initial guess for the root:");
  scanf("%lf",&x_0);
  header("1D Newton's Method");
  double w =  newton1D(&f,&f_prime,x_0,1000);
 }
 
 else //part v
 {
  header("Root 1 - Newton");
  newton1D(&fwhm,&f,-1,1000);
  header("Root 2 - Bisection");
  bisection(&fwhm,1, 2);
  header("Root 3 - Newton");
  newton1D(&fwhm,&f, 5,1000);
 }
 return 0; //exit success
}



