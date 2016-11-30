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
#include<stdlib.h>

//global for simplicity
double n;

#define THETA 0
#define ETA 1
#define MHAT 2
#define IHAT 3
#define OMEGAHAT 4

//fourth order Runge Kutta
double RK4(double (*f)(double,double), double x0, double y0, double x, double h);
//runge kutta solver for second order eqn split into a first order system
double RK4_2(void (*f)(double,double,double,double*,double*), double x0, double y0, double yp0, double x, double h, int* flag);
 //runge kutta solver for full system of eqns for lane emden
void RK4_Sys(void (*f)(double,double*, double*), double xi0, double theta0, double eta0, double mhat0, double ihat0,
				double omegahat0, double x, double h, double* results);

void laneEmden(double xi, double theta, double eta, double* x, double* y)
{
	if(xi == 0) 
	{
		*x = eta;
		*y = 0;
		return;
	}
	*x = eta; //derivative of xi with respect to theta is eta
	*y = -2*eta/xi-pow(theta,n);
}

void laneEmdenSystem(double xi, double inputs[], double outputs[])
{
	if(xi == 0) 
	{
		outputs[THETA] = inputs[ETA];
		outputs[ETA] = 0;
		outputs[MHAT] = 0;
		outputs[IHAT] = 0;
		outputs[OMEGAHAT] = 0;
		return;
	}
	outputs[THETA] = inputs[ETA]; //derivative of theta with respect to xi is eta
	outputs[ETA] = -2*inputs[ETA]/xi-pow(inputs[THETA],n);
	outputs[MHAT] = 4*PI*pow(inputs[THETA],n)*pow(xi,2);
	outputs[IHAT] = (8.0/3.0)*PI*pow(inputs[THETA],n)*pow(xi,4);
	outputs[OMEGAHAT] = 4*PI*inputs[MHAT]*pow(inputs[THETA],n)*xi;
}


void printResults(double* results, double xi)
{
	printf("xi:\t %lf \t theta:\t %lf\n",xi,results[THETA]);
	printf("mhat:\t %lf \t ihat:\t %lf \t omegahat:\t %lf\n",results[MHAT],results[IHAT],results[OMEGAHAT]);
	printf("\n");
	
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
	int flag = 0;
	while(x < 5.0)
	{
		printf("(%lf,%lf)\n",x,RK4_2(laneEmden,0,1,0,x,h,&flag));
		if(flag == 1) break;
		x+= step;
	}
	if(flag != 1) //we didn't make it out of the star for whatever reason..
		return 0;
	double surface = x;
	x = 0; //reset for another round
	printf("\n\n");
	double* results = (double*) malloc(sizeof(double)*5);
	while(x < 5.0)
	{
		RK4_Sys(laneEmdenSystem,0,1,0,0,0,0,x,h,results);
		results[IHAT] = results[IHAT]/(results[MHAT]*pow(surface,2)); //make dimensionless
		results[OMEGAHAT] =  results[OMEGAHAT]*surface/pow(results[MHAT],2);
		printResults(results);
		x+= step;
	}
	free(results); 
}

//fourth order Runge Kutta
double RK4(double (*f)(double,double), double x0, double y0, double x, double h)
{
 int n = (int) ((x-x0)/h);
 double k1,k2,k3,k4;
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
} 
 //runge kutta solver for second order eqn split into a first order system
 double RK4_2(void (*f)(double,double,double, double*, double*), double x0, double y0, double yp0, double x, double h, int* flag)
 {
 *flag = 0;
 int n = (int) ((x-x0)/h);
 double k1,k2,k3,k4,m1,m2,m3,m4;
 double temp;
 double y = y0,yp=yp0; //two things to keep track of now that we're second order
 for(int i = 1; i <=n; i++)
 {
  f(x0,y,yp,&k1,&m1);
  f(x0+.5*h,y+0.5*h*k1,yp+0.5*h*m1,&k2,&m2);
  f(x0+0.5*h, y+0.5*h*k2,yp+0.5*h*m2,&k3,&m3);
  f(x0+h,y+h*k3,yp+h*m3,&k4,&m4);

  //update next value of y
  temp  = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
  if(temp < 0) {*flag = 1; break;}
  else y = temp;
  yp = yp + (h/6.0)*(m1 + 2*m2 + 2*m3 + m4);
  x0 = x0+h;
	 
 }
 return y;
} 

 //runge kutta solver for full system of eqns for lane emden
 void RK4_Sys(void (*f)(double,double[], double[]), double xi0, double theta0, double eta0, double mhat0, double ihat0,
				double omegahat0, double x, double h, double* y)
 {
 int n = (int) ((x-x0)/h);
 double y1[5], y2[5], y3[5], k1[5],k2[5],k3[5],k4[5];
 double temp; //for checking if theta has become negative, ie we have left the star.
 y[THETA] = theta0, y[ETA] = eta0, y[MHAT] = mhat0, y[IHAT] = ihat0, y[OMEGAHAT] = omegahat0;
 
 //do our four steps
 for(int i = 1; i <=n; i++)
 {
  f(xi0,y,k1);
  y1[THETA] = theta0+0.5*h*k1[THETA], y1[ETA] = eta0+0.5*h*k1[ETA], y1[MHAT] = mhat0+0.5*h*k1[MHAT], 
			y1[IHAT] = ihat0+0.5*h*k1[IHAT], y1[OMEGAHAT] = omegahat0+0.5*h*k1[OMEGAHAT];
  f(xi0+.5*h,y1,k2);
  y2[THETA] = theta0+0.5*h*k2[THETA], y2[ETA] = eta0+0.5*h*k2[ETA], y2[MHAT] = mhat0+0.5*h*k2[MHAT], 
			y2[IHAT] = ihat0+0.5*h*k2[IHAT], y2[OMEGAHAT] = omegahat0+0.5*h*k2[OMEGAHAT];
  f(xi0+0.5*h, y2,k3);
  y3[THETA] = theta0+h*k3[THETA], y3[ETA] = eta0+h*k3[ETA], y3[MHAT] = mhat0+h*k3[MHAT], 
			y3[IHAT] = ihat0+h*k3[IHAT], y3[OMEGAHAT] = omegahat0+h*k3[OMEGAHAT];
  f(xi0+h,y3,k4);

  //update next value of all our systems
  temp  = y[THETA] + (h/6.0)*(k1[THETA] + 2*k2[THETA] + 2*k3[THETA] + k4[THETA]);
  if(temp < 0) break; //stop after we leave the star
  else y[THETA] = temp;
  y[ETA] = y[ETA] + (h/6.0)*(k1[ETA] + 2*k2[ETA] + 2*k3[ETA] + k4[ETA]);
  y[MHAT] = y[MHAT] + (h/6.0)*(k1[MHAT] + 2*k2[MHAT] + 2*k3[MHAT] + k4[MHAT]);
  y[IHAT] = y[IHAT] + (h/6.0)*(k1[IHAT] + 2*k2[IHAT] + 2*k3[IHAT] + k4[IHAT]);
  y[ETA] = y[OMEGAHAT] + (h/6.0)*(k1[OMEGAHAT] + 2*k2[OMEGAHAT] + 2*k3[OMEGAHAT] + k4[OMEGAHAT]);
  xi0 = xi0+h;
	 
 }
} 
