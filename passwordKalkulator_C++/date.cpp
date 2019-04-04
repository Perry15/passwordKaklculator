#include "date.h"
#include "exception.h"

Date::Date(QString d, QString m, QString y): startingData(2), day(d),
    month(m), year(y) {}

Date::~Date() {}

QString Date::getDay() const{
    return day;
}
QString Date::getMonth() const{
    return month;
}
QString Date::getYear() const{
    return year;
}
QString Date::getData() const{
    return day+month+year;
}

//per Date checkLength e validate non servirebbero
bool Date::checkLength() {
    //la lunghezza della data è compresa tra 6 e 8 quindi non può essere <6 o >8
    //perche QDateEdit elimina se ci sono zeri davanti al giorno o al mese
    if((day+month+year).length()<6 || (day+month+year).length()>8)
        throw Exception("errore lunghezza data");
    return true;
}
void Date::validate(){
    //tolgo spazi
    day.replace( " ", "" );
    month.replace( " ", "" );
    year.replace( " ", "" );
    //controllo che non ci siano numeri o caratteri speciali
    if(day.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || day.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se non ci sono solo numeri
        throw Exception("Giorno non valido,\nsono consentiti solo numeri");
    }
    if(month.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || month.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se non ci sono solo numeri
        throw Exception("Mese non valido,\nsono consentiti solo numeri");
    }
    if(year.toStdString().find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos || year.toStdString().find_first_of("\\|&<>`~!£$%/()=?^'[]{}*+-#@°ç,._;:\"") != std::string::npos){//se non ci sono solo numeri
        throw Exception("Anno non valido,\nsono consentiti solo numeri");
    }

}
