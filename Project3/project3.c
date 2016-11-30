//
// File:	project3.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Project 3
//
// This program assists in the analysis of stellar approximations, 
// specifically the Lane-Emden Equation and it's analogue for White Dwarves.
//

#include<math.h>
#include<stdio.h>


//global for simplicity
double n;

//fourth order Runge Kutta
double RK4(double (*f)(double,double), double x0, double y0, double x, double h);
//runge kutta solver for second order eqn split into a first order system
double RK4_2(double (*f)(double,double), double (*g)(double,double), double x0, double y0, double yp0, double x, double h);


void laneEmden(double theta, double xi, double eta, double& x, double&y)
{
	if(xi == 0) 
	{
		x = 0;
		y = 0;
		return;
	}
	x = eta; //derivative of xi with respect to theta is eta
	y = -2*eta/xi-pow(theta,n)
}






int main()
{
	int numpoints;
	double h;
	printf("Enter n for Lane-Emden: ");
	scanf("%lf",&n);
	printf("Enter number of points to generate: ");
	scanf("%d",&numpoints);
	printf("Enter stepsize: ");
	scanf("%lf", &h);
	
	double step = 5.0/numpoints;
	double x = 0;
	
	while(x < 5.0)
	{
		printf("(%lf,%lf)\n",x,RK4(laneEmden,0,0,1,x,h));
		x+= step;
	}
	return 0;
}

//fourth order Runge Kutta
double RK4(double (*f)(double,double), double x0, double y0, double x, double h)
{
 int n = (int) ((x-x0)/h);
 double k1,k2,k3,k4,k5;
 double y = y0;
 for(int i = 1; i <=n; i++)
 {
  k1 = h*f(x0,y);
  k2 = h*f(x0+.5*h,y+0.5*k1);
  k3 = h*f(x0+0.5*h, y+0.5*k2);
  k4 = h*f(x0+h,y+k3);

  //update next value of y
  y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);

  x0 = x0+h;
 }
 
 //runge kutta solver for second order eqn split into a first order system
 double RK4_2(void (*f)(double,double,double, double&, double&), double x0, double y0, double yp0, double x, double h)
 {
 int n = (int) ((x-x0)/h);
 double k1,k2,k3,k4,k5,m1,m2,m3,m4,m5;
 double y = y0,yp=yp0; //two things to keep track of now that we're second order
 for(int i = 1; i <=n; i++)
 {
  f(x0,y,yp,k1,m1);
  f(x0+.5*h,y+0.5*h*k1,yp+0.5*h*m1,k2,m2);
  f(x0+0.5*h, y+0.5*h*k2,yp+0.5*h*m2,k3,m3);
  f(x0+h,y+h*k3,yp+h*m3,k4,m4);

  //update next value of y
  y = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
  yp = yp + (h/6.0)*(m1 + 2*m2 + 2*m3 + m4);
  x0 = x0+h;
	 
 }
 