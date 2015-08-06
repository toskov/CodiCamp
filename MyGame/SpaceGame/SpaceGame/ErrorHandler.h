#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "CIndieLib.h"
#include <iostream>
#include <cstring>
#include <string>
#include "time.h"

using namespace std;

class ErrorHandler 
{

public:
	ErrorHandler();
   ~ErrorHandler();
   static bool trace(string str);
   static bool trace(int number);
   static bool trace(float number);
   static bool trace(double number);
};
#endif