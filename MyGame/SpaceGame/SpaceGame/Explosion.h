#ifndef EXPLOSION_H
#define	EXPLOSION_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "GlobalHeader.h"

class Explosion
{
private:
	int *frames = new int(16);  // must be set outside
	int *frameWidth = new int(64); // frame width - must be set outside
	int *frameHeight = new int(64); // frame hight - must be set outside
	int *frameColumns = new int(4);  // must be set outside to be universal
	int *frameRows = new int(4); //  must be set outside to be universal
	int *currentFrame = new int(0); // current frame
	int *time = new int(10); // animation delay time - depends on frame rate animation

	int *posX = new int(0);
	int *posY = new int(0);
	IND_Surface *picture = IND_Surface::newSurface();
	IND_Entity2d *explosion = IND_Entity2d::newEntity2d();

	//IND_Entity2d *border = IND_Entity2d::newEntity2d(); //for collisions if necessary
	//IND_Surface *collisionSurface = IND_Surface::newSurface();

public:

	Explosion();
	Explosion(CIndieLib *mI, int x, int y);
	bool Update(CIndieLib *mI, double deltaTime);
	void destroy(CIndieLib *mI);
	~Explosion();
};

#endif