#include "Options.h"
Options::Options(){
	//------- Load options file ---------

	//FILE *input = fopen("options", "r");
	//ch = getc(input);

	

}

bool Options::saveOptions()
{
	FILE *file;
	file = fopen("options.txt", "w");

	if (file == NULL) {
		//printf("Error occurred while file creation!");
		return false;
	}
	else {
		//printf("The file is created successfully! ");
		fclose(file);
		return true;
	}
}

Options::~Options()
{
	delete keyUp;
	delete keyDown; 
	delete keyLeft;
	delete keyRight;
	delete keyShoot;
	delete soundValue;
}