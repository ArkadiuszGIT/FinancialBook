#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

public:
    FileWithIncomes(string fileName) : XmlFile(fileName){};
    void addIncomeToFile(Income income);
    void addAllIncomesToFile(vector <Income> &incomes);
    vector <Income> loadIncomesFromFile();

};

#endif
