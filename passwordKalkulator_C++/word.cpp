#include "word.h"
#include "exception.h"

Word::Word(QString s) : startingData(4), str(s) {}
Word::~Word() {}
QString Word::getWord() const{
    return str;
}
QString Word::getData() const{
    return str;
}
void Word::validate(){
    //tolgo spazi
    str.replace( " ", "" );
    //controllo che non ci siano numeri o caratteri speciali
    if(str.toStdString().find_first_of("0123456789") != std::string::npos || str.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se ci sono numeri
        throw Exception("Parola non valida,\nsono consentite solo lettere");
    }
}
bool Word::checkLength() {
    if(str.length()<3)
        throw Exception("I campi utilizzati per calcolare\nla password, devono essere\nlunghi almeno 3 caratteri");
    return true;
}
