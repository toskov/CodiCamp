#include "CIndieLib.h"

class Object
{
private:
	int *posX, *posY, *posZ;

public:
	 void SetPosition(int *x, int *y, int *z);
	 int GetX();
	 int GetY();
	 int GetZ();
	 Object(CIndieLib *mI, std::string resource);
	 ~Object();
	 Object();
	 void Hide();
};