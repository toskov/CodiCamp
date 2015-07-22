#ifndef OPTIONSMENU_H
#define	OPTIONS_H
#include "CIndieLib.h"

// GAME OPTIONS
class Options
{
public:
	IND_Key *keyUp = new IND_Key(IND_KEYUP);
	IND_Key *keyDown = new IND_Key(IND_KEYDOWN);
	IND_Key *keyLeft = new IND_Key(IND_KEYLEFT);
	IND_Key *keyRight = new IND_Key(IND_KEYRIGHT);
	IND_Key *keyShoot = new IND_Key(IND_SPACE);
	IND_Key *soundValue = new int(50u); // 0-100
	Options(); // read file
	bool saveOptions(void);
	~Options();
};

#endif