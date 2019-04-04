#include "grafica.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //per mettere un icona
    a.setWindowIcon(QIcon(":/icon.png"));

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int width = screenGeometry.width()/1.8;
    int height = screenGeometry.height()/2;

    grafica g(width, height);
    g.setWindowTitle("passwordKalkulator");
    g.setGeometry((screenGeometry.width() - width)/2, height/5, width, height);
    g.show();

    return a.exec();
}
