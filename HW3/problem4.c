//
// File:	problem4.c
// Author:	Margaret Dorsey
//
// MATH 411 Numerical Analysis Homework 3 Problem 4
//
// Integration of Plank's Law

#include"numericalcalc.h"
#include<stdio.h>

double f_x(double x) //transformed for improper integral
{
 double val = x/(1-x);
 return ((val*val)*(val+1)*(val+1))/(exp(val)-1);
}

double g_x(double x) //for mean photon energy
{
 double val = x/(1-x);
 return x*f_x(x);
}

double f_y(double y)
{
 double val = y/(1-y);
 
// printf("val:%lf f:%lf\n",val,((val+1)*(val*1))/((exp(val)-1)*val));
 return ((val+1)*(val+1))/((exp(val)-1)*val);

}
double g_y(double y)
{
 double val = y/(1-y);
 return val*f_y(y);
}
double mean;
double f_dev(double x)
{
 double val = x/(1-x);
 return (val-mean)*(val-mean)*f_x(x);

}


int main()
{
 double upperbound,lowerbound;
 int n;
 printf("Enter bounds separated by space: ");
 scanf("%lf %lf",&lowerbound,&upperbound);
 printf("n: ");
 scanf("%d",&n);
 double result = simpson(f_x,lowerbound,upperbound,n);
 printf("Result: %lf\n",result);


 double half = result/2.0;
 double median = (lowerbound+upperbound)/2;
 double temp = simpson(f_x,lowerbound,median,n);
 double ub = upperbound;
 double lb = lowerbound;
 while(fabs(temp - half) > .000001)
 {
  if(temp > half)
  {
   ub = median;
   median -= (median - lb)/2;
  }
  else
  {
   lb = median;
   median+= (ub - median)/2;
  }
 //printf("%lf\n",median);
  temp = simpson(f_x,lowerbound,median,n);
 } 
 printf("\n\nmedian: %lf\n",median);

 mean = simpson(g_x,lowerbound,upperbound,n);
 mean /= result;
 printf("mean photon energy: %lf\n",mean);

 double wavresult = simpson(f_y, lowerbound,upperbound,n);
 double wavmean = simpson(g_y, lowerbound, upperbound,n);
 wavmean /= wavresult;
 printf("total wavelength: %lf\n",wavresult);
 printf("mean wavelength: %lf\n",wavmean);

 double stddev = simpson(f_dev,lowerbound,upperbound,n);
 stddev/=result;
 stddev = sqrt(stddev);
 printf("Standard deviation in wavelength: %lf\n",stddev);
}
