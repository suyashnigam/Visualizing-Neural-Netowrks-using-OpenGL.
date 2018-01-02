#ifndef LAYER8RELU_IS_INCLUDED
#define LAYER8RELU_IS_INCLUDED


class Layer8_Relu
{
public:

	double input_ReLU[7 * 7][64];
	double output_ReLU[7 * 7][64];
	//char *info[256];


	// char* info(); //Info about the layer
	void ReLU(double input[7*7][64]); // Performs ReLU
};
#endif
