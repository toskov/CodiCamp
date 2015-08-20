#ifndef THING_H
#define	THING_H

#include "CIndieLib.h"
#include "IND_Entity2d.h"
#include "IND_Animation.h"
#include "IND_Surface.h"
#include "GlobalHeader.h"
#include "Frame.h"
#include <vector>
#include "Errorhandler.h"
#include "Ai.h"

class Thing
{
private:
	int *health = new int(10); // increase or decrease players health etc. 
	double *posX = new double(0);
	double *posY = new double(0);
	int *type = new int(0);
	string name = "";
	double *collisionsX = new double(0);
	double *collisionsY = new double(0); 
	double *velosityX = new double(), *velosityY = new double(); // for moving objects
	double *rotation = new double(0);
	double relativeX, relativeY;
	
	CIndieLib *mI;
	IND_Entity2d *thing = IND_Entity2d::newEntity2d();
	IND_Entity2d *border = IND_Entity2d::newEntity2d(); // collision border
	IND_Surface *thingPictures;
	IND_Surface *collisionSurface = IND_Surface::newSurface();
	void Construct(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life); // for multy constructor initialise
	vector<Frame*> frames;
	int frameCount = 0; // number of frames
	int currentFrame = 0; // current frame in animation
	boolean ready = true; // ready for shooting once
	//Ai *brain = new Ai();

public:
	boolean readyToShoot(void);
	void setVelosity(int vX,int vY);
	double getAngle(); // get rotation angle
	Bullet* shoot();
	int getHealth(void);
	int getType();
	//void show(int x, int y);
	void destroy();
	int getCollisionPositionX();
	int getCollisionPositionY();
	//void getHealth(void);
	void animationUpdate(); // Update animation
	void Update(double *delta);
	IND_Entity2d* getColisionBorder();
	Thing();
	Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle, vector<Frame*> frms);
	~Thing();
};
#endif