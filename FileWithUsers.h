#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#include "User.h"
#include "SupportMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string fileName) : XmlFile(fileName){};
    void addUserToFile(User user);
    void addAllUsersToFile(vector <User> &users);
    vector <User> loadUsersFromFIle();

};

#endif
