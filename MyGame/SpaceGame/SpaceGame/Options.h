#ifndef OPTIONS_H
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
	float *soundValue = new float(0.50f); // 0-100
	Options(); // read file
	void loadGameOptions(void); // read objects from file
	bool saveOptions(void);
	~Options();
};

#endif