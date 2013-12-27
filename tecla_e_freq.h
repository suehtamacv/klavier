#ifndef TECLA_E_FREQ_H
#define TECLA_E_FREQ_H

#include "widget.h"

enum Notas {
    C=Qt::Key_A,Cs=Qt::Key_W,D=Qt::Key_S,Ds=Qt::Key_E,E=Qt::Key_D,F=Qt::Key_F,Fs=Qt::Key_T,G=Qt::Key_G,
    Gs=Qt::Key_Y,A=Qt::Key_H,As=Qt::Key_U,B=Qt::Key_J,
};

enum FreqNotas {
    nC4=262, nCs4=277, nD4=294, nDs4=311, nE4=330, nF4=350, nFs4=370, nG4=392, nGs4=415, nA4=440, nAs4=466, nB4=494
};

#endif // TECLA_E_FREQ_H
