#include "Layer1Conv.h"
#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
//#include "layer3.h"
#include "Layer2Relu.h"


void Layer2_Relu::ReLU(double input[28 * 28][16])
{

	for (int i = 0; i < 28 * 28; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (input[i][j] < 0)
			{
				output_ReLU[i][j] = 0.0;
			}
			else
				output_ReLU[i][j] = input[i][j];

		}
	}
	//The output into the next function should be object.output_ReLU
}