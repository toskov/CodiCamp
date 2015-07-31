#ifndef PARTICLE_H
#define PARTICLE_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "GlobalHeader.h"

class Particle
{
private:
	IND_Surface *particleSurface = IND_Surface::newSurface();
	IND_Entity2d *particle = IND_Entity2d::newEntity2d();
	double *alpha = new double(255.0); // for controll alfa chanel
public:
	Particle(CIndieLib*, int, int);
	void destroy(CIndieLib* mI);
	bool Update(CIndieLib* mI, double delta);
	~Particle();
};
#endif