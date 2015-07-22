#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	isHidden = true;
	// ------- set Cursor ---------
	myI->_surfaceManager->add(mSurfaceCursor, "..\\SpaceGame\\resources\\cursor.png", IND_ALPHA, IND_32); // return?
	myI->_entity2dManager->add(mCursor);					       // Entity adding
	mCursor->setSurface(mSurfaceCursor);					   // Set the surface into the entity

	// ---------- main menu ----------
	itemPlay = new MenuItem(myI, 400, 150, false, "Play");
	itemOptions = new MenuItem(myI, 400, 200, false, "Options");
	itemQuit = new MenuItem(myI, 400, 250, false, "Quit");

	// ---------- Options menu ---------
	itemControls = new MenuItem(myI, 400, 150, false, "Controls");
	itemSound = new MenuItem(myI, 400, 200, false, "Sound");
	itemBack = new MenuItem(myI, 400, 250, false, "Back");

	// ------- set Cursor ---------
	myI->_surfaceManager->add(mSurfaceCursor, "..\\SpaceGame\\resources\\cursor.png", IND_ALPHA, IND_32); // return?
	myI->_entity2dManager->add(mCursor);					       // Entity adding
	mCursor->setSurface(mSurfaceCursor);					   // Set the surface into the entity
}
void Menu::Update(CIndieLib  *myI)
{
	int positionX, positionY; // mouse possition
	if (isHidden)
	{
		HideMenu();
		mCursor->setPosition(-100,-100,1);
		return;
	}
	positionX = myI->_input->getMouseX();
	positionY = myI->_input->getMouseY();
	mCursor->setPosition(positionX, positionY, 1);
	ShowMenu();
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
	mCursor->setPosition(-100, -100, 1);
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