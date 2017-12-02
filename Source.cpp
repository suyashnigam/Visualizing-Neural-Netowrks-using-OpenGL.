#include "ParseStringBias.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
int main(void) {
	//FILE *fp = fopen('Weights_2.txt', 'r');
	int start = 3, end = 10;
	double *bias =ParseWeights("bias_2.txt", start, end);
	for (int i = 0; i < end-start; i++)
	{
		std::cout << bias[i]<<"\n";
	}
	return 0;
}