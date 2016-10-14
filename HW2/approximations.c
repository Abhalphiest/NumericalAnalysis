#include"approximations.h"
#include <stdio.h> //for print debugging


#define pi 3.141592653589793

double lagrangePoly(int n, Point* points, double xval)
{
	double a, s, t, k = 0.0f;
	for(int i = 0; i < n; i++)
	{
		s = 1.0f, t = 1.0f;
		for(int j = 0; j < n; j++)
		{
			if(j != i)
			{
				s = s*(xval-points[j].x);
				t = t*(points[i].x-points[j].x);
			}
		}
		k+=((s/t)*points[i].y);
	}
	return k;
	
}

double* cubicSpline(int n, int boundcondition, 
		double c1, double c2, Point* points)
{
	
  double* matrix = calloc(n*n, sizeof(double)); //calloc initializes to 0
  double* RHS = calloc(n, sizeof(double));
  double* solution = calloc(n, sizeof(double));
	

	
  for (int i=1; i<n-1; i++) 
  {
    RHS[i] = 6.0*((points[i+1].y-points[i].y)/(points[i+1].x-points[i].x)-
		  (points[i].y-points[i-1].y)/(points[i].x-points[i-1].x));

      //fill in our matrix
      matrix[i*n+(i-1)]+=points[i].x-points[i-1].x;
      matrix[i*n+i]+=2.0*(points[i+1].x-points[i-1].x);
      matrix[i*n+i+1]+= points[i+1].x- points[i].x;
  }
  
  switch(boundcondition)
  {
	case NATURAL:
	matrix[0] = 1.0;
    RHS[0]=0.0;
    matrix[n*n-1] = 1.0;
    RHS[n-1] = 0.0;
	break;
	
	case CURVEADJUSTED:
	matrix[0] = 1.0;
    RHS[0] = c1;
    matrix[n*n-1] = 1.0;
    RHS[n-1] = c2;
	break;
	
	case CLAMPED:
	matrix[0] = 2.0;
    matrix[1] = 1.0;
    RHS[0]=6.0*((points[1].y-points[0].y)/(points[1].x-points[0].x) - c1);
    matrix[n*n-2] = 1.0;
    matrix[n*n-1] = 2.0;
    RHS[n-1] = 6.0*(c2 - (points[n-1].y-points[n-2].y)/(points[n-1].x-points[n-2].x) );
	break;
	
	case PARABOLIC:
	matrix[0] = 1.0;
    matrix[1] = -1.0;
    RHS[0]=0.0;
    matrix[n*n-2] = -1.0;
    matrix[n*n-1] = 1.0;
    RHS[n-1] = 0.0;
	break;
	
	case NOTAKNOT:
	matrix[0] = points[2].x-points[1].x;
    matrix[1] = points[0].x-points[2].x;
    matrix[2] = points[1].x-points[0].x;
    RHS[0]=0.0;
    matrix[n*n-3] = points[n-1].x-points[n-2].x;
    matrix[n*n-2] = points[n-3].x-points[n-1].x;
    matrix[n*n-1] = points[n-2].x-points[n-3].x;
    RHS[n-1] = 0.0;
	break;
	  
  }
    
  //GSL stuff for linear system solving

  gsl_matrix_view m = gsl_matrix_view_array (matrix,n,n);
  gsl_vector_view b = gsl_vector_view_array (RHS,n);
  gsl_vector *x = gsl_vector_alloc(n);
  int s;
  gsl_permutation * p = gsl_permutation_alloc(n);
  gsl_linalg_LU_decomp(&m.matrix,p,&s);
  gsl_linalg_LU_solve(&m.matrix,p,&b.vector,x);

  //x has the solution
  for (int i=0; i<n; i++) {
    solution[i] = gsl_vector_get(x, i);
  }

  gsl_permutation_free(p);
  gsl_vector_free(x);

  //free our memory before returning
  free(matrix);
  free(RHS);
  return solution;
}


//adapted from algorithm from numerical recipes book
double splint(double* y_p, int n, Point* points, double xval)
{
  int k,klo = 0,khi=n-1;
  float h, b, a;
  
  //bisection search for correct interval
  while(khi-klo > 1)
  {
   k = (khi + klo) >> 1; //take midpoint of the indices
   if(points[k].x > xval) khi = k;
   else klo = k;
  }
  
  h = points[khi].x - points[klo].x;
  
  a = (points[khi].x - xval)/h;
  b = (xval - points[klo].x)/h;
  
  return a*points[klo].y+b*points[khi].y + ((a*a*a-a)*y_p[klo] + (b*b*b-b)*y_p[khi])*(h*h)/6.0;
   
}
//not implemented yet
Point bezier(int n, Point* points, double t)
{
	
}


//for chebyshev
double Tnx(int n, double x)
{
 return cos(n*acos(x));
}

double* chebyshev_coeff(double a, double b, int n, double (*f)(double))
{
  double* points = (double*) malloc(n*sizeof(double));
  double* coefs = (double*) calloc(n,sizeof(double));

  int i,j;
  double angle, x;

  for(i=0; i<n; i++){
    angle = (double) (2*i + 1)*pi / (double) (2*n);
	x = cos(angle);
	x = .5 * (a+b) + x* .5 * (b-a) ; //adjust for different interval
	points[i] = f(x);
  }

  for(i=0; i<n; i++){
    for(j=0; j<n; j++) {
	  angle = (double)((i*(2*j+1))*pi)/(double)(2*n);
      coefs[i]+=points[j]*cos(angle);
    }
    //This is the normalization for all terms other than zero
    coefs[i] *= 2.0/(double)n;
  }

  free(points);
  return coefs;
	
}


//actually gives us an approximation
double chebyshev(double a, double b, int n, double* c, double x)
{
	double di=0.0,dip1=0.0,dip2,y;
	int i;
	y = (2.0*x - a - b)/(b-a);
	for(i = n-1; 0 < i; i--)
	{
		dip2 = dip1;
		dip1 = di;
		di = 2.0*y * dip1 - dip2 + c[i];
		
	}
	return y*di-dip1+0.5*c[0];
}
