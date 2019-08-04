#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load( XML_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "Date", expense.getStringDate());
    xml.AddElem( "UserID", expense.getUserId());
    xml.AddElem( "Amount", expense.getAmount());
    xml.AddElem( "Description", expense.getDescription());

    xml.Save( XML_FILE_NAME );
    return true;
}

void FileWithExpenses::addAllExpensesToFile(vector <Expense> &expenses)
{
    CMarkup xml;

    xml.Load( XML_FILE_NAME );

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.RemoveElem();
    }
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        xml.AddElem( "Expense" );
        xml.IntoElem();
        xml.AddElem( "Date", itr -> getStringDate());
        xml.AddElem( "UserID", itr -> getUserId());
        xml.AddElem( "Amount", itr -> getAmount());
        xml.AddElem( "Description", itr -> getDescription());
        xml.OutOfElem();
    }

    xml.Save( XML_FILE_NAME );
}

vector <Expense> FileWithExpenses::getExpensesOfLoggedUserFromFile(int ID_OF_LOGGED_USER)
{
    Expense expense;
    vector <Expense> expenses;
    CMarkup xml;

    xml.Load( XML_FILE_NAME);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "Date" );
        expense.setStringDate(xml.GetData());
        expense.setIntDate(SupportMethods::conversionDateFromStringToIntWithoutDash(expense.getStringDate()));
        xml.FindElem( "UserID" );
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Amount" );
        expense.setAmount(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Description" );
        expense.setDescription(xml.GetData());
        xml.OutOfElem();
        if (ID_OF_LOGGED_USER == expense.getUserId())
            expenses.push_back(expense);
    }
    return expenses;
}
