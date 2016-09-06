/* 
 * File:	problem1.c
 * Course:	MATH 411, Fall 2016
 * Author:	Margaret Dorsey
 * 
 * Homework 1	Problem 1
 *
 * Break math using a computer. To be a bit more specific, demonstrate a 
 * numerical calculation using the computer language of your choice where
 * the answer is demonstrably wrong. I'll want to see the code you used,
 * preferably something brief and punchy, and then the result.
 *
 * For full credit, fix math again by demonstrating an alternate method
 * of calculating the result that previously broke math but yields the 
 * correct answer.
 *
 */

#include<stdio.h>
#include<math.h>

void broken();
void notBroken();

int main(int argc, char** argv)
{
  if(argc > 1) //has command line argument
  {
   	notBroken(); //the correct algorithm
  }
  else
	broken();   //the math breaking

  return 0;
}


//because .1 cannot be represented as a finite floating
//point number in base 2 (much like 1/3 cannot be a finite decimal
//in base 10) we end up with significant error - we shouldn't have any numbers
// with more than one non-zero decimal place, but our last number printed
// is 9.99999999998!
void broken()
{
  double i = -1.0;
  for(int j = 0; j < 1000000; j++)
  {
    i += 0.10;
  }
  fprintf(stdout, "-1 + 1000000*.1 = %f \n",i);
  return;
}


// Here we avoid the problem entirely by essentially building our own floating
// point numbers. We know sums of .1 will always only have at most 1 nonzero
// decimal place, and so we can simply represent our number as an integer plus
// a tenths place and handle it that way. This wouldn't necessarily work
// for more difficult numbers with no float representation.
void notBroken()
{
  int base = -1;
  int dec = 0;
  for(int j = 0; j < 1000000; j++)
  {
   dec++;
   if(dec > 9)
   {
    base++;
    dec = 0;
   }
  }
  fprintf(stdout,"-1 + 1000000*.1 = %d.%d \n", base, dec);

}
