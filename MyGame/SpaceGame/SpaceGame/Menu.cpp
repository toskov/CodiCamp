#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{

	// Font
	IND_Font *mFontSmall = IND_Font::newFont();
	if (!myI->_fontManager->add(mFontSmall, "../../resources/font_small.png", "../../resources/font_small.xml", IND_ALPHA, IND_32))
	{
		CatchError("Cannot find font resources!");
	}

	// ----- Font creation -----

	IND_Entity2d *mTextSmallWhite = IND_Entity2d::newEntity2d();
	myI->_entity2dManager->add(mTextSmallWhite);			// Entity adding
	mTextSmallWhite->setFont(mFontSmall);				// Set the font into the entity
	mTextSmallWhite->setLineSpacing(18);
	mTextSmallWhite->setCharSpacing(-8);
	mTextSmallWhite->setPosition(5, 5, 1);
	mTextSmallWhite->setAlign(IND_LEFT);
	
}

Menu::~Menu()
{
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
}