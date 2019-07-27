#include "FinancialBook.h"

char FinancialBook::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportMethods::loadChar();

    return choice;
}

char FinancialBook::chooseOptionFromUserMenu()
{
    userManager.chooseOptionFromUserMenu();
}

void FinancialBook::userRegistration()
{
    userManager.userRegistration();
}

int FinancialBook::userLoggingIn()
{
    userManager.userLoggingIn();
    userManager.checkIfUserIsLogged();
    //if (userManager.czyUzytkownikJestZalogowany())
    //{
    //    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, userManager.pobierzIdZalogowanegoUzytkownika());
    //}
}

int FinancialBook::userLoggingOut()
{
    userManager.userLoggingOut();
   // delete adresatMenedzer;
    //adresatMenedzer = NULL;
}

void FinancialBook::changePasswordOfLoggedUser()
{
    userManager.changePasswordOfLoggedUser();
}

void FinancialBook::showAllUsers()
{
    userManager.showAllUsers();
}

bool FinancialBook::checkIfUserIsLoged()
{
    userManager.checkIfUserIsLogged();
}
