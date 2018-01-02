#ifndef LAYER4CONV_IS_INCLUDED
#define LAYER4CONV_IS_INCLUDED
#include <vector>

class Layer4_conv
{
public:
	std::vector<std::vector<std::vector<double>>> input3D{ 0.0 };
	int flag_layer = 4;
	const int c = 32;
	const int size = 14;
	double output_conv[14 * 14][32] = { 0 };//Output of all the 16 images in columns
	//double *output_buffer_col;

	void conv(double input[14 * 14][16], double ***weights, double *bias);

	void Show(int n);
	void LayerClean();
};

#endif