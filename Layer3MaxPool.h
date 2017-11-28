#ifndef LAYER3MAXPOOL_IS_INCLUDED
#define LAYER3MAXPOOL_IS_INCLUDED

class layer3_MaxPool  //Maxpool Layer 3
{
	private:
		double max1(double e, double b, double c, double d);
public:
	
    int c=16;
    int ksize=2; //Size of kernel
    int maxP_stride=2;
    int layer_flag=3;
	int in_size = 28;
	int out_size = 14;
    double input_maxP[28 * 28][16];
    double output_maxP[14 * 14][16];
    //char info[500];

    void show(int n); //Calls the master function for showing arbitrary dimensional array n-cooresponds the number of display channels
    int parameter(); //Return the parameters of a layer
   // char* info(); //Info about the layer
	
	void maxP(double input[28 * 28][16]); // Performs maxPool
};


  #endif