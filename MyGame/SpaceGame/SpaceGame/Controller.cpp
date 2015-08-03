#include "Controller.h"


Controller::Controller(CIndieLib* engine)
{
	mI = engine;
}

Controller::~Controller()
{

}

bool Controller::updateParticles(int index)
{

}


int Controller::getParticlesCount()
{
	return particlesCount;
}

void Controller::createParticle()
{

}

void Controller::GameOver()
{
	
}

void Controller::gameInit()
{
	// -------- Load Options ----------------
	Options *gameOptions = new Options(); // read options from file
	gameOptions->saveOptions(); // for tests
	gameOptions->loadGameObjects();
	menu = new Menu(mI);
	ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	hud = new HUD(mI); // game info
}

void Controller::refresh()
{
	srand(time(NULL)); // random generfated possition

	int randomX = rand() % WINDOW_WIDTH;
	int randomY = rand() % WINDOW_HEIGH;
	/*
		for (int i = 0; i < 5; i++)
	{
		// create 5 more rocks objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % (WINDOW_HEIGH - 100);
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, ROCK, randomX, randomY, -20, angle)); // create object anonymously
	}

	for (int i = 0; i < 1; i++)
	{
		// create 2 more health objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % (WINDOW_HEIGH - 100);
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, HEALTH, randomX, randomY, 10)); // create object anonymously
	}
	*/
	for (int i = 0; i < 5; i++)
	{
		// create 5 more rocks objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % (WINDOW_HEIGH - 100);
		int angle = rand() % 360;
		rocks.push_back(new Rock(mI, randomX, randomY)); // create object anonymously
	}




}
void Controller::gameGenerator()
{

	// Creating surface for the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	!mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Colorful_Galaxy-800x600.jpg", IND_OPAQUE, IND_32);

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	// Planet surface for gravity game
	IND_Surface *planetSurface = IND_Surface::newSurface();
	!mI->_surfaceManager->add(planetSurface, "../SpaceGame/resources/planet_surface.png", IND_OPAQUE, IND_32);
	IND_Entity2d *mGround = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mGround);					// Entity adding
	mGround->setSurface(planetSurface);				// Set the surface into the entity
	mGround->setPosition(0, 150, 3);
	mGround->setBoundingRectangle("ground", 0, 400, 800, 200);
	//mGround->setTransparency(50);
	



	// ---- creating objects ---------------
	Planet *sunPlanet = new Planet(mI, "../SpaceGame/resources/animations/smallSun.xml");
	


	srand(time(NULL)); // random generfated possition

	int randomX = rand() % WINDOW_WIDTH;
	int randomY = rand() % WINDOW_HEIGH;
	Thing *asteroid = new Thing(mI, ASTEROID, randomX, randomY, -20);

	randomX = rand() % WINDOW_WIDTH;
	randomY = rand() % (WINDOW_HEIGH -100);
	Thing *diamond = new Thing(mI, DIAMOND, randomX, randomY, 0);
	allObjects.push_back(diamond);
	allObjects.push_back(asteroid);

	for (int i = 0; i < 5; i++)
	{
		// create 5 more rocks objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % (WINDOW_HEIGH - 100);
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, ROCK, randomX, randomY, -20, angle)); // create object anonymously
	}

	for (int i = 0; i < 1; i++)
	{
		// create 2 more health objects
		randomX = rand() % WINDOW_WIDTH;
		randomY = rand() % (WINDOW_HEIGH - 100);
		int angle = rand() % 360;
		allObjects.push_back(new Thing(mI, HEALTH, randomX, randomY, 10)); // create object anonymously
	}



	hud->showAlert("Quit F12!");
}