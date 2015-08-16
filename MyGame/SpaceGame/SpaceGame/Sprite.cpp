#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(CIndieLib *mI, const char* resource, int x, int y)
{
	*posX = x;
	*posY = y;

	mI->_surfaceManager->add(picture, (const char*) resource, IND_ALPHA, IND_32); // background?
	sprite->setSurface(picture);
	mI->_entity2dManager->add(sprite);					// Entity adding	
	sprite->setPosition(x, y, 3);
	//sprite->setHotSpot(0.5f, 0.5f);
	sprite->setRegion(0, 0, 50, 66); // must be set outside
}

void Sprite::destroy(CIndieLib *mI)
{
	mI->_entity2dManager->remove(sprite);
	mI->_surfaceManager->remove(picture);
}

Sprite::~Sprite()
{
	delete frames;
	delete frameWidth;
	delete frameHight;
	delete frameColumns;
	delete currentFrame;
	delete posX;
	delete posY;

}

void Sprite::Update()
{
	*currentFrame+=1;
	if (*currentFrame > (*frames-1)) *currentFrame = 0; // from 0 to frames-1
	int offsetX = (*currentFrame)*(*frameWidth); // one row picture
	int offsetY = 0; // one row picture
	sprite->setRegion(offsetX, offsetY, *frameWidth, *frameHight); // must be set outside
}