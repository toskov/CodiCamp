#include "Object.h"

Object::Object()
{
	*posX = 0;
	*posY = 0;
	*posZ = 0;
}

Object::Object(CIndieLib *myI, std::string resource)
{
	*posX = 0;
	*posY = 0;
	*posZ = 0;
}

void Object::SetPosition(int *x, int *y, int *z)
{
	posX = x;
	posY = y;
	posZ = z;
}

int Object::GetX()
{

}

int Object::GetY()
{

}


int Object::GetZ()
{

}

Object::~Object()
{
	delete posX;
	delete posY;
	delete posZ;
}


void Object::Hide()
{

}