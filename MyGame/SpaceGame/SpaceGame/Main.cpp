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
#include <time.h>       /* time */
#include "GlobalHeader.h"
#include "Sprite.h"


/*
==================
Main
==================
*/

int IndieLib() // main
{

	// Vector Objects container
	vector<Thing*> allObjects;
	
	// ----- Sound Library --------------


	// ----- new engine instance ------------
	CIndieLib *mI = CIndieLib::instance(); // engine
	if (!mI->init()) return 0;
		
	// Creating surface for the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Colorful_Galaxy-800x600.jpg", IND_OPAQUE, IND_32)) return 0;


	// -------- Load Options ----------------
	Options *gameOptions = new Options(); // read options from file
	gameOptions->saveOptions(); // for tests
	gameOptions->loadGameObjects();


	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	
	Planet *sunPlanet = new Planet(mI, "../SpaceGame/resources/animations/smallSun.xml");
	Ship *ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	HUD *hud = new HUD(mI);
	Menu *menu = new Menu(mI);
	
	
	srand(time(NULL)); // random generfated possition

	int randomX = rand() % windowMaxX;
	int randomY = rand() % windowMaxY;
	Thing *asteroid = new Thing(mI, ASTEROID, randomX, randomY, -20);	
	allObjects.push_back(asteroid);

// old way	
//	randomX = rand() % windowMaxX;
// randomY = rand() % windowMaxY;
//	Thing *health = new Thing(mI, HEALTH, randomX, randomY, 10); 	

//	 randomX = rand() % windowMaxX;
//	 randomY = rand() % windowMaxY;
//	 Thing *rock = new Thing(mI, ROCK, randomX, randomY, -20);
//	allObjects.push_back(health);
//	allObjects.push_back(rock);

	for (int i = 0; i < 5; i++)
	{
		// create 5 more rocks objects
	randomX = rand() % windowMaxX;
	randomY = rand() % windowMaxY;
	int angle = rand() % 360;
	allObjects.push_back(new Thing(mI, ROCK, randomX, randomY, -20, angle)); // create object anonymously
	}
	
	for (int i = 0; i < 5; i++)
	{
		// create 5 more health objects
		randomX = rand() % windowMaxX;
		randomY = rand() % windowMaxY;
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, HEALTH, randomX, randomY, 10)); // create object anonymously
	}

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

	bool play = false;
	// ----- Main Loop -----
	while (!mI->_input->onKeyPress(IND_F12) && !mI->_input->quit() && !menu->isExitSelected())
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
			// ---- Menu control --------
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
				if (menu->Update(mI)) play = true;
			}		
			
		// ------- Collisions -----------
			/*
			* old version of collision detect
							if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", asteroid->getColisionBorder(), "thing"))
			{
				hud->showAlert(" Collision detected!");
				if (gameTime > 2)
				{
					// initial all collisions are set true
					ship->increaseHealth(asteroid->getHealth());
					asteroid->destroy(mI);
				}
				
			}
				// asteroid collision

				if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", health->getColisionBorder(), "thing"))
				{
					hud->showAlert(" Collision detected!");
					if (gameTime > 2)
					{
						// initial all collisions are set true
						ship->increaseHealth(health->getHealth());
						health->destroy(mI);
					}

				}
			*/

			// check collisions with ship for all objects
			if (gameTime > 2)
			{
				// just to prevent initial collisions
				for (int i = 0; i < allObjects.size(); i++)
				{
					if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", allObjects[i]->getColisionBorder(), "thing"))
					{
						hud->showAlert(" Collision detected!"); // for tests only
						ship->increaseHealth(allObjects.at(i)->getHealth()); // corect ship health

						allObjects.at(i)->destroy(mI); // destroy object
						allObjects.erase((allObjects.begin() + i)); // remove pointer from vector
					}
				}
			}

		// -------- Render -------
		mI->_render->clearViewPort(0, 0, 60);
		mI->_render->beginScene();
		mI->_entity2dManager->renderEntities2d();
		//mI->_entity2dManager->renderCollisionAreas(255, 0, 0, 255); // for tests
		mI->_render->endScene();
		mI->_render->showFpsInWindowTitle(); //FPS
		//mI->_entity2dManager->renderGridAreas(255, 255, 0, 255);
	}

	// ----- Indielib End -----
	mI->end();

	return 0;
}


