#include "Vector2Image.h"


//This function converts a ID image vector into 2d image array
double** Vector2Image(double Vector[], int n)
{

	double** pixel_2d_arr;
	pixel_2d_arr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		pixel_2d_arr[i] = new double[n];
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			pixel_2d_arr[r][c] = Vector[n*r + c];
		}
	}
	return pixel_2d_arr;
}