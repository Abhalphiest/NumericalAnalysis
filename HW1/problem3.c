/*
 * File:	problem3.c
 * Course:	MATH 411, Fall 2016
 * Author:	Margaret Dorsey
 *
 * Homework 1	Problem 3
 *
 * Write code that can invert a given matrix, using as much pre-existing
 * code as possble. Through legal use of numerical libraries and packages,
 * see how little code you have to write yourself to do this task.
 * Make sure to find good code to do this, with pivoting, not just a straight
 * Gauss-Jordan elimination code, or heaven forfend, Cramer's rule. Please 
 * submit your code, noting where you got it from.
 *
 */

#include<gsl/gsl_linalg.h>
#include<stdio.h>

//
// I used the GSL library, or GNU Scientific Library, to do the inversion
// with an LU decomposition (using a mixture of pivot and GJ methods). The
// GSL library is default for many *nix systems, but it is available at
// 
// https://www.gnu.org/software/gsl/
//
// and because it is open source, the source code for it is available as well.
//


int main(int argc, char** argv)
{
 printf("Please enter the dimension of the matrix: \n");
 int dim; //dimension of our square matrix
 scanf("%d",&dim);
 printf("Enter your values, row major: ");
 gsl_matrix* mat = gsl_matrix_alloc(dim, dim);

 float val;
 for(int i = 0; i < dim; i++) //fill in our matrix
 {
  for(int j = 0; j < dim; j++)
   {
	scanf("%f", &val);
        //printf(" %f\n", val);
	gsl_matrix_set(mat,i,j, val); 
   }
 }
 gsl_matrix_fprintf(stdout, mat,"%f"); //print it out for the user

 gsl_permutation* p = gsl_permutation_alloc(dim);
 int sign;
 gsl_matrix* inverse = gsl_matrix_alloc(dim,dim); //for LU decomposition
 //printf("test");
 gsl_linalg_LU_decomp(mat, p, &sign);
 //gsl_permutation_fprintf(stdout, p, "%f");
 gsl_linalg_LU_invert(mat, p, inverse);
 printf("\n");
 gsl_matrix_fprintf(stdout, inverse, "%f");
 gsl_permutation_free(p);
 gsl_matrix_free(inverse);
 gsl_matrix_free(mat); //free our matrix and return success
 return 0;
}
