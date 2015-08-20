#include "Bullet.h"

Bullet::Bullet(CIndieLib *mI, float angle, float posX, float posY)
{

	//this->mI = mI;
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
	// Need to be updated every cycle
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

IND_Entity2d* Bullet::getColisionBorder()
{
	return mBullet_;
}


bool Bullet::outOfRange(int maxX, int maxY)
{
	int x = mBullet_->getPosX();
	int y = mBullet_->getPosY();

	if (x < 0 || y < 0 || x > maxX || y > maxY) return true;

	return false;// The bullet is ready to be destroyed if it is out of window 
}

void Bullet::destroy()
{
	/**/
	//return; // TODO !!!!!!!!

	delete speedX_;
	delete speedY_;
	mBullet_->deleteBoundingAreas("bullet");
	mBullet_->setShow(false);
	//destroy();
	//mSurfaceBullet_->destroy();
	//mI->_entity2dManager->remove(mBullet_);
	//mI->_surfaceManager->remove(mSurfaceBullet_);
	
	
}

Bullet::~Bullet()
{
	delete speedX_;
	delete speedY_;

}
