#ifndef LAYER2RELU_IS_INCLUDED
#define LAYER2RELU_IS_INCLUDED

class Layer2_Relu
  {
  public:

    double input_ReLU[28 * 28][16];
    double output_ReLU[28 * 28][16];
    char *info[256];

   
   // char* info(); //Info about the layer
	void ReLU(double input[28 * 28][16]); // Performs ReLU
 



  };


  #endif