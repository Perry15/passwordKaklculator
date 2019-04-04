#ifndef LEV3_H
#define LEV3_H
#include "password.h"
#include <iostream>
using namespace std;
class lev3 : public Password{
private:
    const int lenMin;
    QString description;
public:
    lev3(QString p="0000000000");
    ~lev3();
    virtual QString combination1(const startingData &d1, const startingData &d2);
    virtual QString combination2(const startingData &d1, const startingData &d2);
    virtual QString combination3(const startingData &d1, const startingData &d2);
    virtual QString getDescription() const;
};
#endif // LEV3_H
