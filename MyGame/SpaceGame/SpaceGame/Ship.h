#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "Object.h"

class Ship : public Object
{

public:
	Ship(CIndieLib *mI, std::string str);
	~Ship();
};