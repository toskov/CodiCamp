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

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	
	Planet *sunPlanet = new Planet(mI, "../SpaceGame/resources/animations/smallSun.xml");
	Ship *ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	HUD *hud = new HUD(mI);
	hud->showAlert(" Message system is working!");
	

	//<------ DELTA TIME ------>
	double* mDelta = new double(0.1);
	double *mDeltaAverage = new double(0.001);
	double *mDeltaSum = new double(0.001);
	double count = 0;
	

	// Menu *menu = new Menu(mI); moved into HUD

	// ----- Main Loop -----
	while (!mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit())
	{
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
		
		// --------- Game control --------
				ship->Update(mDeltaAverage);
				ship->ReadKeys(mI);
	
		// -------- UI ------------


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


