#include "PixelCol.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"


int **myMesh(int windowSize)
{
	// Input
	// windowSize is the size of the window you want to create, ex: windowSize = 5 ..
	// creates a 5 x 5 window with origin being the top left corner and x=4,y=4 being the ..
	// bottom right corner

	// Output
	// returns a pointer to x and y pointers. 

	int inputx = 0, inputy = 0, count = 0;
	int element = windowSize * windowSize;

	int *x = new int[element], *y = new int[element];

	for (int i = 0; i < element; i++)
	{
		++count;
		if (i % windowSize == 0)
		{
			++inputx;
		}
		inputy = count;
		if (count % windowSize == 0)
		{
			count = 0;
		}
		x[i] = inputx - 1;
		y[i] = inputy - 1;
	}

	int* xPointer = x;
	int* yPointer = y;

	int **pointers = new int*[2];
	pointers[0] = x;
	pointers[1] = y;

	return pointers;
}



void DrawXGoButton(const int bX, const int bY, const int size)
{
	//X Button
	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(bX, bY + size + 45);
	glVertex2i(bX, bY + size + 5);
	glVertex2i(bX + 40, bY + size + 5);
	glVertex2i(bX + 40, bY + size + 45);
	glEnd();

	glRasterPos2d(bX + 10, bY + size + 35);
	YsGlDrawFontBitmap20x32("x");

	//Go Button
	glBegin(GL_LINE_LOOP);
	glVertex2i(bX + size - 40, bY + size + 5);
	glVertex2i(bX + size, bY + size + 5);
	glVertex2i(bX + size, bY + size + 45);
	glVertex2i(bX + size - 40, bY + size + 45);
	glEnd();

	glRasterPos2d(bX + size - 35, bY + size + 35);
	YsGlDrawFontBitmap16x24("Go");

	glRasterPos2d(bX - 10, bY - 10);
	YsGlDrawFontBitmap10x14("Draw a Number");
}

PixelCol::PixelCol(int x, int y)
{
	ptrImg = nullptr;
	bX = x;
	bY = y;
}

PixelCol::~PixelCol()
{
	CleanUp();
}

void PixelCol::CleanUp(void)
{
	if (nullptr != ptrImg)
		delete[] ptrImg;
	ptrImg = nullptr;
}

void PixelCol::Initialize(const int size)
{
	ptrImg = new int[size*size];
	for (int i = 0; i < size*size; ++i)
	{
		ptrImg[i] = 0;
	}
}

void PixelCol::SetColor(const int mx, const int my, const int bX, const int bY, const int size)
{
	for (int i = mx - bX - 4; i < mx - bX + 4; ++i)            //
	{                                                          // sets the Mouse Pixel and 4 adjacent pixels on each side to white color
		for (int j = my - bY - 4; j < my - bY + 4; ++j)        //
		{
			if (i > 0 && i < size - 1 && j > 0 && j < size - 1) //check if all pixels are within the box area
			{
				ptrImg[j*size + i] = 255;
			}
		}
	}
}

void PixelCol::Draw(const int bX, const int bY, const int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			glColor3ub(ptrImg[j*size + i], ptrImg[j*size + i], ptrImg[j*size + i]);
			glBegin(GL_QUADS);
			glVertex2i(bX + i, bY + j);
			glVertex2i(bX + i, bY + j - 1);
			glVertex2i(bX + i + 1, bY + j - 1);
			glVertex2i(bX + i + 1, bY + j);
			glEnd();
		}
	}
	DrawXGoButton(bX, bY, size);
}

double** PixelCol::Downsample(const int size, const int dScale, double** ImageOut)
{
	//convert 1D image to 2D using Sagar's Code 
	double** pixel_2d_arr;
	pixel_2d_arr = new double*[size];
	for (int i = 0; i < size; i++)
	{
		pixel_2d_arr[i] = new double[size];
	}
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			pixel_2d_arr[r][c] = ptrImg[size*r + c];
		}
	}

	//downsample the Image to a 28x28 image using Krishna's code
	const int n2 = size / dScale;
	int windowSize = dScale*dScale;

	// Compute the n2 x n2 image from n1 x n1
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n2; j++) {
			// Loop over all values in n2 x n2

			int curPixel[2];
			// Create a window of size windowSize in the n1 x n1 image
			curPixel[0] = dScale * i; curPixel[1] = dScale * j;

			// Create a window of scale x scale with the top left corner being curPixel[0] and curPixel[1]
			int *x = new int[windowSize], *y = new int[windowSize];

			// pixMove is nothing but meshGrid(1:4,1:4)-1 
			int **temp = myMesh(dScale);
			//int *pixMoveX = temp[0], *pixMoveY = temp[1];

			// Calculate the pixel positions wrt curPixel
			for (int iMove = 0; iMove < windowSize; iMove++) {
				x[iMove] = curPixel[0] + temp[0][iMove];
				y[iMove] = curPixel[1] + temp[0][iMove];
			}

			// Calculate the no. of pixels which are activated (0 or 1) in the window
			double sum = 0; int nPix = 0;
			while (nPix < windowSize)
			{
				int loc1 = x[nPix], loc2 = y[nPix];
				sum = sum + pixel_2d_arr[loc1][loc2];
				nPix++;
			}
			// Threshold of just greater than half
			if (sum > windowSize / 2)
				ImageOut[i][j] = 255;
			else
				ImageOut[i][j] = 0;
			
			delete[] temp[0];
			delete[] temp[1];
			delete[] x;
			delete[] y;
		}
	}
	// CleanUp
	for (int i = 0; i < size; i++)
	{
		delete[] pixel_2d_arr[i];
	}
	return ImageOut;
}

void PixelCol::MouseEventLooping(int bX, int sizeInp, int bY, int lb, int mb, int rb, int mx, int my,int &flag,int &flag_2, int &flag_exit,double **ImageOut)
{
	
	
	if (lb == 1 && mx > bX && mx < bX + sizeInp && my > bY && my < bY + sizeInp)    //check if left mouse button is pressed and mouse is over the Test Image Box
	{
		SetColor(mx, my, bX, bY, sizeInp);
	}//set pixels to white

	if (lb == 1 && mx > bX + sizeInp - 40 && mx < bX + sizeInp && my > bY + sizeInp  && my < bY + sizeInp + 45)
	{
		flag = 1;
	}

	if (lb == 1 && mx > bX && mx < bX + 40 && my > bY + sizeInp + 5 && my < bY + sizeInp + 45)    //check if left mouse button is pressed and mouse is over the X Button
	{ 
		Initialize(sizeInp);
		flag = 1;
		flag_exit=1;

	}
}
