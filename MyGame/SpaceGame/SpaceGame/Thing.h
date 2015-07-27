#ifndef THING_H
#define	THING_H
#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Surface.h"
#include "GlobalHeader.h"

class Thing
{
private:
	int *health = new int(10); // increase or decrease players health etc. 
	int *posX = new int(0);
	int *posY = new int(0);
	int *type = new int(0);
	
	
	IND_Entity2d *thing = IND_Entity2d::newEntity2d();
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	IND_Animation *thingAnimation = IND_Animation::newAnimation();
	IND_Surface *collisionSurface = IND_Surface::newSurface();

public:
	int getHealth(void);
	int getType();
	void hide(void);
	void show(int x, int y);
	void destroy(CIndieLib *mI);
	//void getHealth(void);
	IND_Entity2d* getColisionBorder();
	Thing();
	Thing(CIndieLib *mI, int type, int x, int y, int life);
	~Thing();
};
#endif