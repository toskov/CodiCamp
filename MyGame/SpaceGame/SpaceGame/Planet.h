#ifndef PLANET_H
#define PLANET_H
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include <iostream>
#include <string>
using namespace std;

class Planet
{
private:
	string resource = "";
public:
	 Planet(CIndieLib *mI, string resource);
	~Planet();
};
#endif
