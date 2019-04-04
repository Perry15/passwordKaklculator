#include "lev0.h"
#include <algorithm>
#include <string>
using std::string;

lev0::lev0(QString p): lenMin(4), Password(p,p.length()){
    description="Una password di livello 0 contiene solo lettere minuscole o solo numeri"
                " e possiede una lunghezza minima pari a 4 caratteri.";
}
lev0::~lev0(){}
QString lev0::getDescription() const{
    return description;
}
QString lev0::combination1(const startingData &d1, const startingData &d2){
    //LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE MINUSCOLE O SOLO NUMERI
    //combination1 concatena 3 elementi della stringa di d1 con
    //altri 3 elementi della stringa di d2
    int l=d1.getData().length();//lunghezza di d1
    //qrand() % ((high+1)-low)+low
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3).toLower();
    l = d2.getData().length();//lunghezza di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2= d2.getData().mid(r,3).toLower();
    setPassword(p1+p2);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return p1+p2;
}

QString lev0::combination2(const startingData &d1, const startingData &d2){
    //LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE MINUSCOLE O SOLO NUMERI
    //combination2 è l'inverso di combination1, preleva 3 elementi della stringa
    //stringa di d1 gli inverte e concatena con altri 3 elementi della stringa di
    //d2 anche questi invertiti
    int l=d1.getData().length();//lunghezza di d1
    int r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d1
    QString p1= d1.getData().mid(r,3).toLower();
    l = d2.getData().length();//l di d2
    r = qrand() % ((l - 2) - 0) + 0;//indice casuale per estrarre 3 elementi da d2
    QString p2= d2.getData().mid(r,3).toLower();
    //prima di concatenare inverto i due gruppi con inversion
    setPassword(inversion(p1)+inversion(p2));//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return inversion(p1)+inversion(p2);
}

QString lev0::combination3(const startingData &d1, const startingData &d2){
    //LEV0 LUNGHEZZA MINIMA 4 O SOLO LETTERE MINUSCOLE O SOLO NUMERI
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
    if(n%2==0)//se è pari ma in lev0 sarà sempre pari perchè 3+3=6
        k=0;//la costante è 0
    else//se la lunghezza è dispari
        k=1;//k è 1 perchè lo aggiungo al primo parametro della mid in modo da
            //tenere un carattere centrale fermo in ris (di solito lunga 9)
    for(int i=0;i<n/2;++i){
        ris+=tmp.mid(i,1)+tmp.mid(i+(n/2)+k,1);
    }
    if(k==1){//se la lunghezza era dispari
        //aggiungo tmp.mid(n/2,1) nella pos centrale di ris
        ris.insert(n/2, tmp.mid(n/2,1));
    }
    setPassword(ris);//setto la password risultante
    setLength(getPassword().length());//setto la lunghezza effettiva
    return ris;
}
