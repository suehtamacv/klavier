#include "tecla_e_freq.h"
#include <QKeyEvent>
#include "som.h"
#include <QDir>
#include <QUrl>
#include <QString>

sonora::sonora(){
   int i =0;

    Player = new QMediaPlayer[24];


    for ( i = 0; i<=23 ; i++){

    Players[i].setMedia(QMediaContent(QUrl::fromLocalFile(QDir::currentPath() + QString::tr("/sounds/Amostras/Piano/") + QString::number(i) + QString::tr(".mp3")));
    Player[i].setVolume(50);

    }


}
sonora::~sonora() {

    delete sonora;

}

void sonora::tocar_nota(QKeyEvent *event) {
    switch(event->key()) {

        case C1: Player[0].play(); break;
        case Cs1: Player[1].play(); break;
        case D1: Player[2].play(); break;
        case Ds1: Player[3].play(); break;
        case E1: Player[4].play(); break;
        case F1: Player[5].play(); break;
        case Fs1: Player[6].play(); break;
        case G1: Player[7].play(); break;
        case Gs1: Player[8].play(); break;
        case A1: Player[9].play(); break;
        case As1: Player[10].play(); break;
        case B1: Player[11].play(); break;
        case C2: Player[12].play(); break;
        case Cs2: Player[13].play(); break;
        case D2: Player[14].play(); break;
        case Ds2: Player[15].play(); break;
        case E2: Player[16].play(); break;
        case F2: Player[17].play(); break;
        case Fs2: Player[18].play(); break;
        case G2: Player[19].play(); break;
        case Gs2: Player[20].play(); break;
        case A2: Player[21].play(); break;
        case As2: Player[22].play(); break;
        case B2: Player[23].play(); break;
    }
}

void sonora::parar_nota(QKeyEvent *){
    switch(event->key()) {

       case C1: Player[0].stop(); break;
       case Cs1: Player[1].stop(); break;
       case D1: Player[2].stop(); break;
       case Ds1: Player[3].stop(); break;
       case E1: Player[4].stop(); break;
       case F1: Player[5].stop(); break;
       case Fs1: Player[6].stop(); break;
       case G1: Player[7].stop(); break;
       case Gs1: Player[8].stop(); break;
       case A1: Player[9].stop(); break;
       case As1: Player[10].stop(); break;
       case B1: Player[11].stop(); break;
       case C2: Player[12].stop(); break;
       case Cs2: Player[13].stop(); break;
       case D2: Player[14].stop(); break;
       case Ds2: Player[15].stop(); break;
       case E2: Player[16].stop(); break;
       case F2: Player[17].stop(); break;
       case Fs2: Player[18].stop(); break;
       case G2: Player[19].stop(); break;
       case Gs2: Player[20].stop(); break;
       case A2: Player[21].stop(); break;
       case As2: Player[22].stop(); break;
       case B2: Player[23].stop(); break;
    }
}
