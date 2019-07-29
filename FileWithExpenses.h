#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses : public XmlFile
{

public:
    FileWithExpenses(string fileName) : XmlFile(fileName){};
    void addExpenseToFile(Expense expense);
    void addAllExpensesToFile(vector <Expense> &expenses);
    vector <Expense> loadExpensesFromFile();

};

#endif
