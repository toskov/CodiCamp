#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Surface.h"

class Thing
{
private:
	int health = 10; // increase or decrease players health etc. 
	int *posX = new int(0);
	int *posY = new int(0);

public:
	IND_Animation *thingAnimation = IND_Animation::newAnimation();
	IND_Surface *collisionSurface = IND_Surface::newSurface();

	IND_Entity2d *thing = IND_Entity2d::newEntity2d();
	IND_Entity2d *border = IND_Entity2d::newEntity2d();
	Thing(CIndieLib *mI, const char *resource, int x, int y);
	~Thing();
};