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


//for print debugging
void printarray(double* arr, int n)
{
 printf("\n");
 for(int i = 0; i < n; i++)
 {
  printf("%lf\t",arr[i]);

 }
 printf("\n");

}
void printpoints(Point* arr, int n)
{
 printf("\n");
 for(int i = 0; i < n; i++)
	printf("(%lf, %lf)\n",arr[i].x, arr[i].y);
 printf("\n");

}
//function declarations for the 3 functions we're concerned with
double function1(double x) {return -cos(x-0.2);}
double function2(double x){return 1 - x*x;}
double function3(double x){return sqrt(5-x*x);} 

//generates n equally spaced points in the [a,b] interval for function f
Point* generatePoints(double (*f)(double), int n, double a, double b);
//produces an output friendly data set for the 2nd project
void produceInterpDataSet(Point* points, int n, char* title);
//computes data relevant to project 2, not part of main functionality of the program
void project2data();
//takes the list of points that were interpolated, the coefficients of the second derivative,
//and an x value and returns the value of the first derivative at that value
double calcSplineDerivative(Point* points, int n, double* coeffs,  double x);


int main(int argc, char** argv)
{
  if(argc > 1) //do the standard output for the assignment
  {
    project2data();
  }

  else //the program required by the assignment
  {
   int n;
   printf("Enter the number of points: ");
   scanf("%d",&n); //get number of points
   printf("Enter the x and y coordinates of each point, space delimited.\n");
   Point* funcPoints = (Point*) malloc(sizeof(Point)*n);
   for(int i = 0; i < n; i++)
   {
    scanf("%lf %lf",&(funcPoints[i].x),&(funcPoints[i].y));
   }
   double* coeffs = cubicSpline(n, NATURAL,0,0,funcPoints);
   printf("Enter the x value to evaluate at: ");
   double x;
   scanf("%lf",&x);
   double result = splint(coeffs,n,funcPoints,x);
   //need to calculate derivative
   double deriv = calcSplineDerivative(funcPoints, n, coeffs, x);
   printf("x:\t%lfy:\t%lf,dx/dy:\t%lf \n",x,result,deriv);
	   
  }
  return 0;
}

double calcSplineDerivative(Point* points, int n, double* y_dp, double x)
{
 int index = 0;
 for(; index < n-1; index++)
   {
	if(x >= points[index].x)
		break;
   }
 double splineCoeff[4];
 double x1 = points[index].x, x2 = points[index+1].x;
 double y1 = points[index].y, y2 = points[index+1].y;
 double A = (x2-x)/(x2-x1);
 double B = 1 - A;
 double C = (1/6.0)*(A*(A*A) - A)*pow((x2-x1),2);
 double D = (1/6.0)*(B*(B*B) - B)*pow(x2-x1,2);
	
 double y_p = -y_dp[index]*(x2-x1)*(3*A*A - 1)/6.0 + y_dp[index+1]*(x2-x1)*(3*B*B - 1)/6.0 + (y2 - y1)/(x2-x1); //value of the first derivative at x
	
 return y_p;
	
}


//auxiliary function implementations


void produceInterpDataSet(Point* points, int n, char* title)
{
  double* funcCoeffs = cubicSpline(n,NATURAL,0,0,points);
  printf("\nCoefficients for %s\n",title);
  printarray(funcCoeffs, 5);

  printf("\n Values of Cubic Interpolant for %s\n",title);
  for(int i = -20; i < 21; i+=2)
  {
   double x = i/21.0;
   printf("(%lf, %lf)\n dy/dx:\t%lf\n\n",x,splint(funcCoeffs,5,points,x),calcSplineDerivative(points,n,funcCoeffs,x));
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
void project2data()
{
  Point* funcPoints = (Point*) malloc(sizeof(Point)*5);

  funcPoints[0].x = -1,funcPoints[0]. y = -0.36236;
  funcPoints[1].x =-0.5,funcPoints[1].y= -0.76484;
  funcPoints[2].x=0, funcPoints[2].y=-.98007;
  funcPoints[3].x=0.5,funcPoints[3].y= -0.95534;
  funcPoints[4].x= 1,funcPoints[4].y= -0.69671;
  printf("Data Set 1\n");
  printpoints(funcPoints,5); 
  produceInterpDataSet(funcPoints,5, "Data Set 1");
  //changing one data point to (0,-.24582)
  funcPoints[2].y = -.24582;
  printf("Data Set 2\n");
  printpoints(funcPoints,5);
  produceInterpDataSet(funcPoints,5,"Data Set 2");

  //1-x^2
  free(funcPoints);
  funcPoints = generatePoints(function2, 5, -1, 1);
  printf("Data Set 3\n");
  printpoints(funcPoints,5);
  produceInterpDataSet(funcPoints,5,"1-x^2");
  free(funcPoints);
	
  funcPoints = generatePoints(function3, 5, -1,1);
  printf("Data Set 4\n");
  printpoints(funcPoints,5);
  produceInterpDataSet(funcPoints,5,"sqrt(5-x^2)"); 
  free(funcPoints);
	
}
