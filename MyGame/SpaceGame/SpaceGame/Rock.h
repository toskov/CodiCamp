#ifndef ROCK_H
#define ROCK_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"


class Rock
{
private:
	int *frames = new int(49);  // must be set outside
	int *frameWidth = new int(77); // frame width - must be set outside
	int *frameHeight = new int(72); // frame hight - must be set outside
	int *frameColumns = new int(13);  // must be set outside  --- is rotated
	int *frameRows = new int(4);

	int  *currentFrame = new int(0);
	int *posX = new int(0);
	int *posY = new int(0);
	int *animationSpeedDelay = new int(1000);
	int *delta = new int(0);

	float *speedX_ = new float(0.1f), *speedY_ = new float(0.1f);
	IND_Entity2d *rock = IND_Entity2d::newEntity2d();
	IND_Surface *picture = IND_Surface::newSurface(); // surface
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	IND_Surface *collisionSurface = IND_Surface::newSurface();

public:
	Rock();
	Rock(CIndieLib *mI, int x, int y);
	Rock(CIndieLib *mI, int x, int y, int angle);
	void update(float delta);
	void update();
	void destroy(CIndieLib *mI);
	~Rock();
};


#endif