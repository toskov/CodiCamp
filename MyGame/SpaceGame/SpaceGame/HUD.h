#ifndef HUD_H
#define HUD_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"


/*
======================================
HUD interface
======================================
*/

class HUD
{

private:
	IND_Entity2d *hud_ = IND_Entity2d::newEntity2d();
	IND_Font *mFontSmall = IND_Font::newFont(); // small font for alerts
	IND_Font *mFontBig = IND_Font::newFont();	// big font for game info
	IND_Entity2d *mAlert = IND_Entity2d::newEntity2d(); // alert field
	IND_Entity2d *mPoints = IND_Entity2d::newEntity2d(); // score field
	IND_Entity2d *mHealth = IND_Entity2d::newEntity2d(); // health field
	IND_Entity2d *mShots = IND_Entity2d::newEntity2d();  // number of shots
	int *points, *health, *shots; 

public:
	HUD(CIndieLib *mI);
	~HUD();
	void showMenu();
	void showAlert(const char *str);
	void showAlert(double value);
	void hideMenu();
	void updateHud(int points, int health, int shots, int time);  // refresh game info
};
#endif