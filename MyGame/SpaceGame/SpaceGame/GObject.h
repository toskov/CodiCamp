#ifndef OBJECT_H
#define	OBJECT_H
#include "CIndieLib.h"

class GObject
{
protected:
	float *posX=0, *posY=0, *posZ=0;

public:
	void SetPosition(const float x, const float y, const float z);
	float GetX();
	float GetY();
	float GetZ();
	 ~GObject();
	 GObject();
	 void Hide();
}; 

#endif