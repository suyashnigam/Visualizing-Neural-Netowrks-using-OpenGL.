
#ifndef PIXELCOL_IS_INCLUDED
#define PIXELCOL_H_IS_INCLUDED


class PixelCol                            //class for the Test Image drawn by the user
{
public:
	int bX, bY;
	int *ptrImg;                          //pointer to a 1 dimensional array that stores the color data of each pixel
	//double** ImageOut;
	PixelCol(int x, int y);
	~PixelCol();
	void CleanUp(void);

	void Initialize(const int size);      //set each pixel to black color initially, or if the user presses the X button
	void SetColor(const int mx, const int my, const int bX, const int bY, const int size);     //for the pixels covered by FsGetMousEvent, change to white color
	void Draw(const int bX, const int bY, const int size);        // draw the Test Image Input Box
	double** Downsample(const int size, const int dScale, double** ImageOut);    //downsample the drawn image to a 28x28 array for imput to the neural network
	void MouseEventLooping(int bX, int sizeInp, int bY, int lb, int mb, int rb, int mx, int my,int &flag,int &flag_2, int &flag_exit, double **ImageOut);
};

#endif