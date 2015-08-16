#include "Ai.h"

void Ai::Update(vector<Thing*> gameObjects, Ship *ship, double *delta)
{
	this->delta = delta;
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->getType() == UFO)
		{
			gameObjects[i]->Update(delta); //update objects animation
		}
		
	}

}

Ai::Ai()
{

}

Ai::~Ai()
{

}