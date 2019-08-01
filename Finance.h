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
    double amount;
    string description;

public:
    Finance(string date = "", int intDate = 0, int userId = 0, double amount = 0, string description = "")
    {
        this -> stringDate = stringDate;
        this -> intDate = intDate;
        this -> userId = userId;
        this -> amount = amount;
        this -> description = description;
    }
    void setStringDate(string newStringDate);
    void setIntDate(int newIntDate);
    void setUserId(int newUserId);
    void setAmount(double newAmount);
    void setDescription(string newDescription);

    string getStringDate();
    int getIntDate();
    int getUserId();
    double getAmount();
    string getDescription();

};

#endif
