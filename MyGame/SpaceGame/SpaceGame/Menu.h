#ifndef MENU_H
#define	MENU_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"
#include "MenuItem.h"
#include "GlobalHeader.h"

class Menu 
{
private:
	CIndieLib *mI;
	int *posX, *posY;
	bool hidden = true,exitSelected = false;
	MenuItem *itemPlay, *itemQuit, *itemOptions, *itemControls, *itemSound, *itemBack, *itemNewGame,*itemSaveGame, *itemLoadGame;
	MenuItem *itemSaveOptions, *itemIncrease, *itemDecrease;


	enum difficulty { EASY = 1, NORMAL, HARD, EXPERT, UNDEFINED };
	difficulty gameDifficulty = EASY;
	currentMenu gameCurrentMenu = PLAY;
	IND_Surface *mSurfaceCursor = IND_Surface::newSurface();
	IND_Entity2d *mCursor = IND_Entity2d::newEntity2d();
	bool mouseButtonReleased = true;
	


public:
	Menu();
	Menu(CIndieLib *mI);
	~Menu();
	int Update(); // return result and hide menu
	void HideMenu(void);
	void ShowOptions(void);
	void HideOptions(void);
	void ShowSoundOptions(void);
	void HideSoundOptions(void);
	void ShowControls(void);
	void HideControls(void);
	bool isHidden(void);
	bool isExitSelected(void); // for game exit
	void ShowPauseMenu(void);
	void ShowGameOverMenu(void);
	void clearMenu(void);
};

#endif