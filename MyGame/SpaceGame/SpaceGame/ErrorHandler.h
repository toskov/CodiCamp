#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
#include <string>
using namespace std;

class ErrorHandler 
{
private:
	string currentErrorStr = " ";
public:
	ErrorHandler();
   ~ErrorHandler();
	static void CatchError(string currentErrorStr);

};
#endif