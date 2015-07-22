#ifndef OPTIONSMENU_H
#define	OPTIONS_H
#include "CIndieLib.h"

// GAME OPTIONS
class Options
{
public:
	char *keyUp = new char(' ');
	char *keyDown = new char(IND_KEYUP); 
	char *keyLeft = new char(IND_KEYUP);
	char *keyRight = new char(IND_KEYUP); 
	char *keyShoot = new char(IND_KEYUP);
	char *soundValue = new char(0xF0); // 0-100
	Options(); // read file
	bool saveOptions(void);
	~Options();
};

#endif