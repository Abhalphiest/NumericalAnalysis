/*
 * File:	problem2.c
 * Course:	MATH 411, Fall 2016
 * Author:	Margaret Dorsey
 * 
 * Homework 1 Problem 2
 *
 * Write a program that greets the world. Have it read in a number and
 * then write it back out. Then have it write out the value of pi, using
 * only inverse trig functions and multiplication/divisions.
 *
 */


#include<stdio.h>
#include<math.h>

int main(int argc, char** argv)
{
 printf("Hello, world! \n");
 float num;
 scanf("%f", &num);
 printf("%f \n", num);
 printf("Pi is %f  \n", atan(1)*4);

 return 0; //exit success
}
