#include "Ship.h"

Ship::Ship()
{
	// mI->_window->getWidth / 0.2f, mI->_window->getHeight / 0.2f, 0);
}

Ship::Ship(CIndieLib *mI,const char *str)
{
	*sX_ = 0.05f;
	*sY_ = 0.005f;
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
	ship_->setPosition(300,200, 1);
	ship_->setHotSpot(0.5f, 0.5f);
}


void Ship::MoveTo(float X, float Y)
{
	ship_->setPosition(X , Y, 0);
}

/// Update ship position
void Ship::Update()
{
	float tempX = ship_->getPosX() + *sX_;
	if (tempX > 800) tempX = 0;
	if (tempX < 0) tempX = 800;
	float tempY = ship_->getPosY() + *sY_;
	if (tempY > 600) tempY = 0;
	if (tempY < 0) tempY = 600;
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

void Ship::increaseSpeed(float step)
{
	float angle = ship_->getAngleZ()*3.14159265 / 180.f;
	*sX_ = *sX_+ std::sin(angle)*step;
	*sY_ = *sY_- std::cos(angle)*step;
}

void Ship::decreaseSpeed(float step)
{
	float angle = ship_->getAngleZ()*3.14159265 / 180.f;
	*sX_ = *sX_ - std::sin(angle)*step;
	*sY_ = *sY_ + std::cos(angle)*step;
}

void Ship::rotateLeft(float speed)
{
	float tempAngle = ship_->getAngleZ();
	ship_->setAngleXYZ(0, 0, tempAngle - speed);
}

void Ship::rotateRight(float speed)
{
	float tempAngle = ship_->getAngleZ();
	ship_->setAngleXYZ(0, 0, tempAngle + speed);
}

void Ship::ReadKeys(CIndieLib *mI)
{
	// Rotate right
	if (mI->_input->isKeyPressed(IND_KEYRIGHT))
	{
		this->rotateRight(0.03f);
	}
	else
	{
		this->rotateRight(0);
	}
	// Rotate left
	if (mI->_input->isKeyPressed(IND_KEYLEFT))
	{
		this->rotateLeft(0.03f);
	}
	else
	{
		this->rotateLeft(0);
	}

	if (mI->_input->isKeyPressed(IND_KEYUP))
	{
		this->increaseSpeed(0.00001f);
	}

	if (mI->_input->isKeyPressed(IND_KEYDOWN))
	{
		this->decreaseSpeed(0.00001f);
	}
}
Ship::~Ship()
{
	delete sX_;
	delete sY_;
}
