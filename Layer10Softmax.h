#pragma once
#ifndef LAYER10SOFTMAX_IS_INCLUDED
#define LAYER10SOFTMAX_IS_INCLUDED

class Layer10_Softmax
{
public:
	double *soft;
	double store, deno;
	int length;
	Layer10_Softmax();
	~Layer10_Softmax();
	double *calculation(double a[]);
	void Initialize(void);
	double softmax(double s, double deno);
};

class Layer10_Visualize
{
public:
	int wid = 20, hei = 20 ;
	double sf, color2[10]={ 0,0,0,0,0,0,0,0,0,0 };
	double color[10]= { 0,0,0,0,0,0,0,0,0,0 };
	int y = 50, x = 400, space= 10;
	void draw(void);
	//void Initialize(void);
	void fill(double *val);
};

#endif
#pragma once
