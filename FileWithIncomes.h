#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"
#include "Markup.h"
#include "SupportMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

public:
    FileWithIncomes(string fileName) : XmlFile(fileName){};
    bool addIncomeToFile(Income income);
    vector <Income> getIncomesOfLoggedUserFromFile(int ID_OF_LOGGED_USER);
    int getIdOfLastIncomeFromFile();
};

#endif
