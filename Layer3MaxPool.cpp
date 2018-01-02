#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer3MaxPool.h"
#include <vector>
#include "fssimplewindow.h"
#include "ysglfontdata.h"


double layer3_MaxPool::max1(double e1, double e2, double e3, double e4)
{
	double a[4];
	a[0] = e1;
	a[1] = e2;
	a[2] = e3;
	a[3] = e4;
	double max = a[0];
	for (int i = 0; i < 4; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void layer3_MaxPool::maxP(double input[28 * 28][16])
{
	int  j, max, p, q;
	std::vector<std::vector<double>> input_buffer_vec;
	input_buffer_vec.resize(28);
	for (int i = 0; i < 28; i++)
	{
		input_buffer_vec[i].resize(28);
	}
	for (int k = 0; k < c; k++)
	{
		int m = 0;
		for (int p = 0; p < 28; p++)
		{
			for (int q = 0; q < 28; q++)
			{
				input_buffer_vec[p][q] = input[m][k];
				m++;
			}

			j = 0;
			for (int i = 0; i < 28; i += 2)
				for (int l = 0; l < 28; l += 2)
				{
					{
						output_maxP[j][k] = max1(input_buffer_vec[i][l], input_buffer_vec[i][l + 1], input_buffer_vec[i + 1][l], input_buffer_vec[i + 1][l + 1]);
						j++;
					}
				}
		}
		/*
		for (int i = 0; i < 45; i++)
		{
			std::cout << "Behenchod " << "\n";
			std::cout << output_maxP[i][0] << " ";
			if (i == 14) { std::cout << "\n dfsdgvs"; }
		}
		*/
	}
}

int layer3_MaxPool::parameter()

{
	return ksize;
}
/*
char* layer3_MaxPool::info()
{
	return info;
}
*/

void layer3_MaxPool::show(int n)
{
	double** arr;
	arr = new double*[n];
	for (int i = 0; i < n; i++)
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
	dispLay.x_l = 422; //Change This
	dispLay.y_l = 460;
	dispLay.gap = 76;

	dispLay.DrawLayer(n, out_size, arr);
	glColor3ub(0, 0, 0);
	glRasterPos2d(225, 495);
	YsGlDrawFontBitmap10x14("MaxPooling 1");
	glRasterPos2d(1215, 495);
	YsGlDrawFontBitmap10x14("6/16 Images");
	dispLay.CleanUp();


	// Cleaning Up
	for (int i = 0; i <n; i++)
	{
		delete[] arr[i];
	}
}