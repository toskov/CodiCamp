#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

class Menu
{
private:
	int *posX, *posY;

public:
	Menu(IND_Entity2dManager *myI);
	~Menu();
	void ShowMenu(void);
	void HideMenu(void);
};