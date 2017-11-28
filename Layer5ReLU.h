#ifndef LAYER5RELU_IS_INCLUDED
#define LAYER5RELU_IS_INCLUDED


class Layer5_Relu
{
public:

	double input_ReLU[14 *14][32];
	double output_ReLU[14 * 14][32];
	//char *info[256];


	// char* info(); //Info about the layer
	void ReLU(double input[14 * 14][32]); // Performs ReLU
};
#endif
