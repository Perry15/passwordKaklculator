#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T18:18:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = passwordKalkulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    address.cpp \
    date.cpp \
    exception.cpp \
    frameLeft.cpp \
    frameRight.cpp \
    grafica.cpp \
    lev0.cpp \
    lev1.cpp \
    lev2.cpp \
    lev3.cpp \
    namesurname.cpp \
    number.cpp \
    password.cpp \
    startingdata.cpp \
    word.cpp

HEADERS += \
    startingdata.h \
    address.h \
    date.h \
    exception.h \
    frameLeft.h \
    frameRight.h \
    grafica.h \
    lev0.h \
    lev1.h \
    lev2.h \
    lev3.h \
    namesurname.h \
    number.h \
    password.h \
    word.h

FORMS +=

RESOURCES += \
    resources.qrc
