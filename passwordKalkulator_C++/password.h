#ifndef PASSWORD_H
#define PASSWORD_H

#include <QString>
#include "startingdata.h"

class Password {
private:
    QString pwd;//la password risultato dell'operazione
    int len;//lunghezza effettiva della password
public:
    Password(QString p, int l);
    virtual ~Password();
    QString getPassword() const;
    void setPassword(QString p);
    int getLength() const;
    void setLength(int l);
    //inversione stringhe
    QString inversion(QString s);

    virtual QString combination1(const startingData &d1, const startingData &d2)=0;
    virtual QString combination2(const startingData &d1, const startingData &d2)=0;
    virtual QString combination3(const startingData &d1, const startingData &d2)=0;

    virtual QString getDescription() const=0;
    //mi serve virtuale perchè con l'oggetto result che ha TS Password(madre)
    //devo chiamare i giusti getDescription in base al TD istanziato
};
#endif // PASSWORD_H
