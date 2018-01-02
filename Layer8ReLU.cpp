#include "DisplayLayer.h"
#include <stdio.h>
#include <iostream>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "Layer8ReLU.h"


void Layer8_Relu::ReLU(double input[7*7][64])
{

	for (int i = 0; i<7*7; i++)
	{
		for (int j = 0; j<64; j++)
		{
			if (input[i][j]<0)
			{
				output_ReLU[i][j] = 0;
			}
			else
				output_ReLU[i][j] = input[i][j];

			//std::cout << output_ReLU[i][j]<<"\n";
		}

	}
	//The output into the next function should be object.output_ReLU
}