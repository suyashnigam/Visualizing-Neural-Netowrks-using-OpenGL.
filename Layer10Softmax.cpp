#include "Layer10Softmax.h"
#include <math.h>
#include "fssimplewindow.h"
#include<iostream>
#include "ysglfontdata.h"


Layer10_Softmax::Layer10_Softmax()
{
	soft = nullptr;
	length = 10;
	deno = 0.0;
}
Layer10_Softmax::~Layer10_Softmax()
{
	if (soft != nullptr)
	{
		delete[] soft;
	}
	soft = nullptr;
	length = 0;
	deno = 0.0;
}
void Layer10_Softmax::Initialize(void)
{
	soft = nullptr;
	length = 10;
	deno = 0.0;
	for (int i = 0; i < 10; i++)
	{
		soft_output[i] = 0;
	}
}
double *Layer10_Softmax::calculation(double a[])
{
	Initialize();
	soft = new double[length];
	for (int i = 0; i < 10; i++)
	{
		deno += exp(a[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		soft[i] = softmax(a[i], deno);
	}
	for (int i = 0; i < 10; i++)
	{
		soft_output[i] = soft[i];
	}
	return soft;
}
double Layer10_Softmax::softmax(double s, double deno)
{

	store = double(exp(s) / (deno));
	return store;
}

void Layer10_Visualize::draw(void)
{
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(605, 50);
	glVertex2i(955, 50);
	glVertex2i(955, 145);
	glVertex2i(605, 145);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(615, 60);
	glVertex2i(945, 60);
	glVertex2i(945, 135);
	glVertex2i(615, 135);
	glEnd();

	glColor3ub(0, 0, 0);
	glRasterPos2d(225, 110);
	YsGlDrawFontBitmap16x24("OUTPUT");
	for (int i = 0; i < 10; i++)
	{
		glColor3ub(color2[i], 0, 0);
		glBegin(GL_QUADS);
		glVertex2i((i*(wid + space)) + x - 2, y - 2);
		glVertex2i(((i*(wid + space)) + x) + wid + 2, y - 2);
		glVertex2i(((i*(wid + space)) + x) + wid + 2, y + hei + 2);
		glVertex2i((i*(wid + space)) + x - 2, y + hei + 2);
		glEnd();

		glColor3ub(color[i], color[i], color[i]);
		glBegin(GL_QUADS);
		glVertex2i((i*(wid + space)) + x, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y + hei);
		glVertex2i((i*(wid + space)) + x, y + hei);
		glEnd();

		glColor3ub(0, 0, 0);
		glRasterPos2d(i*(wid + space) + x + 4, y - 5);
		sprintf(num, "%d", i);
		YsGlDrawFontBitmap16x24(num);
	}
}
void Layer10_Visualize::fill(double val[10])
{
	double biggest;
	biggest = val[0];
	int position = 0;

	for (int i = 0; i < 10; i++)
	{
		if (val[i] > biggest)
		{
			biggest = val[i];
			position = i;
		}
	}

	sf = 1 / val[position];
	for (int i = 0; i < 10; i++)
	{
		color2[i] = 0;
	}
	color2[position] = 255;
	for (int i = 0; i < 10; i++)
	{
		color[i] = 255 * (1 - (sf*val[i]));
	}

}