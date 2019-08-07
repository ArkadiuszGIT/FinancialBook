#include "FinancialManager.h"

int FinancialManager::addIncome()
{
    Income income;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
        choice = chooseOptionFromIncomeMenu();

        switch (choice)
        {
        case '1':
            income = setDataOfTodayIncome();
            incomes.push_back(income);
            if (fileWithIncomes.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;
        case '2':
            income = setDataOfAnotherDayIncome();
            incomes.push_back(income);
            if (fileWithIncomes.addIncomeToFile(income))
                cout << "The new income has been added" << endl;
            else
                cout << "Error. It was not possible to add a new income to the file." << endl;
            system("pause");
            break;
        case '3':
            return 0;
            break;
        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Income FinancialManager::setDataOfTodayIncome()
{
    Income income;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);
    date = SupportMethods::getTodaysDate();
    dateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of income: ";
    amount = SupportMethods::loadLine();
    amountDouble = SupportMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = SupportMethods::loadLine();

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setAmount(amountDouble);
    income.setDescription((description));

    return income;
}

Income FinancialManager::setDataOfAnotherDayIncome()
{
    Income income;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    income.setUserId(ID_OF_LOGGED_USER);

    cout << "Give the date in rrrr-mm-dd format: ";

    do
    {
        date = SupportMethods::loadLine();
    } while(checkIfDateIsCorrect(date) == false);
    dateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of income: ";
    amount = SupportMethods::loadLine();
    amountDouble = SupportMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = SupportMethods::loadLine();

    income.setStringDate(date);
    income.setIntDate(dateInt);
    income.setAmount(amountDouble);
    income.setDescription((description));

    return income;
}

int FinancialManager::addExpense()
{
    Expense expense;

    char choice;

    while(1)
    {
        system("cls");
        cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
        choice = chooseOptionFromExpenseMenu();

        switch (choice)
        {
        case '1':
            expense = setDataOfTodayExpense();
            expenses.push_back(expense);
            if (fileWithExpenses.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;
        case '2':
            expense = setDataOfAnotherDayExpense();
            expenses.push_back(expense);
            if (fileWithExpenses.addExpenseToFile(expense))
                cout << "The new expense has been added" << endl;
            else
                cout << "Error. It was not possible to add a new expense to the file." << endl;
            system("pause");
            break;
        case '3':
            return 0;
            break;
        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    return 0;
}

Expense FinancialManager::setDataOfTodayExpense()
{
    Expense expense;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);
    date = SupportMethods::getTodaysDate();
    dateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of expense: ";
    amount = SupportMethods::loadLine();
    if(amount[0] != '-')
        amount = '-' + amount;
    amountDouble = SupportMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = SupportMethods::loadLine();

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setAmount(amountDouble);
    expense.setDescription((description));

    return expense;
}

Expense FinancialManager::setDataOfAnotherDayExpense()
{
    Expense expense;

    string date, amount, description;
    int dateInt;
    double amountDouble;

    expense.setUserId(ID_OF_LOGGED_USER);

    cout << "Give the date in rrrr-mm-dd format: ";
    do
    {
        date = SupportMethods::loadLine();
    } while(checkIfDateIsCorrect(date) == false);
    dateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(date);

    cout << "Give the amount of expense: ";
    amount = SupportMethods::loadLine();
    if(amount[0] != '-')
        amount = '-' + amount;
    amountDouble = SupportMethods::conversionFromStringToDouble(amount);

    cout << "Write the description: ";
    description = SupportMethods::loadLine();

    expense.setStringDate(date);
    expense.setIntDate(dateInt);
    expense.setAmount(amountDouble);
    expense.setDescription((description));

    return expense;
}

void FinancialManager::showBalanceFromTheCurrentMonth()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = SupportMethods::getTodaysDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            if ( year == yearOfIncome && month == monthOfIncome)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            if ( year == yearOfExpense && month == monthOfExpense)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void FinancialManager::showBalanceFromThePreviousMonth()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string date = SupportMethods::getTodaysDate();
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    int monthInt = SupportMethods::conversionFromStringToInt(month) - 1;
    double incomesSum = 0;
    double expensesSum = 0;

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            string yearOfIncome = dateOfIncome.substr(0,4);
            string monthOfIncome = dateOfIncome.substr(5,2);
            int monthOfIncomeInt = SupportMethods::conversionFromStringToInt(monthOfIncome);
            if ( year == yearOfIncome && monthInt == monthOfIncomeInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            string yearOfExpense = dateOfExpense.substr(0,4);
            string monthOfExpense = dateOfExpense.substr(5,2);
            int monthOfExpenseInt = SupportMethods::conversionFromStringToInt(monthOfExpense);
            if ( year == yearOfExpense && monthInt == monthOfExpenseInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void FinancialManager::showBalanceFromTheSelectedPeriod()
{
    int numberOfIncomes = 0;
    int numberOfExpenses = 0;
    string firstDay, lastDay;
    int firstDayInt, lastDayInt;
    double incomesSum = 0;
    double expensesSum = 0;

    cout << "Give first day in rrrr-mm-dd format: ";
    do
    {
        firstDay = SupportMethods::loadLine();
    } while(checkIfDateIsCorrect(firstDay) == false);
    firstDayInt = SupportMethods::conversionDateFromStringToIntWithoutDash(firstDay);

    cout << "Give last day in rrrr-mm-dd format: ";
    do
    {
        lastDay = SupportMethods::loadLine();
    } while(checkIfDateIsCorrect(lastDay) == false);
    lastDayInt = SupportMethods::conversionDateFromStringToIntWithoutDash(lastDay);

    system("cls");
    if (!incomes.empty())
    {
        sort(incomes.begin(), incomes.end(),greater<Income>());

        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            string dateOfIncome = itr -> getStringDate();
            int dateOfIncomeInt = SupportMethods::conversionDateFromStringToIntWithoutDash(dateOfIncome);
            if ( dateOfIncomeInt >= firstDayInt && dateOfIncomeInt <= lastDayInt)
            {
                showDataOfIncome(*itr);
                incomesSum = incomesSum + itr -> getAmount();
                numberOfIncomes++;
            }
        }
        displayTheNumberOfSearchedIncomesAndSum(numberOfIncomes, incomesSum);
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes in a selected period." << endl << endl;
    }
    if (!expenses.empty())
    {
        sort(expenses.begin(), expenses.end(),greater<Expense>());

        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            string dateOfExpense = itr -> getStringDate();
            int dateOfExpenseInt = SupportMethods::conversionDateFromStringToIntWithoutDash(dateOfExpense);
            if ( dateOfExpenseInt >= firstDayInt && dateOfExpenseInt <= lastDayInt)
            {
                showDataOfExpense(*itr);
                expensesSum = expensesSum + itr -> getAmount();
                numberOfExpenses++;
            }
        }
        displayTheNumberOfSearchedExpensesAndSumAndTotalSum(numberOfExpenses, incomesSum, expensesSum);
    }
    else
    {
        cout << endl << "There are no expenses in a selected period." << endl << endl;
    }

    system("pause");
}

void FinancialManager::displayTheNumberOfSearchedIncomesAndSum(int numberOfIncomes, double incomesSum)
{
    if (numberOfIncomes == 0)
        cout << endl << "There are no incomes in a selected period." << endl;
    else
        cout << endl << "The amount of incomes in a selected period is: " << numberOfIncomes << endl;
    cout << "The Sum of incomes: " << setprecision(15) << incomesSum << endl << endl;
}

void FinancialManager::displayTheNumberOfSearchedExpensesAndSumAndTotalSum(int numberOfExpenses, double incomesSum, double expensesSum)
{
    if (numberOfExpenses == 0)
        cout << endl << "There are no expenses in a selected period." << endl;
    else
        cout << endl << "The amount of expenses in a selected period is: " << numberOfExpenses << endl;
    cout << "The Sum of Expenses: " << setprecision(15) << expensesSum << endl << endl;
    cout << "TOTAL INCOME IN THE SELECTED PERIOD: " << setprecision(15) << incomesSum + expensesSum;
        cout << endl << endl;
}

void FinancialManager::showDataOfIncome(Income income)
{
    cout << endl << "Date:                 " << income.getStringDate() << endl;
    cout << "Amount:               " << setprecision(15) << income.getAmount() << endl;
    cout << "Description:          " << income.getDescription() << endl;
}

void FinancialManager::showDataOfExpense(Expense expense)
{
    cout << endl << "Date:                 " << expense.getStringDate() << endl;
    cout << "Amount:               " << setprecision(15) << expense.getAmount() << endl;
    cout << "Description:          " << expense.getDescription() << endl;
}

bool FinancialManager::checkIfDateIsCorrect(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if((date[i] < 48 || date[i] > 57) && date[i] != '-')
        {
            cout << "Wrong date format. Enter the date again!" << endl;
            return false;
        }
    }
    if( date.length() == 10 && date[4] == '-' && date[7] == '-' )
    {

        string year = date.substr(0,4);
        string month = date.substr(5,2);
        string day = date.substr(8,2);
        string todaysDate = SupportMethods::getTodaysDate();
        int todaysDateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(todaysDate);
        int dateInt = SupportMethods::conversionDateFromStringToIntWithoutDash(date);
        int yearInt = SupportMethods::conversionFromStringToInt(year);
        int monthInt = SupportMethods::conversionFromStringToInt(month);
        int dayInt = SupportMethods::conversionFromStringToInt(day);
        if (dateInt > todaysDateInt)
        {
            cout << "You cannot enter a date later than today!" << endl;
            return false;
        }
        if (yearInt > 0 && monthInt > 0 && monthInt <= 12 && dayInt > 0 && dayInt <= calculateTheNumberOfDaysInAMonth(monthInt, yearInt))
        {
            cout << "The date entered correctly." << endl;
            return true;
        }
        else
        {
            cout << "bad date values. Enter the date again!" << endl;
            return false;
        }

    }
    else
    {
        cout << "Wrong date format. Enter the date again!" << endl;
            return false;
    }
}

int FinancialManager::calculateTheNumberOfDaysInAMonth(int month, int year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
    {
        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            return 29;
        else
            return 28;
    }
    break;
    }
    return 0;
}


char FinancialManager::chooseOptionFromIncomeMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's income" << endl;
    cout << "2 - Income from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = SupportMethods::loadChar();

    return choice;
}

char FinancialManager::chooseOptionFromExpenseMenu()
{
    char choice;

    cout << "---------------------------" << endl;
    cout << "1 - Today's expense" << endl;
    cout << "2 - Expense from another day" << endl;
    cout << "3 - Exit " << endl;
    cout << endl << "Your choice: ";
    choice = SupportMethods::loadChar();

    return choice;
}

