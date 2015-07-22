#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

class Thing
{
private:
	int health = 10; // increase or decrease players health etc. 

public:
	IND_Animation *thingAnimation = IND_Animation::newAnimation();
	IND_Entity2d *thing = IND_Entity2d::newEntity2d();
	Thing(CIndieLib *mI, const char *resource);
	IND_Entity2d newObject(CIndieLib *mI, const char *resource);
	IND_Entity2d* getObject();
	~Thing();
};