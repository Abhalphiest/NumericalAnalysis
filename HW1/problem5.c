// 
// File:	problem5.c
// Course:	Math 411 Numerical Analysis Fall 2016
// Author:	Margaret Dorsey
//
// Homework 1
//
// This file contains a c program that tries a variety of root finding
// methods for a specified problem.
//

#include<stdio.h>
#include<math.h>


#define ACC .000000001 //8 digits
#define MAX_ITER 500 //maximum number of iterations we'll allow
#define ALPHA .25

double bisection(double a, double b);
double secant(double a, double b);
double FPI(double (*g)(double),double a);
double falseposition(double a, double b);
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
void header(char* name);

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
 	bisectionResult = bisection(x1, x2);
        secantResult = secant(x1,x2);
        falsePositionResult = falseposition(x1,x2);
 }
 else
 {
	bisectionResult = bisection(x2, x1);
        secantResult = secant(x2,x1);
        falsePositionResult = falseposition(x1,x2);
 }



 double fpi1, fpi2, fpi3;

 //FPI 1
 printf(" \n\n Enter the FPI guess: ");
 scanf("%lf", &x1);

 fpi1 = FPI(&g1,x1);
 //FPI 2

 fpi2 = FPI(&g2,x1);
 //FPI 3

 fpi3 = FPI(&g3,x1);
 //print out summary

 return 0; //exit success
}

double bisection(double a, double b)
{
 header("BISECTION METHOD");
 double c;
 double f = 2*ACC; //multiplication by 2 is fastest (will be compiled to 
		  //bitshift)  
 int i;
 for(i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
  c = (b + a)/2.0;
  f = function(c);

  if(f < 0)
	a = c;
  else
	b = c;

  printf("i: %d a: %lf b: %lf value: %.9lf \n", i, a, b, f);
 }

 return c;
}

double secant(double a, double b)
{
 header("SECANT METHOD");
 double c;
 double f = 2*ACC;
 for(int i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
   c =(a*function(b) - b*function(a))/(function(b) - function(a));
   f = function(c);
   a = b;
   b = c;
   printf("i: %d a: %lf b: %lf value: %.9lf\n", i, a, b, f);
 }
 return c;
}

double falseposition(double a, double b)
{
 header("FALSE POSITION METHOD");
 double c;
 double f = 2*ACC;
 for(int i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
  c = (a*function(b) - b*function(a))/(function(b) - function(a));
  f = function(c);
  if(function(c)*function(a) < 0)
  	b = c;
  else 
	a = c;
  printf("i: %d a: %lf b: %lf value: %.9lf\n", i, a, b, f);
 }
 return c;
}

double FPI(double (*g)(double), double a)
{
 header("FIXED POINT ITERATION");
 double c = a;
 double f = ACC*2;
  
 for(int i = 0; i < MAX_ITER && fabs(c - g(c)) > ACC; i++)
 {
  f = g(c);
  printf("i: %d x: %lf value: %.9lf\n",i,c,f);
  c = f;
 }
 return c;
}
void header(char* name)
{
 printf("\n\n");
 printf("--------------------------\n %s\n -----------------------\n",name);
 printf("\n\n");
 return;
}


