
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"



class Ship : public GObject
{

public:
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void SetPosition(int x,int y,int z);
	~Ship();
};