#include "Particle.h"

Particle::Particle(CIndieLib *mI, int x, int y)
{
	// Planet surface for gravity game
	*alpha = 100; // start time 
	mI->_surfaceManager->add(particleSurface, "../SpaceGame/resources/smoke.png", IND_OPAQUE, IND_32,255,255,255);
	particle->setSurface(particleSurface);				// 1. Set the surface into the entity
	mI->_entity2dManager->add(particle);				// 2. Add Entity  to manager
	particle->setPosition(x, y, 55);
}

Particle::~Particle()
{
	delete alpha;
	particle->destroy();
}
void Particle::destroy(CIndieLib* mI)
{
		delete alpha;
		//particle->destroy(); //!!!
		mI->_entity2dManager->remove(particle);
		mI->_surfaceManager->remove(particleSurface);
}

bool Particle::Update(CIndieLib* mI, double delta)
{
	if (*alpha < 1)
	{
		return false;
	}
	*alpha = *alpha - 150 * delta;
	byte transp = (byte)(*alpha);
	particle->setScale(50/(*alpha),50/(*alpha));
	particle->setTransparency(transp); // set tranparency
	return true;
}