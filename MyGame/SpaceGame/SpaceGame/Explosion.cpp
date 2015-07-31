#include "Explosion.h"

Explosion::Explosion()
{

}


Explosion::Explosion(CIndieLib *mI, int x, int y)
{
	*posX = x-*frameWidth/2;   //?????
	*posY = y-*frameHeight/2;

	mI->_surfaceManager->add(picture, "../SpaceGame/resources/expl-composite.png", IND_ALPHA, IND_32); // background?
	explosion->setSurface(picture);
	mI->_entity2dManager->add(explosion);					// Entity adding	
	explosion->setPosition(*posX, *posY, 30);
	explosion->setRegion(0, 0, *frameWidth, *frameHeight); // must be set outside
}

bool Explosion::Update(CIndieLib *mI,double deltaTime)
{
	*time = *time - 10000*deltaTime;
	if (*time > 0) return true;
	*time = 5;

	*currentFrame += 1;
	if (*currentFrame < *frames-1)
	{
		int offsetX = (*frameWidth)*((*currentFrame) % (*frameColumns)); // x offset
		int offsetY = (*frameHeight)*((*currentFrame) / (*frameRows)); // y offset
		explosion->setRegion(offsetX, offsetY, *frameWidth, *frameHeight); // shows region
		return true;
		
	}
	//if (*currentFrame == *frames) 
	destroy(mI); // destroy once
	return false;
}

void Explosion::destroy(CIndieLib *mI)
{
	mI->_entity2dManager->remove(explosion);
	mI->_surfaceManager->remove(picture);
	delete time;
	delete frames;
	delete frameWidth;
	delete frameHeight;
	delete frameColumns;
	delete currentFrame;
	delete frameRows;
	delete posX;
	delete posY;
}
Explosion::~Explosion()
{
	delete time;
	delete frames;  
	delete frameWidth;
	delete frameHeight; 
	delete frameColumns;
	delete currentFrame;
	delete posX;
	delete posY;
	picture->destroy();
	explosion->destroy();
}