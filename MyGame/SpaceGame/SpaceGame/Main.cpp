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
#include "GameControll.h"
#include <irrKlang.h>

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

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

	GameControll controller = GameControll(mI); // createing a game controller and initialize
	controller.sceneGenerator();
		

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

	float animationDelay = 30; // 30 fps animation refresh

	// ----- Main Loop -----
	while (!mI->_input->onKeyPress(IND_F12) && !mI->_input->quit() && !controller.isExitSelected())
	{
		gameTime = (int)(mTimer->getTicks() / 1000.0f); //time in seconds

		
		

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

			// ------ Game controller update ---------------
			controller.Update(gameTime, deltaAverage);

			// ---- Update rarely -----
			// creating delay for animation
			//animationDelay -= 1000 * (*deltaAverage);
			animationDelay -= mI->_render->getFrameTime();
			if (animationDelay < 0) 
			{
				animationDelay = 30;
				controller.AnimationsUpdate();
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


