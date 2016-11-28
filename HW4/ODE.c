#include"ODE.h"

double Euler(double(*f)(double),double x0, double y0, double t, double h)
{
 double x = x0, y = y0, k;
 while(x <= t)
 {
  k=h*f(x,y);
  y = y+k;
  x = x+h;
 }
 return y;
}

double RK2(double (*f)(double), double x0, double y0, double x, double h)
{
 int n = (int)((x-x0)/h);
 double k1,k2,k3;
 double y = y0;
 for(int i = 1; i <= n; i++)
 {
  k1 = h*f(x0,y);
  k2 = h*f(x0+.5*h,y+.5*k1);
  y += k2;
 }
 return y;
}
double RK4(double (*f)(double), double x0, double y0, double x, double h)
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

double AdamsBashforth(double(*f)(double),double x0,double y0, double x, double h)
{
 double k1, k2, k3, k4, k5, y;
 while(x0 < x)
 {
 k1 = y + h*f(x0,y); //euler method
 k2 = k1 + h*((3.0/2.0)*f(x0+h,k1)-.5*f(x0,y));
 k3 = k2 + h*((22.0/12.0)*f(x0+2*h,k2) - 
		(4.0/3.0)*f(x0+h,k1) + (5.0/12.0)*f(x0,y));
 k4 = k3+h*((55.0/24.0)*f(x0+3*h,k3) - (59.0/24.0)*f(x0+2*h,k2) 
		+ (37.0/24.0)*f(x0+h,k1)-(3.0/8.0)*f(x0,y));
 k5 = k4+ h*((1901.0/720.0)*f(x0+4*h,k4) - (1387.0/360.0)*f(x0+3*h, k3) +
		(109.0/30.0)*f(x0+2*h,k2) - (637.0/360.0)*f(x0+h,k1) +
		(251.0/720.0)*f(x0,y));
 y = k5;
 x0 += 5*h;
 }
 return y;
}

double AdamsMoulton(double(*f)(double),double x0, double y0, double y1, double x, double h)
{
 double k0,k1,k2,k3,k4,y = y0;
 while(x0 < x)
 {


 }
 return y;

}
