#include "Menu.h"
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"

Menu::Menu()
{

}

Menu::Menu(CIndieLib  *myI)
{

	IND_Entity2d *object = IND_Entity2d::newEntity2d();
	
	// TODO Create animated menu buttons
	
}

Menu::~Menu()
{
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
}