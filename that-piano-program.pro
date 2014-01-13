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
        widget.cpp \
    mainwindow.cpp \
    botao.cpp \
    metronomo.cpp \
    sonora.cpp

HEADERS  += widget.h \
    tecla_e_freq.h \
    mainwindow.h \
    botao.h \
    metronomo.h \
    sonora.h

FORMS    += widget.ui

RESOURCES += \
    icons.qrc \
    sounds/samples/p0.qrc \
    sounds/samples/p1.qrc \
    sounds/samples/p2.qrc \
    sounds/samples/p3.qrc \
    sounds/samples/p4.qrc \
    sounds/samples/p5.qrc \
    sounds/samples/p6.qrc \
    sounds/samples/p7.qrc \
    sounds/samples/p8.qrc \
    sounds/samples/p9.qrc \
    sounds/samples/p10.qrc \
    sounds/samples/p11.qrc \
    sounds/samples/p12.qrc \
    sounds/samples/p13.qrc \
    sounds/samples/p14.qrc \
    sounds/samples/p15.qrc \
    sounds/samples/p16.qrc \
    sounds/samples/p17.qrc \
    sounds/samples/p18.qrc \
    sounds/samples/p19.qrc \
    sounds/samples/p20.qrc \
    sounds/samples/p21.qrc \
    sounds/samples/p22.qrc \
    sounds/samples/p23.qrc \
    sounds/samples/g0.qrc \
    sounds/samples/g1.qrc \
    sounds/samples/g2.qrc \
    sounds/samples/g3.qrc \
    sounds/samples/g4.qrc \
    sounds/samples/g5.qrc \
    sounds/samples/g6.qrc \
    sounds/samples/g7.qrc \
    sounds/samples/g8.qrc \
    sounds/samples/g9.qrc \
    sounds/samples/g10.qrc \
    sounds/samples/g11.qrc \
    sounds/samples/g12.qrc \
    sounds/samples/g13.qrc \
    sounds/samples/g14.qrc \
    sounds/samples/g15.qrc \
    sounds/samples/g16.qrc \
    sounds/samples/g17.qrc \
    sounds/samples/g18.qrc \
    sounds/samples/g19.qrc \
    sounds/samples/g20.qrc \
    sounds/samples/g21.qrc \
    sounds/samples/g22.qrc \
    sounds/samples/g23.qrc

OTHER_FILES +=
