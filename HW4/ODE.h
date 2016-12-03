#include<math.h>

double Euler(double(*f)(double,double),double x0, double y0, double x, double h);
double RK2(double (*f)(double,double), double x0, double y0, double x, double h);
double RK4(double (*f)(double,double),double x0, double y0, double x, double h);
//runge kutta solver for second order eqn split into a first order system
 double RK4_2(void (*f)(double,double,double, double*, double*), double x0, double y0, double yp0, double x, double h);
double AdamsBashforth(double(*f)(double,double), double x0, double y0, double x, double h);
double AdamsMoulton(double(*f)(double,double), double x0, double y0, double x, double h);
