
#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer6MaxPool.h"


double layer6_MaxPool::max1(double e, double b, double c, double d)
{
	double a[4];
	a[0] = e;
	a[1] = b;
	a[2] = c;
	a[3] = d;
	double max = a[0];
	for (int i = 0; i < 4; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void layer6_MaxPool::maxP(double input[14 * 14][32])
{
	int  j, max, p, q;

	for (int k = 0; k < c; k++)
	{
		double input_buffer[14][14];
		for (int m = 0; m < in_size*in_size; m++)
		{
			p = m / in_size;
			q = m % in_size;
			input_buffer[p][q] = input[m][k];
		}
		j = 0;
		for (int i = 0; i < in_size; i += 2)
			for (int l = 0; l <in_size; l += 2)
			{
				{
					output_maxP[j][k] = max1(input_buffer[i][l], input_buffer[i][l + 1], input_buffer[i + 1][l], input_buffer[i + 1][l + 1]);
					j++;
				}
			}

	}
}

int layer6_MaxPool::parameter()

{
	return ksize;
}
/*
char* layer3_MaxPool::info()
{
return info;
}
*/

void layer6_MaxPool::show(int n)
{
	double** arr;
	arr = new double*[n];
	for (int i = 0; i <n; i++)
	{
		arr[i] = new double[out_size*out_size];
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < out_size*out_size; i++)
		{
			arr[j][i] = output_maxP[i][j];
		}
	}
	DisplayLayer dispLay;
	dispLay.x_l = 100; //Change This - Iterate
	dispLay.y_l = 500;
	dispLay.DrawLayer(n, out_size, arr);
}