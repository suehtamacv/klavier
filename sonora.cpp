#include "sonora.h"
#include "mainwindow.h"
#include <QKeyEvent>
#include <QSignalMapper>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QString>
#include <QTimer>
#include "tecla_e_freq.h"

sonora::sonora(QWidget *parn) : QWidget(parn) {
    parent = parn;

    _RAND_NUMBER_ = rand();

    Player = new QMediaPlayer[24];
    for (int i=0;i<100;i++) Musica[i][0]=Musica[i][1]=Musica[i][2]=0;
    criar_arq_temp();
    set_instrumento(sonora::Piano);
    Estado_Atual = Parado;
    Relogio_Master.start();
    Relogio_Inicio_Nota = new QTimer();
    Composicao_Criada=Notas_Tocadas=trono=0;
    for (int i = 0; i<=23 ; i++ ) {
        Player[i].setMedia(QMediaContent(QUrl::fromLocalFile(QDir::tempPath() + QString("/work") + QString::number(_RAND_NUMBER_) + "_" + QString::number(i) + QString(".mp3"))));
    }
    connect(this,SIGNAL(nota_tocada(int)),parent,SLOT(set_tecla_pressionada(int)));
    connect(this,SIGNAL(nota_parada(int)),parent,SLOT(set_tecla_solta(int)));
}

sonora::~sonora() {
    excluir_arq_temp();
    //delete Player;
}

void sonora::tocar_nota(QKeyEvent *event) {
    if (Estado_Atual == Tocando) {
        QMessageBox *erro = new QMessageBox();
        erro->setWindowTitle("ERRO!");
        erro->setText("Uma composição está sendo tocada no momento.");
        erro->exec();
    } else {
        int note = procurar_nota(event->key());
        if (note!=-1) {
            if (Player[note].state() == QMediaPlayer::StoppedState) Player[note].play();
        }
        if (Estado_Atual == Gravando){
            iniciar_gravacao(event);
        }
    }
}

