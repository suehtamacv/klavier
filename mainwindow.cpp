#include "mainwindow.h"
#include "metronomo.h"
#include "tecla_e_freq.h"
#include <stdlib.h>
#include "widget.h"
#include <QKeyEvent>
#include <QIcon>
#include "botao.h"
#include <QString>
#include <QtWidgets>
#include <QFileDialog>
#include <QSound>
#include <QTimer>

MainWindow::MainWindow() {
    BPM=0;
    isBPM=0;

    sound = new sonora();
    clique = new QSound(":/sounds/click.wav");

    QWidget *widget = new QWidget; // Criando a barra principal
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget; // Criando as "cascatas" verticais de "Arquivo" e "Editar"
    topFiller->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    topFiller->setMinimumSize(0,0);

    QWidget *middle = new QWidget;
    middle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    middle->setFixedWidth(710);
    middle->setFixedHeight(214);

    QWidget *bottomFiller = new QWidget;  // Criando a "cascata" horizontal de "Timbre"
    bottomFiller->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    bottomFiller->setMinimumSize(0,0);

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *hlayout = new QHBoxLayout;

    vlayout->setMargin(0);
    vlayout->addWidget(topFiller);
    vlayout->addWidget(middle);
    set_buttons();
    vlayout->addLayout(buttons);
    vlayout->addWidget(bottomFiller);

    hlayout->setMargin(0);
    hlayout->addWidget(topFiller);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(bottomFiller);
    widget->setLayout(hlayout);

    createActions();
    createMenus();

    setWindowTitle(tr("That Piano Program"));
    setMinimumSize(712, 300);
    resize(712,300);
    setWindowIcon(QIcon(tr(":/pics/ico500px.png")));

    piano = new Widget(middle);
}

MainWindow::~MainWindow() {
    delete piano;
    delete sound;
    close();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) // Aqui será as funções das ações ( Ou métodos, como preferir chamar )
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}

void MainWindow::Composicao()
{
    // Função
}

void MainWindow::Abrir()
{
    QFileDialog *abrir_arquivo = new QFileDialog(this);
    QString caminho = abrir_arquivo->getOpenFileName(this,tr("Abrir Arquivo"),".",tr("Images (*.jpg *.png)"));
    delete abrir_arquivo;
}

void MainWindow::Salvar()
{
    QFileDialog *salvar_arquivo = new QFileDialog(this);
    QString caminho = salvar_arquivo->getSaveFileName(this,tr("Salvar Arquivo"),".",tr("Images (*.jpg *.png)"));
    delete salvar_arquivo;
}

void MainWindow::Metronomo() {
    wid_metronomo = new metronomo(this);
    wid_metronomo->setAttribute(Qt::WA_DeleteOnClose);
    connect(this,SIGNAL(destroyed()),wid_metronomo,SLOT(fechar()));
}

void MainWindow::Oitava()
{
    // Função
}

void MainWindow::Instrumento_1()
{
    // Função
}

void MainWindow::Instrumento_2()
{
    // Função
}

void MainWindow::Instrumento_3()
{
    // Função
}


