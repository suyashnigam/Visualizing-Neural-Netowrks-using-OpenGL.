#include "imageClass.h"
#include "Vector2Image.h"
#include "CommonVariable.h"
#include "Upscale.h"
#include "fssimplewindow.h"


// This function draws the square
void DrawSquare(int x, int y, double c)
{
	double rgb = 255 * c;

	glColor3ub(rgb, rgb, rgb);

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + 1, y);
	glVertex2i(x + 1, y + 1);
	glVertex2i(x, y + 1);
	glEnd();
}

//Set bx for the image
void Images::SetBx(int x)
{
	bx = x;
}

//Set by for the image
void Images::SetBy(int y)
{
	by = y;
}

//Set pixel length for the image
void Images::SetPx(int Pixels)
{
	pixel_length = Pixels;
}

//Get bx for the image
int Images::GetBx() const
{
	return bx;
}

//Get by for the image
int Images::GetBy() const
{
	return by;
}

//Get pixel length for the image
int Images::GetPx() const
{
	return pixel_length;
}

void Images::DrawImage(double bmp[]) const
{
	//Covert 1d vector to 2d image
	double** pixel_2d_arr = Vector2Image(bmp, pixel_length);

	double** upscale_image = Upscale(pixel_2d_arr, pixel_length);

	
	for (int i = 0; i < pixel_length*upscale_fac; i++)
	{
		for (int j = 0; j < pixel_length*upscale_fac; j++)
		{
			//j spans x....i spans y........
			DrawSquare(bx + i, by + j, upscale_image[j][i]);

		}
	}

}
