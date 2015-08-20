#ifndef WORLD
#define WORLD

#include "CIndieLib.h"
#include "Thing.h"
#include "Bullet.h"

class World
{
	private:
		CIndieLib* mI;
	public:
	vector<Thing*> gameObjects;
	vector<Bullet*> bullets;

	World(CIndieLib* mI);
	~World();

};
#endif
