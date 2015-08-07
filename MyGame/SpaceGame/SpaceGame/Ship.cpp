#include "Ship.h"

Ship::Ship()
{
	// mI->_window->getWidth / 0.2f, mI->_window->getHeight / 0.2f, 0);
}

 Ship::Ship(CIndieLib *mI, const char *str)
{

	*speedX_ = 0.01f; // initial speed
	*speedY_ = 0.01f;
	// clear scores
	*health = 100;
	engine  = new Sprite(mI, "../SpaceGame/resources/sEngine.png", 0,0);

	// Sound init
	soundEngine = irrklang::createIrrKlangDevice();
	if (!soundEngine)
	{
		printf("Could not startup engine\n");
		// error starting up the engine
	}
	

	// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();

	if (!mI->_animationManager->addToSurface(mAnimationRocket, (const char*)str, IND_ALPHA, IND_32))
	{
		ErrorHandler::trace("Cannot find animation resources!"); // TODO 
	}
	
	// Character rocket
	mI->_entity2dManager->add(ship_);					// Entity adding
	ship_->setAnimation(mAnimationRocket);				// Set the animation into the entity
	ship_->setSequence(1);
	ship_->setPosition(174,482, 5);
	ship_->setHotSpot(0.5f, 0.5f);
	//ship_->setScale(0.3, 0.3);
	

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setPosition(ship_->getPosX(), ship_->getPosY(), 1);
	border->setBoundingAreas("../SpaceGame/resources/shipBound.xml");

	//Predefine 10 bullets 
	for (int i = 0; i < MAX_BULLETS; i++){
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
 void Ship::Update(CIndieLib* mI, double* delta)
{
	/*
	Infinite ship movement in rectangle
	*/
	Ship::gravityUpdate(*delta);
	this->mDelta = delta;
	float tempX = ship_->getPosX() + (*mDelta)* (*speedX_);
	//if (tempX > 800) tempX = 0;
	//if (tempX < 0) tempX = 800;
	if ((tempX > 800)||(tempX < 0)) *speedX_ = -*speedX_;
	float tempY = ship_->getPosY() + (*mDelta)* (*speedY_);
	//if (tempY > 600) tempY = 0;
	//if (tempY < 0) tempY = 600;
	if ((tempY > 600) || (tempY < 0)) *speedY_ = -*speedY_;
	ship_->setPosition(tempX, tempY, 0);
	border->setPosition(tempX, tempY, 1);
	border->setAngleXYZ(0, 0, ship_->getAngleZ());
	/*
	Update bullets 
	*/
	for (int i = 0; i < MAX_BULLETS; i++){
		bullets_[i]->Update(delta);
	}
	/*
	Calculate offset from the center of the ship to spawn bullet
	*/
	float offsetX, offsetY;
	float angle = (ship_->getAngleZ()-145)*3.14159265 / 180.f;
	offsetX = ship_->getPosX() + std::sin(angle) * 40;
	offsetY = ship_->getPosY() - std::cos(angle) * 40;

	/*
	Calculate ship engine flames position
	*/
	engine->sprite->setPosition(offsetX, offsetY, 0);
	engine->sprite->setAngleXYZ(0, 0, ship_->getAngleZ());
	engine->Update();
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
	engine->sprite->setShow(false);
	//rotating = false;
	// Rotate right
	if (mI->_input->isKeyPressed(IND_KEYRIGHT) || mI->_input->isKeyPressed(IND_D))
	{
		this->rotateRight(250.0f * (*mDelta));
		rotating = true;
	}
	else
	{
		this->rotateRight(0);
	}
	// Rotate left
	if (mI->_input->isKeyPressed(IND_KEYLEFT) || mI->_input->isKeyPressed(IND_A))
	{
		this->rotateLeft(250.0f * (*mDelta));
		rotating = true;
	}
	else
	{
		this->rotateLeft(0);
	}

	if (mI->_input->isKeyPressed(IND_KEYUP) || mI->_input->isKeyPressed(IND_W))
	{
		this->increaseSpeed(500.0f * (*mDelta));
		engine->sprite->setShow(true);
	}

	if (mI->_input->isKeyPressed(IND_KEYDOWN) || mI->_input->isKeyPressed(IND_S))
	{
		this->decreaseSpeed(500.0f * (*mDelta));
	}

	if (mI->_input->isKeyPressed(IND_SPACE))
	{
		Shoot(); //shooting
		
	}
	else
	{
		shootInterval = 0; // imediately shppting
	}
}

/*
======================================
Control bullets
======================================
*/
void Ship::Shoot()
	{
		shootInterval--;
		if (shootInterval > 1) return;
		shootInterval = 2000000*(*mDelta); // speed of shooting. Can be increased in game levels
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
		soundEngine->play2D("../SpaceGame/resources/weapon_player.wav");
		soundEngine->setSoundVolume(soundVolume); // have to be set by FX volume from controller
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
	soundEngine->drop();
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

void Ship::changeHealth(int h)
{
	*health = *health + h;
}

void Ship::changeScore()
{
	*score +=1;
}

void Ship::changeScore(int points)
{
	*score += points;
}

// Return bullet border
IND_Entity2d* Ship::getBulletBorder(int number)
{
	if (number < 0 || number >MAX_BULLETS) return bullets_[0]->getColisionBorder(); // for error preventing 
	return bullets_[number]->getColisionBorder();
}

void Ship::gravityUpdate(double delta)
{
	*speedY_ = *speedY_ + gravity*delta*10;
}

void Ship::setSoundVolume(float volume)
{
	soundVolume = volume;
}