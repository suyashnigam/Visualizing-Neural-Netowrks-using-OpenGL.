#include "Layer1Conv.h"
#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer9FullyConnected.h"
#include "Parse9.h"


//void transpose(double filters[3136][10], double filterst[10][3136]);

Layer9_FullyConnected::Layer9_FullyConnected()
{
	for (int i = 0; i < 10; i++)
	{
		output_vector[i] = 0;
	}
	
}

void Layer9_FullyConnected::FullyConnected(double input_fully_c[7 * 7][64], double **filter)
{
	int i, j, k;
	i = 0;
	//Initialize everything to zero
	for (int i = 0; i < 10; i++)
	{
		output_vector[i] = 0;
	}
	//Column-Wise Expansion
	double input_changed[7 * 7][64] = { 0 };
	int count = 0;
	for (int k = 0; k < 64; k++)
	{
		count = 0;
		for (int j = 0; j < 7; j++)
		{
			for (int i = 0; i < 49; i++)
			{
				if (i % 7 == j)
				{
					input_changed[count][k] = input_fully_c[i][k];
					count++;
				}
			}
		}
	}

	for (j = 0; j < 64; j++)
	{
		for (k = 0; k < 49; k++)
		{
			output_fully_c[i] = input_changed[k][j];
			i++;
		}
	}

	get_weights(filter);
	operation();
}

void Layer9_FullyConnected::get_weights(double **filter)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 7 * 7 * 64; j++)
		{
			weights[i][j] = filter[i][j];
		}
	}

}

void Layer9_FullyConnected::operation()
{
	int i, j;
	double weightst[10][3136] = { 0 };
	
	for (i = 0; i < 10; i++)
	{
		output_vector[i] = 0;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 7 * 7 * 64; j++)
		{
			output_vector[i] += weights[i][j] * output_fully_c[j];
		}
		output_vector[i] += bias[i];
	}
}