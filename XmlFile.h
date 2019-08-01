#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile
{
protected:
    const string XML_FILE_NAME;

public:
    XmlFile(string xmlFileName) : XML_FILE_NAME(xmlFileName) {};
};

#endif
