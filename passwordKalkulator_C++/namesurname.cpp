#include "exception.h"
#include "namesurname.h"
#include <algorithm>
#include <string>
using std::string;

NameSurname::NameSurname(QString n, QString s) : startingData(1), name(n), surname(s) {}

NameSurname::~NameSurname() {}

QString NameSurname::getName() const{
    return name;
}
QString NameSurname::getSurname() const{
    return surname;
}
void NameSurname::setName(QString n){
    name=n;
}

void NameSurname::setSurname(QString s){
    surname=s;
}
QString NameSurname::getData() const{
    return name+surname;
}
void NameSurname::validate(){
    //tolgo spazi
    name.replace( " ", "" );
    surname.replace( " ", "" );
    //controllo che non ci siano numeri o caratteri speciali
    if(name.toStdString().find_first_of("0123456789") != std::string::npos || name.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("Nome non valido,\nsono consentite solo lettere");
    }
    if(surname.toStdString().find_first_of("0123456789") != std::string::npos || surname.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("Cognome non valido,\nsono consentite solo lettere");
    }
}
bool NameSurname::checkLength() {
    if(name.length()<3 || surname.length()<3)
        throw Exception("I campi utilizzati per calcolare\nla password, devono essere\nlunghi almeno 3 caratteri");
    return true;
}
