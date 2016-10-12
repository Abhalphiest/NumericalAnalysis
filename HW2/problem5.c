#include "approximations.h"
#include<stdio.h>
int main()
{
 Point points[3];
 points[0].x = 1;
 points[0].y = 1;
 points[1].x = 2;
 points[1].y = 4;
 points[2].x = -5;
 points[2].y = 25;
 float xval = 0;
 printf("%lf\n", lagrangePoly(3, points, xval));
 xval = 12;
 printf("%lf\n", lagrangePoly(3, points, xval));
 return 0;
}
