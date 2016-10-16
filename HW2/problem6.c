#include "approximations.h"
#include<stdio.h>

double f1(double x)
{
 return cos(2*pi*x);

}

double f2(double x)
{
 if(x < 0) //calculating sign
   return -f1(x);
 else if(x > 0)
   return f1(x);
 else 
   return 0; //defined as 0 at 0
}

double f3(double x)
{
 return sin(2*pi*fabs(x));
}

void printCoeffs(double* coeff, int n)
{
 for(int i = 0; i < n; i++)
  printf("%lf\n",coeff[i]);
}

int main()
{
 double* coeffs = chebyshev_coeff(-1,1,10,f1);
 printf("\n\n Function 1: 10 Nodes \n\n");
 printCoeffs(coeffs, 10);
 free(coeffs);
 coeffs = chebyshev_coeff(-1,1,20,f1);
 printf("\n\n Function 1: 20 Nodes \n\n");
 printCoeffs(coeffs,20);
 free(coeffs);


 coeffs = chebyshev_coeff(-1,1, 20, f2);
 printf("\n\n Function 2: 10 Nodes \n\n"); 
 printCoeffs(coeffs,10);
 free(coeffs);
 coeffs = chebyshev_coeff(-1,1,20,f2);
 printf("\n\n Function 2: 20 Nodes \n\n");
 printCoeffs(coeffs,20);
 free(coeffs);
	
 coeffs = chebyshev_coeff(-1,1, 20, f3);
 printf("\n\n Function 3: 10 Nodes \n\n"); 
 printCoeffs(coeffs,10);
 free(coeffs);
 coeffs = chebyshev_coeff(-1,1,20,f3);
 printf("\n\n Function 3: 20 Nodes \n\n");
 printCoeffs(coeffs,20);
 free(coeffs);
}
