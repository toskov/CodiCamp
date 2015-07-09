#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

class Bullet
{
private:
	float *speedX_ = new float(0.1f), *speedY_ = new float(0.1f);
	IND_Entity2d *mBullet_ = IND_Entity2d::newEntity2d();
	IND_Surface *mSurfaceBullet_ = IND_Surface::newSurface();
	double speedStep = 0.1; // TODO delta time

public:
	Bullet(CIndieLib *mI,float angle,float posX, float posY);
	void Update();
	void Set(float angle,float x,float y);
	~Bullet();
};