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
#include "GlobalHeader.h"
#include "irrKlang.h"

using namespace irrklang; // Sound engine

//class Ship : public ErrorHandler
class Ship
{

private:
	float *speedX_ = new float(0), *speedY_ = new float(0); // Ship speed
	Bullet *bullets_[MAX_BULLETS]; //buffer for bullets
	int bulletIndex = 0; // current bullet
	double *mDelta; //speed synchronization
	int *shots = new int(0), *health = new int(0), *score = new int(0);
	IND_Surface *collisionSurface = IND_Surface::newSurface();
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	Sprite *engine = new Sprite();
	float gravity = 0;  // GRAVITY;
	bool rotating = false;
	int shootInterval = 300;
	ISoundEngine* soundEngine;
	float soundVolume = 0.5f;

	
public:
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();	
	IND_Entity2d* getBulletBorder(int number); // get collision border for one of bullets
	IND_Entity2d* getColisionBorder();
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void maxHealth();
	void clearScore();
	void clearShots();
	void Update(CIndieLib* mI, double *delta); // update ship position
	void Shoot(); 
	void setSpeedX(float sX);
	void setSpeedY(float sY);
	void increaseSpeed(float step);
	void changeHealth(int h);
	void decreaseSpeed(float step);
	void rotateLeft(float speed);
	void rotateRight(float speed);
	void ReadKeys(CIndieLib *mI);
	void changeScore(); // increase by 1 point
	void changeScore(int i); // increase by 1 point
	int getScore();
	int getHealth();
	int getShots();
	int getX();
	int getY();
	int getAngleZ();
	void gravityUpdate(double delta);
	void setSoundVolume(float volume);

	~Ship();
};
#endif
