#include "approximations.h"
#include<stdio.h>
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
 
 printf("%lf\n", cubicSpline(4, NATURAL, 0, 0, points, -1));
 return 0;
}
