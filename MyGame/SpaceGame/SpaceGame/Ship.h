
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"



class Ship : public ErrorHandler
{

private:
	float *sX_ = new float(0), *sY_ = new float(0);
public:
	IND_Entity2d *ship_ = IND_Entity2d::newEntity2d();
	Ship();
	Ship(CIndieLib *mI, const char *str);
	void MoveTo( float X,  float Y);
	void Move();
	void setSpeedX(float sX);
	void setSpeedY(float sY);
	~Ship();
};