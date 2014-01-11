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
    resources.qrc

OTHER_FILES += \
    sounds/Amostras/Piano/0.mp3 \
    sounds/Amostras/Piano/1.mp3 \
    sounds/Amostras/Piano/2.mp3 \
    sounds/Amostras/Piano/3.mp3 \
    sounds/Amostras/Piano/4.mp3 \
    sounds/Amostras/Piano/5.mp3 \
    sounds/Amostras/Piano/6.mp3 \
    sounds/Amostras/Piano/7.mp3 \
    sounds/Amostras/Piano/8.mp3 \
    sounds/Amostras/Piano/9.mp3 \
    sounds/Amostras/Piano/10.mp3 \
    sounds/Amostras/Piano/11.mp3 \
    sounds/Amostras/Piano/12.mp3 \
    sounds/Amostras/Piano/13.mp3 \
    sounds/Amostras/Piano/14.mp3 \
    sounds/Amostras/Piano/15.mp3 \
    sounds/Amostras/Piano/16.mp3 \
    sounds/Amostras/Piano/17.mp3 \
    sounds/Amostras/Piano/18.mp3 \
    sounds/Amostras/Piano/19.mp3 \
    sounds/Amostras/Piano/20.mp3 \
    sounds/Amostras/Piano/21.mp3 \
    sounds/Amostras/Piano/22.mp3 \
    sounds/Amostras/Piano/23.mp3
