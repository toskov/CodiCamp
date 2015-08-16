#include "Thing.h"

Thing::Thing()
{
}

Thing::Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle, vector<Frame*> frms)
{
<<<<<<< HEAD
	// random speed and direction (rand() % 2 - 1)
	//srand(time(NULL));
	*velosityX = rand() % 100;
	*velosityY = rand() % 100;

	this->thingPictures = thingsPicture;
	this->frames = frms;
	*posX = x;
=======
<<<<<<< remotes/git_Toskov/master
	Thing::Construct(mI, type, x, y, life);
}

Thing::Thing(CIndieLib *mI, int type, int x, int y, int life, int angle)
{
	Thing::Construct(mI, type, x, y, life);
	//Rotation angle
	thing->setAngleXYZ(0, 0, angle);
}

void Thing::Construct(CIndieLib *mI, int type, int x, int y, int life)
{
*posX = x;
=======
	// random speed and direction (rand() % 2 - 1)
	//srand(time(NULL));
	*velosityX = rand() % 100;
	*velosityY = rand() % 100;
	this->mI = mI;
	this->thingPictures = thingsPicture;
	this->frames = frms;
	*posX = x;
>>>>>>> local
>>>>>>> Main
	*posY = y;
	*health = life;
	*this->type = type;

	thing->setSurface(thingsPicture);
	mI->_entity2dManager->add(thing);

	int radius = 0;
	string typ = "";

	switch (type){
	case HEALTH:
		typ = "health";
		radius = 20;
		break;
	case ASTEROID:
		typ = "asteroid";
		radius = 40;
		thing->setScale(0.7, 0.7);
		break;
	case ROCK:
		typ = "rock";
		radius = 20;
		break;
	case DIAMOND:
		typ = "diamond";
		radius = 20;
		break;
	case UFO:
		typ = "ufo";
		radius = 15;
		break;
	}

	name = typ;

	// Search first picture for type;
	frameCount = 0; // clear number of frames
	int width, height,offsetX,offsetY;	
	for (int i = 0; i < frms.size(); i++)
	{
		
		if (typ == frms.at(i)->name)
		{
			frameCount++;
			width = frms.at(i)->width;
			height = frms.at(i)->height;
			offsetX = frms.at(i)->offsetX;
			offsetY = frms.at(i)->offsetY;			
			// break;
			currentFrame = i;// last frame 
		}
	}
	//srand(time(NULL)); // random generfated possition
	currentFrame = rand() % (frameCount-1);
	// Entity adding
	thing->setPosition(x, y, 1);
	//health (1) = 360 1180 50 50
	//thing->setRegion(360, 1180, 50, 50);
	thing->setRegion(offsetX, offsetY, width, height); // shows first picture from sprite

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	//border->setPosition(x,y,COLLISIONS);
	border->setBoundingCircle("thing", x + width /2, y + height / 2, radius);	
	// prepare positions for explosion
	*collisionsX = border->getPosX();//x + width / 2;	
	*collisionsY = border->getPosY();//y + height / 2;
	relativeX =  width / 2;
	relativeY =  height / 2;
}

IND_Entity2d* Thing::getColisionBorder()
{
	return border;
}


int Thing::getHealth(void)
{
	return *health;
}

int Thing::getType()
{
	return *type;
}

int Thing::getCollisionPositionX()
{
		return *posX+relativeX;
}

int Thing::getCollisionPositionY()
{
		return *posY+relativeY;
}

void Thing::animationUpdate()
{
	// get current frame from sprite
	int width, height, offsetX, offsetY;

	currentFrame++;
	if (currentFrame > frameCount) currentFrame = 1;

	for (int i = 0; i < frames.size(); i++)
	{

		if ((name == frames.at(i)->name) && (frames.at(i)->frameNumber == currentFrame))
		{			
			width = frames.at(i)->width;
			height = frames.at(i)->height;
			offsetX = frames.at(i)->offsetX;
			offsetY = frames.at(i)->offsetY;
			break;
		}
	}

	thing->setRegion(offsetX, offsetY, width, height); // shows region
}

//Used for moving objects
void Thing::setVelosity(int vx, int vy) 
{
	*velosityX = vx;
	*velosityY = vy;

}

//Update moving objects
void Thing::Update(double *delta)
{
	
	*posX = *posX + *velosityX*(*delta);
	*posY = *posY + *velosityY*(*delta);
	thing->setPosition(*posX,*posY, 2);
	*collisionsX = border->getPosX() + *velosityX*(*delta);
	*collisionsY = border->getPosY() + *velosityY*(*delta);

	border->setPosition(*collisionsX, *collisionsY, ENEMY);
	if ((*posX > WINDOW_WIDTH) || (*posX <1)) *velosityX = -*velosityX;
	if ((*posY > WINDOW_HEIGHT) || (*posY <1)) *velosityY = -*velosityY;

}

void Thing::destroy()
{
	delete health;
	delete type;
	delete posX;
	delete posY;
	border->deleteBoundingAreas("thing");
	mI->_entity2dManager->remove(thing);
	mI->_entity2dManager->remove(border);
	mI->_surfaceManager->remove(collisionSurface);
}

Thing::~Thing()
{
	delete velosityX;
	delete velosityY;
	delete health;
	delete posX;
	delete posY;
	delete type;
}