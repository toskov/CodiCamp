#ifndef MENU_H
#define	MENU_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"
#include "MenuItem.h"

class Menu 
{
private:
	CIndieLib *mI;
	int *posX, *posY;
	bool isHidden = true,exitSelected = false;
	MenuItem *itemPlay, *itemQuit, *itemOptions, *itemControls, *itemSound, *itemBack;
	enum currentMenu { MAIN = 1, OPTIONS, CONTROLS, SOUND, DIFFICULTY };
	enum difficulty { EASY = 1, NORMAL, HARD, EXPERT, UNDEFINED };
	difficulty gameDifficulty = EASY;
	currentMenu gameCurrentMenu = MAIN;
	IND_Surface *mSurfaceCursor = IND_Surface::newSurface();
	IND_Entity2d *mCursor = IND_Entity2d::newEntity2d();
	


public:
	Menu();
	Menu(CIndieLib *mI);
	~Menu();
	int Update(CIndieLib  *myI); // return result and hide menu
	void ShowMenu(void);
	void HideMenu(void);
	void ShowOptions(void);
	void HideOptions(void);
	void ShowSoundOptions(void);
	void HideSoundOptions(void);
	void ShowControls(void);
	void HideControls(void);
	bool isExitSelected(); // for game exit
};

#endif