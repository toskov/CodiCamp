#ifndef FRAME_H
#define FRAME_H

#include "CIndieLib.h"
#include <string.h>


class Frame
{
private:

public:
	string name; // frame name
	int frameNumber = 0; //frame number
	int offsetX = 0; //X offset
	int offsetY = 0; //Y offset
	int width = 0; // width
	int height = 0; // height
	Frame();
	Frame(string str, int frameNum, int offX, int offY, int w, int h);
	~Frame();
};

#endif