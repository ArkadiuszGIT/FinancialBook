#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = inputDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "The account was successfully created" << endl << endl;
    system("pause");
}

User UserManager::inputDataOfNewUser()
{
    User user;

    user.setId(getIdOfNewUser());

    cout << "Enter name: ";
    user.setName(SupportMethods::loadLine());

    cout << "Enter surname: ";
    user.setSurname(SupportMethods::loadLine());

    do
    {
        cout << "Enter login: ";
        user.setLogin(SupportMethods::loadLine());
    } while (checkIfLoginExist(user.getLogin()) == true);

    cout << "Enter password: ";
    user.setPassword(SupportMethods::loadLine());

    return user;
}

int UserManager::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkIfLoginExist(string login)
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login already exist." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers()
{
    for (unsigned int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
    system("pause");
}

int UserManager::userLoggingIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = SupportMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempt = 3; attempt > 0; attempt--)
            {
                cout << "Enter password. Attempts remaining: " << attempt << ": ";
                password = SupportMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    idOfLoggedUser = itr -> getId();
                    cout << endl << "You've logged in successfully." << endl << endl;
                    system("pause");
                    return 0;
                }
            }
            cout << "A wrong password was entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return 0;
}

int UserManager::userLoggingOut()
{
    idOfLoggedUser = 0;
    return idOfLoggedUser;
}

void UserManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = SupportMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idOfLoggedUser)
        {
            itr -> setPassword(newPassword);
            fileWithUsers.addAllUsersToFile(users);
        }
    }
    cout << "Password has been changed." << endl << endl;
    system("pause");
}

bool UserManager::checkIfUserIsLogged()
{
    if (idOfLoggedUser > 0)
        return true;
    else
        return false;
}

int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}

char UserManager::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from the current month" << endl;
    cout << "4. Balance from the previous month" << endl;
    cout << "5. Balance from the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. change password" << endl;
    cout << "7. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = SupportMethods::loadChar();

    return choice;
}
