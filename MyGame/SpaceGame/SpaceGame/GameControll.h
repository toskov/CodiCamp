#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <time.h>      /* time */
#include "CIndieLib.h"
#include "IND_Surface.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "Bullet.h"
#include "Sprite.h"
#include "GlobalHeader.h"
#include "Explosion.h"
#include "Menu.h"
#include "Ship.h"
#include "Planet.h"
#include "HUD.h"
#include "Thing.h"
#include "Options.h"
#include "Rock.h"
#include "Frame.h"
#include "irrKlang.h"
#include "Ai.h"
#include "Bullet.h"
#include "World.h"
#include <vector>
#include <string>
#include <sstream>


using namespace irrklang; // Sound engine

//#pragma comment(lib, "irrKlang-64bit-1.5.0/lib/Winx64-visualStudio/irrKlang.lib")  // link with irrKlang.dll



class GameControll
{

private:
	CIndieLib* mI;
	IND_Surface *thingsPicture = IND_Surface::newSurface(); // things sprites
	ISoundEngine* soundEngine;
	Menu *menu;
	Ship *ship;
	HUD *hud;
	World *world;
	Options *gameOptions = new Options();

	bool gameExit = false;
	bool play = true;
	double *delta;

	double soundVolume = 0.3f;
	float fxVolume = 0.5f;
	
	// Vector Objects container
	vector<Explosion*> explosions;
	vector<Rock*> rocks;
	vector<Frame*> frames;	
	void gameInit(); // initialize game
	

	
public:
	GameControll(CIndieLib* mI);

	void Update(int gtime, double *delta); // Update for inpt controls and collisions
	void AnimationsUpdate(); // Update rarely for animation
	void sceneGenerator(); // generate random objects
	void killObjects(); // remove all objects from screen
	void gameLogic();
	void GameOver(); // Final screen
	void readThingsFile(); // reading info for pictures in spritesheet
	bool isExitSelected();
	void saveGameState(void);
	void loadGameState(void);
	~GameControll();
};

#endif