#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"
#include "Thing.h"

class Asteroid: public Thing
{
private:

public:
	Asteroid();
	Asteroid(CIndieLib *mI, int type, int x, int y, int life);
	~Asteroid();
};