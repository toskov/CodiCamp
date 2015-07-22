#ifndef SHIP_H
#define	SHIP_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"
#include "Bullet.h"
#include "Asteroid.h"
class Ship : public ErrorHandler
{

private:
	float *speedX_ = new float(0), *speedY_ = new float(0); // Ship speed
	Bullet *bullets_ [20]; // Must define buffer size
	int bulletIndex = 0; // current bullet
	double *mDelta; //speed synchronization
	int *shots = new int(0), *health = new int(0), *score = new int(0);
	
public:
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void Update(double* mDelta); // update ship position
	void Shoot(); 
	void setSpeedX(float sX);
	void setSpeedY(float sY);
	void increaseSpeed(float step);
	void decreaseSpeed(float step);
	void rotateLeft(float speed);
	void rotateRight(float speed);
	void ReadKeys(CIndieLib *mI);
	int getScore();
	int getHealth();
	int getShots();
	int getX();
	int getY();
	int getAngleZ();
	IND_Entity2d getObject();
	~Ship();
};
#endif
