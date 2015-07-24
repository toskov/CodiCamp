#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Font.h"

class MenuItem
{
private:
	IND_Entity2d *item = IND_Entity2d::newEntity2d();
	IND_Surface *mBgSurface = IND_Surface::newSurface();
	IND_Surface *mBgSurfaceSelected = IND_Surface::newSurface();
	IND_Entity2d *mBackground = IND_Entity2d::newEntity2d();
	
	IND_Font *mFontBig = IND_Font::newFont();	// big font for game info
	int posX, posY;
	bool selected;
public:
	MenuItem(CIndieLib *mI,int posX, int posY, bool selected, const char *str);
	void selectedItem(void);
	void delesectedItem(void);
	bool isMouseOver(int x,int y);
	void hide(void);
	void show(void);
	IND_Entity2d* getBound(void);
	~MenuItem();
};