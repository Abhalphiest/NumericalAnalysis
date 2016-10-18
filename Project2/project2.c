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
#include<math.h>

void printarray(double* arr, int n)
{
 printf("\n");
 for(int i = 0; i < n; i++)
 {
  printf("%lf\t",arr[i]);

 }
 printf("\n");

}

double function2(double x){return 1 - x*x;}
double function3(double x){return sqrt(5-x*x);} 
Point* generatePoints(double (*f)(double), int n, double a, double b);
void produceInterpDataSet(Point* points, int n, char* title);
int main()
{
  Point* funcPoints = (Point*) malloc(sizeof(Point)*5);
//Point* derivPoints = (Point*) malloc(sizeof(Point)*5);

  funcPoints[0].x = -1,funcPoints[0]. y = -0.36236;
  funcPoints[1].x =-0.5,funcPoints[1].y= -0.76484;
  funcPoints[2].x=0, funcPoints[2].y=-.98007;
  funcPoints[3].x=0.5,funcPoints[3].y= -0.95534;
  funcPoints[4].x= 1,funcPoints[4].y= -0.69671;
 
  produceInterpDataSet(funcPoints,5, "Data Set 1");
  //changing one data point to (0,-.24582)
  funcPoints[2].y = -.24582;

  produceInterpDataSet(funcPoints,5,"Data Set 2");

  //1-x^2
  free(funcPoints);
  funcPoints = generatePoints(function2, 5, -1, 1);
  produceInterpDataSet(funcPoints,5,"1-x^2");
  free(funcPoints);
	
  funcPoints = generatePoints(function3, 5, -1,1);
  produceInterpDataSet(funcPoints,5,"sqrt(5-x^2)"); 
  free(funcPoints);
  return 0;
}

void produceInterpDataSet(Point* points, int n, char* title)
{
  double* funcCoeffs = cubicSpline(n,NATURAL,0,0,points);
  printf("\nCoefficients for %s\n",title);
  printarray(funcCoeffs, 5);

  printf("\n Values of Cubic Interpolant for %s\n",title);
  for(int i = -20; i < 21; i+=2)
  {
   double x = i/21.0;
   printf("(%lf, %lf)\n",x,splint(funcCoeffs,5,points,x));
  }
  free(funcCoeffs);
}

Point* generatePoints(double (*f)(double), int n, double a, double b)
{
 Point* points = (Point*) malloc(sizeof(Point)*n);
 double dist = b - a;
 double interval = dist/(n-1);
 for(int i = 0; i < n; i++)
 {
  points[i].x = a+i*interval;
  points[i].y = f(a+i*interval);
 }
 return points;
}
