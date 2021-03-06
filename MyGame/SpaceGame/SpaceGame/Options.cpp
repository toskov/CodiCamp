﻿#include "Options.h"
Options::Options(){
	//------- Load options file ---------

	//FILE *input = fopen("options", "r");
	//fclose(input);
	/*
		 *keyUp = IND_KEYUP;
	 *keyDown = IND_KEYUP;
	 *keyLeft = IND_KEYUP;
	 *keyRight = IND_KEYUP;
	 *keyShoot = IND_KEYUP;
	 *soundValue = 50u; // 0-100
	*/

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
		// WRITE
		int numbers[6] = { *keyUp, *keyDown, *keyLeft, *keyRight, *keyShoot, *soundValue };
		fwrite(numbers, sizeof(int), 6, file); //записва въведените от клавиатурата числа във файл
		fclose(file);
		return true;
	}
}

void Options::loadGameOptions()
{
	//TODO parsing game options
	FILE *file;
	file = fopen("options.txt", "r");
	 
	if (file == NULL) {
		//printf("Error occurred while file creation!");
	}
	else {
		// READ
		IND_Key buffer[6];
		fread(buffer, sizeof(int), 6, file); //Read options
		*this->keyUp = buffer[0];
		*this->keyDown = buffer[1];
		*this->keyLeft = buffer[2];
		*this->keyRight = buffer[3];
		*this->keyShoot = buffer[4];
		*this->soundValue = buffer[5];
		fclose(file);
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