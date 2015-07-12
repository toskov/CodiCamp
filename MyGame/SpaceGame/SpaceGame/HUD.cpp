#include "HUD.h"

HUD::HUD(CIndieLib *mI)
{
	//<----- Text --------->
	// Font
	
	if (!mI->_fontManager->add(mFontSmall, "../SpaceGame/resources/font_small.png", "../SpaceGame/resources/font_small.xml", IND_ALPHA, IND_32))
	{
		// error handler
	}

	if (!mI->_fontManager->add(mFontBig, "../SpaceGame/resources/font_small.png", "../SpaceGame/resources/font_big.xml", IND_ALPHA, IND_32))
	{
		// error handler
	}

	// ----- Font creation -----

	
	mI->_entity2dManager->add(mAlert);				// Entity adding
	mAlert->setFont(mFontSmall);					// Set the font into the entity
	mAlert->setLineSpacing(18);
	mAlert->setCharSpacing(-8);
	mAlert->setPosition(5, 5, 1);
	mAlert->setAlign(IND_LEFT);
	
};

void HUD::showAlert(const char *str)
{
	char mText[2048];
	mText[0] = 0;
	strcpy(mText, str);
	mAlert->setText(mText);
}

HUD::~HUD()
{
	hud_->destroy();
	mFontSmall->destroy();
	mFontBig->destroy();
	mAlert->destroy();
	delete points;
	delete health;
	delete shots;
}