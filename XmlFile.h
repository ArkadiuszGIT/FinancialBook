#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XmlFile
{
protected:
    const string XML_FILE_NAME;
    //bool czyPlikJestPusty();

public:

    XmlFile(string xmlFileName) : XML_FILE_NAME(xmlFileName) {};
};

#endif
