#include "GameControll.h"

GameControll::GameControll(CIndieLib* mI)
{
	this->mI = mI;
	gameInit();
}

void GameControll::gameLogic()
{

}

bool GameControll::isExitSelected()
{
	return gameExit;
}

void GameControll::GameOver()
{
	
}

void GameControll::gameInit()
{
	
	ErrorHandler::trace(" ******  New trace ***********");
	readThingsFile();
	// Sound init
	soundEngine = createIrrKlangDevice();
	if (!soundEngine)
	{
		printf("Could not startup engine\n");
		// error starting up the engine
	}
	//soundEngine->play2D("../SpaceGame/resources/explosion_player.wav"); // on collision
	soundEngine->play2D("../SpaceGame/resources/music_background.wav", true);
	soundEngine->setSoundVolume(soundVolume);

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
	mGround->setBoundingRectangle("ground", 0, 400, 800, 0);
	//mGround->setTransparency(50);

	// -------- Load Options ----------------
	Options *gameOptions = new Options(); // read options from file
	gameOptions->saveOptions(); // for tests
	gameOptions->loadGameObjects();
	menu = new Menu(mI);
	ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	ship->setSoundVolume(0.3);

	hud = new HUD(mI); // game info

	// ---- creating objects ---------------
	//Planet *sunPlanet = new Planet(mI, "../SpaceGame/resources/animations/smallSun.xml"); // ...

	mI->_surfaceManager->add(thingsPicture, "../SpaceGame/resources/things.png", IND_ALPHA, IND_32); // open things sprites once

}

//Reading spritesheet text file
void GameControll::readThingsFile()
{

	// example of one line: asteroid (10) = 120 0 120 120
	string line;
	ifstream myfile("../SpaceGame/resources/things.txt");
	if (myfile.is_open())
	{
		string name;
		int framenum ;
		int offsetX;
		int offsetY;
		int width;
		int hight;
		string buf; // Have a buffer string
		int count = 0;

		while (getline(myfile, line))
		{		
			// parse sprite file
			count++;
			stringstream ss(line); // Insert the string into a stream					
			vector<string> tokens; // Create vector to hold our words
			while (ss >> buf) tokens.push_back(buf);

			 name = tokens.at(0);
			 // remove brackets
			 string sub = tokens.at(1).substr(1);
			 framenum = stoi(sub);
			 offsetX = stoi(tokens[3]);
			 offsetY = stoi(tokens[4]);
			 width = stoi(tokens[5]);
			 hight = stoi(tokens[6]);
			// create simple frame

			Frame *newframe = new Frame(name, framenum, offsetX, offsetY, width, hight);
			frames.push_back(newframe);					
		}
		myfile.close();
		// vector frames contains
	}
}

void GameControll::sceneGenerator()
{	
	srand(time(NULL)); // random generfated possition

	int randomX = rand() % (WINDOW_WIDTH-50);
	int randomY  = rand() % (WINDOW_HEIGHT -100);
	for (int i = 0; i < 5; i++)
	{
		randomX =15 + rand() % (WINDOW_WIDTH - 50);
		randomY =15 + rand() % (WINDOW_HEIGHT - 100);
		gameObjects.push_back(new Thing(mI, thingsPicture, ROCK, randomX, randomY, -10, 0, frames));
	}

	for (int i = 0; i < 3; i++)
	{
		randomX = 15 + rand() % (WINDOW_WIDTH - 50);
		randomY = 15 + rand() % (WINDOW_HEIGHT - 100);
		//Thing *ufo = new Thing(mI, thingsPicture, UFO, randomX, randomY, 10,0,frames);
	gameObjects.push_back(new Thing(mI, thingsPicture, UFO, randomX, randomY, -10, 0, frames));
	}

	randomX = 15 + rand() % (WINDOW_WIDTH - 50);
	randomY = 15 + rand() % (WINDOW_HEIGHT - 100);
	gameObjects.push_back(new Thing(mI, thingsPicture, HEALTH, randomX, randomY, 10, 0, frames));

	randomX = 15 + rand() % (WINDOW_WIDTH - 50);
	randomY = 15 + rand() % (WINDOW_HEIGHT - 100);
	gameObjects.push_back(new Thing(mI, thingsPicture, DIAMOND, randomX, randomY, 10, 0, frames));
	
	hud->showAlert("Quit F12!");
}

