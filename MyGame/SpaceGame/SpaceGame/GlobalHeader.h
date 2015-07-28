#ifndef GLOBALS
#define GLOBALS
// ------- Global definitions -----
#define WINDOW_WIDTH  800 // max gamewindow width 
#define WINDOW_HEIGH  600 // max gamewindow high 
#define MAX_BULLETS 10u // max size of bullet buffer in ship

#define DIAMOND_SCORE 10u // game score  

#define PI 3.14159 //the pi number

enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, ENEMY, BONUS }; // type of objects on scene

#endif 