#pragma once

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
#include <string.h>
#include <stdio.h>
#include "Parse9.h"


class NeuralNet
{
public:
	int Run(void);


};
