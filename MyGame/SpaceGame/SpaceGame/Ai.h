#ifndef AI_H
#define	AI_H

#include "CIndieLib.h"
#include <vector>
#include "Thing.h"
#include "Ship.h"

class Ai
{
private:
	double *delta;

public:
	Ai();
	void Update(vector<Thing*> gameObjects, Ship *ship, double *delta);
	~Ai();
};

#endif