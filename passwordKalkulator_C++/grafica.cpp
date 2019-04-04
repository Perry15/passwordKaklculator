#include "exception.h"
#include "grafica.h"
#include <QGridLayout>
//#include <QGroupBox>

grafica::grafica(int width, int height, QWidget* parent) : QWidget(parent) {
    c = new frameRight(width,height,this);
    QGridLayout *mainGrid = new QGridLayout(this);
    mainGrid->addWidget(c->createLeftGroup(),0,0,Qt::AlignTop);
    mainGrid->setRowStretch(0,0);
    mainGrid->addWidget(c->createRightGroup(),0,1,Qt::AlignTop);
    this->setLayout(mainGrid);
}

grafica::~grafica(){
    delete c;
}


