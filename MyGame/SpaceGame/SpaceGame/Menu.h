#ifndef MENU_H
#define	MENU_H

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"
#include "ErrorHandler.h"

class Menu : public ErrorHandler
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