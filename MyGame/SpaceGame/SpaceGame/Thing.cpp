#include "Thing.h"

Thing::Thing(CIndieLib *mI, const char *resource)
{

	if (!mI->_animationManager->addToSurface(thingAnimation, (const char*)resource, IND_ALPHA, IND_32))
	{
		// TODO 
	}
	mI->_entity2dManager->add(thing);					// Entity adding
	thing->setAnimation(thingAnimation);				// Set the animation into the entity
	thing->setSequence(0);
	thing->setPosition(300, 200, 1);
	thing->setHotSpot(0.5f, 0.5f);
	//thing->setScale(0.3, 0.3);

	// for tests only! Must be set by method!
	thing->setBoundingCircle("health", 0, 0, 50);
}
Thing::~Thing()
{
	thing->destroy();
}

IND_Entity2d* Thing::getObject()
{
	return thing;
}

IND_Entity2d Thing::newObject(CIndieLib *mI, const char *resource)
{
	Thing(mI,resource);
	
}