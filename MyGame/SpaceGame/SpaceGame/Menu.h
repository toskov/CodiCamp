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
	MenuItem *itemPlay, *itemQuit;

public:
	Menu();
	Menu(CIndieLib *mI);
	~Menu();
	void ShowMenu(void);
	void HideMenu(void);
};

#endif