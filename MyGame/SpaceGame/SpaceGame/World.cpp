#include "World.h"

World::World(CIndieLib* myI)
{
	this->mI = myI;
}

World::~World()
{
	bullets.clear();
	gameObjects.clear();

}