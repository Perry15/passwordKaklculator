#ifndef DATA_H
#define DATA_H

#include <QString>
class startingData{
private:
    int id;//identifica le classi figlie
public:
    startingData(int id=0);
    virtual ~startingData();
    virtual QString getData() const=0;
    int getId() const;

    //checkLength non è const solo perchè in Number e sul n.civico dell'Address
    //se il numero è formato da meno di 3 cifre lo modifico aggiungendo zeri
    //davanti per arrivare a 3 cifre
    virtual bool checkLength()=0;
    virtual void validate()=0;
};
#endif // DATA_H
