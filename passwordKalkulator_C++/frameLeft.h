#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

#include "namesurname.h"
#include "date.h"
#include "address.h"
#include "word.h"
#include "number.h"

#include<QGroupBox>
#include<QGridLayout>

class frameLeft : public QWidget {
    Q_OBJECT
public:
    frameLeft(int width, int height, QWidget* parent=0);
    ~frameLeft();
    QGroupBox* createLeftGroup() const;//crea il layout della parte sinistra
protected://le sottoclassi di frameLeft devono avere accesso, in particolare al
    int width, height;

    //puntatori agli oggetti in cui salverò i dati inseriti
    NameSurname* nameSurname;
    Date* date;
    Address* address;
    Word* word;
    Number* number;

    QLabel* output;//messaggi d'errore
    QLabel *labTitle1, *labName, *labSurname,
    *labDate, *labAddress, *labStreetName, *labStreetNumber, *labTown,
    *labWord, *labNumber;
    QLineEdit* inputName;
    QLineEdit* inputSurname;
    QDateEdit* inputDate;
    QLineEdit* inputStreetName, *inputStreetNumber, *inputTown;
    QLineEdit* inputWord;
    QLineEdit* inputNumber;

    void saveData();//alloca i dati inseriti dall'utente
};
#endif // FRAME_H
