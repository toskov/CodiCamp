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
	mBullet_->setAngleXYZ(0, 0, angle);
	mBullet_->setBoundingCircle("bullet",4,4,6);


}

void Bullet::Update(double *delta)
{
	mDelta = delta;
	// Need to be updated every frame
	float tempX = mBullet_->getPosX() + *speedX_;
	float tempY = mBullet_->getPosY() + *speedY_;
	mBullet_->setPosition(tempX, tempY, 0);
}

void Bullet::Set(float angle, float x, float y, double* delta)
{
	this->mDelta = delta;

	// Set new position for bullet when the ship is shooting
	mBullet_->setPosition(x, y, 0);	//mBullet_->setPosition(300, 200, 0);
	mBullet_->setAngleXYZ(0, 0, angle); // must be the same as the ship angle
	angle = angle*3.14159265 / 180.f; // converting from radians to degrees
	*speedX_ = std::sin(angle)* (*mDelta) * bulletSpeed;
	*speedY_ = -std::cos(angle)* (*mDelta) * bulletSpeed;
}

Bullet::~Bullet()
{
	delete speedX_;
	delete speedY_;
	mBullet_->destroy();
	mSurfaceBullet_->destroy();
}