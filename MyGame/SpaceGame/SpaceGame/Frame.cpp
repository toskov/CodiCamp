#include "Frame.h"



Frame::Frame(string str, int frameNum, int offX, int offY, int w, int h)
{
	name = str;
	frameNumber = frameNum;
	offsetX = offX;
	offsetY = offY;
	width = w;
	height = h;
}

Frame::Frame()
{
	
}

Frame::~Frame()
{
}

