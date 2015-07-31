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
#include "Explosion.h"
#include <time.h>       /* time */
#include "Menu.h"
#include "Ship.h"
#include "Planet.h"
#include "HUD.h"
#include "Thing.h"
#include "Options.h"
#include "Controller.h"

//Creating game levels sould be there!

class Controller
{
private:
	CIndieLib* mI;
	vector<Particle*> particles;
	int particlesCount = 0;
	int particleIndex = 0;
	
public:
	// Vector Objects container
	vector<Thing*> allObjects;
	vector<Explosion*> explosions;
	Menu *menu;
	Ship *ship;
	HUD *hud;
	void refresh();
	void gameInit();
	Controller(CIndieLib*);
	void createParticle();
	bool updateParticles(int);
	int getParticlesCount();
	void gameGenerator();
	void GameOver();
	~Controller();
};

#endif