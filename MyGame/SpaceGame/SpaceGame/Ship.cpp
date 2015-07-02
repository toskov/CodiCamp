#include "Ship.h"

Ship::Ship(CIndieLib *mI, std::string str)
{

		// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRocket, "../SpaceGame/resources/animations/rocket.xml", IND_ALPHA, IND_32)){
		// "../SpaceGame/resources/animations/rocket.xml"
		// Error handler TODO
	}	

	// Character rocket
	IND_Entity2d *rocket = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(rocket);					// Entity adding
	rocket->setAnimation(mAnimationRocket);				// Set the animation into the entity
	rocket->setPosition(600, 300, 0);
	rocket->setHotSpot(0.5f, 0.5f);
	


}

Ship::~Ship()
{

}
