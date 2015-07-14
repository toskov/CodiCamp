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
	
	// ----- MeniItem -----	
	mI->_entity2dManager->add(item);
	item->setFont(mFontBig);
	item->setLineSpacing(18);
	item->setCharSpacing(-8);
	item->setPosition(posX, posY, 1);
	item->setAlign(IND_CENTER);

	char mText[10];
	sprintf(mText, str);
	item->setText(mText);

}
void MenuItem::selectItem()
{

}
void MenuItem::delesectItem()
{

}
MenuItem::~MenuItem()
{
	item->destroy();
	mFontBig->destroy();
}
void MenuItem::hide()
{
	item->setPosition(-100, -100, 1);
}
void MenuItem::show()
{
	item->setPosition(this->posX, this->posY, 1);
}