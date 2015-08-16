#ifndef GLOBALS
#define GLOBALS
// ------- Global definitions -----
#define windowMaxX  800 // max gamewindow width 
#define windowMaxY  600 // max gamewindow high 
#define MAX_BULLETS 20u // max size of bullet buffer in ship

#define PI 3.14159 //the pi number

<<<<<<< remotes/git_Toskov/master
enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, ENEMY, BONUS }; // type of objects on scene
=======
enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, UFO, BONUS }; // type of objects on scene
enum layer {BACKGROUND = 1, ENEMY, ROCKS, SHIP, MENU, CURSOR, COLLISIONS }; // named layers
enum currentMenu { MAIN = 1, NEWGAME, OPTIONS, CONTROLS, QUIT, SOUND, DIFFICULTY, BACK };

>>>>>>> local

#endif 