/*****************************************************************************************
* Desc: Tutorial a) 01 Installing
*****************************************************************************************/

#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "Menu.h"

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
	if (!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Blue_Space-800x600.jpg", IND_OPAQUE, IND_32)) return 0;

	/*IND_Surface *mSurfacePlanet = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfacePlanet, "../SpaceGame/resources/planet.png", IND_OPAQUE, IND_32)) return 0;*/

	IND_Surface *mSurfaceSpaceShip = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceSpaceShip, "../SpaceGame/resources/genesis/Space-Ship-icon2.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceSun = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceSun, "../SpaceGame/resources/genesis/Sun-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceMercury = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceMercury, "../SpaceGame/resources/genesis/Mercury-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceVenus = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceVenus, "../SpaceGame/resources/genesis/Venus-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceEarth = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceEarth, "../SpaceGame/resources/genesis/Earth-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceMars = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceMars, "../SpaceGame/resources/genesis/Mars-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceJupiter = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceJupiter, "../SpaceGame/resources/genesis/Jupiter-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfaceSaturn = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceSaturn, "../SpaceGame/resources/genesis/Saturn-icon.png", IND_OPAQUE, IND_32)) return 0;
	
	IND_Surface *mSurfaceUranus = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceUranus, "../SpaceGame/resources/genesis/Uranus-icon.png", IND_OPAQUE, IND_32)) return 0;
	
	IND_Surface *mSurfaceNeptune = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfaceNeptune, "../SpaceGame/resources/genesis/Neptune-icon.png", IND_OPAQUE, IND_32)) return 0;

	IND_Surface *mSurfacePluto = IND_Surface::newSurface();
	if (!mI->_surfaceManager->add(mSurfacePluto, "../SpaceGame/resources/genesis/Pluto-icon.png", IND_OPAQUE, IND_32)) return 0;

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();		// BACKGROUND
	mI->_entity2dManager->add(mBack);						// Entity adding
	mBack->setSurface(mSurfaceBack);						// Set the surface into the entity

	IND_Entity2d *mSpaceShip = IND_Entity2d::newEntity2d();  // SHIP
	mI->_entity2dManager->add(mSpaceShip);					 // Entity adding
	mSpaceShip->setSurface(mSurfaceSpaceShip);			     // Set the surface into the entity
	mSpaceShip->setHotSpot(0.5f, 0.5f);
	mSpaceShip->setScale(1, 1);
	mSpaceShip->setPosition(150, 450, 0);


	IND_Entity2d *mSun= IND_Entity2d::newEntity2d();        // SUN 0
	mI->_entity2dManager->add(mSun);					    // Entity adding
	mSun->setSurface(mSurfaceSun);			                // Set the surface into the entity
	mSun->setPosition(300, 200, 0);
	mSun->setScale(0.4f, 0.4f);

	IND_Entity2d *mMercury = IND_Entity2d::newEntity2d();   // MERCURY 1
	mI->_entity2dManager->add(mMercury);					// Entity adding
	mMercury->setSurface(mSurfaceMercury);			        // Set the surface into the entity
	mMercury->setPosition(260, 200, 0);
	mMercury->setScale(0.1f, 0.1f);

	IND_Entity2d *mVenus = IND_Entity2d::newEntity2d();     // VENUS 2
	mI->_entity2dManager->add(mVenus);					    // Entity adding
	mVenus->setSurface(mSurfaceVenus);			            // Set the surface into the entity
	mVenus->setPosition(170, 240, 0);
	mVenus->setScale(0.2f, 0.2f);

	IND_Entity2d *mEarth = IND_Entity2d::newEntity2d();     // EARTH 3
	mI->_entity2dManager->add(mEarth);					    // Entity adding
	mEarth->setSurface(mSurfaceEarth);			            // Set the surface into the entity
	mEarth->setPosition(100, 350, 0);
	mEarth->setScale(0.2f, 0.2f);

	IND_Entity2d *mMars = IND_Entity2d::newEntity2d();      // MARS 4
	mI->_entity2dManager->add(mMars);					    // Entity adding
	mMars->setSurface(mSurfaceMars);			            // Set the surface into the entity
	mMars->setPosition(150, 450, 0);
	mMars->setScale(0.2f, 0.2f);

	IND_Entity2d *mJupiter = IND_Entity2d::newEntity2d();   // JUPITER 5
	mI->_entity2dManager->add(mJupiter);					// Entity adding
	mJupiter->setSurface(mSurfaceJupiter);			        // Set the surface into the entity
	mJupiter->setPosition(550, 50, 0);
	mJupiter->setScale(0.3f, 0.3f);

	IND_Entity2d *mSaturn = IND_Entity2d::newEntity2d();    // SATURN 6
	mI->_entity2dManager->add(mSaturn);					    // Entity adding
	mSaturn->setSurface(mSurfaceSaturn);			        // Set the surface into the entity
	mSaturn->setPosition(550, 230, 0);
	mSaturn->setScale(0.3f, 0.3f);

	IND_Entity2d *mUranus = IND_Entity2d::newEntity2d();    // URANUS 7
	mI->_entity2dManager->add(mUranus);					    // Entity adding
	mUranus->setSurface(mSurfaceUranus);			        // Set the surface into the entity
	mUranus->setPosition(570, 430, 0);
	mUranus->setScale(0.2f, 0.2f);

	IND_Entity2d *mNeptune = IND_Entity2d::newEntity2d();     // NEPTUNE 8
	mI->_entity2dManager->add(mNeptune);					  // Entity adding
	mNeptune->setSurface(mSurfaceNeptune);			          // Set the surface into the entity
	mNeptune->setPosition(670, 490, 0);
	mNeptune->setScale(0.15f, 0.15f);

	IND_Entity2d *mPluto = IND_Entity2d::newEntity2d();     // PLUTO 9
	mI->_entity2dManager->add(mPluto);					    // Entity adding
	mPluto->setSurface(mSurfacePluto);			            // Set the surface into the entity
	mPluto->setPosition(750, 550, 0);
	mPluto->setScale(0.1f, 0.1f);


	// Creating 2d entity for the background
	//IND_Entity2d *mPlanet = IND_Entity2d::newEntity2d();
	//mI->_entity2dManager->add(mPlanet);					// Entity adding
	//mPlanet->setSurface(mSurfacePlanet);			   // Set the surface into the entity
	//mPlanet->setPosition(400, 170, 0);
	//mPlanet->setHotSpot(0.5f, 0.5f);
	//mPlanet->setTint(240, 160, 230);
	//mPlanet->setTransparency(200);
	//mPlanet->setAngleXYZ(0,0,180);
	//mPlanet->setFade(230,0,230,128);
	//mPlanet->setRegion(0,0,200,200);


	//Menu *menu = new Menu(mI);


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


