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
 return y;	
}

int main()
{
 double result = Euler(f1,0,0,1,.005);
 printf("%lf\n",result);
 result = RK2(f1,0,0,1,.005);
 printf("%lf\n",result);
 result = RK4(f1,0,0,1,.005);
 printf("%lf\n",result);
 result = AdamsBashforth(f1,0,0,1,.005);
 printf("%lf\n",result);

 printf("\n\n");
	
 result = Euler(f2,0,1,1,.005);
 printf("%lf\n",result);
 result = RK2(f2,0,1,1,.005);
 printf("%lf\n",result);
 result = RK4(f2,0,1,1,.005);
 printf("%lf\n",result);
 result = AdamsBashforth(f2,0,1,1,.005);
 printf("%lf\n",result);
 return 0;


}
