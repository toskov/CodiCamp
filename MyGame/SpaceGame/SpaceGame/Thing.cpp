#include "Thing.h"

Thing::Thing()
{
}

Thing::Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle, vector<Frame*> frms)
{
	this->thingPictures = thingsPicture;
	this->frames = frms;
	*posX = x;
	*posY = y;
	*health = life;
	*this->type = type;

	thing->setSurface(thingsPicture);
	mI->_entity2dManager->add(thing);

	int radius = 0;
	string typ = "";

	switch (type){
	case HEALTH:
		typ = "health";
		radius = 20;
		break;
	case ASTEROID:
		typ = "asteroid";
		radius = 40;
		thing->setScale(0.7, 0.7);
		break;
	case ROCK:
		typ = "rock";
		radius = 20;
		break;
	case DIAMOND:
		typ = "diamond";
		radius = 20;
		break;
	case UFO:
		typ = "ufo";
		radius = 15;
		break;
	}

	name = typ;

	// Search first picture for type;
	frameCount = 0; // clear number of frames
	int width, height,offsetX,offsetY;	
	for (int i = 0; i < frms.size(); i++)
	{
		
		if (typ == frms.at(i)->name)
		{
			frameCount++;
			width = frms.at(i)->width;
			height = frms.at(i)->height;
			offsetX = frms.at(i)->offsetX;
			offsetY = frms.at(i)->offsetY;			
			// break;
			currentFrame = i;// last frame 
		}
	}

	// Entity adding
	thing->setPosition(x, y, 1);
	//health (1) = 360 1180 50 50
	//thing->setRegion(360, 1180, 50, 50);
	thing->setRegion(offsetX, offsetY, width, height); // shows first picture from sprite

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setBoundingCircle("thing", x + width /2, y + height / 2, radius);	
	// prepare positions for explosion
	collisionsX = x + width / 2;
	collisionsY = y + height / 2;
}


Thing::~Thing()
{

}


IND_Entity2d* Thing::getColisionBorder()
{
	return border;
}

void Thing::destroy(CIndieLib *mI)
{
	delete health;
	delete type;
	delete posX;
	delete posY;
	border->deleteBoundingAreas("thing");
	mI->_entity2dManager->remove(thing);
	mI->_entity2dManager->remove(border);
	mI->_surfaceManager->remove(collisionSurface);
}

int Thing::getHealth(void)
{
	return *health;
}

int Thing::getType()
{
	return *type;
}

int Thing::getCollisionPositionX()
{
		return collisionsX;
}

int Thing::getCollisionPositionY()
{
	return collisionsY;
}

void Thing::animationUpdate()
{
	// get current frame from sprite
	int width, height, offsetX, offsetY;

	currentFrame++;
	if (currentFrame > frameCount) currentFrame = 1;

	for (int i = 0; i < frames.size(); i++)
	{

		if ((name == frames.at(i)->name) && (frames.at(i)->frameNumber == currentFrame))
		{			
			width = frames.at(i)->width;
			height = frames.at(i)->height;
			offsetX = frames.at(i)->offsetX;
			offsetY = frames.at(i)->offsetY;
			break;
		}
	}

	thing->setRegion(offsetX, offsetY, width, height); // shows region
}