#include "Layer1Conv.h"
#include "DisplayLayer.h"
#include <stdio.h>
#include<iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "ParseString.h"
#include "ysglfontdata.h"
#include "fssimplewindow.h"

void Layer1_Conv::conv(double **input,double **filters,double *bias)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			input_conv[i][j] = input[i][j];
		}
	}
	//Making the input of the layer accessible in the class
	//Pad the image
	double conv_im[30][30];//////////////////////////////////////////////////////////
	for (int i = 0; i < size+2; ++i)
	{
		for (int j = 0; j < size+2; ++j)
		{
			//Padding
			if (j == 0 || j == size+1 || i == 0 || i == size+1) 
			{
				conv_im[i][j] = 0;
			}
			else { conv_im[i][j] = input_conv[i-1][j-1]; }
		}
	}


	//Convolution Operation
	double sum = 0;
	double **output_buffer;
	output_buffer = new double*[size];

	for (int i = 0; i <size; i++)
	{
		output_buffer[i] = new double[size];
	}

	for (int m = 0; m < c; ++m)
	{
		
		//Define buffers for each channel
		double **filter_buffer;	

		//Convert filter[3*3][m] into filter_buffer[3][3]
		//Convert the 9 element column of a 2D array into another array
		double column_filter_buffer[9];

		for (int i = 0; i < 9; ++i)
		{
			column_filter_buffer[i] = *(filters[m] + i);
		}
		//Obtain filter_buffer[3][3]
		filter_buffer = Vector2Image(column_filter_buffer, 3);
		//std::cout << "\n\n now printing Conv1 output \n\n";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						sum = sum + filter_buffer[k][l] * conv_im[i + k][j + l];
					}
				}
				output_buffer[i][j] = sum + bias[m];
				//if (m == 0)
				//	std::cout << output_buffer[i][j] << " ";
			}
			//std::cout << "\n";
		}
		//std::cout << "\n conv1 done \n";

		//Convert output_buffer[28][28] into output[28*28][m]
		output_buffer_col = Image2Vec(output_buffer, size);
		for (int k = 0; k < size*size; ++k)
		{
			output_conv[k][m] = output_buffer_col[k];
		}

		// Cleaning Up
	
	}
	for (int i = 0; i <size; i++)
	{
		delete[] output_buffer[i];
	}
	delete[] output_buffer_col;
}

void Layer1_Conv::Show(int n)
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
	dispLay.x_l = 394;
	dispLay.y_l = 550;
	dispLay.gap = 20;

	dispLay.DrawLayer(n, size, arr);
	glColor3ub(0, 0, 0);
	glRasterPos2d(225, 610);
	YsGlDrawFontBitmap10x14("Convolution 1");
	glRasterPos2d(1215, 610);
	YsGlDrawFontBitmap10x14("6/16 Images");
	dispLay.CleanUp();
	

	// Cleaning Up
	for (int i = 0; i <n; i++)
	{
		delete[] arr[i];
	}
}
