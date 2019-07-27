#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>

using namespace std;

class Finance
{
protected:
    string date;
    int userId;
    int amount;
    string description;

public:
    Finance(string date = "", int userId = 0, int amount = 0, string description = "")
    {
        this -> date = date;
        this -> userId = userId;
        this -> amount = amount;
        this -> description = description;
    }
    void setDate(string newDate);
    void setUserId(int newUserId);
    void setAmount(int newAmount);
    void setDescription(string newDescription);

    string getDate();
    int getUserId();
    int getAmount();
    string getDescription();

};

#endif
