#include "MenuItem.h"
MenuItem::MenuItem(CIndieLib *mI,int posX, int posY, bool selected, const char *str)
{
	this->selected = selected;
	this->posX = posX;
	this->posY = posY;

	if (!mI->_fontManager->add(mFontBig, "../SpaceGame/resources/font_big.png", "../SpaceGame/resources/font_big.xml", IND_ALPHA, IND_32))
	{
		// error handler
	}
	// ----- Background ------
	mI->_surfaceManager->add(mBgSurface, "..\\SpaceGame\\resources\\buttonBg.png", IND_ALPHA, IND_32); // background?
	//mI->_surfaceManager->add(mBgSurfaceSelected, "..\\SpaceGame\\resources\\buttonBgSel.png", IND_ALPHA, IND_32); // background?
	mBackground->setSurface(mBgSurface);					   // Set the surface into the entity
	mI->_entity2dManager->add(mBackground);					       // Entity adding
	mBackground->setPosition(posX, posY, 9);
	mBackground->setHotSpot(0.5f, 0.5f);
	mBackground->setBoundingRectangle("rect", 0, 0, 248, 42); // If it is necessary
	
	// ----- Text -----	
	mI->_entity2dManager->add(item);
	item->setFont(mFontBig);
	item->setLineSpacing(18);
	item->setCharSpacing(-8);
	item->setPosition(posX, posY, 10);
	item->setAlign(IND_CENTER);

	char mText[10];
	sprintf(mText, str);
	item->setText(mText);

}
void MenuItem::selectedItem()
{
	// for mouseover visualisation
	mBackground->setTint(255,255, 50);
}
void MenuItem::delesectedItem()
{
	mBackground->setTint(255, 255, 255);
}
MenuItem::~MenuItem()
{
	// Must be used remove from Entity Manager!!!
	item->destroy();
	mFontBig->destroy();
	mBgSurface->destroy();
	mBackground->destroy();
//	mBgSurfaceSelected->destroy();
}
void MenuItem::hide()
{
	item->setPosition(-100, -100, 10);
	mBackground->setPosition(-100, -100, 9);
}
void MenuItem::show()
{
	item->setPosition(this->posX, this->posY, 10);
	mBackground->setPosition(this->posX, this->posY+27, 9); // some offset
}
void MenuItem::show(int x, int y)
{
	item->setPosition(x, y, 10);
	mBackground->setPosition(x, y + 27, 9); // some offset
}
bool  MenuItem::isMouseOver(int x, int y)
{
	// Return true if mouse over
	// rectangular area must be set manualy
	return true;
}

IND_Entity2d* MenuItem::getBound(void)
{
	return mBackground;
}