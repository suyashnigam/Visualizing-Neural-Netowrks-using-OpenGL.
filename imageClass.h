
#ifndef IMAGECLASS_H_IS_INCLUDED
#define IMAGECLASS_H_IS_INCLUDED


//Class images
///////////////////////////////////////////////////////////////////
class Images
{
private:

	int bx; //box topleft x location
	int by; //box topleft y location
	int pixel_length; //length of the pixel

public:
	void SetBx(int x);
	void SetBy(int y);
	void SetPx(int Pixels);

	int GetBx() const;
	int GetBy() const;
	int GetPx() const;
	void DrawImage(double bmp[]) const;
};

#endif