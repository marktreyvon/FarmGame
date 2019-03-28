#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T08:28:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FarmGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classimplement.cpp \
    farmstore.cpp \
    farmbackpack.cpp \
    windowbuy.cpp \
    formsimpestore.cpp

HEADERS  += mainwindow.h \
    mainclass.h \
    farmstore.h \
    farmbackpack.h \
    windowbuy.h \
    formsimpestore.h

FORMS    += mainwindow.ui \
    farmstore.ui \
    farmbackpack.ui \
    windowbuy.ui \
    formsimpestore.ui

RESOURCES += \
    farmresouces.qrc
