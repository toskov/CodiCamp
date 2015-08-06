#ifndef THING_H
#define	THING_H
#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Surface.h"
#include "GlobalHeader.h"
#include "Frame.h"
#include <vector>
#include "Errorhandler.h"

class Thing
{
private:
	int *health = new int(10); // increase or decrease players health etc. 
	int *posX = new int(0);
	int *posY = new int(0);
	int *type = new int(0);
	
	
	IND_Entity2d *thing = IND_Entity2d::newEntity2d();
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	IND_Surface *thingPictures;
	IND_Surface *collisionSurface = IND_Surface::newSurface();
	void Construct(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life); // for multy constructor initialise
	vector<Frame*> frames;

public:
	int getHealth(void);
	int getType();
	//void show(int x, int y);
	void destroy(CIndieLib *mI);
	int getPositionX();
	int getPositionY();
	//void getHealth(void);
	IND_Entity2d* getColisionBorder();
	Thing();
	Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle, vector<Frame*> frms);
	~Thing();
};
#endif