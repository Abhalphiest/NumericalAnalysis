//calculates the absolute and relative error of a problem2.exe output for
//5 point stencils

#include<stdio.h>
#include<math.h> //for trig
#include<stdlib.h> //for strtol

//derivatives from wolfram alpha
double firstderiv(double x)
{
 return exp(cos(x))*(cos(x)-sin(x)*sin(x));
}

double secondderiv(double x)
{
 return sin(x)*exp(cos(x))*(sin(x)*sin(x)-3*cos(x)-1);
}

int main(int argc, char** argv)
{
 if(argc < 2) return -1;
 int count = (int) strtol(argv[1],NULL,10);
 double absErrorSum=0, relErrorSum=0;
 double x, f_x, estimate, val;
 for(int i = 0; i < count; i++)
 {
  scanf("x:\t %lf \t f(x): \t %lf \t f'(x) \t %lf \n",&x, &f_x,&estimate);
  val = firstderiv(x);
  absErrorSum += fabs(val-estimate);
  relErrorSum += fabs((estimate-val)/val);
  printf("val: %lf estimate: %lf\n",val,estimate);
 }
 printf("\n\nFirst Derivative \n\n");
 printf("Average Absolute Error: %lf\n",absErrorSum/count);
 printf("Average Relative Error: %lf\n",relErrorSum/count);

 absErrorSum = 0, relErrorSum=0;
 for(int i = 0; i < count; i++)
 {
  scanf("x:\t %lf \t f(x): \t %lf \t f''(x) \t %lf \n",&x,&f_x,&estimate);
  val = secondderiv(x);
  absErrorSum += fabs(val-estimate);
  relErrorSum += fabs((estimate-val)/val);
  printf("val: %lf  estimate: %lf\n",val,estimate);
 }
 printf("\n\nSecond Derivative \n\n");
 printf("Average Absolute Error: %lf\n", absErrorSum/count);
 printf("Average Relative Error: %lf\n", relErrorSum/count);
}
