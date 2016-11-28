#include<math.h>

double Euler(double(*f)(double,double),double x0, double y0, double x, double h);
double RK2(double (*f)(double,double), double x0, double y0, double x, double h);
double RK4(double (*f)(double,double),double x0, double y0, double x, double h);
double AdamsBashforth(double(*f)(double,double), double x0, double y0, double x, double h);
double AdamsMoulton(double(*f)(double,double), double x0, double y0, double x, double h);
