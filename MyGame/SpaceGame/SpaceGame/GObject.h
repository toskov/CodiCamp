#include "CIndieLib.h"
#ifndef OBJECT_H
#define	OBJECT_H

class GObject
{
protected:
	int *posX, *posY, *posZ;

public:
	 void SetPosition(int *x, int *y, int *z);
	 int GetX();
	 int GetY();
	 int GetZ();
	 ~GObject();
	 GObject();
	 void Hide();
}; 

#endif