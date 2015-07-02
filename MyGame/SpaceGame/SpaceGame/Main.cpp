/*****************************************************************************************
* Desc: Tutorial a) 01 Installing
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "Menu.h"
#include "Ship.h"

/*
==================
Main
==================
*/
int IndieLib() // main
{
	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance(); // engine
	if (!mI->init()) return 0;
		

	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/earth_bkg.jpg", IND_OPAQUE, IND_32)) return 0;

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity





	IND_Animation *mAnimationRobot = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRobot, "../SpaceGame/resources/animations/robot.xml", IND_ALPHA, IND_32)) return 0;

	// Character robot
	IND_Entity2d *robot = IND_Entity2d::newEntity2d();
	IND_Entity2d *robot2 = IND_Entity2d::newEntity2d();

	mI->_entity2dManager->add(robot);					// Entity adding
	mI->_entity2dManager->add(robot2);					// Entity adding
	
	robot2->setAnimation(mAnimationRobot);				// Set the animation into the entity
	robot2->setHotSpot(0.5f, 0.5f);
	
	robot2->setPosition(200, 300,0);
	robot2->setScale(2, 2);
	robot2->setAngleXYZ(0, 0, 90);

	robot->setAnimation(mAnimationRobot);				// Set the animation into the entity
	robot->setPosition(400, 300, 0);
	robot->setHotSpot(0.5f, 0.5f);
	robot->setRegion(50, 50, 20, 20);



	Menu *menu = new Menu(mI);

	//Ship *ship = new Ship(mI,"../SpaceGame/resources/animations/rocket.xml" );

	// ----- Main Loop -----

	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{
		// ----- Input Update ----

		mI->_input->update();

		// -------- Render -------

		mI->_render->clearViewPort(0, 0, 60);
		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		mI->_render->endScene();
		mI->_render->showFpsInWindowTitle(); //FPS
	}

	// ----- Indielib End -----

	mI->end();

	return 0;
}


