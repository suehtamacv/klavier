#-------------------------------------------------
#
# Project created by QtCreator 2013-12-25T20:59:12
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = that-piano-program
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    tecla_e_freq.h

FORMS    += widget.ui
