#include "exception.h"
#include "frameRight.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include<QFontDatabase>
#include <stdlib.h>     // srand, rand
#include <time.h>
#include<QFile>
#include<QFileSystemModel>

frameRight::frameRight(int width, int height, QWidget* parent) : frameLeft(width, height, parent){
    srand (time(NULL));//per garantire numeri davvero casuali
    buttonCounter=0;

    //fonts questi forse dovrebbero essere comuni tra input e calcolo
    QFont titleFont("Arial", 18, QFont::Bold);
    QFont labelFont("Lucida", 12, QFont::Normal);

    //generazione password
    result = new lev0();
    d1 = new NameSurname();//primo termine operazione
    d2 = new NameSurname();//secondo termine operazione

    //da qui in poi generazione password
    //titolo
    labTitle2 = new QLabel("Generazione password", this);
    labTitle2->setAlignment(Qt::AlignCenter);
    labTitle2->setFont(titleFont);
    //descrizioni
    labOut = new QLabel("Scegli il livello della password che vuoi ottenere...", this);
    labOut->setAlignment(Qt::AlignLeft);
    labOut->setFont(labelFont);

    levelDesc = new QLabel(result->getDescription(), this);
    levelDesc->setAlignment(Qt::AlignJustify);
    levelDesc->setWordWrap(1);
    levelDesc->setFont(labelFont);

    //combo (tendina) per scegliere il livello della password
    levelList = new QStringList(QStringList()<<"Livello 0"<<"Livello 1"<<"Livello 2"<<"Livello 3");
    level = new QComboBox(this);
    level->setFont(labelFont);
    level->addItems(*levelList);
    connect(level, SIGNAL(currentIndexChanged(int)), this, SLOT(resultType()));

    QFont fontDisplay("Courier New", 18, QFont::Bold);
    //display della calcolatrice
    display = new QLineEdit(this);
    display->setAlignment(Qt::AlignRight|Qt::AlignBottom);
    display->setReadOnly(true);
    display->setFont(fontDisplay);
    display->setMinimumHeight(height/4);
    display->setStyleSheet("vertical-align:bottom;background-color:#ccff99;border:7px solid #bfbfbf;border-radius:13px;");
    //pulsanti
    //bgen1 == operazione +
    bgen1 = new QPushButton("Genera 1", this);
    bgen1->setFont(labelFont);
    //bgen1->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bgen1->setFixedHeight(height/7);
    connect(bgen1, SIGNAL(clicked(bool)), this, SLOT(clickedB1()));

    bgen2 = new QPushButton("Genera 2", this);
    bgen2->setFont(labelFont);
    //bgen2->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bgen2->setFixedHeight(height/7);
    connect(bgen2, SIGNAL(clicked(bool)), this, SLOT(clickedB2()));

    bgen3 = new QPushButton("Genera 3", this);
    bgen3->setFont(labelFont);
    //bgen3->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bgen3->setFixedHeight(height/7);
    connect(bgen3, SIGNAL(clicked(bool)), this, SLOT(clickedB3()));

    bequal = new QPushButton("=", this);
    bequal->setFont(labelFont);
    //bequal->setStyleSheet("margin-top:-3px;");
    bequal->setMinimumHeight(height/7);
    connect(bequal, SIGNAL(clicked(bool)), this, SLOT(clickedBEqual()));

    bcanc = new QPushButton("C", this);
    bcanc->setFont(labelFont);
    //bequal->setStyleSheet("margin-top:-3px;");
    bcanc->setMinimumHeight(height/7);
    connect(bcanc, SIGNAL(clicked(bool)), this, SLOT(clickedBCanc()));

    bnamesurname = new QPushButton("Nome Cognome", this);
    bnamesurname->setFont(labelFont);
    //bnamesurname->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bnamesurname->setFixedHeight(height/7);
    connect(bnamesurname, SIGNAL(clicked(bool)), this, SLOT(clickedBNameSurname()));

    baddress = new QPushButton("Indirizzo", this);
    baddress->setFont(labelFont);
    //baddress->setStyleSheet("background-color:#aaaaaa;");
    baddress->setFixedHeight(height/7);
    connect(baddress, SIGNAL(clicked(bool)), this, SLOT(clickedBAddress()));

    bdate = new QPushButton("Data", this);
    bdate->setFont(labelFont);
    //bdate->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bdate->setFixedHeight(height/7);
    connect(bdate, SIGNAL(clicked(bool)), this, SLOT(clickedBDate()));

    bword = new QPushButton("Parola", this);
    bword->setFont(labelFont);
    //bword->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bword->setFixedHeight(height/7);
    connect(bword, SIGNAL(clicked(bool)), this, SLOT(clickedBWord()));

    bnumber = new QPushButton("Numero", this);
    bnumber->setFont(labelFont);
    //bnumber->setStyleSheet("margin-left:10px;margin-right:10px;padding:25px;");
    bnumber->setFixedHeight(height/7);
    connect(bnumber, SIGNAL(clicked(bool)), this, SLOT(clickedBNumber()));

    setData();//se la password è di livello 0 non posso usare indirizzo
}

