//
// File:	problem5.c
//
// Author:	Margaret Dorsey
// 
// MATH 411 Numerical Analysis Homework 3 Problem 5
//

#include"numericalcalc.h"
#include<stdio.h>
#include<math.h> //for math functions

#define CONST_E 2.718281828459
//a,b,c,d
double f1(double x){return cos(x)*cos(x);}
double f2(double x){return x*log(x+1);}
double f3(double x){return sin(x)*sin(x) - 2*x*sin(x) + 1;}
double f4(double x){return 1.0/(x*log(x));}

int main()
{
 double aresult,bresult,cresult,dresult;
 aresult = romberg(f1,-1,1,12,12);
 bresult = romberg(f2,-.75, .75, 12, 12);
 cresult = romberg(f3, 1, 4, 12, 12);
 dresult = romberg(f4, CONST_E, 2*CONST_E,12,12);

 printf("a.) %lf\nb.) %lf\nc.) %lf\nd.) %lf\n",
	aresult,bresult,cresult,dresult);
 return 0; 

}




