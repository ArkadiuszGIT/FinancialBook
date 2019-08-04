#include "SupportMethods.h"

string SupportMethods::conversionFromIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportMethods::conversionFromStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

double SupportMethods::conversionFromStringToDouble(string number)
{
    for(int i = 0; i <= number.length()-1; i++)
    {
        if(number[i] == ',')
            number[i] = '.';
        if(number[i] == ' ')
            number.replace(i,1,"");
    }
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}

string SupportMethods::conversionFromDoubleToString(double number)
{
    ostringstream ss;
    ss.precision(15);
    ss << number;
    string str = ss.str();
    return str;
}

string SupportMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

string SupportMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char SupportMethods::loadChar()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Enter again." << endl;
    }
    return character;
}

string SupportMethods::changeFirstLetterToUpperAndNextLettersToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int SupportMethods::loadInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> input)
            break;
        cout << "This is not a number. Enter again. " << endl;
    }
    return number;
}

string SupportMethods::getTodaysDate()
{
    string date;
    SYSTEMTIME st;
    GetSystemTime(&st);
    string year = conversionFromIntToString(st.wYear);
    string month = conversionFromIntToString(st.wMonth);
    if (month.length() == 1)
        month = '0' + month;
    string day = conversionFromIntToString(st.wDay);
    if (day.length() == 1)
        day = '0' + day;
    date = year + '-' + month + '-' + day ;
    return date;
}

string SupportMethods::conversionDateFromStringToIntWithoutDash(string date)
{
    for(int i = 0; i <= date.length()-1; i++)
    {
        if(date[i] == '-')
            date.replace(i,1,"");
    }
    int dateInt = conversionFromStringToInt(date);
    return dateInt;
}

