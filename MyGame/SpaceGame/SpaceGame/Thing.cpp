#include "Thing.h"

Thing::Thing(CIndieLib *mI, const char *resource,int x,int y)
{
	*posX = x;
	*posY = y;

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

	// for colisions only!
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
}
