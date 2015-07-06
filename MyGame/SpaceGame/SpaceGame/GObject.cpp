#include "GObject.h"


GObject::GObject()
{
	this->posX = 0;
	this->posY = 0;
	this->posZ = 0;
}

void GObject::SetPosition(int *x, int *y, int *z)
{
	posX = x;
	posY = y;
	posZ = z;
}

int GObject::GetX()
{
	return *posX;
}

int GObject::GetY()
{
	return *posY;
}


int GObject::GetZ()
{
	return *posZ;
}

GObject::~GObject()
{
	delete posX;
	delete posY;
	delete posZ;
}


void GObject::Hide()
{

}