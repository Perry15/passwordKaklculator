#ifndef LEV0_H
#define LEV0_H

#include "password.h"
#include <iostream>
using namespace std;

class lev0 : public Password{
private:
    const int lenMin;
    QString description;
public:
    lev0(QString p="0000");
    ~lev0();
    virtual QString combination1(const startingData &d1, const startingData &d2);
    virtual QString combination2(const startingData &d1, const startingData &d2);
    virtual QString combination3(const startingData &d1, const startingData &d2);
    virtual QString getDescription() const;
};
#endif // LEV0_H
