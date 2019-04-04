#ifndef DATE_H
#define DATE_H

#include <QString>
#include "startingdata.h"
class Date : public startingData{
private:
    QString day;
    QString month;
    QString year;
public:
    Date(QString d="01", QString m="01", QString y="0000");
    ~Date();
    QString getDay() const;
    QString getMonth() const;
    QString getYear() const;
    QString getData() const;

    void validate();
    bool checkLength();

};
#endif // DATE_H
