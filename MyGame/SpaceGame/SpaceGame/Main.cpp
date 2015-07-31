/*****************************************************************************************
* Desc: Space Game
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
#include "Controller.h"


/*
==================
Main
==================
*/

int IndieLib() // main
{
	char TempText[30];
	
	// ----- Sound Library --------------


	// ----- new engine instance ------------
	CIndieLib *mI = CIndieLib::instance(); // engine
	if (!mI->init()) return 0;

	Controller controller = Controller(mI);
	controller.gameInit();
	controller.gameGenerator();
		

	//<------ DELTA TIME ------>
	double *delta = new double(0.1);
	double *deltaAverage = new double(0.001);
	double *mDeltaSum = new double(0.001);
	int count = 0;
	
	// time
	int gameTime = 125;

	// Create and start the timer;
	IND_Timer *mTimer = new IND_Timer();
	mTimer->start();

	bool play = false;
	// ----- Main Loop -----
	while (!mI->_input->onKeyPress(IND_F12) && !mI->_input->quit() && !controller.menu->isExitSelected())
	{
		gameTime = (int)(mTimer->getTicks() / 1000.0f); //time in seconds

		//stop game
		if (controller.ship->getHealth() < 1){
			controller.hud->updateHud(controller.ship->getScore(), controller.ship->getHealth(), controller.ship->getShots(), gameTime);
			controller.hud->showAlert(" Game over! F12 to quit"); // for tests only	
			play = false;

		}


		// ------ Average delta time ---------
		*delta = mI->_render->getFrameTime() / 1000.0f;
			count++;
			*mDeltaSum += *delta;

			if (count == 100){			
				count = 0;
				*deltaAverage = *mDeltaSum / 100;
				*mDeltaSum = 0;
			}
			// ----- Input Update ----
			mI->_input->update();
			if (mI->_input->onKeyPress(IND_ESCAPE))
			{
				controller.menu->ShowMenu();
				play = !play;
			}

			// ---- Update rarely -----
			// creating delay for animation
			if (count == 0)
			{
				//Update explosions 
				for (int i = 0; i < controller.explosions.size(); i++)
					{
						if (!controller.explosions[i]->Update(mI, *deltaAverage)) controller.explosions.erase((controller.explosions.begin() + i)); // remove explosion from vector
					}
				
			}
			

			// ---- Menu control --------
			if (play)
			{
				controller.menu->HideMenu();
					// --------- Game control --------
				controller.ship->Update(mI, deltaAverage);
				controller.ship->ReadKeys(mI);
	
					// -------- UI ------------
				controller.hud->updateHud(controller.ship->getScore(), controller.ship->getHealth(), controller.ship->getShots(), gameTime);
				controller.hud->showAlert("F12 to quit!");
					
			}else{
				switch (controller.menu->Update(mI))
				{
					  case 0:
							break;
					case 1:
						play = true;
							break; 
					case 3:
						// button restart pressed
						break;
					default:
						break;
				}
					
			}		
			
		// ------- Collisions -----------
			
			if (gameTime > 2)
			{
				// just to prevent initial collisions
				
				for (int i = 0; i < controller.allObjects.size(); i++)
				{
					// check collisions with ship for all objects
					if (mI->_entity2dManager->isCollision(controller.ship->getColisionBorder(), "body", controller.allObjects[i]->getColisionBorder(), "thing"))
					{
						controller.hud->showAlert(" Collision detected!"); // for tests only
						if (controller.allObjects[i]->getType() == HEALTH)
						{
							if (controller.ship->getHealth() < 100)
							{
								controller.ship->changeHealth(controller.allObjects.at(i)->getHealth()); // corect ship health
							}
							
						}
						if (controller.allObjects[i]->getType() == DIAMOND)
						{
							controller.ship->changeScore(DIAMOND_SCORE); // corect ship health
						}
						if ((controller.allObjects[i]->getType() == ROCK) || (controller.allObjects[i]->getType() == ASTEROID))
						{
							controller.ship->changeHealth(controller.allObjects.at(i)->getHealth()); // corect ship health
						}

						controller.allObjects.at(i)->destroy(mI); // destroy object
						controller.allObjects.erase((controller.allObjects.begin() + i)); // remove pointer from vector
					}

					
					// test for bullet collisions
					/**/
					for (int k = 0; k < 10; k++) //k - bullet number
					{
						if (mI->_entity2dManager->isCollision(controller.ship->getBulletBorder(k), "bullet", controller.allObjects[i]->getColisionBorder(), "thing"))
						{
							if ((controller.allObjects[i]->getType() == ROCK) || (controller.allObjects[i]->getType() == ASTEROID))
							{
								// collision with rock detected
															
								controller.explosions.push_back(new Explosion(mI, controller.allObjects[i]->getPositionX(), controller.allObjects[i]->getPositionY()));// create new explosion in vector
								controller.ship->changeScore(5); // increase game score
								controller.allObjects.at(i)->destroy(mI); // destroy object
								controller.allObjects.erase((controller.allObjects.begin() + i)); // remove pointer from vector								
								
							}
							
						}
					}
					// regenerate items
					if (controller.allObjects.size() == 0) controller.refresh();
					
					
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


