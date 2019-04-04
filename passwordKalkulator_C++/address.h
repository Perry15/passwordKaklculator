#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
#include "startingdata.h"
class Address : public startingData{
private:
    QString streetName;
    QString streetNumber;
    QString town;
public:
    Address(QString strNam="000", QString strNum="000", QString t="000");
    ~Address();
    void setStreetName(QString s);
    void setStreetNumber(QString s);
    void setTown(QString s);
    QString getStreetName() const;
    QString getStreetNumber() const;
    QString getTown() const;
    QString getData() const;
    void validate();
    bool checkLength();
};
#endif // ADDRESS_H
