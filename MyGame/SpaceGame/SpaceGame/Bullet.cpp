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
	mBullet_->setPosition(posX, posY, 0);	//mBullet_->setPosition(300, 200, 0);
	mBullet_->setHotSpot(0.5f, 0.5f);
	mBullet_->setAngleXYZ(0,0,angle);

	
	mTimer_->start();
	startTime = mTimer_->getTicks();

}

void Bullet::Update()
{
	float tempX = mBullet_->getPosX() + *speedX_;
	float tempY = mBullet_->getPosY() + *speedY_;
	if ((tempX > 800) || (tempX < 0) || (tempY > 600) || (tempY < 0)) this->~Bullet();
	mBullet_->setPosition(tempX, tempY, 0);
	if (mTimer_->getTicks() - startTime > 150) {
		 this->~Bullet();
	}
}

Bullet::~Bullet()
{
	delete speedX_;
	delete speedY_;
	delete mTimer_;
	mBullet_->destroy();
	mSurfaceBullet_->destroy();
}