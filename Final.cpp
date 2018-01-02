#include "NeuralNet.h"

int RunNet() {
	NeuralNet *neuralNet = new NeuralNet[1];
	int reRun = (*neuralNet).Run();
	delete[] neuralNet;
	neuralNet = nullptr;
	return reRun;
}

int main(void)
{
	FsOpenWindow(0, 0, 1330, 700, 1);

	int reRun = 1;
	while (reRun == 1) {
		reRun=RunNet();
	}
	return 0;
}