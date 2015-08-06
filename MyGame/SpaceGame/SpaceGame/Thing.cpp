#include "Thing.h"

Thing::Thing()
{
}

Thing::Thing(CIndieLib *mI, IND_Surface *thingsPicture, int type, int x, int y, int life, int angle, vector<Frame*> frms)
{
	this->thingPictures = thingsPicture;
	this->frames = frms;
	*posX = x;
	*posY = y;
	*health = life;
	*this->type = type;
		
	/*
	mI->_surfaceManager->add(picture, "../SpaceGame/resources/rock.png", IND_ALPHA, IND_32); // background?
	rock->setSurface(picture);
	mI->_entity2dManager->add(rock);					// Entity adding	
	rock->setPosition(x, y, 3);
	rock->setRegion(0, 0, *frameWidth, *frameHeight); // must be set outside
	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setBoundingCircle("rock", x + (*frameWidth) / 2, y + (*frameHeight)/2, 20);
	HEALTH = 1, ASTEROID, ROCK, DIAMOND, ENEMY, UFO 
	*/

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

	// Search first picture for type;
	int width, height,offsetX,offsetY;	
	for (int i = 0; i < frms.size(); i++)
	{
		if (frms.at(i)->name.compare(typ) && (frms.at(i)->frameNumber == 2))
		{
			width = frms.at(i)->width;
			height = frms.at(i)->height;
			offsetX = frms.at(i)->offsetX;
			offsetY = frms.at(i)->offsetY;			
			break;
		}
	}
	ErrorHandler::trace(frms.at(200)->name);

	width = frms.at(190)->width;
	height = frms.at(190)->height;
	offsetX = frms.at(190)->offsetX;
	offsetY = frms.at(190)->offsetY;
	
	// Entity adding
	thing->setPosition(x, y, 1);
	//health (1) = 360 1180 50 50
	//thing->setRegion(360, 1180, 50, 50);
	thing->setRegion(offsetX, offsetY, width, height); // shows first picture from sprite

	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);

	border->setBoundingCircle("thing", x + width /5, y + height / 5, radius);	
}


Thing::~Thing()
{

}


IND_Entity2d* Thing::getColisionBorder()
{
	return border;
}

void Thing::destroy(CIndieLib *mI)
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

int Thing::getHealth(void)
{
	return *health;
}

int Thing::getType()
{
	return *type;
}

int Thing::getPositionX()
{
	return thing->getPosX();
}

int Thing::getPositionY()
{
	return thing->getPosY();
}