#ifndef DATESUPPORTER_H
#define DATESUPPORTER_H

#include <iostream>
#include <windows.h>

#include "SupportMethods.h"

using namespace std;

class DateSupporter
{
    int calculateTheNumberOfDaysInAMonth(int month, int year);

public:
    string getTodaysDate();
    bool checkIfDateIsCorrect(string date);

};

#endif
