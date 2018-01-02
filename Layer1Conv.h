#ifndef LAYER1CONV_IS_INCLUDED
#define LAYER1CONV_IS_INCLUDED



class Layer1_Conv
{
public:
	double input_conv[28][28];
	const int flag_layer = 1;
	const int c = 16;
	const int size = 28;
	double output_conv[28 * 28][16];//Output of all the 16 images in columns
	double *output_buffer_col;

	void Layer1_Conv::conv(double **input, double **filter, double *bias);
	void Show(int n);
	Layer1_Conv()
	{
		output_buffer_col = nullptr;
	}
	~Layer1_Conv()
	{
	
	}

	void Layer1_Conv::CleanUp() {
		
	}
}; 

#endif 