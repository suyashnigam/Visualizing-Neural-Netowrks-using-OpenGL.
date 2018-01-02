
#ifndef LAYER9FULLYCONNECTED_IS_INCLUDED
#define LAYER9FULLYCONNECTED_IS_INCLUDED

class Layer9_FullyConnected  //Fully connected layer
{
private:

	double input_fully_c[7 * 7][64];
	double output_fully_c[7 * 7 * 64];
	double input_changed[7 * 7] [64];
	double weights[10][7 * 7 * 64];
	char *info[256];
	double bias[10] = { -0.012013176,0.018485941,-0.0013255535,0.0034290906,-0.014242185,0.0020050916,-0.0056662420, 0.015405872,-0.00096196536,-0.0051202890 };

public:

	//double **filter;
	double output_vector[10];
	//char* info(); //Info about the layer
	void FullyConnected(double input_fully_c[7 * 7][64], double **filter);
	Layer9_FullyConnected();
	void operation();
	void get_weights(double **filter);

};



#endif