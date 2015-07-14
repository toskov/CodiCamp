#include "Menu.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{
	itemPlay = new MenuItem(myI, 400, 100, false, "Play");
	itemQuit = new MenuItem(myI, 400, 150, false, "Quit");

}
void Menu::ShowMenu()
{
	itemPlay->show();
	itemQuit->show();
}
void Menu::HideMenu()
{
	itemPlay->hide();
	itemQuit->hide();
}
Menu::~Menu()
{
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
}