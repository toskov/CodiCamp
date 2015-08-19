#ifndef AI_H
#define	AI_H

#include "CIndieLib.h"
#include <vector>
#include "Bullet.h"

class Ai
{
private:
	double *delta;
	vector<Bullet*> bullets; // For enemy shooting posibilities
	int shootInterval = 15;
	const int enemyShootInterval = 15;
public:
	Ai();
	void Update();
	void Perception();
	void Think();
	void React();
	void Memorize();
	~Ai();
};

#endif