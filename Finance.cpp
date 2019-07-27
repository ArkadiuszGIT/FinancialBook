#include "Finance.h"

using namespace std;

void Finance::setDate(string newDate)
{
    date = newDate;
}
void Finance::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Finance::setAmount(int newAmount)
{
    amount = newAmount;
}
void Finance::setDescription(string newDescription)
{
    description = newDescription;
}

string Finance::getDate()
{
    return date;
}
int Finance::getUserId()
{
    return userId;
}
int Finance::getAmount()
{
    return amount;
}
string Finance::getDescription()
{
    return description;
}
