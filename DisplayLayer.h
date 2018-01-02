#ifndef DISPLAYLAYER_H_IS_INCLUDED
#define DISPLAYLAYER_H_IS_INCLUDED
#include "imageClass.h"


//Class layer
///////////////////////////////////////////////////////////////////
class DisplayLayer
{
public:
	int n_images; //no of images
	Images *img;

	int x_l; //initial x of the layer
	int y_l; //top y of each images in layer
	int gap; //gap between images

	DisplayLayer();
	~DisplayLayer();
	void CleanUp();
	void DrawLayer(int N_I, int pixels, double **arr);
};



#endif
