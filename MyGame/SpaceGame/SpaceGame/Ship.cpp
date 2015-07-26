#include "Ship.h"

Ship::Ship()
{
	// mI->_window->getWidth / 0.2f, mI->_window->getHeight / 0.2f, 0);
}

 Ship::Ship(CIndieLib *mI, const char *str)
{

	*speedX_ = 100.0f; // initial speed
	*speedY_ = 100.0f;
	// clear scores
	*health = 100;

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
	ship_->setPosition(400,200, 5);
	ship_->setHotSpot(0.5f, 0.5f);
	//ship_->setScale(0.3, 0.3);

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setPosition(ship_->getPosX(), ship_->getPosY(), 1);
	border->setBoundingAreas("../SpaceGame/resources/shipBound.xml");

	//Predefine 10 bullets 
	for (int i = 0; i < 10; i++){
		bullets_[i] = new Bullet(mI, 0, 10000, 10000);
	}
}

 IND_Entity2d* Ship::getColisionBorder()
 {
	 return border;
 }

/*
======================================
Update ship position
======================================
*/
void Ship::Update(double* delta)
{
	/*
	Infinite ship movement in rectangle
	*/
	this->mDelta = delta;
	float tempX = ship_->getPosX() + (*mDelta)* (*speedX_);
	if (tempX > 800) tempX = 0;
	if (tempX < 0) tempX = 800;
	float tempY = ship_->getPosY() + (*mDelta)* (*speedY_);
	if (tempY > 600) tempY = 0;
	if (tempY < 0) tempY = 600;
	ship_->setPosition(tempX, tempY, 0);
	border->setPosition(tempX, tempY, 1);
	border->setAngleXYZ(0, 0, ship_->getAngleZ());
	/*
	Update bullets 
	*/
	for (int i = 0; i < 10; i++){
		bullets_[i]->Update(delta);
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
	if (mI->_input->isKeyPressed(IND_KEYRIGHT) || mI->_input->isKeyPressed(IND_D))
	{
		this->rotateRight(300.0f * (*mDelta));
	}
	else
	{
		this->rotateRight(0);
	}
	// Rotate left
	if (mI->_input->isKeyPressed(IND_KEYLEFT) || mI->_input->isKeyPressed(IND_A))
	{
		this->rotateLeft(300.0f * (*mDelta));
	}
	else
	{
		this->rotateLeft(0);
	}

	if (mI->_input->isKeyPressed(IND_KEYUP) || mI->_input->isKeyPressed(IND_W))
	{
		this->increaseSpeed(500.0f * (*mDelta));
	}

	if (mI->_input->isKeyPressed(IND_KEYDOWN) || mI->_input->isKeyPressed(IND_S))
	{
		this->decreaseSpeed(500.0f * (*mDelta));
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
		*shots+=1; 

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
		float angle = ship_->getAngleZ()*3.14159265 / 180.f;
		offsetX =ship_->getPosX() + std::sin(angle)*40;
		offsetY =ship_->getPosY() - std::cos(angle)*40;
		
		bullets_[bulletIndex]->Set(ship_->getAngleZ(), offsetX, offsetY, mDelta); // Move and rotate last bullet
	}


/*
======================================
Game status
======================================
*/
int Ship:: getScore()
{
	return *score;
}

int Ship::getHealth()
{
	return *health;
}

int Ship::getShots()
{
	return *shots;
}

Ship::~Ship()
{
	delete speedX_;
	delete speedY_;
	delete [] bullets_;
	delete shots;
	delete health;
	delete score;
	ship_->destroy();
}

int Ship::getX()
{
	return ship_->getPosX();
}

int Ship::getY()
{
	return ship_->getPosY();
}

int Ship::getAngleZ()
{
	return ship_->getAngleZ();
}

void Ship::increaseHealth(int h)
{
	*health = *health + h;
}