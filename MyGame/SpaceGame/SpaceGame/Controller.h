#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"
#include "Bullet.h"
#include "Sprite.h"
#include "GlobalHeader.h"
#include "Particle.h"
#include "Particle.h"


class Controller
{
private:
	CIndieLib* mI;
	vector<Particle*> particles;
	int particlesCount = 0;
	int particleIndex = 0;
public:
	Controller(CIndieLib*);
	void createParticle();
	bool updateParticles(int);
	int getParticlesCount();
	void GameOver();
	~Controller();
};

#endif