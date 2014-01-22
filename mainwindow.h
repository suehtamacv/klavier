#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QSound>
#include <QHBoxLayout>
#include "widget.h"
#include "metronomo.h"
#include "sonora.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow();
        ~MainWindow();

    protected:
        void contextMenuEvent(QContextMenuEvent *event);

    public slots:
        void Adiciona_Botao_Metronomo();
        void set_tecla_pressionada(int);
        void set_tecla_solta(int);

    private slots:
        void Abrir();
        void Ajuda();
        void Fechar();
        void Gravar();
        void Instrumento_1();
        void Instrumento_2();
        void Instrumento_3();
        void keyPressEvent(QKeyEvent *);
        void keyReleaseEvent(QKeyEvent *);
        void Manual();
        void Metronomo();
        void Parar();
        void Play();
        void play_metronomo();
        void Salvar();
        void Sobre();

    private:
        int isBPM, isMetronomo;
        float BPM;
        metronomo *wid_metronomo;
        QAction *Abrir_A, *Ajuda_A, *Instrumento_1_A, *Instrumento_2_A, *Instrumento_3_A, *Manual_A, *Metronomo_A,
                *Salvar_A, *Sair_A, *Sobre_A;
        QCheckBox *metr;
        QHBoxLayout *buttons;
        QMenu *ArquivoMenu, *editMenu, *TimbreMenu, *AjudaMenu, *MetronomoMenu;
        QSound *clique;
        sonora *sound;
        Widget *piano;

        void createActions();
        void createMenus();
        void set_buttons();
};

#endif // MAINWINDOW_H
