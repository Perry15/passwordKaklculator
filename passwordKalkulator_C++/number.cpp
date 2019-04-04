#include "exception.h"
#include "number.h"

Number::Number(QString n) : startingData(5), numb(n) {}
Number::~Number() {}
QString Number::getNumber() const{
    return numb;
}
QString Number::getData() const{
    return numb;
}
void Number::validate(){
    //tolgo spazi
    numb.replace( " ", "" );
    //controllo che non ci siano numeri o caratteri speciali
    if(numb.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || numb.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){
        throw Exception("Numero non valido,\nsono consentiti solo numeri");
    }
}
bool Number::checkLength(){
    QString s="0";
    if(numb.length()<3)
        numb = s.repeated(3-numb.length()) + numb;
    return true;
}
