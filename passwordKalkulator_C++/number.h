#ifndef NUMBER_H
#define NUMBER_H

#include <QString>
#include <algorithm>
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include "startingdata.h"

class Number : public startingData{
private:
    QString numb;
public:
    Number(QString n="000");
    ~Number();
    QString getNumber() const;
    QString getData() const;
    void validate();
    bool checkLength();
};
#endif // NUMBER_H
