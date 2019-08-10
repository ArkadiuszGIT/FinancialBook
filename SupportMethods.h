#ifndef SUPPORTMETHODS_H
#define SUPPORTMETHODS_H

#include <iostream>
#include <windows.h>
#include <sstream>

using namespace std;

class SupportMethods
{

public:
    static double conversionFromStringToDouble(string number);
    static string conversionFromDoubleToString(double number);
    static string conversionFromIntToString(int number);
    static int conversionFromStringToInt(string number);
    static int conversionDateFromStringToIntWithoutDash(string date);
    static string loadLine();
    static char loadChar();
};

#endif
