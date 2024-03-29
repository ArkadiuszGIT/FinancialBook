#include "Finance.h"

using namespace std;

void Finance::setStringDate(string newStringDate)
{
    stringDate = newStringDate;
}
void Finance::setIntDate(int newIntDate)
{
    intDate = newIntDate;
}
void Finance::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Finance::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void Finance::setAmount(double newAmount)
{
    amount = newAmount;
}
void Finance::setDescription(string newDescription)
{
    description = newDescription;
}

string Finance::getStringDate()
{
    return stringDate;
}
int Finance::getIntDate()
{
    return intDate;
}
int Finance::getUserId()
{
    return userId;
}
int Finance::getId()
{
    return id;
}
double Finance::getAmount()
{
    return amount;
}
string Finance::getDescription()
{
    return description;
}
