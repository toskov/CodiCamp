#include "Thing.h"

Thing::Thing(CIndieLib *mI, const char *resource,int x,int y,int life)
{
	*posX = x;
	*posY = y;
	*health = life;
	if (!mI->_animationManager->addToSurface(thingAnimation, (const char*)resource, IND_ALPHA, IND_32))
	{
		// TODO 
	}
	mI->_entity2dManager->add(thing);					// Entity adding
	thing->setAnimation(thingAnimation);				// Set the animation into the entity
	thing->setSequence(0); 
	thing->setPosition(x, y, 1);
	thing->setHotSpot(0.5f, 0.5f);
	//thing->setScale(0.3, 0.3);

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setBoundingCircle("health", x, y, 20);
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
	*health = 0;
	mI->_entity2dManager->remove(thing);
	mI->_entity2dManager->remove(border);
}

int Thing::getHealth(void)
{
	return *health;
}