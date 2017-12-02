
#include "fssimplewindow.h"
#include "imageClass.h"
#include "Upscale.h"
#include "CommonVariable.h"
#include "DisplayLayer.h"
#include"ParseString.h"
#include <ctype.h>
#include <stdlib.h>
#include "Vector2Image.h"
#include "Image2Vector.h"
#include "PixelCol.h"
#include "Layer1Conv.h"
#include "Layer2Relu.h"
#include "Layer3MaxPool.h"
#include "Layer4Conv.h"
#include "Layer5ReLU.h"
#include "Layer6MaxPool.h"
#include "Layer7Conv.h"
#include "Layer8ReLU.h"
#include "Layer9FullyConnected.h"
#include "Layer10Softmax.h"


#include <iostream>
#include<string.h>
#include<stdio.h>
#include "Parse9.h"



int main(void)
{
	const int sizeInp = 112;//                   //default size of Test Image Box (112x112 pixels)
	PixelCol p(50, 50);//
	p.Initialize(sizeInp);//	
	int flag = 0;
	int flag_2 = 0;
	

	static Layer1_Conv conv_layer1;
	static Layer2_Relu ReLU_layer2;
	static layer3_MaxPool MaxPool_layer3;
	static Layer4_conv conv_layer4;
	static Layer5_Relu ReLU_layer5;
	static layer6_MaxPool MaxPool_layer6;
	static Layer7_conv conv_layer7;
	static Layer8_Relu ReLU_layer8;
	
	// Specific to layer 9
	char fileName[] = "abc.txt";
	FILE *fp = fopen(fileName, "r");
	HugeWeights wt(fp);
	double **filter = wt.Run();
	
	static Layer9_FullyConnected FullyConnected_layer9;

	//specific to Layer_10
	static Layer10_Softmax Softmax_layer10;
	static Layer10_Visualize Visualize_layer10;
	double *layer_10_output;
	
	
	FsOpenWindow(0, 0, 1080, 720, 1);

	for (;;)
	{
		FsPollDevice();
		auto key = FsInkey();
		if (key != FSKEY_NULL)
		{
			break;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		int lb, mb, rb, mx, my;
		FsGetMouseEvent(lb, mb, rb, mx, my);
		p.MouseEventLooping(p.bX, sizeInp, p.bY, lb, mb, rb, mx, my, flag);

		p.Draw(p.bX, p.bY, sizeInp);

		double** ImageOut;
		ImageOut = p.Downsample(sizeInp, 4);

		if (lb == 0 && flag == 1)
		{
			conv_layer1.conv(ImageOut);
			ReLU_layer2.ReLU(conv_layer1.output_conv);
			MaxPool_layer3.maxP(ReLU_layer2.output_ReLU);
			conv_layer4.conv(MaxPool_layer3.output_maxP);
			ReLU_layer5.ReLU(conv_layer4.output_conv);
			MaxPool_layer6.maxP(ReLU_layer5.output_ReLU);
			conv_layer7.conv(ReLU_layer5.output_ReLU);
			ReLU_layer8.ReLU(conv_layer7.output_conv);
			FullyConnected_layer9.FullyConnected(ReLU_layer8.output_ReLU,filter);
			layer_10_output = Softmax_layer10.calculation(FullyConnected_layer9.output_vector);
			Visualize_layer10.fill(layer_10_output);

			flag = 0;
			flag_2 = 1;
		}

		if (flag == 0 && flag_2 == 1)
		{
			conv_layer1.Show(4);
			MaxPool_layer3.show(3);
			conv_layer4.Show(10);
			MaxPool_layer6.show(3);
			conv_layer7.Show(5);
			Visualize_layer10.draw();

		}
		
		FsSwapBuffers();
		FsSleep(5);
	}
	glFlush();
	while (FSKEY_NULL == FsInkey())
	{
		FsPollDevice();
	}
	return 0;
}
