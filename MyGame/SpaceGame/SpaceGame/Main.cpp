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
#include "Explosion.h"


/*
==================
Main
==================
*/

int IndieLib() // main
{

	// Vector Objects container
	vector<Thing*> allObjects;
	vector<Explosion*> explosions;
	
	// ----- Sound Library --------------


	// ----- new engine instance ------------
	CIndieLib *mI = CIndieLib::instance(); // engine
	if (!mI->init()) return 0;
		
	// Creating surface for the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Colorful_Galaxy-800x600.jpg", IND_OPAQUE, IND_32)) return 0;


	// Planet surface for gravity game
	IND_Surface *mPlanetSurface = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mPlanetSurface, "../SpaceGame/resources/planet_surface.png", IND_OPAQUE, IND_32)) return 0;
	IND_Entity2d *mGround = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mGround);					// Entity adding
	mGround->setSurface(mPlanetSurface);				// Set the surface into the entity
	mGround->setPosition(0, 150, 2);


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

	int randomX = rand() % WINDOW_WIDTH;
	int randomY = rand() % WINDOW_HEIGH;
	Thing *asteroid = new Thing(mI, ASTEROID, randomX, randomY, -20);	

	randomX = rand() % WINDOW_WIDTH;
	randomY = rand() % WINDOW_HEIGH;
	Thing *diamond = new Thing(mI, DIAMOND, randomX, randomY, 0);
	allObjects.push_back(diamond);
	allObjects.push_back(asteroid);

	for (int i = 0; i < 5; i++)
	{
		// create 5 more rocks objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % WINDOW_HEIGH;
	int angle = rand() % 360;
	allObjects.push_back(new Thing(mI, ROCK, randomX, randomY, -20, angle)); // create object anonymously
	}
	
	for (int i = 0; i < 2; i++)
	{
		// create 5 more health objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % WINDOW_HEIGH;
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, HEALTH, randomX, randomY, 10)); // create object anonymously
	}

	menu->HideMenu();
	hud->showAlert("Quit F12!");

	// TEST
	//Explosion *explode = new Explosion(mI, 200, 300);
	//explosions.push_back(explode);

	

	//<------ DELTA TIME ------>
	double *mDelta = new double(0.1);
	double *mDeltaAverage = new double(0.001);
	double *mDeltaSum = new double(0.001);
	int count = 0;
	
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

			// ---- Update explosions -----
			// creating delay for animation
			if (count == 0)
			{
				for (int i = 0; i < explosions.size(); i++)
					{
						if (!explosions[i]->Update(mI, *mDeltaAverage)) explosions.erase((explosions.begin() + i)); // remove explosion from vector
					}
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
			
			if (gameTime > 2)
			{
				// just to prevent initial collisions
				
				for (int i = 0; i < allObjects.size(); i++) 
				{
					// check collisions with ship for all objects
					if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", allObjects[i]->getColisionBorder(), "thing"))
					{
						hud->showAlert(" Collision detected!"); // for tests only
						if (allObjects[i]->getType() == HEALTH)
						{
							ship->changeHealth(allObjects.at(i)->getHealth()); // corect ship health
						}
						if (allObjects[i]->getType() == DIAMOND)
						{
							ship->changeScore(DIAMOND_SCORE); // corect ship health
						}
						if ((allObjects[i]->getType() == ROCK) || (allObjects[i]->getType() == ASTEROID))
						{
							ship->changeHealth(allObjects.at(i)->getHealth()); // corect ship health
						}

						allObjects.at(i)->destroy(mI); // destroy object
						allObjects.erase((allObjects.begin() + i)); // remove pointer from vector
					}
					// test for bullet collisions
					/**/
					for (int k = 0; k < 10; k++) //k - bullet number
					{
						if (mI->_entity2dManager->isCollision(ship->getBulletBorder(k), "bullet", allObjects[i]->getColisionBorder(), "thing"))
						{
							if ((allObjects[i]->getType() == ROCK) || (allObjects[i]->getType() == ASTEROID))
							{
								// collision with rock detected
								hud->showAlert(" Collision detected!"); // for tests only								
								explosions.push_back(new Explosion(mI, allObjects[i]->getPositionX(), allObjects[i]->getPositionY()));// create new explosion in vector
								ship->changeScore(5); // increase game score
								allObjects.at(i)->destroy(mI); // destroy object
								allObjects.erase((allObjects.begin() + i)); // remove pointer from vector
								
							}
							
						}
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


