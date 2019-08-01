#include <iostream>

#include "FinancialBook.h"

using namespace std;

int main()
{
    char choice;

    FinancialBook financialBook("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true)
    {
        if (financialBook.checkIfUserIsLoged() == false)
        {
            choice = financialBook.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                financialBook.userRegistration();
                break;
            case '2':
                financialBook.userLoggingIn();
                break;
            case '3':
                financialBook.showAllUsers();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = financialBook.chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                //financialBook.addIncome();
                break;
            case '2':
                //financialBook.addExpense();
                break;
            case '3':
                //financialBook.showBalanceFromTheCurrentMonth();
                break;
            case '4':
                //financialBook.showBalanceFromThePreviousMonth();
                break;
            case '5':
                //financialBook.showBalanceFromTheSelectedPeriod();
                break;
            case '6':
                financialBook.changePasswordOfLoggedUser();
                break;
            case '7':
                financialBook.userLoggingOut();
                break;
            }
        }
    }
    return 0;
}
