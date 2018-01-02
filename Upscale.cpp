#include "Upscale.h"
#include "CommonVariable.h"



//This function upscales the image by a factor of upscale_fac
double** Upscale(double** arr, int length)
{

	double** upscale_image;
	upscale_image = new double*[length*upscale_fac];
	for (int i = 0; i < length*upscale_fac; i++)
	{
		upscale_image[i] = new double[length*upscale_fac];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			for (int r = upscale_fac*i; r < upscale_fac*(i + 1); r++)
			{
				for (int c = upscale_fac*j; c < upscale_fac*(j + 1); c++)
				{
					upscale_image[r][c] = arr[i][j];
				}
			}
		}
	}

	return  upscale_image;

}