#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"


class Menu
{
private:
	int *posX, *posY;
	const IND_Entity2dManager *mI;

public:
	Menu(IND_Entity2dManager const *mi);
	~Menu();
	void ShowMenu(void);
	void HideMenu(void);
};