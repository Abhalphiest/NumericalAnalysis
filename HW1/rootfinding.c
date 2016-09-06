



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

  printf("i: %d a: %lf b: %lf value: %.9lf \n", i, a, b, f);
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
   printf("i: %d a: %lf b: %lf value: %.9lf\n", i, a, b, f);
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
  printf("i: %d a: %lf b: %lf value: %.9lf\n", i, a, b, f);
 }
 return c;
}

double FPI(double (*g)(double),double(*function)(double), double a)
{
 double c = a;
 double f = ACC*2;
  
 for(int i = 0; i < MAX_ITER && fabs(c - g(c)) > ACC; i++)
 {
  f = g(c);
  printf("i: %d x: %lf value: %.9lf\n",i,c,f);
  c = f;
 }
 return c;
}
void header(char* name)
{
 printf("\n\n");
 printf("--------------------------\n %s\n -----------------------\n",name);
 printf("\n\n");
 return;
}