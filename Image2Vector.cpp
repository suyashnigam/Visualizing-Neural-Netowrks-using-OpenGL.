#include "Image2Vector.h"

double *Image2Vec(double **arr, int n)
{
	double *temp;
	int element;
	element = n*n;
	temp = new double[element];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i*n + j] = arr[i][j];
		}

	}
	return temp;
}