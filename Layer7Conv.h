#ifndef LAYER7CONV_IS_INCLUDED
#define LAYER7CONV_IS_INCLUDED
#include <vector>

class Layer7_conv
{
public:
	std::vector<std::vector<std::vector<double>>> input3D{ 0.0 };
	int flag_layer = 7;
	const int c = 64;
	const int size = 7;
	double output_conv[7 * 7][64] = { 0.0 };//Output of all the 64 images in columns
	//double *output_buffer_col;
	void conv(double input[7 * 7][32], double ***weights, double *bias);
	void Show(int n);
};

#endif
