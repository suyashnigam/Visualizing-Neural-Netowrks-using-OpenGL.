#pragma once
#include<stdio.h>
#ifndef PARSE9_H_IS_INCLUDED
#define PARSE9_H_IS_INCLUDED

class HugeWeights

{
public:
	double **rowPointer;
	int numOfLines = 10, numInLine = 3136;
	FILE* fp;

	HugeWeights(FILE *fp1);

	double**  Run(void);
	double* ProcessLine(char* line, int numInLine);
	void ParseText1();
};

#endif // !PARSE9_H_IS_INCLUDED
