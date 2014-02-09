#-------------------------------------------------
#
# Project created by QtCreator 2013-12-25T20:59:12
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = klavier
TEMPLATE = app

win32:RC_FILE += icone.rc

SOURCES += main.cpp\
        widget.cpp \
        mainwindow.cpp \
        botao.cpp \
        metronomo.cpp \
        sonora.cpp \
        ajuda_wid.cpp \
        BubbleSort.cpp

HEADERS  += widget.h \
        tecla_e_freq.h \
        mainwindow.h \
        botao.h \
        metronomo.h \
        sonora.h \
        ajuda_wid.h \
        BubbleSort.h

FORMS    += widget.ui \
        ajuda_wid.ui

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
    sounds/samples/g23.qrc \
    sounds/samples/v0.qrc \
    sounds/samples/v1.qrc \
    sounds/samples/v2.qrc \
    sounds/samples/v3.qrc \
    sounds/samples/v4.qrc \
    sounds/samples/v5.qrc \
    sounds/samples/v6.qrc \
    sounds/samples/v7.qrc \
    sounds/samples/v8.qrc \
    sounds/samples/v9.qrc \
    sounds/samples/v10.qrc \
    sounds/samples/v11.qrc \
    sounds/samples/v12.qrc \
    sounds/samples/v13.qrc \
    sounds/samples/v14.qrc \
    sounds/samples/v15.qrc \
    sounds/samples/v16.qrc \
    sounds/samples/v17.qrc \
    sounds/samples/v18.qrc \
    sounds/samples/v19.qrc \
    sounds/samples/v20.qrc \
    sounds/samples/v21.qrc \
    sounds/samples/v22.qrc \
    sounds/samples/v23.qrc \
    html_files.qrc

CONFIG += embed_manifest_exe
