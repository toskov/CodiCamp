/*****************************************************************************************
* Desc: Tutorial a) 01 Installing
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"

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

	IND_Entity2dManager manager;
	IND_Entity2d *object = IND_Entity2d::newEntity2d();

	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/blue_background.jpg", IND_OPAQUE, IND_32)) return 0;

	// Characters animations, we apply transparency
	IND_Animation *mAnimationRobot = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRobot, "../SpaceGame/resources/animations/robot.xml", IND_ALPHA, IND_32)) return 0;

	// Characters animations, we apply transparency
	IND_Animation *mAnimationRocket = IND_Animation::newAnimation();
	if (!mI->_animationManager->addToSurface(mAnimationRocket, "../SpaceGame/resources/animations/rocket.xml", IND_ALPHA, IND_32)) return 0;

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	// Character robot
	IND_Entity2d *robot = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(robot);					// Entity adding
	robot->setAnimation(mAnimationRobot);				// Set the animation into the entity
	robot->setPosition(300, 200,0);

	// Character rocket
	IND_Entity2d *rocket = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(rocket);					// Entity adding
	rocket->setAnimation(mAnimationRocket);				// Set the animation into the entity
	rocket->setPosition(400, 300, 0);


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


