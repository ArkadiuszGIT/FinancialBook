#include "User.h"

using namespace std;

void User::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}
void setName(string newName)
{
    name = newName;
}
void setSurname(string newSurname)
{
    surname = newSurname;
}
void User::setLogin(string newLogin)
{
    login = newLogin;
}
void User::setPassword(string newPassword)
{
    password = newPassword;
}

int User::getId()
{
    return id;
}
string getName()
{
    return name;
}
string getSurname()
{
    return surname;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
