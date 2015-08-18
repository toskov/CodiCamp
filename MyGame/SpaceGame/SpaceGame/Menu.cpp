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
	itemQuit = new MenuItem(myI, 400, 390, false, "Quit");
	itemSaveOptions = new MenuItem(myI, 400, 400, false, "Back"); 
	itemIncrease = new MenuItem(myI, 400, 450, false, "Sound +");
	itemDecrease = new MenuItem(myI, 400, 500, false, "Sound -");

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


int Menu::Update()
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
			ShowOptions();
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
			// HideMenu();
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

	 // check button BACK OPTIONS
	 if (mI->_entity2dManager->isCollision(itemSaveOptions->getBound(), "rect", mCursor, "pointer"))
	 {
		 // mouse over
		 itemSaveOptions->selectedItem();
		 if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		 {
			 //On left mouse button click
			 //HideMenu();
			 // SAVE TODO
			 ShowPauseMenu();
			 return SAVEOPTIONS; // refresh game
		 }
	 }
	 else
	 {
		 itemSaveOptions->delesectedItem();
	 }
	

	// check button INCREASE
	if (mI->_entity2dManager->isCollision(itemIncrease->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemIncrease->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
			return INCREASE; // refresh game
		}
	}
	else
	{
		itemIncrease->delesectedItem();
	}

	
	// check button DECREASE
	if (mI->_entity2dManager->isCollision(itemDecrease->getBound(), "rect", mCursor, "pointer"))
	{
		// mouse over
		itemDecrease->selectedItem();
		if (mI->_input->isMouseButtonPressed(IND_MBUTTON_LEFT))
		{
			//On left mouse button click
			return DECREASE; // refresh game
		}
	}
	else
	{
		itemDecrease->delesectedItem();
	}

	return false;
}


void Menu::ShowPauseMenu()
{
	hidden = false;
	itemPlay->show(400, 150);
	itemSaveGame->show(400, 200);
	itemLoadGame->show(400, 250);
	itemOptions->show(400, 300);
	itemQuit->show(400, 350);


}

void Menu::ShowGameOverMenu(void)
{
	hidden = false;
	itemNewGame->show(400, 150);
	itemLoadGame->show(400, 200);
	itemQuit->show(400, 250);
}

void Menu::ShowOptions(void)
{
	hidden = false;
	clearMenu();
	
	itemSaveOptions->show(400, 150);
	itemIncrease->show(400, 200);
	itemDecrease->show(400, 250);
}
void Menu::HideMenu()
{
	mCursor->setPosition(-100, -100, 20);
	hidden = true;
	clearMenu();
}

void Menu::clearMenu()
{
	itemPlay->hide();
	itemQuit->hide();
	itemOptions->hide();
	itemControls->hide();
	itemSound->hide();
	itemBack->hide();
	itemNewGame->hide();
	itemSaveGame->hide();
	itemLoadGame->hide();
	itemDecrease->hide();
	itemIncrease->hide();
	itemSaveOptions->hide();
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
	delete itemSaveOptions;
	delete itemIncrease;
	delete itemDecrease;
	delete posX;
	delete posY;
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