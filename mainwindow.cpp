#include "mainwindow.h"
#include "tecla_e_freq.h"
#include <QKeyEvent>
#include <QtWidgets>
#include <widget.h>

MainWindow::MainWindow() {
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
    vlayout->addWidget(bottomFiller);

    hlayout->setMargin(0);
    hlayout->addWidget(topFiller);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(bottomFiller);
    widget->setLayout(hlayout);

    createActions();
    createMenus();

    setWindowTitle(tr("That Piano Project"));
    setMinimumSize(712, 216);
    resize(712,216);

    piano = new Widget(middle);
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
    // Função
}

void MainWindow::Salvar()
{
    // Função
}

void MainWindow::Metronomo()
{
    // Função
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
    Composicao_A = new QAction("Nova Composição",this); // Isso é o que será exibido no Menu
 /* Composicao_A->setShortcuts(QKeySequence::New);*/ //Esse comando apresenta o atalho na tela
 /* Composicao_A->setStatusTip("Cria um novo Arquivo");*/ // Esse Comando dá uma breve informação no canto inferior da tela
    connect(Composicao_A, SIGNAL(triggered()), this, SLOT(/*função de novo arquivo*/));

    Abrir_A = new QAction("Abrir", this);
 /* Abrir_A->setShortcuts(QKeySequence::Abrir); */ // Deixarei Optativo
/*  Abrir_A->setStatusTip("Abre um arquivo"); */ // Deixarei Optativo
    connect(Abrir_A, SIGNAL(triggered()), this, SLOT(/*Função para Abrir */));

    Salvar_A = new QAction("Salvar", this);
/*  Salvar_A->setShortcuts(QKeySequence::Salvar); */ // Deixarei Optativo
/*  Salvar_A->setStatusTip("Salvar Composição)); */ // Deixarei Optativo
    connect(Salvar_A, SIGNAL(triggered()), this, SLOT(/*Função para salvar*/));



    Sair_A = new QAction("Sair", this);
/*  Sair_A->setShortcuts(QKeySequence::Quit); */ // Deixarei Optativo
/*  Sair_A->setStatusTip("Sair do programa"); */ // Deixarei Optativo
    connect(Sair_A, SIGNAL(triggered()), this, SLOT(close())); // Esse já pega tranquilo, sem função

    Metronomo_A = new QAction("Ajustar Metronômo", this);

/* Os atalhos ja são definidos pelo sistema, por isso deixei optativo. No caso dos comando de Editar,
se usarmos atalhos teremos de criar os próprios atalhos. Eu acho melhor deixar sem */

/*  Metronomo_A->setStatusTip("Altera O tempo do Metrônomo"); */ // Deixarei Optativo
    connect(Metronomo_A, SIGNAL(triggered()), this, SLOT(/*função que altera Metrônomo */));

    Oitava_A = new QAction("Alterar Oitava", this);
    /* Os atalhos ja são definidos pelo sistema, por isso deixei optativo. No caso dos comando de Editar,
    se usarmos atalhos teremos de criar os próprios atalhos. Eu acho melhor deixar sem */
/*  Oitava_A->setStatusTip(" Muda a oitava "); */ // Deixarei Optativo
    connect(Oitava_A, SIGNAL(triggered()), this, SLOT(/*Função de alterar Oitavas*/));

/* Essa Opção de Editar é uma sugestão ! ( mudar o instrumento ) */

    Instrumento_1_A = new QAction("Instrumento 1", this);
/*  Instrumento_1_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_1_A, SIGNAL(triggered()), this, SLOT(/* Função para mudar os arquivos de som */));


    Instrumento_2_A = new QAction("Instrumento 2", this);
/*  Instrumento_2_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_2_A, SIGNAL(triggered()), this, SLOT(/* Função para mudar os arquivos de som */));



    Instrumento_3_A = new QAction("Instrumento 3", this);
/*  Instrumento_3_A->setStatusTip("Troca o timbre"); */
    connect(Instrumento_3_A, SIGNAL(triggered()), this, SLOT(/* Função para mudar os arquivos de som */));

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
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    piano->tratar_tecla_solta(event);
}

