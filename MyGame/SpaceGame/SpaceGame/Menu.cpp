#include "Menu.h"
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"

Menu::Menu(IND_Entity2dManager const *myI)
{
	this->mI = myI;
	IND_Entity2d *object = IND_Entity2d::newEntity2d();
	
	/*
		// Characters animations, we apply transparency
	IND_Animation *mAnimationRobot = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRobot, "../SpaceGame/resources/animations/robot.xml", IND_ALPHA, IND_32)) return 0;

	// Character robot
	IND_Entity2d *robot = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(robot);					// Entity adding
	robot->setAnimation(mAnimationRobot);				// Set the animation into the entity
	robot->setPosition(300, 200, 0);
	
	*/

}

Menu::~Menu()
{
	// Remove object
	//mI->_entity2dManager->remove(robot);
	//robot->destroy();
}