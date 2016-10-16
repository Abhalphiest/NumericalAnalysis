#include "approximations.h"
#include"problem5.h"

double function(double x)
{
 return 1.0/(1+x*x);
}

int main()
{
 evenPoints(-5,5);
 double* coeffs = chebyshev_coeff(-5, 5, 5,function);
 double* cPoints = chebyshevMidpoints(-5,5,5);
 printf("\n\n\n Chebyshev Approximation 5 Nodes \n\n");
 for(int i = 0; i < 4; i++)
 {
	printf("x:\t\t%lf\nchebyshev:\t%lf\nactual:\t\t%lf\n\n",cPoints[i], chebyshev(-5,5,5, coeffs,cPoints[i]), function(cPoints[i]));
 }
 free(coeffs);
 free(cPoints);
 coeffs = chebyshev_coeff(-5, 5, 10,function);
 cPoints = chebyshevMidpoints(-5,5,10);


 printf("\n\n\n Chebyshev Approximation 10 Nodes \n\n");
 for(int i = 0; i < 9; i++)
 {
	printf("x:\t\t%lf\nchebyshev:\t%lf\nactual:\t\t%lf\n\n",cPoints[i], chebyshev(-5,5,10, coeffs,cPoints[i]), function(cPoints[i]));
 }
 free(coeffs);
 free(cPoints);
 coeffs = chebyshev_coeff(-5, 5, 10,function);
 cPoints = chebyshevMidpoints(-5,5,10);
 printf("\n\n\n Chebyshev Approximation 10 Nodes \n\n");
 for(int i = 0; i < 14; i++)
 {
	printf("x:\t\t%lf\nchebyshev:\t%lf\nactual:\t\t%lf\n\n",cPoints[i], chebyshev(-5,5,15, coeffs,cPoints[i]),function(cPoints[i]));
 }
 free(coeffs);
 free(cPoints);

 return 0;
}



Point* makePoints(double xstart,double xend, int npoints)
{
 Point* points = (Point*) malloc(sizeof(Point)*npoints);
 double dx = (xend - xstart)/(npoints-1);
 for(int i = 0; i < npoints; i++)
 {
  points[i].x = xstart + i*dx;
  points[i].y = function(points[i].x);
 }
 return points;
}
Point* findActual(Point* points, int n)
{
 Point* actual = (Point*) malloc(sizeof(Point)*(n-1)); //one less midpoint
 for(int i = 0; i < n-1; i++)
 {
  actual[i].x = (points[i].x + points[i+1].x)/2.0;
  actual[i].y = function(actual[i].x);
 }
 return actual;
}
void printPoints(Point* points, int n)
{
 for(int i = 0; i < n; i++)
 {
  if(i%3 == 0) printf("\n");
  printf("(%lf,%lf) ",points[i].x,points[i].y);
 }
 printf("\n\n");
}
void evenPoints(double xstart, double xend)
{
 printf("5 DATA POINTS \n\n");
 Point* points = makePoints(xstart,xend,5);
 printf("Initial Points: \n");
 printPoints(points, 5);

 Point* actual = findActual(points,5);

 double* result = cubicSpline(5, NATURAL, 0, 0, points);
 double* result2 = cubicSpline(5, CURVEADJUSTED, 37.0/4394.0, 37.0/4394.0,
				points);
 //only need to get the spline once per set of points

 for(int i = 0; i < 4; i++) //n-1 midpoints
 {
   printf("x:\t\t%lf\nlagrange:\t%lf\ncubic:\t\t%lf\ncurveadj:\t%lf\nactual:\t\t%lf\n\n",
	actual[i].x, lagrangePoly(4,points,actual[i].x), 
	splint(result,5,points,actual[i].x), 
	splint(result2, 5, points,actual[i].x), actual[i].y); 
 }  
 printf("\n\n\n");
 //cleanup before next set
 free(points);
 free(actual);
 free(result);
 
 printf("10 DATA POINTS \n\n");
 points = makePoints(xstart,xend,10);
 printf("Initial Points: \n");
 printPoints(points, 10);

 actual = findActual(points,10);

 result = cubicSpline(10, NATURAL, 0, 0, points);
 result2 = cubicSpline(10,CURVEADJUSTED, 37.0/4394.0, 37.0/4394.0,points); 
	//37/4394 is the value of the second 
	//derivative at both 5 and -5

 for(int i = 0; i < 9; i++) //n-1 midpoints
 {
  printf("x:\t\t%lf\nlagrange:\t%lf\ncubic:\t\t%lf\ncurveadj:\t%lf\nactual:\t\t%lf\n\n",
	actual[i].x, lagrangePoly(9,points,actual[i].x), 
	splint(result,10,points,actual[i].x),
	splint(result2, 10, points,actual[i].x), actual[i].y); 
 } 
 printf("\n\n\n"); 
 //cleanup before next set
 free(points);
 free(actual);
 free(result);
 
 printf("15 DATA POINTS \n\n");
 points = makePoints(xstart,xend,15);
 printf("Initial Points: \n");
 printPoints(points, 15);

 actual = findActual(points,15);

 result = cubicSpline(15, NATURAL, 0, 0, points);
 result2 = cubicSpline(15,CURVEADJUSTED, 37.0/4394.0, 37.0/4394.0,points); 
 for(int i = 0; i < 9; i++) //n-1 midpoints
 {
  printf("x:\t\t%lf\nlagrange:\t%lf\ncubic:\t\t%lf\ncurveadj:\t%lf\nactual:\t\t%lf\n\n",
	actual[i].x, lagrangePoly(14,points,actual[i].x), 
	splint(result,15,points,actual[i].x),
	splint(result2, 15, points,actual[i].x), actual[i].y); 
 }  
 printf("\n\n\n");
 //cleanup before next set
 free(points);
 free(actual);
 free(result);
 
 return;
}
int cmpfunc(const void * a, const void* b)
{
 return (*(double*)a - *(double*)b);
}
double* chebyshevMidpoints(double a,double b, int n)
{
	double* points = (double*) malloc(sizeof(double)*n);
  for(int i=0; i<n; i++){
    points[i] = cos((i+.5)*pi/(n));
    points[i] = .5*(a+b) + .5*(b-a)*points[i];
  }
  qsort(points, n, sizeof(double), cmpfunc);
  
  double* midpoints = (double*) malloc(sizeof(double)*(n-1));
  for(int i = 0; i < n-1; i++)
  {
	  midpoints[i] = .5*(points[i]+points[i+1]);
  }
  free(points);
  return midpoints;	
}
