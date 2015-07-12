#include "HUD.h"

HUD::HUD(CIndieLib *mI)
{
	//<----- Text --------->
	// Font
	
	if (!mI->_fontManager->add(mFontSmall, "../SpaceGame/resources/font_small.png", "../SpaceGame/resources/font_small.xml", IND_ALPHA, IND_32))
	{
		// error handler
	}

	if (!mI->_fontManager->add(mFontBig, "../SpaceGame/resources/font_big.png", "../SpaceGame/resources/font_big.xml", IND_ALPHA, IND_32))
	{
		// error handler
	}

	// ----- Alert creation -----	
	mI->_entity2dManager->add(mAlert);				// Entity adding
	mAlert->setFont(mFontSmall);					// Set the font into the entity
	mAlert->setLineSpacing(18);
	mAlert->setCharSpacing(-8);
	mAlert->setPosition(15, 580, 1);
	mAlert->setAlign(IND_LEFT);

	// ----- Score -----	
	mI->_entity2dManager->add(mPoints);				
	mPoints->setFont(mFontBig);					
	mPoints->setLineSpacing(18);
	mPoints->setCharSpacing(-8);
	mPoints->setPosition(400, 5, 1);
	mPoints->setAlign(IND_CENTER);

	// ----- Health -----	
	mI->_entity2dManager->add(mHealth);
	mHealth->setFont(mFontBig);
	mHealth->setLineSpacing(18);
	mHealth->setCharSpacing(-8);
	mHealth->setPosition(800, 5, 1);
	mHealth->setAlign(IND_RIGHT);
	
	// ----- Shots -----	
	mI->_entity2dManager->add(mShots);
	mShots->setFont(mFontBig);
	mShots->setLineSpacing(18);
	mShots->setCharSpacing(-8);
	mShots->setPosition(5, 5, 1);
	mShots->setAlign(IND_LEFT);

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
	mPoints->destroy();
	mHealth->destroy();
	mShots->destroy();
	delete points;
	delete health;
	delete shots;
}

void HUD::updateHud(int points, int health, int shots, int time)
{
	// Shows game info
	char mText[10];
	sprintf(mText, "score %d ", points);
	mPoints->setText(mText);
	sprintf(mText, "health %d ", health);
	mHealth->setText(mText);
	sprintf(mText, "shots %d ",shots);
	mShots->setText(mText);
	// time ---- sprintf(mText, "time>%d:%d", time / 60, time % 60);
}