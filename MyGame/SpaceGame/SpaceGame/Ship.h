#ifndef SHIP_H
#define	SHIP_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"
#include "Bullet.h"

class Ship : public ErrorHandler
{

private:
	float *sX_ = new float(0), *sY_ = new float(0);
	float *shootTime_ = new float(0), *shootTimeOld_ = new float(0);
	Bullet *bullets_ [20];
	int index = 0;

public:
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void Update();
	void Shoot();
	void setSpeedX(float sX);
	void setSpeedY(float sY);
	void increaseSpeed(float step);
	void decreaseSpeed(float step);
	void rotateLeft(float speed);
	void rotateRight(float speed);
	void ReadKeys(CIndieLib *mI);
	~Ship();
};
#endif
