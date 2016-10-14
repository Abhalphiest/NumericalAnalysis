#include "approximations.h"
#include<stdio.h>

double function(double x)
{
 return 1.0/(1+x*x);
}
int main()
{
 Point points[4];
 points[0].x = 0;
 points[0].y = 3;
 points[1].x = 1;
 points[1].y = 5;
 points[2].x = 2;
 points[2].y = 2;
 points[3].x = 3;
 points[3].y = 1;
 
 double* result =  cubicSpline(4, NATURAL, 0, 0, points);

 for(int i = 0; i < 4; i++)
	printf("%lf ",result[i]);
 printf("\n");

 double xval = 1.3;
 double y = splint(result,4,points,xval);
 printf("%lf\n",y);
 return 0;
}
