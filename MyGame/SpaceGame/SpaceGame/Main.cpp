/*****************************************************************************************
* Desc: Tutorial a) 01 Installing
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "Menu.h"
#include "Ship.h"
#include "Planet.h"
#include "HUD.h"
#include "Thing.h"
#include "Options.h"


/*
==================
Main
==================
*/


int IndieLib() // main
{

	

	// ----- IndieLib initialization -----

	CIndieLib *mI = CIndieLib::instance(); // engine
	if (!mI->init()) return 0;
		
	// Creating surface for the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Colorful_Galaxy-800x600.jpg", IND_OPAQUE, IND_32)) return 0;


	// -------- Load Options ----------------
	Options *gameOptions = new Options(); // read options from file
	gameOptions->saveOptions(); // for tests


	// ------------- FOR TESTS - COLLISIONS ---------------
	// Loading Rocket
	/*
		IND_Surface *mSurfaceRocket = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceRocket, "..\\SpaceGame\\resources\\rocket.png", IND_ALPHA, IND_32)) return 0;

	// Loading Beetleship
	IND_Surface *mSurfaceBeetle = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBeetle, "..\\SpaceGame\\resources\\beetleship.png", IND_ALPHA, IND_32)) return 0;

	// Creating 2d entity for the Rocket
	IND_Entity2d *mRocket = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mRocket);					       // Entity adding
	mRocket->setSurface(mSurfaceRocket);					   // Set the surface into the entity

	// Creating 2d entity for the Beetleship
	IND_Entity2d *mBeetle = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBeetle);					       // Entity adding
	mBeetle->setSurface(mSurfaceBeetle);					   // Set the surface into the entity
	// Beetle
	mBeetle->setHotSpot(0.5f, 0.5f);
	mBeetle->setMirrorX(1);
	mBeetle->setPosition(150, 400, 2);
	mBeetle->setBoundingTriangle("beetle_head", 160, 105, 160, 170, 190, 135);
	mBeetle->setBoundingCircle("beetle_boy_head", 85, 52, 55);

	// Rocket
	mRocket->setHotSpot(0.5f, 0.5f);
	mRocket->setPosition(200, 450, 3);
	mRocket->setBoundingAreas("..\\SpaceGame\\resources\\rocket_collisions.xml");
	//mRocket->deleteBoundingAreas("engines");

	*/
	// ------------- end FOR TEST ----------------

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	
	Planet *sunPlanet = new Planet(mI, "../SpaceGame/resources/animations/smallSun.xml");
	Ship *ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	HUD *hud = new HUD(mI);
	Menu *menu = new Menu(mI);
	//Thing *health = new Thing(mI, "../SpaceGame/resources/animations/health.xml");

	menu->HideMenu();
	hud->showAlert("Quit F12!");


	

	//<------ DELTA TIME ------>
	double *mDelta = new double(0.1);
	double *mDeltaAverage = new double(0.001);
	double *mDeltaSum = new double(0.001);
	double count = 0;
	
	// time
	int gameTime = 125;

	// Create and start the timer;
	IND_Timer *mTimer = new IND_Timer();
	mTimer->start();

	bool play = true;
	// ----- Main Loop -----
	while (!mI->_input->onKeyPress(IND_F12)&&!mI->_input->quit())
	{
		gameTime = (int)(mTimer->getTicks() / 1000.0f); //time in seconds

		// ------ Average delta time ---------
			*mDelta = mI->_render->getFrameTime() / 1000.0f;
			count++;
			*mDeltaSum += *mDelta;

			if (count == 100){			
				count = 0;
				*mDeltaAverage = *mDeltaSum / 100;
				*mDeltaSum = 0;
			}
			// ----- Input Update ----
			mI->_input->update();

			if (mI->_input->onKeyPress(IND_ESCAPE))
			{
				menu->ShowMenu();
				play = !play;
			}

				if (play)
			{
				menu->HideMenu();
					// --------- Game control --------
					ship->Update(mDeltaAverage);
					ship->ReadKeys(mI);
	
					// -------- UI ------------
					hud->updateHud(ship->getScore(), ship->getHealth(), ship->getShots(), gameTime);
					hud->showAlert("F12 to quit!");
			}else{
				menu->Update(mI);
			}		
			/*----- for test ---------
			
			if (mI->_entity2dManager->isCollision(mBeetle, "beetle_boy_head", mRocket, "rocket_boy_head"))
			{
				hud->showAlert(" Collision detected!");
			}
			// beetle folow the ship
			//mBeetle->setPosition(ship->getX(), ship->getY(), 1);
			//mBeetle->setAngleXYZ(0, 0, ship->getAngleZ());
			*/// ----- end for tests -------- 
		// ------- Collisions -----------
		
		// -------- Render -------
		mI->_render->clearViewPort(0, 0, 60);
		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255); // for tests
		mI->_render->endScene();
		mI->_render->showFpsInWindowTitle(); //FPS
		//mI->_entity2dManager->renderGridAreas(255, 255, 0, 255);
	}

	// ----- Indielib End -----
	mI->end();

	return 0;
}


