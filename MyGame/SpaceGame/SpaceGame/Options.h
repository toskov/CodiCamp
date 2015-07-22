// GAME OPTIONS
#include "CIndieLib.h"

#ifndef OPTIONSMENU_H
#define	OPTIONS_H
class Options
{
public:
	char *keyUp, *keyDown, *keyLeft, *keyRight, *keyShoot;
	int *soundValue;
	Options(); // read file
	bool saveOptions(void);
	~Options();
};

#endif