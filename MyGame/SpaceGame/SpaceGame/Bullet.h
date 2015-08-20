#ifndef BULLET_H
#define BULLET_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

class Bullet
{
private:
	CIndieLib *mI;
	float *speedX_ = new float(0.1f), *speedY_ = new float(0.1f);
	IND_Entity2d *mBullet_ = IND_Entity2d::newEntity2d();
	IND_Surface *mSurfaceBullet_ = IND_Surface::newSurface();
	double* mDelta;
	double bulletSpeed = 1000;

public:
	Bullet(CIndieLib *mI,float angle,float posX, float posY);
	void Update(double *delta);
	bool outOfRange(int x,int y);// The bullet is ready to be destroyed if it is out of window 
	void Set(float angle, float x, float y, double* delta);
	IND_Entity2d* getColisionBorder(); //return object for collision detection
	void destroy();
	~Bullet();
};

#endif