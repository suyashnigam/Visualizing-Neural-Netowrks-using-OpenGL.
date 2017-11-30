#include "DisplayLayer.h"
#include <stdio.h>
#include<iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer7Conv.h"
#include <vector>
#include "ParseString.h"
using namespace std;


void Layer7_conv::conv(double input[7 * 7][32])
{
	int height = 9, width = 9, depth = 32, filters = 64;;//Including the padding as well
											//Initialize the Vector
	input3D.resize(height);
	for (int i = 0; i < height; ++i)
	{
		input3D[i].resize(width);
		for (int j = 0; j < width; ++j)
		{
			input3D[i][j].resize(depth);
		}
	}

	//Copying the incoming 2D matrix into the 3D Vector
	for (int k = 0; k < depth; ++k)
	{

		for (int j = 0; j < size; ++j)
		{
			for (int i = 0; i < size; i++)
			{
				input3D[j + 1][i + 1][k] = input[(j) * size + i][k];
			}
		}
	}

	for (int filt_channel = 0; filt_channel < filters; filt_channel++)
	{

		double **filters = ParseWeights("Weights_8.txt", filt_channel * depth, (filt_channel + 1) * depth);

		//Convolution Operation
		double sum = 0;
		//loop for each filter
		for (int m = 0; m < depth; ++m)
		{

			//Convert filter[3*3][m] into filter_buffer[3][3]
			//Convert the 9 element column of a 2D array into another array
			//Define buffers for each channel
			double **filter_buffer;
			double column_filter_buffer[9];
			for (int i = 0; i < 9; ++i)
			{
				column_filter_buffer[i] = *(filters[m] + i);
			}
			//Obtain filter_buffer[3][3]
			filter_buffer = Vector2Image(column_filter_buffer, 3);

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					sum = 0;
					for (int k = 0; k < 3; k++)
					{
						for (int l = 0; l < 3; l++)
						{
							sum = sum + filter_buffer[k][l] * input3D[i + k][j + l][m];
						}
					}
					output_conv[size * i + j][filt_channel] = output_conv[size * i + j][filt_channel] + sum;
				}
			}
		}
	}
}

void Layer7_conv::Show(int n)
{
	double** arr;
	arr = new double*[n];
	for (int i = 0; i <n; i++)
	{
		arr[i] = new double[size*size];
	}

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < size*size; i++)
		{
			arr[j][i] = output_conv[i][j];
		}
	}

	DisplayLayer dispLay;
	dispLay.x_l = 550;
	dispLay.y_l = 150;

	dispLay.DrawLayer(n, size, arr);
}

