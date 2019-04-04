#ifndef WORD_H
#define WORD_H

#include <QString>
#include "startingdata.h"

class Word : public startingData{
private:
    QString str;
public:
    Word(QString s="000");
    ~Word();
    QString getWord() const;
    QString getData() const;
    void validate();
    bool checkLength();
};
#endif // WORD_H
