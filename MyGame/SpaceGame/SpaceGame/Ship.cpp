#include "Ship.h"

Ship::Ship()
{
	// mI->_window->getWidth / 0.2f, mI->_window->getHeight / 0.2f, 0);
}

Ship::Ship(CIndieLib *mI,const char *str)
{
	*sX_ = 0.001f;
	*sY_ = 0.001f;
	// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();

	if (!mI->_animationManager->addToSurface(mAnimationRocket, (const char*)str, IND_ALPHA, IND_32))
	{
		CatchError("Cannot find animation resources!");
	}
	
	// Character rocket
	mI->_entity2dManager->add(ship_);					// Entity adding
	ship_->setAnimation(mAnimationRocket);				// Set the animation into the entity
	ship_->setSequence(0);
	ship_->setPosition(300,200, 0);
	ship_->setHotSpot(0.5f, 0.5f);
}


void Ship::MoveTo(float X, float Y)
{
	ship_->setPosition(X , Y, 0);
}


void Ship::Move()
{
	float tempX = ship_->getPosX() + *sX_;
	if (tempX > 800) tempX = 0;
	float tempY = ship_->getPosY() + *sY_;
	if (tempY > 600) tempY = 0;
	ship_->setPosition(tempX, tempY, 0);
}

void Ship::setSpeedX(float sX)
{
	*sX_ = sX;
}

void Ship::setSpeedY(float sY)
{
	*sY_ = sY;
}

Ship::~Ship()
{

}
