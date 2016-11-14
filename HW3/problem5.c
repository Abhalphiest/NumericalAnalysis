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
double f1(double x){return x*cos(x)*cos(x);}
double f2(double x){return x*log(x+1);}
double f3(double x){return sin(x)*sin(x) - 2*x*sin(x) + 1;}
double f4(double x){return 1.0/(x*log(x));}

int main()
{
 double aresult,bresult,cresult,dresult;
 aresult = romberg(f1,-1,1,3,3);
 bresult = romberg(f2,-.75, .75, 3, 3);
 cresult = romberg(f3, 1, 4, 3, 3);
 dresult = romberg(f4, CONST_E, 2*CONST_E,3,3);

 printf("a.) %lf\n b.) %lf\n c.) %lf\n d.) %lf\n",
	aresult,bresult,cresult,dresult);
 return 0; 

}



}
