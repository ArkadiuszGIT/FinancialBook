#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "XmlFile.h"
#include "Markup.h"
#include "SupportMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile
{

public:
    FileWithExpenses(string fileName) : XmlFile(fileName){};
    bool addExpenseToFile(Expense expense);
    vector <Expense> getExpensesOfLoggedUserFromFile(int ID_OF_LOGGED_USER);
};

#endif
