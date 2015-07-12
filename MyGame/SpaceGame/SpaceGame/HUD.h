#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"

class HUD
{

private:
	IND_Entity2d *hud_ = IND_Entity2d::newEntity2d();
	IND_Font *mFontSmall = IND_Font::newFont();
	IND_Font *mFontBig = IND_Font::newFont();
	IND_Entity2d *mAlert = IND_Entity2d::newEntity2d();
	IND_Entity2d *mPoints = IND_Entity2d::newEntity2d(); 
	IND_Entity2d *mHealth = IND_Entity2d::newEntity2d();
	IND_Entity2d *mShots = IND_Entity2d::newEntity2d();
	int *points, *health, *shots;

public:
	HUD(CIndieLib *mI);
	~HUD();
	void showMenu();
	void showAlert(const char *str);
	void hideMenu();
	void updateHud(int points, int health, int shots, int time);
};