// --------------------Game Update ---------------------------
void GameControll::Update(int gameTime,double *delta)
{
	this->delta = delta;

	enemmy->Update(gameObjects, ship, delta); // Enemy movement
	//stop game

	if (ship->getHealth() < 1){
		hud->updateHud(ship->getScore(), ship->getHealth(), ship->getShots(), gameTime);
		hud->showAlert(" Game over! F12 to quit"); // for tests only	
		play = false;

	}

	// show menu
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
		ship->Update(mI, delta);
		ship->ReadKeys(mI);

		// -------- UI ------------
		hud->updateHud(ship->getScore(), ship->getHealth(), ship->getShots(), gameTime);
		hud->showAlert("F12 to quit!");

	}
	else{
		switch (menu->Update(mI))
		{
		case 0: // hide menu
			break;
		case 1:
			play = true;
			break;
		case 3:
			// button restart pressed
			break;

		case 4: // quit selected
			gameExit = true;
			break;
		default:
			break;
		}

	} // end Menu controll


	// ------- Collisions -----------

	if (gameTime > 2)
	{
		// just to prevent initial collisions

		for (int i = 0; i < gameObjects.size(); i++)
		{
			// check collisions with ship for all objects
			if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", gameObjects[i]->getColisionBorder(), "thing"))
			{
				hud->showAlert(" Collision detected!"); // for tests only
				if (gameObjects[i]->getType() == HEALTH)
				{
					if (ship->getHealth() < 100)
					{
						ship->changeHealth(gameObjects.at(i)->getHealth()); // corect ship health
					}

				}
				if (gameObjects[i]->getType() == DIAMOND)
				{
					ship->changeScore(DIAMOND_SCORE); // corect ship health
					
				}
				if ((gameObjects[i]->getType() == ROCK) || (gameObjects[i]->getType() == ASTEROID) || (gameObjects[i]->getType() == UFO))
				{
					ship->changeHealth(gameObjects.at(i)->getHealth()); // corect ship health
					explosions.push_back(new Explosion(mI, gameObjects[i]->getCollisionPositionX(), gameObjects[i]->getCollisionPositionY()));// create new explosion in vector
					soundEngine->play2D("../SpaceGame/resources/explosion_player.wav");
				}

				gameObjects.at(i)->destroy(mI); // destroy object
				gameObjects.erase((gameObjects.begin() + i)); // remove pointer from vector
			}


			// test for bullet collisions
			/**/
			for (int k = 0; k < 10; k++) //k - bullet number
			{
				if (mI->_entity2dManager->isCollision(ship->getBulletBorder(k), "bullet", gameObjects[i]->getColisionBorder(), "thing"))
				{
					if ((gameObjects[i]->getType() == ROCK) || (gameObjects[i]->getType() == ASTEROID) || (gameObjects[i]->getType() == UFO))
					{
						// collision with rock detected

						explosions.push_back(new Explosion(mI, gameObjects[i]->getCollisionPositionX(), gameObjects[i]->getCollisionPositionY()));// create new explosion in vector
						ship->changeScore(5); // increase game score
						gameObjects.at(i)->destroy(mI); // destroy object
						gameObjects.erase((gameObjects.begin() + i)); // remove pointer from vector		
						soundEngine->play2D("../SpaceGame/resources/explosion_asteroid.wav");

					}

				}
			}
			// regenerate items
			if (gameObjects.size() == 0) sceneGenerator();
		}
	}
}



// ------------------Updates for animation ------------------------
void GameControll::AnimationsUpdate( )
{
	//Update explosions 
	for (int i = 0; i < explosions.size(); i++)
	{
		if (!explosions[i]->Update(mI, *delta)) explosions.erase((explosions.begin() + i)); // remove explosion from vector
	}
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->animationUpdate(); //update objects animation
	}
}
GameControll::~GameControll()
{
	delete menu;
	delete ship;
	delete hud;
	delete enemmy;
	delete delta;
	
	

}