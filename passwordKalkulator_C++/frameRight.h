#ifndef FRAMERIGHT_H
#define FRAMERIGHT_H

#include <QPushButton>
#include <QComboBox>

#include "frameLeft.h"
#include "password.h"
#include "lev0.h"
#include "lev1.h"
#include "lev2.h"
#include "lev3.h"

class frameRight : public frameLeft {
    Q_OBJECT
public:
    frameRight(int width, int height, QWidget *parent=0);
    ~frameRight();
    QGroupBox* createRightGroup() const;//crea il layout della parte sinistra
private slots:
    //slot per i pulsanti
    void clickedBNameSurname();
    void clickedBAddress();
    void clickedBDate();
    void clickedBNumber();
    void clickedBWord();
    void clickedB1();//Genera1
    void clickedB2();//Genera2
    void clickedB3();//Genera3
    void clickedBEqual();
    void clickedBCanc();
    void resultType();//il livello selezionato per la password risultato
private:
    void setData();//setta i pulsanti in base al livello della password

    QLabel *labTitle2, *labOut, *levelDesc;
    QComboBox *level;
    QStringList *levelList;//lista dei dati utilizzabili per generare la password

    //dati input e output delle operazioni di calcolo della password
    startingData *d1,*d2;
    Password *result;

    int operation;//operazione 1=='Genera1', 2=='Genera2', 3=='Genera3'
    int buttonCounter;//conta i bottoni cliccati
    QLineEdit *display;
    QPushButton *bnamesurname, *baddress, *bdate, *bnumber, *bword, *bgen1, *bgen2, *bgen3, *bequal ,*bcanc;

    //void buildLayout(int width, int height);//costruzione del layout
};
#endif // FRAMERIGHT_H
