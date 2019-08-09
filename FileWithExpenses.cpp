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
    xml.AddElem( "ExpenseID", expense.getId());
    xml.AddElem( "UserID", expense.getUserId());
    xml.AddElem( "Date", expense.getStringDate());
    xml.AddElem( "Amount", SupportMethods::conversionFromDoubleToString(expense.getAmount()));
    xml.AddElem( "Description", expense.getDescription());

    xml.Save( XML_FILE_NAME );
    return true;
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
        xml.FindElem( "ExpenseID" );
        expense.setId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "UserID" );
        expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Date" );
        expense.setStringDate(xml.GetData());
        expense.setIntDate(SupportMethods::conversionDateFromStringToIntWithoutDash(expense.getStringDate()));
        xml.FindElem( "Amount" );
        expense.setAmount(atof( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Description" );
        expense.setDescription(xml.GetData());
        xml.OutOfElem();
        if (ID_OF_LOGGED_USER == expense.getUserId())
            expenses.push_back(expense);
    }
    return expenses;
}

int FileWithExpenses::getIdOfLastExpenseFromFile()
{
    Expense expense;
    CMarkup xml;
    int idOfLastExpense;

    bool fileExists = xml.Load( XML_FILE_NAME );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") )
        {
            xml.IntoElem();
            xml.FindElem( "ExpenseID" );
            idOfLastExpense = atoi( MCD_2PCSZ(xml.GetData()));
            xml.OutOfElem();
        }
    }
    else
        idOfLastExpense = 0;

    return idOfLastExpense;
}