QGroupBox* frameRight::createRightGroup() const{
    QGroupBox* l2 = new QGroupBox();//dovrò metterli nel .h come campi dati e anche protetti
    //generazione password
    QGridLayout* setupGen = new QGridLayout();
    setupGen->addWidget(labTitle2,0,0,1,1);
    setupGen->setRowMinimumHeight(1,26);
    setupGen->addWidget(display, 2,0,1,1);
    setupGen->setRowMinimumHeight(3,20);

    QVBoxLayout* setupLevel = new QVBoxLayout();
    setupLevel->addWidget(labOut);
    setupLevel->addWidget(level);
    setupLevel->addWidget(levelDesc);
    setupLevel->addStretch(1);
    setupGen->addLayout(setupLevel,4,0);
    setupGen->setRowMinimumHeight(5,-30);
        QVBoxLayout* setupKeypad = new QVBoxLayout();
            QGridLayout* keypad = new QGridLayout();
            keypad->addWidget(bnamesurname,0,0,1,2);
            keypad->addWidget(baddress,1,0,1,1);
            keypad->addWidget(bequal,3,1,1,2);
            keypad->addWidget(bcanc,3,0,1,1);
            keypad->addWidget(bdate,1,1,1,1);
            keypad->addWidget(bword,2,0,1,1);
            keypad->addWidget(bnumber,2,1,1,1);
            keypad->addWidget(bgen1,0,2,1,1);
            keypad->addWidget(bgen2,1,2,1,1);
            keypad->addWidget(bgen3,2,2,1,1);
        setupKeypad->addLayout(keypad);
        setupKeypad->addStretch(1);
        //setupKeypad->setContentsMargins()
        //left,top,right,bottom
        setupKeypad->setContentsMargins(width/8,width/15,width/8,width/25);

    setupGen->addLayout(setupKeypad,6,0);
    setupGen->setRowStretch(6,1);

    l2->setLayout(setupGen);
    l2->setMinimumWidth(width-(width/2.5));
    l2->setFixedHeight(height*1.6);

    return l2;
}

void frameRight::clickedBCanc(){
    setData();//con setData resetto i bottoni per rifare un altro conto
    display->setText("");
    buttonCounter=0;
    operation=0;
}

