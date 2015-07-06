#include "Ship.h"

Ship::Ship()
{
	
}

Ship::Ship(CIndieLib *mI,const char *str)
{
	//SetPosition(0, 0, 0);	

	
	// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRocket, (const char*)str, IND_ALPHA, IND_32)){
		// "../SpaceGame/resources/animations/rocket.xml"
		//TODO Error handler 
	}	
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();
	// Character rocket
	mI->_entity2dManager->add(ship_);					// Entity adding
	ship_->setAnimation(mAnimationRocket);				// Set the animation into the entity
	ship_->setPosition(600, 300, 0);
	ship_->setHotSpot(0.5f, 0.5f);
		
}

void Ship::SetPosition(int x,int y,int z)
{
	//ship_->setPosition(x, y, z);
}


Ship::~Ship()
{

}
