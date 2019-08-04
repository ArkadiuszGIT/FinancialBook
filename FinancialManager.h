#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Income.h"
#include "Expense.h"
#include "SupportMethods.h"

using namespace std;

class FinancialManager
{
    const int ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;

    Income setDataOfTodayIncome();
    Income setDataOfAnotherDayIncome();
    /*
    Expense setDataOfNewExpense();
    void showDataOfIncome(Income income);
    void showDataOfExpense(Expense expense);
    void displayTheNumberOfSearchedIncomes(int numberOfIncomes);
    void displayTheNumberOfSearchedExpenses(int numberOfExpenses);
    */
    bool checkIfDateIsCorrect(string date);
    char chooseOptionFromIncomeMenu();
    char chooseOptionFromExpenseMenu();

public:
    FinancialManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser)
        : fileWithIncomes(nameOfFileWithIncomes), fileWithExpenses(nameOfFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = fileWithIncomes.getIncomesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
        expenses = fileWithExpenses.getExpensesOfLoggedUserFromFile(ID_OF_LOGGED_USER);
    };
    int addIncome();
    void addExpense();
    /*
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromTheSelectedPeriod();
    */

};

#endif
