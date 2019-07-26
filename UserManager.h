#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "FileWithUsers.h"
#include "User.h"
#include "SupportMethods.h"

using namespace std;

class UserManager
{
    int idOfLogedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User inputDataOfNewUser();
    int getIdOfNewUser();
    bool checkIfLoginExist(string login);

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers){
        idOfLogedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    int userLoggingIn();
    bool checkIfUserIsLoged();
    int userLoggingOut();
    void changePasswordOfLoggedUser();
    void showAllUsers();
    void loadUsersFromFile();
    int getIdOfLoggedUser();
    char chooseOptionFromUserMenu();
};

#endif
