/* 
 * File:	project1.c
 * Course:	Math 411 Numerical Analysis Fall 2016
 * Author:	Margaret Dorsey
 *
 * Project 1
 *
 * This file contains a c program that tries a variety of root finding
 * methods for a problem arising in chemistry.
 *
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"rootfinding.h" //where all the actual rootfinding functions are


double* k, *n; //everything is made global for simplicity
double E;
int M;

double f(double x)
{
 double value = 0;
 for(int i = 0; i < M; i++)
 {
  value += (k[i]*n[i])/(1+k[i]*x);
 }
 value += 1;
 value *= x;
 value -= E;
 return value;
}

double g(double x) //for FPI
{
 double value = 0;
 for(int i = 0; i < M; i++)
   value-= k[i]*n[i]/(1+k[i]*x);;
 value *= x;
 value += E;
 return value;
}

int main()
{
 k = malloc(sizeof(double));
 n = malloc(sizeof(double)); //hardcoding everything because it's just 2 test cases..
 M = 1;
 E = 3;
 k[0] = 1;
 n[0] = 1;
 double x1;
 printf("Enter the initial guess for the first test: ");
 scanf("%lf",&x1);
 header("Fixed Point Iteration");
 FPI(&g,x1);
		
 
 
 n[0] = 5; //only thing that needs to change
 double x1;
 printf("Enter the initial guess for the second test: ");
		scanf("%lf",&x1);
		header("Fixed Point Iteration");
		FPI(&g,x1);
 
 free(k); //clean up our heap
 free(n);
 return 0; //exit success
}



