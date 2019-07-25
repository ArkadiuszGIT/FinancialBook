#ifndef SUPPORTMETHODS_H
#define SUPPORTMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class SupportMethods
{

public:
    static string conversionFromIntToString(int number);
    static int coversionFromStringToInt(string number);
    static string getNumber(string text, int charPosition);
    static string loadLine();
    static char loadChar();
    static string changeFirstLetterToUpperAndNextLettersToLower(string text);
    static int loadInteger();
};

#endif
