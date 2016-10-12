#include"approximations.h"
#include <stdio.h> //for print debugging

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

void cubicSpline(int n, int boundcondition, double c1, double c2, Point* points)
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

  for (int i=0; i<n; i++) {
    solution[i] = gsl_vector_get(x, i);
  }

  gsl_permutation_free(p);
  gsl_vector_free(x);

  free(matrix);
  free(solution);
  free(RHS);
	
}

Point bezier(int n, Point* points, double t)
{
	Point* tmp = (Point*) malloc(sizeof(Point)*n); //this is costly but doesn't matter at this scale
	memcpy(tmp, points, n*sizeof(Point));
	for(int i = n - 1; i >  0; i--)
	{
		for(int k = 0; k < i; k++)
		{
			tmp[k].x = tmp[k].x+t*(tmp[k+1].x - tmp[k].x);
			tmp[k].y = tmp[k].y+t*(tmp[k+1].y - tmp[k].y);
		}
	}
	Point result = tmp[0];
	free(tmp);
	return result;
	
}

double Tnx(int n, double x)
{
 return cos(n*acos(x));
}
