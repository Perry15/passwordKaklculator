#ifndef LEV1_H
#define LEV1_H

#include "password.h"
#include <iostream>
using namespace std;
class lev1 : public Password{
private:
    const int lenMin;
    QString description;
public:
    lev1(QString p="000000");
    ~lev1();
    virtual QString combination1(const startingData &d1, const startingData &d2);
    virtual QString combination2(const startingData &d1, const startingData &d2);
    virtual QString combination3(const startingData &d1, const startingData &d2);
    virtual QString getDescription() const;
};
#endif // LEV1_H
