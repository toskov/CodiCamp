#ifndef SHIP_H
#define	SHIP_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"
#include "Bullet.h"
#include "Sprite.h"

class Ship : public ErrorHandler
{

private:
	float *speedX_ = new float(0), *speedY_ = new float(0); // Ship speed
	Bullet *bullets_ [20]; // Must define buffer size
	int bulletIndex = 0; // current bullet
	double *mDelta; //speed synchronization
	int *shots = new int(0), *health = new int(0), *score = new int(0);

	IND_Surface *collisionSurface = IND_Surface::newSurface();
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	Sprite *engine = new Sprite();
	
public:
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void Update(double* mDelta); // update ship position
	void Shoot(); 
	void resetShots();
	void setScore(int i);
	void setHealth(int i);
	void setSpeedX(float sX);
	void setSpeedY(float sY);
	void increaseSpeed(float step);
	void increaseHealth(int h);
	void decreaseSpeed(float step);
	void rotateLeft(float speed);
	void rotateRight(float speed);
	void ReadKeys(CIndieLib *mI);
	void increaseScore(); // increase by 1 point
	int getScore();
	int getHealth();
	int getShots();
	int getX();
	int getY();
	int getAngleZ();
	IND_Entity2d* getBulletBorder(int number); // get collision border for one of bullets
	IND_Entity2d* getColisionBorder();
	~Ship();
};
#endif
