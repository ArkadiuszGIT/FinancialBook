#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
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
    xml.AddElem( "Date", expense.getDate());
    xml.AddElem( "UserID", expense.getUserId());
    xml.AddElem( "Amount", expense.getAmount());
    xml.AddElem( "Description", expense.getDescription());

    xml.Save( XML_FILE_NAME );
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
        xml.AddElem( "Date", itr -> getDate());
        xml.AddElem( "UserID", itr -> getUserId());
        xml.AddElem( "Amount", itr -> getAmount());
        xml.AddElem( "Description", itr -> getDescription());
        xml.OutOfElem();
    }

    xml.Save( XML_FILE_NAME );
}

vector <Expense> FileWithExpenses::loadExpensesFromFile()
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
        expense.setDate(xml.GetData());
        xml.FindElem( "UserID" );
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Amount" );
        expense.setAmount(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Description" );
        expense.setDescription(xml.GetData());
        xml.OutOfElem();
        expenses.push_back(expense);
    }
    return expenses;
}
