



#include "rootfinding.h"
double bisection(double(*function)(double),double a, double b)
{
 double c;
 double f = 2*ACC; //multiplication by 2 is fastest (will be compiled to 
		  //bitshift)  
 int i;
 for(i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
  c = (b + a)/2.0;
  f = function(c);

  if(f < 0)
	a = c;
  else
	b = c;

  printf("i: %d\ta: %.9lf\tb: %.9lf\tvalue: %.9lf \n", i, a, b, f);
 }

 return c;
}

double secant(double(*function)(double),double a, double b)
{
 double c;
 double f = 2*ACC;
 for(int i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
   c =(a*function(b) - b*function(a))/(function(b) - function(a));
   f = function(c);
   a = b;
   b = c;
   printf("i: %d\ta: %.9lf\tb: %.9lf\tvalue: %.9lf\n", i, a, b, f);
 }
 return c;
}

double falseposition(double(*function)(double),double a, double b)
{
 
 double c;
 double f = 2*ACC;
 for(int i = 0; i < MAX_ITER && fabs(f) > ACC; i++)
 {
  c = (a*function(b) - b*function(a))/(function(b) - function(a));
  f = function(c);
  if(function(c)*function(a) < 0)
  	b = c;
  else 
	a = c;
  printf("i: %d\ta: %.9lf\tb: %.9lf\tvalue: %.9lf\n", i, a, b, f);
 }
 return c;
}

double FPI(double (*g)(double), double a)
{
 double c = a;
 double f = ACC*2;
  
 for(int i = 0; i < MAX_ITER && fabs(c - g(c)) > ACC; i++)
 {
  f = g(c);
  printf("i: %d\tx: %.9lf\tvalue: %.9lf\n",i,c,f);
  c = f;
 }
 return c;
}

double newton1D(double(*f)(double),double(*f_prime)(double), double x, int max_iter)
{
	int i = 0; //iteration counter
	while(fabs(f(x)) > ACC && i < max_iter)
	{
		while(f_prime(x) == 0) //avoid problems unless it's constant..
			x += .001;
		x -= f(x)/f_prime(x);
		printf("i: %d\tx: %.9lf\tvalue: %.9lf\n",i,x,f(x));
		i++;
	}
	return x;
}

void newton2D(double(*f)(double, double),double(*f_x)(double, double), 
		double(*f_y)(double, double), double(*g)(double, double),
		double(*g_x)(double, double),double(*g_y)(double, double),
		double x, double y, int max_iter)
{
	printf("in newton2D\n");
	int i = 0; //iteration counter
	double d = 0; //for our matrix inversion
	printf("%lf %lf\n",pow(f(x,y),2),pow(g(x,y),2));
	while(pow(f(x,y),2) + pow(g(x,y),2) > ACC && i < max_iter)
	{
		d = f_x(x,y)*g_y(x,y) - f_y(x,y)*g_x(x,y);
		if(d == 0)
		  break;
		
		x -= d*g_y(x,y)*f(x,y) - d*f_y(x,y)*g(x,y);
		y -= d*f_x(x,y)*g(x,y) - d*g_x(x,y)*f(x,y);
		printf("i: %d\tx: %.9lf\ty: %.9lf\nf(x,y): %.9lf\tg(x,y): %.9lf\n",i,x,y,f(x,y),g(x,y));
		i++;
	}
}


void header(char* name)
{
 printf("\n\n");
 printf("--------------------------\n %s\n -----------------------\n",name);
 printf("\n\n");
 return;
}
