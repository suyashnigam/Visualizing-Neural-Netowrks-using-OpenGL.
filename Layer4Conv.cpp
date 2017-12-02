#include "DisplayLayer.h"
#include <stdio.h>
#include<iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer4Conv.h"
#include <vector>
#include "ParseString.h"
using namespace std;


void Layer4_conv::conv(double input[14*14][16])
{
	int height = 16, width = 16, depth = 16;//Including the padding as well
	double *bias = ParseBias("bias_5.txt", 0, 32);
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
	for (int k = 0; k < 16; ++k)
	{
		
		for (int j = 0; j < 14; ++j)
		{
			for (int i = 0; i < 14; i++)
			{
				input3D[j+1][i+1][k] = input[(j)*14+i][k];
			}
		}
	}
	
	for (int filt_channel = 0; filt_channel < 32; filt_channel++)
	{
		
		double **filters = ParseWeights("Weights_5.txt", filt_channel*16,(filt_channel+1)*16);
		
		//Convolution Operation
		double sum = 0;
		for (int m = 0; m < 16; ++m)
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
					output_conv[14 * i + j][filt_channel] = output_conv[14 * i + j][filt_channel] + sum+bias[filt_channel];
				}
			}
		}
	}
}

void Layer4_conv::Show(int n)
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
	dispLay.x_l = 400;
	dispLay.y_l = 275;

	dispLay.DrawLayer(n, size, arr);
}

