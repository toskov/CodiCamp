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
	int *posX, *posY;
	bool isHidden;
	MenuItem *itemPlay, *itemQuit, *itemOptions, *itemControls, *itemSound, *itemBack;

public:
	Menu();
	Menu(CIndieLib *mI);
	~Menu();
	void Update();
	void ShowMenu(void);
	void HideMenu(void);
	void ShowOptions(void);
	void HideOptions(void);
	void ShowSoundOptions(void);
	void HideSoundOptions(void);
	void ShowControls(void);
	void HideControls(void);
};

#endif