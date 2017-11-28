#include "DisplayLayer.h"
#include <stdio.h>
#include "CommonVariable.h"


DisplayLayer::DisplayLayer()
{
	n_images = 0;
	img = NULL;
}

DisplayLayer::~DisplayLayer()
{
	CleanUp();
}

void DisplayLayer::CleanUp()
{
	if (img != NULL)
	{
		delete[] img;
		img = NULL;
	}
}

void DisplayLayer::DrawLayer(int N_I, int pixels, double **arr)
{

	n_images = N_I;
	img = new Images[n_images];
	for (int i = 0; i < n_images; i++)
	{
		img[i].SetBx(x_l + (pixels*upscale_fac + gap) * i); //set bx for the image
		img[i].SetBy(y_l); //set by for the image
		img[i].SetPx(pixels); //set pixel length for the image
		img[i].DrawImage(arr[i]);
	}


}
