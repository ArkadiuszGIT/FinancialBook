#ifndef FINANCIALBOOK_H
#define FINANCIALBOOK_H

#include <iostream>

#include "UserManager.h"
#include "FinancialManager.h"
#include "SupportMethods.h"

using namespace std;

class FinancialBook
{
    UserManager userManager;
    FinancialManager *financialManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    FinancialBook(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        financialManager = NULL;
    };
    ~FinancialBook()
    {
        delete financialManager;
        financialManager = NULL;
    };
    void userRegistration();
    int userLoggingIn();
    int userLoggingOut();
    void changePasswordOfLoggedUser();
    void showAllUsers();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    bool checkIfUserIsLoged();
    int addIncome();
    int addExpense();
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
};

#endif
