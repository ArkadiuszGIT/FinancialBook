#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

using namespace std;

class Finance
{
protected:
    string stringDate;
    int intDate;
    int userId;
    int id;
    double amount;
    string description;

public:
    Finance(string stringDate = "", int intDate = 0, int userId = 0, int id = 0, double amount = 0, string description = "")
    {
        this -> stringDate = stringDate;
        this -> intDate = intDate;
        this -> userId = userId;
        this -> id = id;
        this -> amount = amount;
        this -> description = description;
    }
    bool operator > (const Finance& str) const
    {
        return (intDate < str.intDate);
    }
    void setStringDate(string newStringDate);
    void setIntDate(int newIntDate);
    void setUserId(int newUserId);
    void setId(int newId);
    void setAmount(double newAmount);
    void setDescription(string newDescription);

    string getStringDate();
    int getIntDate();
    int getUserId();
    int getId();
    double getAmount();
    string getDescription();

};

#endif
