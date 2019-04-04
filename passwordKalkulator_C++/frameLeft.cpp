#include"frameLeft.h"

frameLeft::frameLeft(int width, int height, QWidget* parent) : QWidget(parent){
    this->width=width;
    this->height=height;
    //alloco tutti i campidati
    nameSurname = new NameSurname();
    date = new Date();
    address = new Address();
    word = new Word();
    number = new Number();

    QFont titleFont("Arial", 18, QFont::Bold);
    QFont labelFont("Lucida", 12, QFont::Normal);
    QFont addFont("Lucida", 11, QFont::Normal);

    //label inserimento dati
    labTitle1 = new QLabel("Inserimento dati", this);
    labTitle1->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    labTitle1->setFont(titleFont);
    //label nome e cognome
    labName = new QLabel("Nome", this);
    labName->setFixedHeight(28);
    labName->setFont(labelFont);
    labSurname = new QLabel("Cognome", this);
    labSurname->setFixedHeight(28);
    labSurname->setFont(labelFont);
    //label indirizzo
    labAddress = new QLabel("Indirizzo", this);
    labAddress->setFixedHeight(28);
    labAddress->setFont(labelFont);
    labStreetName = new QLabel("Via: ", this);
    labStreetName->setFixedHeight(28);
    labStreetName->setFont(addFont);
    labStreetNumber = new QLabel("N.Civico: ", this);
    labStreetNumber->setFixedHeight(28);
    labStreetNumber->setFont(addFont);
    labTown = new QLabel("Comune: ", this);
    labTown->setFixedHeight(28);
    labTown->setFont(addFont);
    //label data
    labDate = new QLabel("Data", this);
    labDate->setFixedHeight(28);
    labDate->setFont(labelFont);
    //label parola
    labWord = new QLabel("Parola", this);
    labWord->setFixedHeight(28);
    labWord->setFont(labelFont);
    //label numero
    labNumber = new QLabel("Numero", this);
    labNumber->setFixedHeight(28);
    labNumber->setFont(labelFont);
    //campi input nome e cognome
    inputName = new QLineEdit(this);
    inputName->setPlaceholderText("Inserisci il tuo nome");
    inputName->setFont(labelFont);
    inputName->setFixedHeight(28);
    inputName->setFocus();
    inputSurname = new QLineEdit(this);
    inputSurname->setPlaceholderText("Inserisci il tuo cognome");
    inputSurname->setFont(labelFont);
    inputSurname->setFixedHeight(28);
    //campi input indirizzo
    inputStreetName = new QLineEdit(this);
    inputStreetName->setPlaceholderText("Inserisci la via");
    inputStreetName->setFont(labelFont);
    inputStreetName->setFixedHeight(28);
    inputStreetNumber = new QLineEdit(this);
    inputStreetNumber->setPlaceholderText("Inserisci il n. civico");
    inputStreetNumber->setFont(labelFont);
    inputStreetNumber->setFixedHeight(28);
    inputTown = new QLineEdit(this);
    inputTown->setPlaceholderText("Inserisci il comnune");
    inputTown->setFont(labelFont);
    inputTown->setFixedHeight(28);
    //campo input data
    inputDate = new QDateEdit(this);
    inputDate->setFont(labelFont);
    inputDate->setFixedHeight(28);
    inputDate->setCalendarPopup(true);
    //campo input parola
    inputWord = new QLineEdit(this);
    inputWord->setPlaceholderText("Inserisci una parola");
    inputWord->setFont(labelFont);
    inputWord->setFixedHeight(28);
    //campo input numero
    inputNumber = new QLineEdit(this);
    inputNumber->setPlaceholderText("Inserisci un numero");
    inputNumber->setFont(labelFont);
    inputNumber->setFixedHeight(28);

    //label che serve come output per messaggi d'errore
    output = new QLabel(this);
    output->setFont(addFont);
    output->setFixedHeight(50);
    output->setAlignment(Qt::AlignCenter);
    output->setStyleSheet("color : red;");


}

QGroupBox* frameLeft::createLeftGroup() const{
    QGroupBox *l1 = new QGroupBox();
    QGridLayout *setup = new QGridLayout();
    //setup->addWidget(oggetto,riga,colonna);
    setup->addWidget(labTitle1,0,0,Qt::AlignTop | Qt::AlignCenter);
    setup->addWidget(labName,1,0);
    setup->addWidget(inputName,2,0);
    setup->addWidget(labSurname,3,0);
    setup->addWidget(inputSurname,4,0);
    setup->addWidget(labAddress,5,0);
        //sottocampi di indirizzo
        QGridLayout* setupAdd = new QGridLayout();
        setupAdd->setSpacing(2);
        setupAdd->addWidget(labStreetName,0,0,1,1);
        setupAdd->addWidget(inputStreetName,0,1,1,1);
        setupAdd->addWidget(labStreetNumber,1,0,1,1);
        setupAdd->addWidget(inputStreetNumber,1,1,1,1);
        setupAdd->addWidget(labTown,2,0,1,1);
        setupAdd->addWidget(inputTown,2,1,1,1);
    setup->addLayout(setupAdd,6,0);
    setup->addWidget(labDate,7,0);
    setup->addWidget(inputDate,8,0);
    setup->addWidget(labWord,9,0);
    setup->addWidget(inputWord,10,0);
    setup->addWidget(labNumber,11,0);
    setup->addWidget(inputNumber,12,0);
    setup->addWidget(output,13,0);//output mostra messaggi errore

    l1->setLayout(setup);
    l1->setMaximumWidth(width/2.5);
    l1->setFixedHeight(height*1.6);

    return l1;
}
void frameLeft::saveData(){
    output->clear();
    //alloco tutto con i dati inseriti
    nameSurname = new NameSurname(inputName->text(), inputSurname->text());
    address =  new Address(inputStreetName->text(), inputStreetNumber->text(), inputTown->text());
    date = new Date(QString::number(inputDate->date().day()), QString::number(inputDate->date().month()), QString::number(inputDate->date().year()));
    word = new Word(inputWord->text());
    number = new Number(inputNumber->text());
    //necessario validare i dati togliere spazi, controllare numeri e caratteri speciali
    //validate può generare eccezioni! le gestisco quando chiamo saveData
    nameSurname->validate();
    address->validate();
    //date->validate();//non serve date essendo QDate è già giusta
    word->validate();
    number->validate();
}
frameLeft::~frameLeft(){
    delete nameSurname;
    delete date;
    delete address;
    delete word;
    delete number;
    delete output;
    delete labTitle1;
    delete labName;
    delete labSurname;
    delete labDate;
    delete labAddress;
    delete labStreetName;
    delete labStreetNumber;
    delete labTown;
    delete labWord;
    delete labNumber;   
    delete inputName;
    delete inputSurname;
    delete inputDate;
    delete inputStreetName;
    delete inputStreetNumber;
    delete inputTown;
    delete inputWord;
    delete inputNumber;
}
