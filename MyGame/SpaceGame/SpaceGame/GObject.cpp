#include "GObject.h"


GObject::GObject()
{

}

void GObject::SetPosition(const float x, const float y, const float z)
{
	*posX = x;
	*posY = y;
	*posZ = z;
}

float GObject::GetX()
{
	return *posX;
}

float GObject::GetY()
{
	return *posY;
}


float GObject::GetZ()
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