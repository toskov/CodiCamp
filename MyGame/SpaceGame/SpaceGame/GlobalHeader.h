#ifndef GLOBALS
#define GLOBALS
// ------- Global definitions -----
#define WINDOW_WIDTH  800 // max gamewindow width 
#define WINDOW_HEIGHT  600 // max gamewindow high 
#define MAX_BULLETS 10u // max size of bullet buffer in ship

#define DIAMOND_SCORE 10u // game score  
#define GRAVITY 9.81f //gravity

#define PI 3.14159 //the pi number

enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, UFO, BONUS }; // type of objects on scene

enum layer {BACKGROUND = 1, ENEMY, ROCKS, SHIP, MENU, CURSOR,COLLISIONS };

enum currentMenu { PLAY = 1, NEWGAME, QUIT, OPTIONS, CONTROLS, SOUND, DIFFICULTY };

#endif 