void frameRight::clickedBEqual(){//exB1
    buttonCounter=0;
    try{
        //chiamo saveData
        saveData();
        //controllo lunghezza campi utilizzati
        try{
            if(d1->checkLength() && d2->checkLength()){
                //setto il tipo di password da calcolare
                resultType();//istanzia result con il tipo specificato in in QComboBox *level
                switch(operation){
                    case 1: display->setText(result->combination1(*d1,*d2));break;
                    case 2: display->setText(result->combination2(*d1,*d2));break;
                    case 3: display->setText(result->combination3(*d1,*d2));break;
                }
            }
            //con setData resetto i bottoni per rifare un altro conto
            setData();
        }
        catch(Exception e){
            //cout<<"Eccezione: "<<e.getError().toStdString()<<endl;
            output->setText(e.getError());
        }
    }
    catch(Exception e){
        //cout<<"Eccezione: "<<e.getError().toStdString()<<endl;
        output->setText(e.getError());
    }
}
void frameRight::clickedBNameSurname(){
    buttonCounter++;
    if(levelList->indexOf(level->currentText())==0){//la password è di livello 0
        //se clicco namesurname con lev 0 poi posso scegliere solo lettere
        //percui disabilito baddress bdate bnumber
        baddress->setEnabled(false);
        bdate->setEnabled(false);
        bnumber->setEnabled(false);
    }
    if(buttonCounter%2!=0){
        try{
            saveData();//salvo i dati inseriti
        }
        catch(Exception e){
            output->setText(e.getError());
        }
        display->setText("Nome Cognome");
        d1 = new NameSurname(nameSurname->getName(), nameSurname->getSurname());
    }
    else if(buttonCounter%2==0){
        d2 = new NameSurname(nameSurname->getName(), nameSurname->getSurname());
        QString s =display->text();
        display->setText(s+" Nome Cognome");
    }
}
void frameRight::clickedBAddress(){
    buttonCounter++;
    if(buttonCounter%2!=0){
        try{
            saveData();//salvo i dati inseriti
        }
        catch(Exception e){
            output->setText(e.getError());
        }
        display->setText(" Indirizzo");
        d1 = new Address(address->getStreetName(), address->getStreetNumber(), address->getTown());
    }
    else if(buttonCounter%2==0){
        d2 = new Address(address->getStreetName(), address->getStreetNumber(), address->getTown());
        QString s =display->text();
        display->setText(s+" Indirizzo");
    }
}
void frameRight::clickedBDate(){
    buttonCounter++;
    if(levelList->indexOf(level->currentText())==0){//la password è di livello 0
        //se clicco data con lev 0 poi posso scegliere solo numeri
        //percui disabilito bword bnamesurname bnumber
        baddress->setEnabled(false);
        bnamesurname->setEnabled(false);
        bword->setEnabled(false);
    }
    if(buttonCounter%2!=0){
        try{
            saveData();//salvo i dati inseriti
        }
        catch(Exception e){
            output->setText(e.getError());
        }
        display->setText(" Data");
        d1 = new Date(date->getDay(), date->getMonth(), date->getYear());
    }
    else if(buttonCounter%2==0){
        d2 = new Date(date->getDay(), date->getMonth(), date->getYear());
        QString s =display->text();
        display->setText(s+" Data");
    }
}
void frameRight::clickedBNumber(){
    buttonCounter++;
    if(levelList->indexOf(level->currentText())==0){//la password è di livello 0
        //se clicco data con lev 0 poi posso scegliere solo numeri
        //percui disabilito bword bnamesurname bnumber
        baddress->setEnabled(false);
        bnamesurname->setEnabled(false);
        bword->setEnabled(false);
    }
    if(buttonCounter%2!=0){
        try{
            saveData();//salvo i dati inseriti
        }
        catch(Exception e){
            output->setText(e.getError());
        }
        display->setText(" Numero");
        d1 = new Number(number->getNumber());
    }
    else if(buttonCounter%2==0){
        d2 = new Number(number->getNumber());
        QString s =display->text();
        display->setText(s+" Numero");
    }
}
void frameRight::clickedBWord(){
    buttonCounter++;
    if(levelList->indexOf(level->currentText())==0){//la password è di livello 0
        //se clicco namesurname con lev 0 poi posso scegliere solo lettere,
        //percui disabilito baddress bdate bnumber
        baddress->setEnabled(false);
        bdate->setEnabled(false);
        bnumber->setEnabled(false);
    }
    if(buttonCounter%2!=0){
        try{
            saveData();//salvo i dati inseriti
        }
        catch(Exception e){
            output->setText(e.getError());
        }
        display->setText(" Parola");
        d1 = new Word(word->getWord());
    }
    else if(buttonCounter%2==0){
        d2 = new Word(word->getWord());
        QString s =display->text();
        display->setText(s+" Parola");
    }
}

void frameRight::clickedB1(){//+ Genera1
    operation=1;
    QString s =display->text();
    display->setText(s+" +");
}
void frameRight::clickedB2(){//- Genera2
    operation=2;
    QString s =display->text();
    display->setText(s+" -");
}
void frameRight::clickedB3(){//* Genera3
    operation=3;
    QString s =display->text();
    display->setText(s+" x");
}
//setta il livello della password risultato
void frameRight::resultType(){
    //indexOf utilizzando il testo settato sul level(level->currentText())
    //torna un indice relativo alla posizione di quel testo nella lista levelList
    switch(levelList->indexOf(level->currentText())){
        case 0://Livello 0
            result= new lev0();
            break;
        case 1://Livello 1
            result= new lev1();
            break;
        case 2://Livello 2
            result= new lev2();         
            break;
        case 3://Livello 3
            result= new lev3();           
            break;
    }
    setData();//setta i pulsanti in base al livello della password
}
//setta i pulsanti in base al livello della password
void frameRight::setData(){
    //setto la descrizione della password
    levelDesc->setText(result->getDescription());
    if(levelList->indexOf(level->currentText())==0){//la password è di livello 0
        //se il livello della pswd è 0 non possiamo usare indirizzo
        //quindi lo disabilito
        baddress->setEnabled(false);
    }
    else{
        baddress->setEnabled(true);
    }
    bnamesurname->setEnabled(true);
    bdate->setEnabled(true);
    bnumber->setEnabled(true);
    bword->setEnabled(true);
}
frameRight::~frameRight(){
    //generazione password
    delete labTitle2;
    delete labOut;
    delete levelDesc;
    delete level;
    delete levelList;
    delete d1;
    delete d2;
    delete result;
    delete display;
    delete bnamesurname;
    delete baddress;
    delete bdate;
    delete bnumber;
    delete bword;
    delete bgen1;
    delete bgen2;
    delete bgen3;
    delete bequal;
    delete bcanc;
}


