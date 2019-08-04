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
            break;
        case '2':
            income = setDataOfAnotherDayIncome();
            break;
        case '3':
            return 0;
            break;
        default:
            cout << endl << "There is no option on the menu!" << endl << endl;
            break;
        }
    }
    incomes.push_back(income);
    if (fileWithIncomes.addIncomeToFile(income))
        cout << "The new income has been added" << endl;
    else
        cout << "Error. It was not possible to add a new income to the file." << endl;
    system("pause");
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
    date = SupportMethods::loadLine();
    while(checkIfDateIsCorrect(date) == false)
    {
        date = SupportMethods::loadLine();
    }
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
/*
void FinancialManager::showBalanceFromTheCurrentMonth()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void FinancialManager::displayTheNumberOfSearchedIncomes(int numberOfIncomes)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void FinancialManager::displayTheNumberOfSearchedExpenses(int numberOfExpenses)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void FinancialManager::showDataOfIncome(Income income)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void FinancialManager::showDataOfExpense(Expense expense)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
*/
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
        int yearInt = SupportMethods::conversionFromStringToInt(year);
        int monthInt = SupportMethods::conversionFromStringToInt(month);
        int dayInt = SupportMethods::conversionFromStringToInt(day);
        if (yearInt > 0 && monthInt > 0 && monthInt <= 12 && dayInt > 0 && dayInt <= 31)
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

