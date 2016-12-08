#pragma once
#ifndef FFT_H
#define FFT_H

#include <math.h>
#include "complex.h"
#define M_PI 3.14159265359

class FFT {
private:
	unsigned int N, which;
	unsigned int log_2_N;
	float pi2;
	unsigned int *reversed;
	complex **T;
	complex *c[2];
protected:
public:
	FFT(unsigned int N);
	~FFT();
	unsigned int reverse(unsigned int i);
	complex t(unsigned int x, unsigned int N);
	void fft(complex* input, complex* output, int stride, int offset);
};

#endif