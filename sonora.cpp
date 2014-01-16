#include <QKeyEvent>
#include "sonora.h"
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QString>
#include "tecla_e_freq.h"

sonora::sonora() {
    Player = new QMediaPlayer[24];
    create_temp_files();
    set_instrumento(sonora::Piano);
    for (int i = 0; i<=23 ; i++ ) {
        Player[i].setMedia(QMediaContent(QUrl::fromLocalFile(QDir::tempPath() + QString("/work") + QString::number(i) + QString(".mp3"))));
    }
}

sonora::~sonora() {
    delete_temp_files();
    //delete Player;
}

void sonora::tocar_nota(QKeyEvent *event) {
    int note;
    switch(event->key()) {
        case C1: note = 0; break;
        case Cs1: note = 1; break;
        case D1: note = 2; break;
        case Ds1: note = 3; break;
        case E1: note = 4; break;
        case F1: note = 5; break;
        case Fs1: note = 6; break;
        case G1: note = 7; break;
        case Gs1: note = 8; break;
        case A1: note = 9; break;
        case As1: note = 10; break;
        case B1: note = 11; break;
        case C2: note = 12; break;
        case Cs2: note = 13; break;
        case D2: note = 14; break;
        case Ds2: note = 15; break;
        case E2: note = 16; break;
        case F2: note = 17; break;
        case Fs2: note = 18; break;
        case G2: note = 19; break;
        case Gs2: note = 20; break;
        case A2: note = 21; break;
        case As2: note = 22; break;
        case B2: note = 23; break;
        default: note = -1;
    }

    if (note!=-1) {
        if (Player[note].state() != QMediaPlayer::PlayingState) Player[note].play();
    }
}

void sonora::parar_nota(QKeyEvent *event){
    int note;
    switch(event->key()) {
        case C1: note = 0; break;
        case Cs1: note = 1; break;
        case D1: note = 2; break;
        case Ds1: note = 3; break;
        case E1: note = 4; break;
        case F1: note = 5; break;
        case Fs1: note = 6; break;
        case G1: note = 7; break;
        case Gs1: note = 8; break;
        case A1: note = 9; break;
        case As1: note = 10; break;
        case B1: note = 11; break;
        case C2: note = 12; break;
        case Cs2: note = 13; break;
        case D2: note = 14; break;
        case Ds2: note = 15; break;
        case E2: note = 16; break;
        case F2: note = 17; break;
        case Fs2: note = 18; break;
        case G2: note = 19; break;
        case Gs2: note = 20; break;
        case A2: note = 21; break;
        case As2: note = 22; break;
        case B2: note = 23; break;
        default: note = -1;
    }

    if (note!=-1) {
        if (Player[note].state() != QMediaPlayer::StoppedState) Player[note].stop();
    }
}

void sonora::set_instrumento(Instrumentos I) {
    switch (I){
        case Piano:
            for ( int i = 0; i<=23 ; i++){
                QFile piano(":/sounds/samples/p" + QString::number(i) + ".mp3");
                if (Files[i]->open(QIODevice::ReadWrite)) {
                    if (piano.open(QIODevice::ReadOnly)) {
                        Files[i]->write(piano.readAll());
                        piano.close();
                    }
                    Files[i]->close();
                }
            }
            break;

        case Guitarra:
            for ( int i = 0; i<=23 ; i++){
                QFile guitarra(":/sounds/samples/g" + QString::number(i) + ".mp3");
                if (Files[i]->open(QIODevice::ReadWrite)) {
                    if (guitarra.open(QIODevice::ReadOnly)) {
                        Files[i]->write(guitarra.readAll());
                        guitarra.close();
                    }
                    Files[i]->close();
                }
            }
            break;

        case Whatever: //por enquanto coloca GUITARRA
            for ( int i = 0; i<=23 ; i++){
                QFile whatever(":/sounds/samples/g" + QString::number(i) + ".mp3");
                if (Files[i]->open(QIODevice::ReadWrite)) {
                    if (whatever.open(QIODevice::ReadOnly)) {
                        Files[i]->write(whatever.readAll());
                        whatever.close();
                    }
                    Files[i]->close();
                }
            }
            break;
    }

}

void sonora::create_temp_files() {
    Files = new QFile*[24];
    for (int i = 0; i<=23; i++) {
        Files[i] = new QFile(QDir::tempPath() + "/work" + QString::number(i) + ".mp3");
    }
}

void sonora::delete_temp_files() {
    for (int i=0 ; i<=23 ; i++) {
        QFile::remove(QDir::tempPath() + "/work" + QString::number(i) + ".mp3");
    }
}

