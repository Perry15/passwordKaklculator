#ifndef LEV2_H
#define LEV2_H

#include "password.h"
#include <iostream>
using namespace std;
class lev2 : public Password{
private:
    const int lenMin;
    QString description;
public:
    lev2(QString p="00000000");
    ~lev2();
    virtual QString combination1(const startingData &d1, const startingData &d2);
    virtual QString combination2(const startingData &d1, const startingData &d2);
    virtual QString combination3(const startingData &d1, const startingData &d2);
    virtual QString getDescription() const;
};
#endif // LEV2_H
