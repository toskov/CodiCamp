#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	hidden = true;
	mI = myI;

	// ---------- main menu ----------
	itemPlay = new MenuItem(myI, 400, 150, false, "Back");
	itemNewGame = new MenuItem(myI, 400, 200, false, "New game");
	itemOptions = new MenuItem(myI, 400, 250, false, "Options");
	itemSaveGame = new MenuItem(myI, 400, 300, false, "Save Game");
	itemLoadGame = new MenuItem(myI, 400, 350, false, "Load Game");
	itemQuit = new MenuItem(myI, 400, 400, false, "Quit");

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


int Menu::Update(CIndieLib  *mI)
{
	// return true if menu is hidden
	float positionX, positionY; // mouse position
	if (hidden)
	{
		HideMenu();
		mCursor->setPosition(-100,-100,100);
		return 1;
	}
	positionX = mI->_input->getMouseX();
	positionY = mI->_input->getMouseY();
	mCursor->setPosition(positionX, positionY, 20);

	// check button NEW GAME
	if (mI->_entity2dManager->isCollision(itemNewGame->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemNewGame->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
			HideMenu();
			return NEWGAME; // refresh game
		}
	}
	else
	{
		itemNewGame->delesectedItem();
	}

	// check button PLAY
	if (mI->_entity2dManager->isCollision(itemPlay->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemPlay->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
			HideMenu();
			return PLAY; // refresh game
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
			return OPTIONS;
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
			 return QUIT;
		 }
	 }
	 else
	 {
		 itemQuit->delesectedItem();
	 }

	 // check button SAVE GAME
	 if (mI->_entity2dManager->isCollision(itemSaveGame->getBound(), "rect", mCursor, "pointer"))
	 {
		 // mouse over
		 itemSaveGame->selectedItem();
		 if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		 {
			 //On left mouse button click
			 HideMenu();
			 return SAVEGAME; // refresh game
		 }
	 }
	 else
	 {
		 itemSaveGame->delesectedItem();
	 }

	 // check button LOAD GAME
	 if (mI->_entity2dManager->isCollision(itemLoadGame->getBound(), "rect", mCursor, "pointer"))
	 {
		 // mouse over
		 itemLoadGame->selectedItem();
		 if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		 {
			 //On left mouse button click
			 HideMenu();
			 return LOADGAME; // refresh game
		 }
	 }
	 else
	 {
		 itemLoadGame->delesectedItem();
	 }

	 ShowMenu();
	return false;
	
}
void Menu::ShowMenu()
{
	hidden = false;
	itemPlay->show();
	itemNewGame->show();
	itemQuit->show();
	itemOptions->show();
	itemSaveGame->show();
	itemLoadGame->show();
}

void Menu::HideMenu()
{
	mCursor->setPosition(-100, -100, 20);
	hidden = true;
	itemPlay->hide();
	itemQuit->hide();
	itemOptions->hide();
	itemControls->hide();
	itemSound->hide();
	itemBack->hide();
	itemNewGame->hide();
	itemSaveGame->hide();
	itemLoadGame->hide();
}
Menu::~Menu()
{
	mI->_surfaceManager->remove(mSurfaceCursor);
	mI->_entity2dManager->remove(mCursor);
	delete itemNewGame;
	delete itemPlay;
	delete itemQuit;
	delete itemOptions;
	delete itemControls;
	delete itemSound;
	delete itemBack;
	delete itemSaveGame;
	delete itemLoadGame;
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

bool Menu::isHidden()
{
	return hidden;
}