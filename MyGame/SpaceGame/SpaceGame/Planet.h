#ifndef PLANET_H
#define PLANET_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "GObject.h"
#include "ErrorHandler.h"
#include <iostream>
#include <string>

using namespace std;

class Planet : public ErrorHandler
{
private:
	string resource = "";
public:
	 Planet();
	 Planet(CIndieLib *mI, const char *resource);
	~Planet();
	IND_Entity2d *planet = IND_Entity2d::newEntity2d();
};
#endif
