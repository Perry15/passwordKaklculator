#include "password.h"
#include<iostream>
using namespace std;
Password::Password(QString p, int l) : pwd(p), len(l) {}

Password::~Password() {}

QString Password::getPassword() const{
    return pwd;
}
void Password::setPassword(QString p){
    pwd=p;
}
int Password::getLength() const{
    return len;
}
void Password::setLength(int l){
    len=l;
}

QString Password::inversion(QString s){
    string str=s.toStdString();
    int n=str.length();
    for(int i=0; i<n/2;++i){
        char tmp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=tmp;
    }
    return QString::fromStdString(str);

}
