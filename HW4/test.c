//for testing ODE solvers

#include"ODE.h"
#include<stdio.h>
#include<math.h>

double f1(double x, double y)
{
 return 3; //y' = 3
}

double f2(double x, double y)
{	
 return x+ y;	
}

int main()
{
 double result;
 result = AdamsBashforth(f1,0,0,1,.005);
 printf("%lf\n",result);

 printf("\n\n");
	
 result = AdamsBashforth(f2,0,1,1,.005);
 printf("%lf\n",result);
 return 0;


}
