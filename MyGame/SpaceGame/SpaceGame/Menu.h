#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

#ifndef MENU_H
#define	MENU_H

class Menu
{
private:
	int *posX, *posY;

public:
	Menu();
	Menu(CIndieLib *mI);
	~Menu();
	void ShowMenu(void);
	void HideMenu(void);
};

#endif