#ifndef LAYER1CONV_IS_INCLUDED
#define LAYER1CONV_IS_INCLUDED



class Layer1_Conv
{
public:
	double input_conv[28][28];
	int flag_layer = 1;
	const int c = 16;
	const int size = 28;
	double output_conv[28 * 28][16];//Output of all the 16 images in columns
	double *output_buffer_col;

	void conv(double **input);
	void Show(int n);
}; 

#endif 