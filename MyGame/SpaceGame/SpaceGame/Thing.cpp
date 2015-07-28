#include "Thing.h"

Thing::Thing()
{
}

// Create flying thing
Thing::Thing(CIndieLib *mI, int type, int x, int y, int life)
{
	Thing::Construct(mI, type, x, y, life);
}

Thing::Thing(CIndieLib *mI, int type, int x, int y, int life, int angle)
{
	Thing::Construct(mI, type, x, y, life);
	//Rotation angle
	thing->setAngleXYZ(0, 0, angle);
}

void Thing::Construct(CIndieLib *mI, int type, int x, int y, int life)
{
*posX = x;
	*posY = y;
	*health = life;
	*this->type = type;
	
	!mI->_animationManager->addToSurface(thingAnimation, "../SpaceGame/resources/animations/thing.xml", IND_ALPHA, IND_32);	
	mI->_entity2dManager->add(thing);					// Entity adding
	thing->setAnimation(thingAnimation);				// Set the animation into the entity
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
}


Thing::~Thing()
{
	thing->destroy();
	collisionSurface->destroy();
	border->destroy();
	thingAnimation->destroy();
	delete posX;
	delete posY;
	delete health;
}

void Thing::hide()
{
	*posX = -100;
	*posY = -100;
	thing->setPosition(*posX, *posY, 0);
	border->setPosition(0, 0, 0);
}

void Thing::show(int x,int y)
{
	*posX = x;
	*posY = y;

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
}

int Thing::getHealth(void)
{
	return *health;
}

int Thing::getType()
{
	return *type;
}