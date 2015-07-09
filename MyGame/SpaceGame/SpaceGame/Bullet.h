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
	float* mDelta;
	double bulletSpeed = 1000.0;

public:
	Bullet(CIndieLib *mI,float angle,float posX, float posY);
	void Update();
	void Set(float angle, float x, float y, float* delta);
	~Bullet();
};