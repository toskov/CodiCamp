#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	itemPlay = new MenuItem(myI, 400, 150, false, "Play");
	itemOptions = new MenuItem(myI, 400, 200, false, "Options");
	itemQuit = new MenuItem(myI, 400, 250, false, "Quit");

}
void Menu::ShowMenu()
{
	itemPlay->show();
	itemQuit->show();
	itemOptions->show();
}
void Menu::HideMenu()
{
	itemPlay->hide();
	itemQuit->hide();
	itemOptions->hide();
}
Menu::~Menu()
{
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
}