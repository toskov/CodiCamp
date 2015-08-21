#include "GameControll.h"

GameControll::GameControll(CIndieLib* mI)
{
	this->mI = mI;
	gameInit();
	world = new World(mI);
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
	menu->ShowGameOverMenu();
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
	soundEngine->play2D("../SpaceGame/resources/getout.ogg", true);
	soundEngine->setSoundVolume(soundVolume);

	// Creating surface for the background
	IND_Surface *mSurfaceBack = IND_Surface::newSurface();
	mI->_surfaceManager->add(mSurfaceBack, "../SpaceGame/resources/genesis/Background_Colorful_Galaxy-800x600.jpg", IND_OPAQUE, IND_32);

	// Creating 2d entity for the background
	IND_Entity2d *mBack = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mBack);					// Entity adding
	mBack->setSurface(mSurfaceBack);					// Set the surface into the entity

	// Planet surface for gravity game
	IND_Surface *planetSurface = IND_Surface::newSurface();
	mI->_surfaceManager->add(planetSurface, "../SpaceGame/resources/planet_surface.png", IND_OPAQUE, IND_32);
	IND_Entity2d *mGround = IND_Entity2d::newEntity2d();
	mI->_entity2dManager->add(mGround);					// Entity adding
	mGround->setSurface(planetSurface);				// Set the surface into the entity
	mGround->setPosition(0, 150, 0);
	mGround->setBoundingRectangle("ground", 0, 400, 800, 0);
	//mGround->setTransparency(50);

	// -------- Load Options ----------------
	gameOptions->loadGameOptions();
	//this->soundVolume =  *gameOptions->soundValue; TODO

	menu = new Menu(mI);
	ship = new Ship(mI, "../SpaceGame/resources/animations/rocket.xml");
	ship->setSoundVolume(0.3f);

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

	int randomX ;
	int randomY ;
	for (int i = 0; i < 5; i++)
	{
		randomX =15 + rand() % (WINDOW_WIDTH - 50);
		randomY =15 + rand() % (WINDOW_HEIGHT - 150);
		world->gameObjects.push_back(new Thing(mI, thingsPicture, ROCK, randomX, randomY, -10, 0, frames,delta));
	}

	for (int i = 0; i < 6; i++)
	{
		randomX = 15 + rand() % (WINDOW_WIDTH - 50);
		randomY = 15 + rand() % (WINDOW_HEIGHT - 150);
		//Thing *ufo = new Thing(mI, thingsPicture, UFO, randomX, randomY, 10,0,frames);
		world->gameObjects.push_back(new Thing(mI, thingsPicture, UFO, randomX, randomY, -10, 0, frames, delta));
	}

	randomX = 15 + rand() % (WINDOW_WIDTH - 50);
	randomY = 15 + rand() % (WINDOW_HEIGHT - 150);
	world->gameObjects.push_back(new Thing(mI, thingsPicture, HEALTH, randomX, randomY, 10, 0, frames, delta));

	randomX = 15 + rand() % (WINDOW_WIDTH - 50);
	randomY = 15 + rand() % (WINDOW_HEIGHT - 150);
	world->gameObjects.push_back(new Thing(mI, thingsPicture, DIAMOND, randomX, randomY, 10, 0, frames, delta));
	
//	hud->showAlert("Quit F12!");
	
}

