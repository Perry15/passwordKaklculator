#ifndef GRAFICA_H
#define GRAFICA_H


#include <QWidget>
#include "frameLeft.h"
#include "frameRight.h"

class grafica : public QWidget {
    Q_OBJECT
public:
    grafica(int width, int height, QWidget* parent=0);
    ~grafica();
private:
    frameRight *c;
};

#endif // GRAFICA_H
