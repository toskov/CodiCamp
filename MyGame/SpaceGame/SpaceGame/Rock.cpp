#include "Rock.h"

Rock::Rock()
{

}
Rock::Rock(CIndieLib *mI, int x, int y, int angle)
{
	*posX = x;
	*posY = y;

	mI->_surfaceManager->add(picture, "../SpaceGame/resources/rock.png", IND_ALPHA, IND_32); // background?
	rock->setSurface(picture);
	mI->_entity2dManager->add(rock);					// Entity adding	
	rock->setPosition(x, y, 3);
	//rock->setHotSpot(2 / (*frameWidth), 2 / (*frameHeight));
	rock->setAngleXYZ(0, 0, angle);
	rock->setRegion(0, 0, *frameWidth, *frameHeight); // must be set outside
	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	float rangle = (angle-55)*3.14159265 / 180.f;
	int offsetX = x - std::sin(rangle) * (*frameWidth) / 2 - 8; // must be corrected
	int offsetY = y + std::cos(rangle) * (*frameHeight) / 2 + 8; // must be corrected
	
	border->setBoundingCircle("thing", offsetX , offsetY, 20);
	
	
}

Rock::Rock(CIndieLib *mI, int x, int y)
{
	*posX = x;
	*posY = y;

	mI->_surfaceManager->add(picture, "../SpaceGame/resources/rock.png", IND_ALPHA, IND_32); // background?
	rock->setSurface(picture);
	mI->_entity2dManager->add(rock);					// Entity adding	
	rock->setPosition(x, y, 3);
	rock->setRegion(0, 0, *frameWidth, *frameHeight); // must be set outside
	// Empty object for colisions!
	mI->_entity2dManager->add(border);
	border->setSurface(collisionSurface);
	border->setBoundingCircle("rock", x + (*frameWidth) / 2, y + (*frameHeight)/2, 20);

}

void Rock::update(float delta)
{
	//skip for animation speed
	*animationSpeedDelay -= 1;
	if (*animationSpeedDelay > 1) return;
	*animationSpeedDelay = 300000 * (delta); // animation speed delta correction
	*this->delta = delta; // if necessary

	// show next image from sprite
	// counting first row, second column
	*currentFrame += 1;
	if (*currentFrame > (*frames - 1)) *currentFrame = 0; // from 0 to frames-1
	int offsetX = (*frameWidth)*((*currentFrame) % (*frameColumns)); // x offset
	int offsetY = (*frameHeight)*((*currentFrame) / (*frameColumns)); // y offset

	rock->setRegion(offsetX, offsetY, *frameWidth, *frameHeight); // shows region
}

void Rock::update()
{

	// show next image from sprite
	// counting first row, second column
	*currentFrame += 1;
	if (*currentFrame > (*frames - 1)) *currentFrame = 0; // from 0 to frames-1
	int offsetX = (*frameWidth)*((*currentFrame) % (*frameColumns)); // x offset
	int offsetY = (*frameHeight)*((*currentFrame) / (*frameColumns)); // y offset

	rock->setRegion(offsetX, offsetY, *frameWidth, *frameHeight); // shows region


}

void Rock::destroy(CIndieLib *mI)
{
	delete frames;
	delete frameWidth;
	delete frameHeight;
	delete frameColumns;
	delete frameRows;
	delete currentFrame;
	delete posX;
	delete posY;
	delete animationSpeedDelay;
	delete delta;
	delete speedX_;
	delete speedY_;

	mI->_entity2dManager->remove(rock);
	mI->_surfaceManager->remove(picture);
	mI->_entity2dManager->remove(border);
	mI->_surfaceManager->remove(collisionSurface);
}

Rock::~Rock()
{
	delete frames; 
	delete frameWidth;
	delete frameHeight;
	delete frameColumns;
	delete frameRows;
	delete currentFrame;
	delete posX;
	delete posY;
	delete animationSpeedDelay;
	delete delta;
	delete speedX_;
	delete speedY_;
}