#ifndef LAYER6MAXPOOL_IS_INCLUDED
#define LAYER6MAXPOOL_IS_INCLUDED

class layer6_MaxPool  //Maxpool Layer 5
{
private:
	double max1(double e, double b, double c, double d);
public:

	int c = 32;
	int ksize = 2; //Size of kernel
	int maxP_stride = 2;
	int layer_flag = 5;
	int in_size = 14;
	int out_size = 7;
	double input_maxP[14 * 14][32];
	double output_maxP[7 * 7][32];
	//char info[500];

	void show(int n); //Calls the master function for showing arbitrary dimensional array n-cooresponds the number of display channels
	int parameter(); //Return the parameters of a layer
					 // char* info(); //Info about the layer

	void maxP(double input[14 * 14][32]); // Performs maxPool
};


#endif
