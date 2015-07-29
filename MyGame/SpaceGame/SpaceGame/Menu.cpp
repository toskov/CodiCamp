#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	isHidden = true;

	// ---------- main menu ----------
	itemPlay = new MenuItem(myI, 400, 150, false, "Restart");
	itemOptions = new MenuItem(myI, 400, 200, false, "Options");
	itemQuit = new MenuItem(myI, 400, 250, false, "Quit");

	// ---------- Options menu ---------
	itemControls = new MenuItem(myI, 400, 150, false, "Controls");
	itemSound = new MenuItem(myI, 400, 200, false, "Sound");
	itemBack = new MenuItem(myI, 400, 250, false, "Back");

	// ------- set Cursor ---------
	myI->_surfaceManager->add(mSurfaceCursor, "..\\SpaceGame\\resources\\rocketCursor.png", IND_ALPHA, IND_32); // return?
	myI->_entity2dManager->add(mCursor);					       // Entity adding
	mCursor->setSurface(mSurfaceCursor);					   // Set the surface into the entity
	mCursor->setHotSpot(0.5f, 0.5f);
	// Empty object for colisions!
	mCursor->setBoundingCircle("pointer",15, 15, 3);

}


bool Menu::Update(CIndieLib  *mI)
{
	// return true if menu is hidden
	float positionX, positionY; // mouse position
	if (isHidden)
	{
		HideMenu();
		mCursor->setPosition(-100,-100,100);
		return true;
	}
	positionX = mI->_input->getMouseX();
	positionY = mI->_input->getMouseY();
	mCursor->setPosition(positionX, positionY, 20);

	// check button PLAY
	if (mI->_entity2dManager->isCollision(itemPlay->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemPlay->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
			HideMenu();
			return true;
		}
	} else 
	{
		itemPlay->delesectedItem();
	}

	// check button OPTIONS
	if (mI->_entity2dManager->isCollision(itemOptions->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemOptions->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
	//TODO enter in submenu
			return true;
		}
	}
	else
	{
		itemOptions->delesectedItem();
	}

	 // check button QUIT
	 if (mI->_entity2dManager->isCollision(itemQuit->getBound(), "rect", mCursor, "pointer"))
	 {
		 // mouse over
		 itemQuit->selectedItem();
		 if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		 {
			 //On left mouse button click
			 HideMenu();
			 exitSelected = true;
			 return true;
		 }
	 }
	 else
	 {
		 itemQuit->delesectedItem();
	 }
	 ShowMenu();
	return false;
	
}
void Menu::ShowMenu()
{
	isHidden = false;
	itemPlay->show();
	itemQuit->show();
	itemOptions->show();
}

void Menu::HideMenu()
{
	mCursor->setPosition(-100, -100, 20);
	isHidden = true;
	itemPlay->hide();
	itemQuit->hide();
	itemOptions->hide();
	itemControls->hide();
	itemSound->hide();
	itemBack->hide();
}
Menu::~Menu()
{
	mSurfaceCursor->destroy();
	mCursor->destroy();
	delete itemPlay;
	delete itemQuit;
	delete itemOptions;
	delete itemControls;
	delete itemSound;
	delete itemBack;
	delete posX;
	delete posY;
}

void Menu::ShowOptions(void)
{

}

void Menu::HideOptions(void)
{

}

void Menu::ShowSoundOptions(void)
{

}
void Menu::HideSoundOptions(void)
{

}
void Menu::ShowControls(void)
{

}
void Menu::HideControls(void)
{

}

bool Menu::isExitSelected()
{
	return exitSelected;
}