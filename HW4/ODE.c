#include"ODE.h"
#include<stdio.h>
double Euler(double(*f)(double,double),double x0, double y0, double t, double h)
{
 double x = x0, y = y0, k;
 while(x <= t)
 {
  k=h*f(x,y);
  y = y+k;
  x = x+h;
  //printf("%lf %lf\n",x,y);
 }
 return y;
}

double RK2(double (*f)(double,double), double x0, double y0, double x, double h)
{
 int n = (int)((x-x0)/h);
 double k1,k2,k3;
 double y = y0;
 for(int i = 1; i <= n; i++)
 {
  k1 = h*f(x0,y);
  k2 = h*f(x0+.5*h,y+.5*k1);
  y += k2;
  x0+=h;
 }
 return y;
}
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
 

 return y;
}

 //runge kutta solver for second order eqn split into a first order system
 double RK4_2(void (*f)(double,double,double, double*, double*), double x0, double y0, double yp0, double x, double h)
 {
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
  y  = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4);
  yp = yp + (h/6.0)*(m1 + 2*m2 + 2*m3 + m4);
  x0 = x0+h;
	 
 }
 return y;
} 

double AdamsBashforth(double(*f)(double,double),double x0,double y0, double x, double h)
{
 double y1,y2,y3,y4,y,y5;
 y = y0;
 y1 = RK4(f,x0,y0,x0+h,h);
 y2 = RK4(f,x0,y0,x0+2*h,h);
 y3 = RK4(f,x0,y0,x0+3*h,h);
 y4 = RK4(f,x0,y0,x0+4*h,h);
 while(x0 < x)
 {
 y5 = y4+ h*((1901.0/720.0)*f(x0+4*h,y4) - (1387.0/360.0)*f(x0+3*h, y3) +
		(109.0/30.0)*f(x0+2*h,y2) - (637.0/360.0)*f(x0+h,y1) +
		(251.0/720.0)*f(x0,y));
 y = y1;
 y1 = y2;
 y2 = y3;
 y3 = y4;
 y4 = y5;
 x0 += h;
 }
 return y;
}
double AdamsBashforthInit(double(*f)(double,double),double x0, double*y0, double 
x, double h)
{
 double y1,y2,y3,y4,y,y5;
 y = y0[0];
 y1 = y0[1];
 y2 = y0[2];
 y3 = y0[3];
 y4 = y0[4];

 while(x0 < x)
 {
 y5 = y4+ h*((1901.0/720.0)*f(x0+4*h,y4) - (1387.0/360.0)*f(x0+3*h, y3) +
		(109.0/30.0)*f(x0+2*h,y2) - (637.0/360.0)*f(x0+h,y1) +
		(251.0/720.0)*f(x0,y));
 y = y1;
 y1 = y2;
 y2 = y3;
 y3 = y4;
 y4 = y5;
 x0 += h;
 }
 return y;

}
double AdamsMoulton(double(*f)(double,double),double x0, double y0, double x, double h)
{
 
  double y1,y2,y3,y4,y,y5;
 y = y0;
 y1 = RK4(f,x0,y0,x0+h,h);
 y2 = RK4(f,x0,y0,x0+2*h,h);
 y3 = RK4(f,x0,y0,x0+3*h,h);
 y4 = RK4(f,x0,y0,x0+4*h,h);
 while(x0 < x)
 {
 y4 = y3+ h*((251.0/720.0)*f(x0+4*h,y4) + (323.0/360.0)*f(x0+3*h, y3) -
		(132.0/360.0)*f(x0+2*h,y2) + (53.0/360.0)*f(x0+h,y1) -
		(19.0/720.0)*f(x0,y));
 y = y1;
 y1 = y2;
 y2 = y3;
 y3 = y4;
 y4 = AdamsBashforth(f,x0,y0,x0+5*h,h);
 x0 += h;
 }
 return y;

}

double AdamsMoultonInit(double(*f)(double,double),double x0, double* y0, double x, double h)
{
 
double y1,y2,y3,y4,y;
 y = y0[0];
 y1 = y0[1];
 y2 = y0[2];
 y3 = y0[3];
 y4 = y0[4];
 printf("yvals: %e %e %e %e %e\n",y,y1,y2,y3,y4);
 while(x0 < x)
 {
  y4 = y3+ h*((251.0/720.0)*f(x0+4*h,y4) + (323.0/360.0)*f(x0+3*h, y3) -
		(132.0/360.0)*f(x0+2*h,y2) + (53.0/360.0)*f(x0+h,y1) -
		(19.0/720.0)*f(x0,y));
 y = y1;
 y1 = y2;
 y2 = y3;
 y3 = y4;
 y4 = AdamsBashforthInit(f,x0,y0,x0+5*h,h);
 x0 += h;
 }
 return y;


}
