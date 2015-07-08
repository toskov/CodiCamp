#include "CIndieLib.h"
#include "Planet.h"

Planet::Planet(CIndieLib *mI, const char *resource)
{
	// Characters animations, we apply transparency
	IND_Animation *mAnimationPlanet = IND_Animation::newAnimation();

	if (!mI->_animationManager->addToSurface(mAnimationPlanet, (const char*)resource, IND_ALPHA, IND_32))
	{
		CatchError("Cannot find animation resources!");
	}

	// Character planet
	mI->_entity2dManager->add(planet);					// Entity adding
	planet->setAnimation(mAnimationPlanet);				// Set the animation into the entity
	planet->setSequence(0);
	planet->setPosition(400, 300, 0);
	planet->setHotSpot(0.5f, 0.5f);
}