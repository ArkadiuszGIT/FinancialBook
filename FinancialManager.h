#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <algorithm>

#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Income.h"
#include "Expense.h"
#include "SupportMethods.h"
#include "DateSupporter.h"

using namespace std;

class FinancialManager
{
    const int ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    FileWithIncomes fileWithIncomes;
    DateSupporter dateSupporter;

    Income setDataOfTodayIncome();
    Income setDataOfAnotherDayIncome();
    Expense setDataOfTodayExpense();
    Expense setDataOfAnotherDayExpense();
    void showDataOfIncome(Income income);
    void showDataOfExpense(Expense expense);
    void displayTheNumberOfSearchedIncomesAndSum(int numberOfIncomes, double incomesSum);
    void displayTheNumberOfSearchedExpensesAndSumAndTotalSum(int numberOfExpenses, double incomesSum, double expensesSum);
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
    int addExpense();
    void showBalanceFromTheCurrentMonth();
    void showBalanceFromThePreviousMonth();
    void showBalanceFromTheSelectedPeriod();

};

#endif
