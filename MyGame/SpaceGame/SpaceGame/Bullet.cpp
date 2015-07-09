#include "Bullet.h"

Bullet::Bullet(CIndieLib *mI, float angle, float posX, float posY)
{
	// Creating surface for the background
	
	if (!mI->_surfaceManager->add(mSurfaceBullet_, "../SpaceGame/resources/fx_lazer_orange_dff.png", IND_OPAQUE, IND_32))
	{
		//TODO catch error
	}

	// Creating 2d entity for the background
	
	mI->_entity2dManager->add(mBullet_);					// Entity adding
	mBullet_->setSurface(mSurfaceBullet_);					// Set the surface into the entity
	mBullet_->setPosition(posX, posY, 5);	//mBullet_->setPosition(300, 200, 0);
	mBullet_->setHotSpot(0.5f, 0.5f);
	mBullet_->setAngleXYZ(0,0,angle);
}

void Bullet::Update()
{
	float tempX = mBullet_->getPosX() + *speedX_;
	float tempY = mBullet_->getPosY() + *speedY_;
	mBullet_->setPosition(tempX, tempY, 0);
}

void Bullet::Set(float angle, float x, float y)
{
	mBullet_->setPosition(x, y, 0);	//mBullet_->setPosition(300, 200, 0);
	mBullet_->setAngleXYZ(0, 0, angle);
	angle = angle*3.14159265 / 180.f;
	*speedX_ = std::sin(angle)*speedStep;
	*speedY_ = -std::cos(angle)*speedStep;
}

Bullet::~Bullet()
{
	delete speedX_;
	delete speedY_;
	mBullet_->destroy();
	mSurfaceBullet_->destroy();
}