void sonora::parar_nota(QKeyEvent *event){
    if (Estado_Atual != Tocando) {
        int note = procurar_nota(event->key());
        if (note!=-1) {
            if (Player[note].state() == QMediaPlayer::PlayingState)
                Player[note].stop();
        }
        if (Estado_Atual == Gravando){
            parar_gravacao(event);
        }
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

void sonora::criar_arq_temp() {
    Files = new QFile*[24];
    for (int i = 0; i<=23; i++) {
        Files[i] = new QFile(QDir::tempPath() + "/work" + QString::number(_RAND_NUMBER_) + "_" + QString::number(i) + ".mp3");
    }
}

void sonora::excluir_arq_temp() {
    for (int i=0 ; i<=23 ; i++) {
        QFile::remove(QDir::tempPath() + "/work" + QString::number(_RAND_NUMBER_) + "_" + QString::number(i) + ".mp3");
    }
}

void sonora::set_estado (Estado atual) {
    Estado_Atual = atual;
}

void sonora::iniciar_gravacao(QKeyEvent *evento){
    int note = procurar_nota(evento->key());
    if (note!=-1) {
       Musica[Num_Notas][0] = note; // Identifica a nota
       Musica[Num_Notas++][1] = Relogio_Master.msecsTo(QTime::currentTime());
    }
}

void sonora::parar_gravacao(QKeyEvent *evento){
    int note = procurar_nota(evento->key());
    if (note!=-1) {
        for (int i=0; i<Num_Notas ;i++) // Acha qual posição está vazia
        // A referência: Se a nota for a mesma e o tempo de duração for igual a zero ( não for preenchido)
        {
            if (Musica[i][0]==note && Musica[i][2]==0) {
                Musica[i][2] = Relogio_Master.msecsTo(QTime::currentTime()); // Preenche a terceira coluna ( Tempo de duração )
                qDebug() << "nota " + QString::number(Musica[i][0]) + " inicio " + QString::number(Musica[i][1]) + " fim " + QString::number(Musica[i][2]);
                break;
            }
        }

    }
}


long int sonora::Diferenca_tempo(int h1, int m1, int s1, int ms1, int h2, int m2, int s2, int ms2) {
    long int diferenca = 3600000*(h1-h2) + 60000*(m1-m2) + 1000*(s1-s2) + ms1 - ms2;
    if (diferenca<0) diferenca+=86400000;
    return diferenca;
}

void sonora::Gravar() {
    set_estado(Gravando);
    Num_Notas=0;
    Relogio_Master.restart();
}

void sonora::Parar() {
    if (Estado_Atual==Tocando) {
        set_estado(Parado);
        qDebug() << "stop play action";
    } else if (Estado_Atual==Gravando) {
        set_estado(Parado);
        if (Num_Notas!=0) Composicao_Criada=1;
        else Composicao_Criada=0;
    }
    for (int i=0;i<24;i++) {
        if (Player[i].state() == QMediaPlayer::PlayingState) {
            Player[i].stop();
            emit nota_parada(i);
        }
    }
}

int sonora::procurar_nota(int tecla) {
    int note;
    switch(tecla) {
        case C1: note = 0;break;
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
    return note;
}

int sonora::is_Composicao_Criada() {
    return Composicao_Criada;
}

int sonora::get_estado() {
    return Estado_Atual;
}

void sonora::salvar_arquivo(QString caminho) {
    if (Composicao_Criada==1) {
        QFile *Arquivo = new QFile(caminho);
        if (Arquivo->open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream saida(Arquivo);
            saida << Num_Notas << "\n";
            for (int i=0;i<Num_Notas;i++) {
                saida << Musica[i][0] << "\n" << Musica[i][1] << "\n" << Musica[i][2] << "\n";
            }
        } else {
            QMessageBox *erro = new QMessageBox();
            erro->setWindowTitle("ERRO!");
            erro->setText("Não foi possível salvar neste arquivo.");
        }
    }
}

void sonora::abrir_arquivo(QString caminho) {
    QFile *Arquivo = new QFile(caminho);
    if (Arquivo->open(QIODevice::ReadOnly)) {
        configurar_de_arquivo(Arquivo);
        Composicao_Criada=1;
    } else {
        QMessageBox *erro = new QMessageBox();
        erro->setWindowTitle("ERRO!");
        erro->setText("Não foi possível ler este arquivo.");
    }
}

void sonora::configurar_de_arquivo(QFile *Arquivo) {
    QTextStream entrada(Arquivo);
    Num_Notas = entrada.readLine().toInt();
    qDebug() << "notas " + QString::number(Num_Notas);
    for (int i=0;i<Num_Notas;i++) {
        Musica[i][0] = entrada.readLine().toInt();
        Musica[i][1] = entrada.readLine().toInt();
        Musica[i][2] = entrada.readLine().toInt();
        qDebug() << "tempo " + QString::number(Musica[i][0]);
    }
    Arquivo->close();
}

void sonora::Play() {
    if (Composicao_Criada==0) {
        QMessageBox *erro = new QMessageBox();
        erro->setWindowTitle("ERRO!");
        erro->setText("Não há nenhuma composição criada.");
        erro->exec();
        emit reproducao_terminada();
    } else {
        for (int i=0;i<24;i++) if (Player[i].state() == QMediaPlayer::PlayingState) Player[i].stop();
        set_estado(Tocando);
        Notas_Tocadas=0;
        Relogio_Master.start();
        Relogio_Inicio_Nota->singleShot(Musica[0][1],this,SLOT(tocar_nota_gravada()));
    }
}

void sonora::tocar_nota_gravada() {
    if (Player[Musica[Notas_Tocadas][0]].state() == QMediaPlayer::StoppedState) Player[Musica[Notas_Tocadas][0]].play();
    emit nota_tocada(Musica[Notas_Tocadas][0]);
    Notas_Tocadas++;
    if (Notas_Tocadas!=Num_Notas) {
        Relogio_Inicio_Nota->singleShot(Musica[Notas_Tocadas][1] - Musica[Notas_Tocadas-1][1],this,SLOT(tocar_nota_gravada()));
    }
}
