//
// File:	whiteDwarves.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Project 3
//
// This program assists in the analysis of stellar approximations, 
// specifically of White Dwarf stars
//

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define PI 3.14159265359

#define THETA 0
#define V 1
#define MHAT 2
//fourth order Runge Kutta
double RK4(double (*f)(double,double), double x0, double y0, double x, double h);
//runge kutta solver for second order eqn split into a first order system
double RK4_2(void (*f)(double,double,double,double*,double*), double x0, double y0, double yp0, double x, double h, int* flag);
 //runge kutta solver for full system of eqns
double RK4_Sys(void (*f)(double,double*, double*), double s0, double theta0, double v0, double mhat0, double x, double h);

void whiteDwarf(double s, double theta, double v, double* x, double* y)
{
	//if(xi == 0) 
	//{
	//	*x = v;
	//	*y = 0;
	//	return;
	//}
	//*x = ; //derivative of theta with respect to xi  is eta
	//*y = -2*eta/xi-pow(theta,n);
}

void printArray(double* arr)
{
 printf("%lf %lf %lf %lf %lf\n",arr[0],arr[1],arr[2],arr[3],arr[4]);

}

void whiteDwarfSystem(double s, double inputs[], double outputs[])
{
	//if(s == 0) 
	//{
		//outputs[THETA] = inputs[ETA];
		//outputs[V] = 0;
		//outputs[MHAT] = 0;

		//return;
	//}
	//outputs[THETA] =; //derivative of theta with respect to xi is eta
	//outputs[V] = 
	//outputs[MHAT] = ;

}


void printResults(double* results, double s)
{
	printf("s:\t %lf \t theta:\t %lf \t mhat: %lf\n",s,results[THETA],results[MHAT]);
	printf("\n");
	
}


int main()
{
	double theta0;
	double h;
	printf("Enter initial value for theta: ");
	scanf("%lf",&theta0);
	printf("Enter stepsize: ");
	scanf("%lf", &h);
	
	
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
  if(temp < 0) {*flag = 1; surface_eta = yp; break;}
  else y = temp;
  yp = yp + (h/6.0)*(m1 + 2*m2 + 2*m3 + m4);
  x0 = x0+h;
	 
 }
 return y;
} 

 //runge kutta solver for full system of eqns for lane emden
 void RK4_Sys(void (*f)(double,double[], double[]), double s0, 
	double theta0, double eta0, double mhat0, double x, double h,double*y)
 {
 int n = (int) ((x-s0)/h);
 double y1[3], y2[3], y3[3], k1[3],k2[3],k3[3],k4[3];
 double temp; //for checking if theta has become negative, ie we have left the star.
 y[THETA] = theta0,
 y[ETA] = eta0, 
 y[MHAT] = mhat0;
 
 //do our four steps
 for(int i = 1; i <=n; i++)
 {
  f(s0,y,k1);
  y1[THETA] = y[THETA]+0.5*h*k1[THETA], 
  y1[V] = y[ETA]+0.5*h*k1[V], 
  y1[MHAT] = y[MHAT]+0.5*h*k1[MHAT], 


  f(s0+.5*h,y1,k2);
  y2[THETA] = y[THETA]+0.5*h*k2[THETA],
		y2[V] = y[V]+0.5*h*k2[V], 
		y2[MHAT] = y[MHAT]+0.5*h*k2[MHAT], 

  f(xi0+0.5*h, y2,k3);
  y3[THETA] = y[THETA]+h*k3[THETA], 
		y3[V] = y[V]+h*k3[V], 
		y3[MHAT] = y[MHAT]+h*k3[MHAT], 
  f(s0+h,y3,k4);

  //update next value of all our systems
  temp  = y[THETA] + 
	(h/6.0)*(k1[THETA] + 2*k2[THETA] + 2*k3[THETA] + k4[THETA]);
  if(temp < 0) break; //stop after we leave the star
  y[THETA] = temp;
  y[V] = y[V] + (h/6.0)*(k1[V] + 2*k2[V] + 2*k3[V] + k4[V]);
  y[MHAT] = y[MHAT] + 
	(h/6.0)*(k1[MHAT] + 2*k2[MHAT] + 2*k3[MHAT] + k4[MHAT]);
  s0 = s0+h;	 
 }
} 
