#include <stdio.h>
#include <stdlib.h>
#include "LCCDE.h"
#define ARRAY_SIZE 10
int main(){

	int L = ARRAY_SIZE;
	int M = ARRAY_SIZE;
	int N = ARRAY_SIZE;
	float a[ARRAY_SIZE];
	float b[ARRAY_SIZE];
	float x[ARRAY_SIZE];
	float y[ARRAY_SIZE];

	for (int i = 0; i < (int)(sizeof(y)/sizeof(int)); i++) {
		y[i] = 0;
		a[i] = (float)rand() / (float)RAND_MAX;
		b[i] = (float)rand() / (float)RAND_MAX;
		x[i] = (float)rand() / (float)RAND_MAX;
	}

	//Part A
	filter(&b, M, &a, N, &x, L, &y);
	
	//Part B
	conv(&a, L, &b, M, &y);

	//Part C


}

void filter(float* b, int M, float* a, int N, float* x, int L, float* y) {
	float sum1 = 0;
	float sum2 = 0;
	printf("Filter\n");
	for (int i = 0; i < L; i++) {
	
		for (int j = 1; j <= N; j++)
		{
			if (i - j >= 0) {
				sum1 += a[j] * y[i - j];
			}
			
		}
		sum1 *= -1;
		for (int j = 0; j <= M; j++) {
			if (i - j >= 0) {
				sum2 += b[j] * x[i - j];
			}
		}
		y[i] = sum1 + sum2;
		sum1 = 0;
		sum2 = 0;
		printf("%f\n",y[i]);
	}
	
}

void conv(float* x, int L, float* h, int M, float*y) {
	float sum = 0;
	printf("Convolution \n");

	for (int i = 0; i < L; i++) {

		for (int j = 0; j < M; j++) {
			if (i - j >= 0) {
				sum = h[j] * x[i - j];
			}
		}
		y[i] = sum;
		sum = 0;
		printf("%f\n", y[i]);
	}


}