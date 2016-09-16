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


double alpha; //for FPI
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
double f_prime(double x) //for newtons method
{
 //product rule
 double value = 0, sumterms = 0;
 for(int i = 0; i < M; i++) //two operands for product rule
 {
  value += (k[i]*n[i])/pow(1+k[i]*x,2);
 }
 value += 1;
 value = value;

 return 0;
}
double g(double x) //for FPI
{
 double value = 0;
 for(int i = 0; i < M; i++)
   value-= k[i]*n[i]/(1+k[i]*x);
 value += alpha;
 value *= x;
 value += E;
 value *= 1/(1+alpha);
 return value;
}

void calcalpha() //assumes input has already been processed
{
 alpha = 0;
 for(int i = 0; i < M; i++)
  alpha += k[i]*n[i];
 return;
}
int main()
{
 printf("Enter M and E, separated by a space:"); //prompt for input
 scanf("%d %lf",&M,&E);
 k = (double*) malloc(sizeof(double)*M);
 n = (double*) malloc(sizeof(double)*M);
 printf("Enter the k values in order: \n");
 for(int i = 0; i < M; i++)
 {
   scanf("%lf",&k[i]);
 }
 printf("\nEnter the n values in order: \n");
 for(int i = 0; i < M; i++)
 {
   scanf("%lf",&n[i]);
 }
 //alpha = 0; //for testing various values of alpha
 calcalpha(); //get our alpha for FPI 
 
 int choice;
 printf("\nEnter 1 for bisection, 2 for fpi, 3 for newton :");
 fseek(stdin,0,SEEK_END); //don't spoil our next scan with old input
 scanf("%d", &choice);
 
 double x1,x2;
 switch(choice)
 {
  case 1:
		printf("Enter the brackets separated by a space: ");
		scanf("%lf %lf",&x1,&x2);
		header("Bisection");
		if(f(x1)*f(x2) > 0)
			return -1; //go die
		if(x1 < x2)
			bisection(&f,x1,x2);
		else
			bisection(&f,x2,x1);
		break;

  case 2:
		printf("Enter the initial guess: ");
		scanf("%lf",&x1);
		header("Fixed Point Iteration");
		FPI(&g,x1);
		break;

  case 3:
		printf("Enter the intial guess: ");
		scanf("%lf",&x1);
		header("Newton");
		newton1D(&f,&f_prime,x1, 1000);
		break;
 }
 free(k); //clean up our heap
 free(n);
 return 0; //exit success
}



