#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load( XML_FILE_NAME );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "IncomeID", income.getId());
    xml.AddElem( "UserID", income.getUserId());
    xml.AddElem( "Date", income.getStringDate());
    xml.AddElem( "Amount", SupportMethods::conversionFromDoubleToString(income.getAmount()));
    xml.AddElem( "Description", income.getDescription());

    xml.Save( XML_FILE_NAME );
    return true;
}

vector <Income> FileWithIncomes::getIncomesOfLoggedUserFromFile(int ID_OF_LOGGED_USER)
{
    Income income;
    vector <Income> incomes;
    CMarkup xml;

    xml.Load( XML_FILE_NAME);

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "IncomeID" );
        income.setId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "UserID" );
        income.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Date" );
        income.setStringDate(xml.GetData());
        income.setIntDate(SupportMethods::conversionDateFromStringToIntWithoutDash(income.getStringDate()));
        xml.FindElem( "Amount" );
        income.setAmount(atof( MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "Description" );
        income.setDescription(xml.GetData());
        xml.OutOfElem();

        if (ID_OF_LOGGED_USER == income.getUserId())
            incomes.push_back(income);
    }
    return incomes;
}

int FileWithIncomes::getIdOfLastIncomeFromFile()
{
    Income income;
    CMarkup xml;
    int idOfLastIncome;

    bool fileExists = xml.Load( XML_FILE_NAME );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") )
        {
            xml.IntoElem();
            xml.FindElem( "IncomeID" );
            idOfLastIncome = atoi( MCD_2PCSZ(xml.GetData()));
            xml.OutOfElem();
        }
    }
    else
        idOfLastIncome = 0;

    return idOfLastIncome;
}


