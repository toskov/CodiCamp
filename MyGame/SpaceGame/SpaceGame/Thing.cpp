#include "Thing.h"

Thing::Thing()
{
}

// Create flying thing
Thing::Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life)
{
	Thing::Construct(mI, thingsPicture, type, x, y, life);
}

Thing::Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle)
{
	Thing::Construct(mI, thingsPicture, type, x, y, life);
	//Rotation angle
	thing->setAngleXYZ(0, 0, angle);
}

void Thing::Construct(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life)
{
	this->thingPictures = thingsPicture;
	*posX = x;
	*posY = y;
	*health = life;
	*this->type = type;
		
	mI->_entity2dManager->add(thing);					// Entity adding
	thing->setSequence(type-1); //animation file have to contain all animations for things. Sequence begins from 0
	thing->setPosition(x, y, 1);
	thing->setHotSpot(0.5f, 0.5f);

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);

	// diferent Objects
	
	if (type == HEALTH)
	{
		border->setBoundingCircle("thing", x, y, 20);
	}
	if (type == ASTEROID)
	{
		thing->setScale(0.7, 0.7);
		border->setBoundingCircle("thing", x, y, 40);
		
	}
	if (type == ROCK)
	{
		//thing->setScale(0.7, 0.7);
		border->setBoundingCircle("thing", x, y, 20);

	}
	if (type == DIAMOND)
	{
		//thing->setScale(0.7, 0.7);
		border->setBoundingCircle("thing", x, y, 20);

	}
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

int Thing::getPositionX()
{
	return thing->getPosX();
}

int Thing::getPositionY()
{
	return thing->getPosY();
}