#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	isHidden = true;

	// ---------- main menu ----------
	itemPlay = new MenuItem(myI, 400, 150, false, "Play");
	itemOptions = new MenuItem(myI, 400, 200, false, "Options");
	itemQuit = new MenuItem(myI, 400, 250, false, "Quit");

	// ---------- Options menu ---------
	itemControls = new MenuItem(myI, 400, 150, false, "Controls");
	itemSound = new MenuItem(myI, 400, 200, false, "Sound");
	itemBack = new MenuItem(myI, 400, 250, false, "Back");
}
void Menu::Update()
{
	if (isHidden)
	{
		HideMenu();
		return;
	}
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
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
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