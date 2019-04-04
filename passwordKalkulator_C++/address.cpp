#include "address.h"
#include "exception.h"

Address::Address(QString strNam, QString strNum, QString t) : startingData(3),
    streetName(strNam), streetNumber(strNum), town(t) {}

Address::~Address() {}

void Address::setStreetName(QString s) {
    streetName=s;
}
void Address::setStreetNumber(QString s) {
    streetNumber=s;
}
void Address::setTown(QString s) {
    town=s;
}
QString Address::getStreetName() const {
    return streetName;
}
QString Address::getStreetNumber() const {
    return streetNumber;
}
QString Address::getTown() const {
    return town;
}
QString Address::getData() const{
    return streetName+streetNumber+town;
}
void Address::validate(){
    //tolgo spazi
    streetName.replace( ".", "" );
    streetName.replace( " ", "" );
    streetNumber.replace( "/", "" );
    streetNumber.replace( " ", "" );
    town.replace( " ", "" );
    //controllo che non ci siano numeri o caratteri speciali
    if(streetName.toStdString().find_first_of("0123456789") != std::string::npos || streetName.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,_;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("Via non valida,\nsono consentite solo lettere\ne il carattere .");
    }
    if(streetNumber.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || streetNumber.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("N.Civico non valido,\nsono consentiti solo numeri\ne il carattere /");
    }
    if(town.toStdString().find_first_of("0123456789") != std::string::npos || town.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("Comune non valida,\nsono consentite solo lettere");
    }
}
bool Address::checkLength() {
    if(streetName.length()<3 || town.length()<3)
        throw Exception("I campi utilizzati per calcolare\nla password, devono essere\nlunghi almeno 3 caratteri");
    QString s="0";
    if(streetNumber.length()<3)
        streetNumber = s.repeated(3-streetNumber.length()) + streetNumber;
    return true;
}

