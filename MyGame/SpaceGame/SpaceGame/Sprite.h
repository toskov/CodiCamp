#ifndef SPRITE_H
#define	SPRITE_H
#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Surface.h"
#include "GlobalHeader.h"

class Sprite
{
private:
	int *frames = new int(4);  // must be set outside
	int *frameWidth = new int(50); // frame width - must be set outside
	int *frameHight = new int(66); // frame hight - must be set outside
	int *frameColumns = new int(4);  // must be set outside
	int  *currentFrame = new int(0);
	int *posX = new int(0);
	int *posY = new int(0);

	
	IND_Surface *picture = IND_Surface::newSurface();
	//IND_Entity2d *border = IND_Entity2d::newEntity2d(); //for collisions if necessary
	//IND_Surface *collisionSurface = IND_Surface::newSurface();

public:
	IND_Entity2d *sprite = IND_Entity2d::newEntity2d();
	Sprite();
	void Update(void);
	Sprite(CIndieLib *mI, const char *resource, int x, int y);
	void destroy(CIndieLib *mI);
	~Sprite();
};
#endif