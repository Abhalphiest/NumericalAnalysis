//
//
// File:	project2.c
//
// Author:	Margaret Dorsey
//
// MATH411 Numerical Analysis Project 2
//
//

#include"approximations.h"


void printarray(double* arr, int n)
{
 printf("\n");
 for(int i = 0; i < n; i++)
 {
  printf("%lf\t",arr[i]);

 }
 printf("\n");

}

int main()
{
  Point* funcPoints = (Point*) malloc(sizeof(Point)*5);
  Point* derivPoints = (Point*) malloc(sizeof(Point)*5);

  funcPoints[0].x = -1,funcPoints[0]. y = -0.36236;
  funcPoints[1].x =-0.5,funcPoints[1].y= -0.76484;
  funcPoints[2].x=0, funcPoints[2].y=-.98007;
  funcPoints[3].x=0.5,funcPoints[3].y= -0.95534;
  funcPoints[4].x= 1,funcPoints[4].y= -0.69671;
 
  derivPoints[0].x= -1, derivPoints[0].y = -.93204;
  derivPoints[1].x=-.5, derivPoints[1].y = -0.64422;
  derivPoints[2].x = 0, derivPoints[2].y = -.19867;
  derivPoints[3].x = .5, derivPoints[3].y = .299552;
  derivPoints[4].x = 1, derivPoints[4].y = .717356;
  
  double* funcCoeffs = cubicSpline(5,NATURAL,0,0,funcPoints);
  double* derivCoeffs = cubicSpline(5,NATURAL,0,0,derivPoints);
  printf("\nCoefficients for Data Set 1\n");
  printarray(funcCoeffs, 5);


//printarray(derivCoeffs,5);
  printf("\n Values of Cubic Interpolant for Data Set 1");
  for(int i = -20; i < 21; i+=2)
  {
   double x = i/21.0;
   printf("(%lf, %lf)\n",x,splint(funcCoeffs,5,funcPoints,x));
  }
  //changing one data point to (0,-.24582)
  funcPoints[2].y = -.24582;
  funcCoeffs = cubicSpline(5,NATURAL,0,0,funcPoints);

  printf("\nCoefficients for Data Set 1\n");
  printarray(funcCoeffs,5);

  printf("\n Values of Cubic Interpolant for Data Set 2");
  for(int i = -20; i < 21; i+=2)
  {
   double x = i/21.0;
   printf("(%lf, %lf)\n",x,splint(funcCoeffs,5,funcPoints,x));
  }

  return 0;
}
