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
    void set_bpm(float);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

public slots:
    void Adiciona_Botao_Metronomo();
    void set_tecla_pressionada(int);
    void set_tecla_solta(int);

private slots:
    // Funções
    void Composicao();
    void Abrir();
    void Fechar();
    void Salvar();
    void Metronomo();
    void Manual();
    void Instrumento_1();
    void Instrumento_2();
    void Instrumento_3();
    void Ajuda();
    void Sobre();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void play_metronomo();
    void play_metronomo(int);
    void Gravar();
    void Parar();
    void Play();


private:
    void set_buttons();
    float BPM;
    int isBPM, isMetronomo;
// Isso é necessário para poder fazer as ações
    void createActions();
    void createMenus();
// São as abas de menu
    QMenu *ArquivoMenu;
    QMenu *editMenu;
    QMenu *TimbreMenu;
    QMenu *AjudaMenu;
    QMenu *MetronomoMenu; //
// Cada Ação correspondente a uma função, para diferenciar das funções coloquei " _A "
// Esses elementos serão chamados no menu
    QAction *Composicao_A;
    QAction *Abrir_A;
    QAction *Salvar_A;
    QAction *Sair_A;
    QAction *Metronomo_A;
    QAction *Manual_A; //
    QAction *Instrumento_1_A;
    QAction *Instrumento_2_A;
    QAction *Instrumento_3_A;
    QAction *Ajuda_A;
    QAction *Sobre_A;
    Widget *piano;
    metronomo *wid_metronomo;
    QHBoxLayout *buttons;
    QSound *clique;
    QCheckBox *metr;
    sonora *sound;
};

#endif // MAINWINDOW_H
