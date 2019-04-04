#include "lev2.h"
#include <algorithm>
#include <string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

lev2::lev2(QString p): lenMin(8), Password(p,p.length()){
    description="Una password di livello 2 contiene lettere minuscole, maiuscole e numeri;"
                " possiede una lunghezza minima pari a 8 caratteri";
}
lev2::~lev2(){}
QString lev2::getDescription() const{
    return description;
}
QString lev2::combination1(const startingData &d1, const startingData &d2){
    //LEV2 LUNGHEZZA MINIMA 8 LETTERE MINUSCOLE E MAIUSCOLE E NUMERI
    //combination1 concatena 3 elementi della stringa di d1 con
    //altri 3 elementi della stringa di d2 e infine altri 3 elementi di d1

    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente
    r = qrand() % ((3 - 0) - 0) + 0;
    int x = qrand() % ((3 - 0) - r) + 1;
    p = p.mid(0,r)+p.mid(r,x).toUpper()+p.mid(r+x,3-(r+x));
    QString ris=p;//primo gruppo preso da d1

    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    p = d2.getData().mid(r,3);
    ris+=p;//secondo gruppo preso da d2

    l = d1.getData().length();//lunghezza di d1
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    p= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente
    r = qrand() % ((3 - 0) - 0) + 0;
    x = qrand() % ((3 - 0) - r) + 1;
    p = p.mid(0,r)+p.mid(r,x).toUpper()+p.mid(r+x,3-(r+x));
    ris+=p;//terzo gruppo preso da d1

    if(ris.toStdString().find_first_of("0123456789") == std::string::npos){//se non ci sono numeri
        //aggiungo 2 cifre casuali
        r = qrand() % (100 - 10) + 10;
        ris+=QString::number(r);
    }
    //se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
    //oppure sono tutti numeri e forse minuscole [0-9a-z]+
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos ||
       ris.toStdString().find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali una minuscola e una maiuscola
        QString alf1="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf1.mid(l,1));//aggiungo prima lettera
        QString alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf2.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}

QString lev2::combination2(const startingData &d1, const startingData &d2){
    //LEV2 LUNGHEZZA MINIMA 8 LETTERE MINUSCOLE E MAIUSCOLE E NUMERI
    //combination2 è l'inverso di combination1, preleva 3 elementi della stringa
    //stringa di d1 gli inverte e concatena con altri 3 elementi della stringa di
    //d2 anche questi invertiti e infine concatena altri 3 elementi di d1 invertiti
    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente
    r = qrand() % ((3 - 0) - 0) + 0;
    int x = qrand() % ((3 - 0) - r) + 1;
    p = p.mid(0,r)+p.mid(r,x).toUpper()+p.mid(r+x,3-(r+x));
    //inverto
    QString ris=inversion(p);//primo gruppo preso da d1

    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    p = d2.getData().mid(r,3);
    //inverto
    ris+=inversion(p);//secondo gruppo preso da d2

    l = d1.getData().length();//lunghezza di d1
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    p= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente
    r = qrand() % ((3 - 0) - 0) + 0;
    x = qrand() % ((3 - 0) - r) + 1;
    p = p.mid(0,r)+p.mid(r,x).toUpper()+p.mid(r+x,3-(r+x));
    //inverto
    ris+=inversion(p);//terzo gruppo preso da d1

    if(ris.toStdString().find_first_of("0123456789") == std::string::npos){//se non ci sono numeri
        //aggiungo 2 cifre casuali
        r = qrand() % (100 - 10) + 10;
        ris+=QString::number(r);
    }
    //se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
    //oppure sono tutti numeri e forse minuscole [0-9a-z]+
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos ||
       ris.toStdString().find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali una minuscola e una maiuscola
        QString alf1="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf1.mid(l,1));//aggiungo prima lettera
        QString alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf2.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}

QString lev2::combination3(const startingData &d1, const startingData &d2){
    //LEV2 LUNGHEZZA MINIMA 8 LETTERE MINUSCOLE E MAIUSCOLE E NUMERI
    //nella moltiplicazione la password formata da 3 gruppi p1, p2, p3
    //(dei quali p1 e p2 possiedono dei caratteri maiuscoli inseriti a caso)
    //viene divisa in 2 gruppi e i caratteri di questi vengono alternati
    //siccome la lunghezza è 9 dipsari il carattere centrale rimane fisso

    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente nel primo gruppo p1
    r = qrand() % ((3 - 0) - 0) + 0;
    int x = qrand() % ((3 - 0) - r) + 1;
    p1 = p1.mid(0,r)+p1.mid(r,x).toUpper()+p1.mid(r+x,3-(r+x));
    QString ris="",tmp=p1;//primo gruppo preso da d1

    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2 = d2.getData().mid(r,3);
    tmp+=p2;//secondo gruppo preso da d2

    l = d1.getData().length();//lunghezza di d1
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p3= d1.getData().mid(r,3);
    //traformo lettere minuscole in maiuscole casualmente nel terzo gruppo p3
    r = qrand() % ((3 - 0) - 0) + 0;
    x = qrand() % ((3 - 0) - r) + 1;
    p3 = p3.mid(0,r)+p3.mid(r,x).toUpper()+p3.mid(r+x,3-(r+x));
    tmp+=p3;//terzo gruppo preso da d1

    //creo un gruppo da 4 alterno con un gruppo da 4 e un carattere centarle rimane lì
    int k,n=tmp.length();
    if(n%2==0)//se è pari
        k=0;//la costante è 0
    else//se la lunghezza è dispari
        k=1;//k è 1 perchè aggiungo al primo parametro della mid in modo da
        //tenere un carattere centrale fermo in ris (di solito lunga 9)

    for(int i=0;i<n/2;++i){
        ris+=tmp.mid(i,1)+tmp.mid(i+(n/2)+k,1);
    }
    if(k==1){//se la lunghezza era dispari
        //aggiungo tmp.mid(n/2,1) nella pos centrale di ris
        ris.insert(n/2, tmp.mid(n/2,1));
    }

    if(ris.toStdString().find_first_of("0123456789") == std::string::npos){//se non ci sono numeri
        //aggiungo 2 cifre casuali
        r = qrand() % (100 - 10) + 10;
        ris+=QString::number(r);
    }
    //se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
    //oppure sono tutti numeri e forse minuscole [0-9a-z]+
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos ||
       ris.toStdString().find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali una minuscola e una maiuscola
        QString alf1="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf1.mid(l,1));//aggiungo prima lettera
        QString alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf2.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}
