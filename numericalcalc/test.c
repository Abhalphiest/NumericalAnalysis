//for testing our integration functions
#include"numericalcalc.h"
#include<math.h>
#include<stdio.h>

double f1(double x){return 0;}
double f2(double x){return x;}
double f3(double x){return x*x;}
double f4(double x){return x*x*x;}
double f5(double x){return sin(x);}
int main()
{
 printf("Constant 0 from 0 to 1\n");
 printf("simpson: %lf\n",simpson(f1,0,1,2));
 printf("trapezoid: %lf\n",trapezoid(f1,0,1,2));
 printf("romberg: %lf\n",romberg(f1,0,1,2,2));

 printf("y = x from 0 to 1\n");
 printf("simpson: %lf\n",simpson(f2,0,1,2));
 printf("trapezoid: %lf\n",simpson(f2,0,1,2));
 printf("romberg: %lf\n", romberg(f2,0,1,15,15));
	
 printf("y = x^2 from 0 to 1\n");
 printf("simpson: %lf\n",simpson(f3,0,1,2));
 printf("trapezoid: %lf\n",simpson(f3,0,1,2));
 printf("romberg: %lf\n", romberg(f3,0,1,15,15));
	
 printf("y = x^3 from 0 to 1\n");
 printf("simpson: %lf\n",simpson(f4,0,1,2));
 printf("trapezoid: %lf\n",simpson(f4,0,1,2));
 printf("romberg: %lf\n", romberg(f4,0,1,15,15));
	
 printf("y = sin(x) from 0 to 1\n");
 printf("simpson: %lf\n",simpson(f5,0,1,20));
 printf("trapezoid: %lf\n",simpson(f5,0,1,20));
 printf("romberg: %lf\n", romberg(f5,0,1,15,15));

 return 0;

}