void MainWindow::createActions() // Aqui são as ações que deverão está conectadas com as funções
{
    Composicao_A = new QAction("Novo",this); // Isso é o que será exibido no Menu
 /* Composicao_A->setShortcuts(QKeySequence::New);*/ //Esse comando apresenta o atalho na tela
 /* Composicao_A->setStatusTip("Cria um novo Arquivo");*/ // Esse Comando dá uma breve informação no canto inferior da tela
    connect(Composicao_A, SIGNAL(triggered()), this, SLOT(Composicao()));

    Abrir_A = new QAction("Abrir", this);
 /* Abrir_A->setShortcuts(QKeySequence::Abrir); */ // Deixarei Optativo
/*  Abrir_A->setStatusTip("Abre um arquivo"); */ // Deixarei Optativo
    connect(Abrir_A, SIGNAL(triggered()), this, SLOT(Abrir()));

    Salvar_A = new QAction("Salvar", this);
/*  Salvar_A->setShortcuts(QKeySequence::Salvar); */ // Deixarei Optativo
/*  Salvar_A->setStatusTip("Salvar Composição)); */ // Deixarei Optativo
    connect(Salvar_A, SIGNAL(triggered()), this, SLOT(Salvar()));



    Sair_A = new QAction("Sair", this);
/*  Sair_A->setShortcuts(QKeySequence::Quit); */ // Deixarei Optativo
/*  Sair_A->setStatusTip("Sair do programa"); */ // Deixarei Optativo
    connect(Sair_A, SIGNAL(triggered()), this, SLOT(Fechar())); // Esse já pega tranquilo, sem função

    Metronomo_A = new QAction("Ajustar Metronômo", this);

/* Os atalhos ja são definidos pelo sistema, por isso deixei optativo. No caso dos comando de Editar,
se usarmos atalhos teremos de criar os próprios atalhos. Eu acho melhor deixar sem */

/*  Metronomo_A->setStatusTip("Altera O tempo do Metrônomo"); */ // Deixarei Optativo
    connect(Metronomo_A, SIGNAL(triggered()), this, SLOT(Metronomo()));

    Oitava_A = new QAction("Alterar Oitava", this);
    /* Os atalhos ja são definidos pelo sistema, por isso deixei optativo. No caso dos comando de Editar,
    se usarmos atalhos teremos de criar os próprios atalhos. Eu acho melhor deixar sem */
/*  Oitava_A->setStatusTip(" Muda a oitava "); */ // Deixarei Optativo
    connect(Oitava_A, SIGNAL(triggered()), this, SLOT(Oitava()));

/* Essa Opção de Editar é uma sugestão ! ( mudar o instrumento ) */

    Instrumento_1_A = new QAction("Instrumento 1", this);
/*  Instrumento_1_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_1_A, SIGNAL(triggered()), this, SLOT(Instrumento_1()));


    Instrumento_2_A = new QAction("Instrumento 2", this);
/*  Instrumento_2_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_2_A, SIGNAL(triggered()), this, SLOT(Instrumento_2()));



    Instrumento_3_A = new QAction("Instrumento 3", this);
/*  Instrumento_3_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_3_A, SIGNAL(triggered()), this, SLOT(Instrumento_3()));

}

void MainWindow::createMenus() // Configurando como fica no Menu!
{
    ArquivoMenu = menuBar()->addMenu("Arquivo");
    ArquivoMenu->addAction(Composicao_A);
    ArquivoMenu->addAction(Abrir_A);
    ArquivoMenu->addAction(Salvar_A);

    ArquivoMenu->addSeparator(); // Esse comando Adiciona uma barrinha divisoria
    ArquivoMenu->addAction(Sair_A);

    editMenu = menuBar()->addMenu("Editar");
    editMenu->addAction(Metronomo_A);
    editMenu->addAction(Oitava_A);


    TimbreMenu = editMenu->addMenu("Timbre");  // Esse Adiciona um menu dentro de outro
    TimbreMenu->addAction(Instrumento_1_A);
    TimbreMenu->addAction(Instrumento_2_A);
    TimbreMenu->addAction(Instrumento_3_A);

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    piano->tratar_tecla_pressionada(event);
    sound->tocar_nota(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    piano->tratar_tecla_solta(event);
    sound->parar_nota(event);
}

void MainWindow::set_buttons() {
    Botao *record = new Botao();
    Botao *play = new Botao();
    Botao *stop = new Botao();
    Botao *pause = new Botao();
    record->setIcon(QIcon(QPixmap(":/pics/record.png")));
    record->setIconSize(QSize(20,20));
    record->setFixedSize(50,50);
    record->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    play->setIcon(QIcon(QPixmap(":/pics/play.png")));
    play->setIconSize(QSize(20,20));
    play->setFixedSize(50,50);
    play->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pause->setIcon(QIcon(QPixmap(":/pics/pause.png")));
    pause->setIconSize(QSize(20,20));
    pause->setFixedSize(50,50);
    pause->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pause->setEnabled(false);
    stop->setIcon(QIcon(QPixmap(":/pics/stop.png")));
    stop->setIconSize(QSize(20,20));
    stop->setFixedSize(50,50);
    stop->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    stop->setEnabled(false);
    buttons = new QHBoxLayout;
    buttons->setMargin(5);
    buttons->addWidget(play);
    buttons->addWidget(pause);
    buttons->addWidget(record);
    buttons->addWidget(stop);

    connect(play,SIGNAL(clicked()),pause,SLOT(ativar()));
    connect(play,SIGNAL(clicked()),play,SLOT(desativar()));
    connect(play,SIGNAL(clicked()),record,SLOT(desativar()));
    connect(play,SIGNAL(clicked()),stop,SLOT(ativar()));
    connect(pause,SIGNAL(clicked()),play,SLOT(ativar()));
    connect(pause,SIGNAL(clicked()),pause,SLOT(desativar()));
    connect(pause,SIGNAL(clicked()),record,SLOT(desativar()));
    connect(stop,SIGNAL(clicked()),record,SLOT(ativar()));
    connect(stop,SIGNAL(clicked()),stop,SLOT(desativar()));
    connect(stop,SIGNAL(clicked()),pause,SLOT(desativar()));
    connect(stop,SIGNAL(clicked()),play,SLOT(ativar()));
    connect(record,SIGNAL(clicked()),stop,SLOT(ativar()));
    connect(record,SIGNAL(clicked()),record,SLOT(desativar()));
    connect(record,SIGNAL(clicked()),play,SLOT(desativar()));
    connect(record,SIGNAL(clicked()),pause,SLOT(desativar()));

//    return buttons;
}

void MainWindow::Fechar() {
    this->destroy(true,true);
    this->~MainWindow();
}

void MainWindow::Adiciona_Botao_Metronomo() {
    BPM = wid_metronomo->get_bpm();
    if (BPM!=0) {
        if (isBPM==0) {
            metr = new QCheckBox(this);
            metr->setIconSize(QSize(30,30));
            metr->setFixedSize(60,50);
            metr->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
            metr->setIcon(QIcon(QPixmap(":/pics/metronomo.png")));
            buttons->addWidget(metr);
            connect(metr,SIGNAL(stateChanged(int)),this,SLOT(play_metronomo(int)));
            isBPM=1;
        }
    }
}

void MainWindow::play_metronomo(int) {
    float frequencia = 60.0 / BPM;
    if (metr->isChecked()) { //botao ativo
        if (BPM == 0) {
            Metronomo();
        } else {
                if(clique->isFinished()) {
                    clique->play();
                    QTimer::singleShot(1000*frequencia,this,SLOT(play_metronomo()));
                }
        }
    } else {
        clique->stop();
    }
}

void MainWindow::play_metronomo() {
    this->play_metronomo(0);
}
