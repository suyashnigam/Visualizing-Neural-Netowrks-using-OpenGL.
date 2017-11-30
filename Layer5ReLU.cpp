#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer5ReLU.h"


/*
char* Layer2_Relu::info()
{
return info;
}
*/
void Layer5_Relu::ReLU(double input[14 * 14][32])
{

	for (int i = 0; i<14*14; i++)
	{
		for (int j = 0; j<32; j++)
		{
			if (input[i][j]<0)
			{
				output_ReLU[i][j] = 0;
			}
			else
				output_ReLU[i][j] = input[i][j];

		}
	}
	//The output into the next function should be object.output_ReLU
}