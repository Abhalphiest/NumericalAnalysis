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

double f3(double x, double y)
{
 return 2*x;
}

int main()
{
 double result;
 result = AdamsMoulton(f1,0,0,1,.005);
 printf("%lf\n",result);

 printf("\n\n");
	
 result = AdamsMoulton(f2,0,1,1,.005);
 printf("%lf\n",result);

 result = AdamsMoulton(f3,0,0,1,.005);
 printf("%lf\n",result);
 return 0;


}
