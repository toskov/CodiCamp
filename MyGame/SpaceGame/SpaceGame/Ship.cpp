#include "Ship.h"

Ship::Ship()
{
	// mI->_window->getWidth / 0.2f, mI->_window->getHeight / 0.2f, 0);
}

Ship::Ship(CIndieLib *mI,const char *str)
{
	*speedX_ = 0.005f; // initial speed

	*speedY_ = 0.005f;
	// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();

	if (!mI->_animationManager->addToSurface(mAnimationRocket, (const char*)str, IND_ALPHA, IND_32))
	{
		CatchError("Cannot find animation resources!"); // TODO 
	}
	
	// Character rocket
	mI->_entity2dManager->add(ship_);					// Entity adding
	ship_->setAnimation(mAnimationRocket);				// Set the animation into the entity
	ship_->setSequence(0);
	ship_->setPosition(300,200, 100);
	ship_->setHotSpot(0.5f, 0.5f);


	//Predefine 10 bullets 
	for (int i = 0; i < 10; i++){
		bullets_[i] = new Bullet(mI, 0, 10000, 10000);
	}
	
}



/*
======================================
Update ship position
======================================
*/
void Ship::Update()
{
	/*
	Infinite ship movement in rectangle
	*/

	float tempX = ship_->getPosX() + *speedX_;
	if (tempX > 800) tempX = 0;
	if (tempX < 0) tempX = 800;
	float tempY = ship_->getPosY() + *speedY_;
	if (tempY > 600) tempY = 0;
	if (tempY < 0) tempY = 600;
	ship_->setPosition(tempX, tempY, 0);
	/*
	Update bullets 
	*/
	for (int i = 0; i < 10; i++){
		bullets_[i]->Update();
	}
}

void Ship::setSpeedX(float sX)
{
	*speedX_ = sX;
}

void Ship::setSpeedY(float sY)
{
	*speedY_ = sY;
}

void Ship::increaseSpeed(float step)
{
	float angle = ship_->getAngleZ()*3.14159265 / 180.f;
	*speedX_ = *speedX_ + std::sin(angle)*step;
	*speedY_ = *speedY_ - std::cos(angle)*step;
}

void Ship::decreaseSpeed(float step)
{
	float angle = ship_->getAngleZ()*3.14159265 / 180.f;
	*speedX_ = *speedX_ - std::sin(angle)*step;
	*speedY_ = *speedY_ + std::cos(angle)*step;
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

/*
======================================
Ship movement by keyboard
======================================
*/
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

	if (mI->_input->onKeyPress(IND_SPACE))
	{
		Shoot();
	}
}

/*
======================================
Control bullets
======================================
*/
void Ship::Shoot()
	{
		//moving last to new position
		bulletIndex++;
		if (bulletIndex > 9)
		{
			bulletIndex = 0;
		}
		
		/*
		Calculate offset from the center of the ship to spawn bullet
		*/
		float offsetX, offsetY;
		float angle = (ship_->getAngleZ()-25)*3.14159265 / 180.f;
		offsetX =ship_->getPosX() + std::sin(angle)*40;
		offsetY =ship_->getPosY() - std::cos(angle)*40;
		
		bullets_[bulletIndex]->Set(ship_->getAngleZ(), offsetX, offsetY); // Move and rotate last bullet
	}

Ship::~Ship()
{
	delete speedX_;
	delete speedY_;
	delete [] bullets_;
}
