#include "ErrorHandler.h"

ErrorHandler::ErrorHandler()
{

}
ErrorHandler::~ErrorHandler()
{

}

bool ErrorHandler::trace(int number)
{
	return trace(to_string(number));
}

bool ErrorHandler::trace(float number)
{
	return trace(to_string(number));
}

bool ErrorHandler::trace(double number)
{
	
	return trace(to_string(number));
}

bool ErrorHandler::trace(string str)
{

	char * cstr = new char[str.length() + 1];
	std::strcpy(cstr, str.c_str());

	FILE *file;
	file = fopen("errors.txt", "a");

	if (file == NULL) {
		//printf("Error occurred while file creation!");
		return false;
	}
	else {
		//printf("The file is created successfully! ");
		// WRITE
		time_t rawtime;
		struct tm * timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);
		printf("Current local time and date: %s", asctime(timeinfo));

		fwrite(asctime(timeinfo), 20, 1, file);
		fwrite(cstr, str.length(), 1, file); // writes message in file
		fwrite(" \n", 3, 1, file); // writes message in file
		fclose(file);
		return true;
	}
}
