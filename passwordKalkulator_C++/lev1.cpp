#include "lev1.h"
#include <algorithm>
#include <string>
using std::string;

lev1::lev1(QString p): lenMin(6), Password(p,p.length()){
    description="Una password di livello 1 contiene lettere minuscole e numeri;"
                " possiede una lunghezza minima pari a 6 caratteri.";
}
lev1::~lev1(){}
QString lev1::getDescription() const{
    return description;
}
QString lev1::combination1(const startingData &d1, const startingData &d2){
    //LEV1 LUNGHEZZA MINIMA 6 LETTERE MINUSCOLE E NUMERI
    //combination1 concatena 3 elementi della stringa di d1 con
    //altri 3 elementi della stringa di d2
    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3).toLower();
    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2= d2.getData().mid(r,3).toLower();
    QString ris=p1+p2;
    //se non ci sono già, aggiungo numeri
    if(ris.toStdString().find_first_of("0123456789") == std::string::npos){//se non ci sono numeri
        //aggiungo 2 cifre casuali
        r = qrand() % (100 - 10) + 10;
        ris+=QString::number(r);
    }
    //se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali
        QString alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r = qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo prima lettera
        l = qrand() % ((26) -0) + 0;//indice tra 0 e 26 escluso
        r = qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}

QString lev1::combination2(const startingData &d1, const startingData &d2){
    //LEV1 LUNGHEZZA MINIMA 6 LETTERE MINUSCOLE E NUMERI
    //combination2 è l'inverso di combination1, preleva 3 elementi della stringa
    //stringa di d1 gli inverte e concatena con altri 3 elementi della stringa di
    //d2 anche questi invertiti
    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3).toLower();
    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2= d2.getData().mid(r,3).toLower();
    //prima di concatenare inverto i due gruppi con inversion
    QString ris=inversion(p1)+inversion(p2);
    if(ris.toStdString().find_first_of("0123456789") == std::string::npos){//se non ci sono numeri
        //aggiungo 2 cifre casuali
        r = qrand() % (100 - 10) + 10;
        ris+=QString::number(r);
    }
    //se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali
        QString alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo prima lettera
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}

QString lev1::combination3(const startingData &d1, const startingData &d2){
    //LEV1 LUNGHEZZA MINIMA 6 LETTERE MINUSCOLE E NUMERI
    //combination3 prende 3 elementi del primo operando d1
    //3 del secondo operando d2 e alterna le lettere dei due gruppi
    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3).toLower();
    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2= d2.getData().mid(r,3).toLower();
    //a questo punto devo creare la stringa alternata
    QString ris="",tmp=p1+p2;
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
    //se non ci sono lettere ovvero ci sono solo numeri, aggiungo 2 lettere casuali
    if(ris.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos){//se non ci sono lettere
        //aggiungo 2 lettere casuali
        QString alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo prima lettera
        l = qrand() % ((26) -0) + 0;//indice casuale tra 0 e 26 escluso
        r=qrand() % ((ris.length()) -0) + 0;//indice casuale
        ris.insert(r,alf.mid(l,1));//aggiungo seconda lettera
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}
