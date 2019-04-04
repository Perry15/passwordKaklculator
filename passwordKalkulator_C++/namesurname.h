#ifndef NAMESURNAME_H
#define NAMESURNAME_H

#include <QString>
#include "startingdata.h"
class NameSurname : public startingData{
private:
    QString name;
    QString surname;
public:
    NameSurname(QString n="000", QString s="000");
    ~NameSurname();
    QString getName() const;
    QString getSurname() const;
    void setName(QString n);
    void setSurname(QString s);
    QString getData() const;
    void validate();
    bool checkLength();
};
#endif // NAMESURNAME_H