// --------------------Game Update ---------------------------
void GameControll::Update(int gameTime,double *delta)
{
	char mText[10];

	this->delta = delta;
	//ship->gravityUpdate(GRAVITY);
	if (menu->isHidden())
	{
		//enemmy->Update(gameObjects, ship, delta); // Enemy movement only if menu is hidden
	}
	
	//stop game

	if (ship->getHealth() < 1){
		hud->updateHud(ship->getScore(), ship->getHealth(), ship->getShots(), gameTime);
		hud->showAlert(" Game over! F12 to quit"); // for tests only	
		play = false;
		GameOver();
	}

	// show menu
	if (mI->_input->onKeyPress(IND_ESCAPE))
	{
		menu->ShowPauseMenu();
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
		// display volume
		
		sprintf(mText, "sound: %f ", soundVolume);
		hud->showAlert(mText);

		switch (menu->Update())
		{
		case 0: // hide menu
			break;
		case PLAY:
			play = true;
			break;
		case OPTIONS:
		//	menu->ShowOptions();
			break;
		case NEWGAME:
			// button restart pressed
			killObjects();
			sceneGenerator();
			ship->maxHealth();
			ship->clearScore();
			ship->clearShots();
			ship->setSpeedX(0);
			ship->setSpeedY(0);
			play = true;
			break;

		case QUIT: // quit selected
			gameExit = true;
			break;

		case SAVEOPTIONS:
			gameOptions->saveOptions(); 
			menu->ShowPauseMenu();			
			break;

		case DECREASE:
			soundVolume -= 0.1;
			if (soundVolume < 0) soundVolume = 0;
			ship->setSoundVolume(soundVolume);			
			soundEngine->setSoundVolume(soundVolume);
			break;

		case INCREASE:
			soundVolume += 0.1;// on single click			
			if (soundVolume > 1) soundVolume = 1;
			ship->setSoundVolume(soundVolume);
			soundEngine->setSoundVolume(soundVolume);
			break;

		default:
			break;
		}

	} // end Menu controll


	// ------- Collisions -----------
	
	if (gameTime > 2)       // just to prevent initial collisions
	{
		
		for (int i = 0; i < (int)(world->bullets.size()); i++)
		{
			world->bullets[i]->Update(delta);

		// bullet collector
			if (world->bullets[i]->outOfRange(WINDOW_WIDTH, WINDOW_HEIGHT))
			{
				world->bullets.at(i)->destroy(); // destroy object //TODO must free memory
				world->bullets.erase((world->bullets.begin() + i)); // remove pointer from vector	
			}


			// Check for collisions
			if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", world->bullets[i]->getColisionBorder(), "bullet"))
			{
				// UFO is shooting on you
				if(ship->getHealth() > 0) ship->changeHealth(-5); // corect ship health
				if (ship->getHealth() < 0) ship->setHealth(0);
				explosions.push_back(new Explosion(mI, ship->getX(), ship->getY()));// create new explosion in vector
				soundEngine->play2D("../SpaceGame/resources/explosion_player.wav");

				// destroy bullet
				world->bullets.at(i)->destroy(); // destroy object //TODO must free memory
				world->bullets.erase((world->bullets.begin() + i)); // remove pointer from vector
			}
		}
		
		
		for (int i = 0; i < (int)(world->gameObjects.size()); i++)
		{
			// Ai update world info for UFOs
			if ((world->gameObjects[i]->getType() == UFO) && play)
			{
				world->gameObjects[i]->Update(delta);
			}

			// check collisions with ship for all objects
			if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", world->gameObjects[i]->getColisionBorder(), "thing"))
			{
				hud->showAlert(" Collision detected!"); // for tests only
				if (world->gameObjects[i]->getType() == HEALTH)
				{
					if (ship->getHealth() < 100)
					{
						ship->changeHealth(world->gameObjects.at(i)->getHealth()); // corect ship health
					}

				}
				if (world->gameObjects[i]->getType() == DIAMOND)
				{
					ship->changeScore(DIAMOND_SCORE); // corect ship health
					
				}
				if ((world->gameObjects[i]->getType() == ROCK) || (world->gameObjects[i]->getType() == ASTEROID) || (world->gameObjects[i]->getType() == UFO))
				{
					ship->changeHealth(world->gameObjects.at(i)->getHealth()); // corect ship health
					explosions.push_back(new Explosion(mI, world->gameObjects[i]->getCollisionPositionX(), world->gameObjects[i]->getCollisionPositionY()));// create new explosion in vector
					soundEngine->play2D("../SpaceGame/resources/explosion_player.wav");
				}
				world->gameObjects.at(i)->destroy(); // destroy object
				world->gameObjects.erase((world->gameObjects.begin() + i)); // remove pointer from vector
			}

			if (mI->_entity2dManager->isCollision(ship->getColisionBorder(), "body", world->gameObjects[i]->getColisionBorder(), "radar"))
			{				
				if (world->gameObjects[i]->readyToShoot(*delta)) world->bullets.push_back(world->gameObjects[i]->shoot()); // UFO shooting
			} 
			else
			{
				world->gameObjects[i]->setShootInnterval(0);
			}

			// test for bullet collisions
			/**/
			for (int k = 0; k < 10; k++) //k - bullet number
			{
				if (mI->_entity2dManager->isCollision(ship->getBulletBorder(k), "bullet", world->gameObjects[i]->getColisionBorder(), "thing"))
				{
					if ((world->gameObjects[i]->getType() == ROCK) || (world->gameObjects[i]->getType() == ASTEROID) || (world->gameObjects[i]->getType() == UFO))
					{
						// collision with rock detected

						explosions.push_back(new Explosion(mI, world->gameObjects[i]->getCollisionPositionX(), world->gameObjects[i]->getCollisionPositionY()));// create new explosion in vector
						ship->changeScore(5); // increase game score
						world->gameObjects.at(i)->destroy(); // destroy object
						world->gameObjects.erase((world->gameObjects.begin() + i)); // remove pointer from vector		
						soundEngine->play2D("../SpaceGame/resources/explosion_asteroid.wav");

					}

				}
			}
			// regenerate items
			if (world->gameObjects.size() == 0) sceneGenerator();
		}
	}
}



// ------------------Updates for animation ------------------------
void GameControll::AnimationsUpdate( )
{
	//Update explosions 
	for (int i = 0; i < (int)explosions.size(); i++)
	{
		if (!explosions[i]->Update(mI, *delta)) explosions.erase((explosions.begin() + i)); // remove explosion from vector
	}
	for (int i = 0; i < (int)world->gameObjects.size(); i++)
	{
		world->gameObjects[i]->animationUpdate(); //update objects animation
	}
}

void GameControll::killObjects()
{
	for (int i = 0; i < (int)world->gameObjects.size(); i++)
	{
		world->gameObjects[i]->destroy(); //delete objects
	}

	world->gameObjects.clear();	// remove all pointers from vector
}
void GameControll::saveGameState(void)
{
	//TODO
}

void GameControll::loadGameState(void)
{
	//TODO
}
GameControll::~GameControll()
{

	delete menu;
	delete ship;
	delete hud;
//	delete enemmy;
	delete delta;


	explosions.clear();
	rocks.clear();
	frames.clear();

	

}