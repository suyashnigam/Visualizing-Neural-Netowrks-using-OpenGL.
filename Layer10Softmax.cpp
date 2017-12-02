#include "Layer10Softmax.h"
#include <math.h>
#include "fssimplewindow.h"
#include<iostream>

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
		//std::cout << soft[i] << "\n";

	}

	return soft;
}
double Layer10_Softmax::softmax(double s, double deno)
{

	store = double(exp(s) / (deno));
	return store;
}

/*void Layer10_Visualize::Initialize(void)
{
	int wid = 50, hei = 50;
	double color2[10] = { 0,0,0,0,0,0,0,0,0,0 };
	double color[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int y = 200, x = 150, space = 10;
}*/

void Layer10_Visualize::draw(void)
{
	//Initialize();
	for (int i = 0; i < 10; i++)
	{
		//printf("color %lf\n", color[i]);
		glColor3ub(color[i], color[i], color[i]);
		glBegin(GL_QUADS);
		glVertex2i((i*(wid + space)) + x, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y + hei);
		glVertex2i((i*(wid + space)) + x, y + hei);
		glEnd();
	}

	for (int i = 0; i < 10; i++)
	{
		glColor3ub(color2[i], 0, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2i((i*(wid + space)) + x, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y);
		glVertex2i(((i*(wid + space)) + x) + wid, y + hei);
		glVertex2i((i*(wid + space)) + x, y + hei);
		glEnd();
	}
}
void Layer10_Visualize::fill(double *val)
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
		//scale[i] = 255 * (1 - (1 / val[i]));
		//color[i] = 255*val[i];
		//printf("color %lf\n", scale[i]);
	}

	sf = 1 / val[position];
	color2[position] = 255;
	for (int i = 0; i < 10; i++)
	{
		color[i] = 255 * (1 - (sf*val[i]));
		//printf("color %lf\n", color[i]);
	}

}