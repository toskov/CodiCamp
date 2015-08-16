#ifndef GLOBALS
#define GLOBALS
// ------- Global definitions -----
#define WINDOW_WIDTH  800 // max gamewindow width 
#define WINDOW_HEIGHT  600 // max gamewindow high 
#define MAX_BULLETS 10u // max size of bullet buffer in ship

#define DIAMOND_SCORE 10u // game score  
#define GRAVITY 9.81f //gravity

#define PI 3.14159 //the pi number

<<<<<<< HEAD
enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, UFO, BONUS }; // type of objects on scene

enum layer {BACKGROUND = 1, ENEMY, ROCKS, SHIP, MENU, CURSOR,COLLISIONS };

=======
<<<<<<< remotes/git_Toskov/master
enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, ENEMY, BONUS }; // type of objects on scene
=======
enum objectType { HEALTH = 1, ASTEROID, ROCK, DIAMOND, UFO, BONUS }; // type of objects on scene
enum layer {BACKGROUND = 1, ENEMY, ROCKS, SHIP, MENU, CURSOR, COLLISIONS }; // named layers
enum currentMenu { MAIN = 1, NEWGAME, OPTIONS, CONTROLS, QUIT, SOUND, DIFFICULTY, BACK };

>>>>>>> local
>>>>>>> Main

#endif 