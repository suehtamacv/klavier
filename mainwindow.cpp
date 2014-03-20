#include "mainwindow.h"
#include "metronomo.h"
#include "tecla_e_freq.h"
#include "ajuda_wid.h"
#include "sonora.h"
#include "widget.h"
#include "botao.h"
#include <QKeyEvent>
#include <QIcon>
#include <QString>
#include <QtWidgets>
#include <QFileDialog>
#include <QSound>
#include <QTimer>

MainWindow::MainWindow() {
    BPM=isBPM=isMetronomo=0;

    clique = new QSound(":/sounds/click.wav");
    metronomo_timer = new QTimer(this);
    sound = new sonora(this);

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

    set_buttons();
    vlayout->setMargin(0);
    vlayout->addWidget(topFiller);
    vlayout->addWidget(middle);
    vlayout->addLayout(buttons);
    vlayout->addWidget(bottomFiller);
    hlayout->setMargin(0);
    hlayout->addWidget(topFiller);
    hlayout->addLayout(vlayout);
    hlayout->addWidget(bottomFiller);
    widget->setLayout(hlayout);

    createActions();
    createMenus();

    setWindowTitle("Klavier");
    setMinimumSize(750, 300);
    resize(750,300);
    setWindowIcon(QIcon(":/pics/ico500px.png"));

    piano = new Widget(middle);
}

MainWindow::~MainWindow() {
    delete piano;
    sound->~sonora();
    if (isMetronomo==1)
        wid_metronomo->fechar();
    close();
}

void MainWindow::Abrir() {
    QFileDialog *abrir_arquivo = new QFileDialog(this);
    QString caminho = abrir_arquivo->getOpenFileName(this,"Abrir Arquivo",QDir::homePath(),"Arquivos do That Piano Program (*.tpp)");
    sound->abrir_arquivo(caminho);
    delete abrir_arquivo;
}

void MainWindow::Adiciona_Botao_Metronomo() {
    isMetronomo=0;
    BPM = wid_metronomo->get_bpm();
    if (BPM!=0) {
        if (isBPM==0) {
            metr = new QCheckBox(this);
            metr->setIconSize(QSize(30,30));
            metr->setFixedSize(60,50);
            metr->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
            metr->setIcon(QIcon(QPixmap(":/pics/metronomo.png")));
            buttons->addWidget(metr);
            connect(metr,SIGNAL(clicked()),this,SLOT(play_metronomo()));
            connect(sound,SIGNAL(bloquear_programa()),metr,SLOT(hide()));
            connect(sound,SIGNAL(desbloquear_programa()),metr,SLOT(show()));
            isBPM=1;
        }
    }
}

void MainWindow::Ajuda() {
    ajuda_wid *Ajuda_Menu = new ajuda_wid(this, ajuda_wid::TipoWidgetAjuda);
    Ajuda_Menu->show();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMenu menu(this);
    menu.exec(event->globalPos());
}

void MainWindow::createActions() {
    Abrir_A = new QAction("Abrir", this);
    connect(Abrir_A, SIGNAL(triggered()), this, SLOT(Abrir()));
    connect(Abrir_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Salvar_A = new QAction("Salvar", this);
    connect(Salvar_A, SIGNAL(triggered()), this, SLOT(Salvar()));
    connect(Salvar_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Sair_A = new QAction("Sair", this);
    connect(Sair_A, SIGNAL(triggered()), this, SLOT(Fechar()));
    connect(Sair_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Metronomo_A = new QAction("Ajustar Metronômo", this);
    connect(Metronomo_A, SIGNAL(triggered()), this, SLOT(Metronomo()));
    connect(Metronomo_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Manual_A = new QAction("Definir Batimentos", this);
    connect(Manual_A, SIGNAL(triggered()), this, SLOT(Manual()));
    connect(Manual_A,SIGNAL(triggered()),sound,SLOT(Parar()));

/* Essa Opção de Editar é uma sugestão ! ( mudar o instrumento ) */

    Instrumento_1_A = new QAction("Piano", this);
    connect(Instrumento_1_A, SIGNAL(triggered()), this, SLOT(Instrumento_1()));
    connect(Instrumento_1_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Instrumento_2_A = new QAction("Guitarra", this);
    connect(Instrumento_2_A, SIGNAL(triggered()), this, SLOT(Instrumento_2()));
    connect(Instrumento_2_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Instrumento_3_A = new QAction("Vibraphone", this);
    connect(Instrumento_3_A, SIGNAL(triggered()), this, SLOT(Instrumento_3()));
    connect(Instrumento_3_A,SIGNAL(triggered()),sound,SLOT(Parar()));

    Ajuda_A = new QAction("Ajuda",this);
    connect(Ajuda_A,SIGNAL(triggered()),this,SLOT(Ajuda()));
    connect(Ajuda_A,SIGNAL(triggered()),sound,SLOT(Parar()));
    Sobre_A = new QAction("Sobre",this);
    connect(Sobre_A,SIGNAL(triggered()),this,SLOT(Sobre()));
    connect(Sobre_A,SIGNAL(triggered()),sound,SLOT(Parar()));
}

void MainWindow::createMenus() {
    ArquivoMenu = menuBar()->addMenu("Arquivo");
    ArquivoMenu->addAction(Abrir_A);
    ArquivoMenu->addAction(Salvar_A);
    ArquivoMenu->addSeparator(); // Esse comando Adiciona uma barrinha divisoria
    ArquivoMenu->addAction(Sair_A);
    connect(ArquivoMenu,SIGNAL(aboutToShow()),sound,SLOT(Parar()));

    editMenu = menuBar()->addMenu("Editar");
    connect(editMenu,SIGNAL(aboutToShow()),sound,SLOT(Parar()));

    MetronomoMenu = editMenu->addMenu("Metrônomo");
    MetronomoMenu->addAction(Metronomo_A);
    MetronomoMenu->addAction(Manual_A);
    connect(MetronomoMenu,SIGNAL(aboutToShow()),sound,SLOT(Parar()));

    TimbreMenu = editMenu->addMenu("Timbre");  // Esse Adiciona um menu dentro de outro
    TimbreMenu->addAction(Instrumento_1_A);
    TimbreMenu->addAction(Instrumento_2_A);
    TimbreMenu->addAction(Instrumento_3_A);
    connect(TimbreMenu,SIGNAL(aboutToShow()),sound,SLOT(Parar()));

    AjudaMenu = menuBar()->addMenu("Ajuda");
    AjudaMenu->addAction(Ajuda_A);
    AjudaMenu->addAction(Sobre_A);
    connect(AjudaMenu,SIGNAL(aboutToShow()),sound,SLOT(Parar()));
}

void MainWindow::Fechar() {
    this->destroy(true,true);
    this->~MainWindow();
}

void MainWindow::Gravar() {
    sound->Gravar();
}

void MainWindow::Instrumento_1() {
    sound->set_instrumento(sonora::Piano);
}

void MainWindow::Instrumento_2() {
    sound->set_instrumento(sonora::Guitarra);
}

void MainWindow::Instrumento_3() {
    sound->set_instrumento(sonora::Vibraphone);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        event->accept();
        piano->tratar_tecla_pressionada(event);
        sound->tocar_nota(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        event->accept();
        piano->tratar_tecla_solta(event);
        sound->parar_nota(event);
    }
}

void MainWindow::Manual() {
    if (isMetronomo==1)
        wid_metronomo->fechar();
    isMetronomo=1;
    wid_metronomo = new metronomo(this, metronomo::TipoManual);
    wid_metronomo->setAttribute(Qt::WA_DeleteOnClose);
    connect(this,SIGNAL(destroyed()),wid_metronomo,SLOT(fechar()));
}

void MainWindow::Metronomo() {
    if (isMetronomo==1)
        wid_metronomo->fechar();
    isMetronomo=1;
    wid_metronomo = new metronomo(this, metronomo::TipoDetectorBatidas);
    wid_metronomo->setAttribute(Qt::WA_DeleteOnClose);
    connect(this,SIGNAL(destroyed()),wid_metronomo,SLOT(fechar()));
}

void MainWindow::Parar() {
    sound->Parar();
}

void MainWindow::Play() {
    sound->Play();
}

void MainWindow::play_metronomo() {
    float frequencia = 60.0 / BPM;
    if (metr->isChecked()) { //botao ativo
        if (BPM == 0) {
            Metronomo();
        } else {
                if(clique->isFinished()) {
                    clique->play();
                    metronomo_timer->singleShot((int)1000*frequencia,this,SLOT(play_metronomo()));
                }
        }
    }
}

void MainWindow::Salvar() {
    if (sound->is_Composicao_Criada()==0) {
        QMessageBox *erro = new QMessageBox();
        erro->setWindowTitle("ERRO!");
        if (sound->get_estado() == sonora::Gravando) {
            erro->setText("Você ainda está gravando. Pare a gravação atual antes de salvar a composição.");
        } else {
            erro->setText("Nenhuma composição foi criada ainda, ou ela é vazia.");
        }
        erro->exec();
    } else {
        QFileDialog *salvar_arquivo = new QFileDialog(this);
        QString caminho = salvar_arquivo->getSaveFileName(this,"Salvar Arquivo",QDir::homePath(),"Arquivos do That Piano Program (*.tpp)");
        sound->salvar_arquivo(caminho);
        delete salvar_arquivo;
    }
}

void MainWindow::set_buttons() {
    Botao *record = new Botao();
    Botao *play = new Botao();
    Botao *stop = new Botao();
    record->setIcon(QIcon(QPixmap(":/pics/record.png")));
    record->setIconSize(QSize(20,20));
    record->setFixedSize(50,50);
    record->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    play->setEnabled(false);
    play->setIcon(QIcon(QPixmap(":/pics/play.png")));
    play->setIconSize(QSize(20,20));
    play->setFixedSize(50,50);
    play->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    stop->setIcon(QIcon(QPixmap(":/pics/stop.png")));
    stop->setIconSize(QSize(20,20));
    stop->setFixedSize(50,50);
    stop->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    stop->setEnabled(false);
    buttons = new QHBoxLayout;
    buttons->setMargin(5);
    buttons->addWidget(play);
    buttons->addWidget(record);
    buttons->addWidget(stop);

    connect(play,SIGNAL(clicked()),play,SLOT(desativar()));
    connect(play,SIGNAL(clicked()),record,SLOT(desativar()));
    connect(play,SIGNAL(clicked()),stop,SLOT(ativar()));
    connect(stop,SIGNAL(clicked()),record,SLOT(ativar()));
    connect(stop,SIGNAL(clicked()),stop,SLOT(desativar()));
    connect(stop,SIGNAL(clicked()),play,SLOT(ativar()));
    connect(record,SIGNAL(clicked()),stop,SLOT(ativar()));
    connect(record,SIGNAL(clicked()),record,SLOT(desativar()));
    connect(record,SIGNAL(clicked()),play,SLOT(desativar()));
    connect(sound,SIGNAL(reproducao_terminada()),stop,SLOT(desativar()));
    connect(sound,SIGNAL(reproducao_terminada()),play,SLOT(ativar()));
    connect(sound,SIGNAL(reproducao_terminada()),record,SLOT(ativar()));
    connect(record,SIGNAL(clicked()),this,SLOT(Gravar())); // Função que inicia o Relogio master e muda o estado
    connect(stop,SIGNAL(clicked()),this,SLOT(Parar()));
    connect(play,SIGNAL(clicked()),this,SLOT(Play()));

    connect(sound,SIGNAL(bloquear_programa()),play,SLOT(desativar()));
    connect(sound,SIGNAL(bloquear_programa()),record,SLOT(desativar()));
    connect(sound,SIGNAL(bloquear_programa()),stop,SLOT(desativar()));
    connect(sound,SIGNAL(bloquear_programa()),this,SLOT(Parar()));
    connect(sound,SIGNAL(desbloquear_programa()),play,SLOT(ativar()));
    connect(sound,SIGNAL(desbloquear_programa()),record,SLOT(ativar()));
}

void MainWindow::set_tecla_pressionada(int tecla) {
    piano->set_tecla_pressionada(tecla);
}


void MainWindow::set_tecla_solta(int tecla) {
    piano->set_tecla_solta(tecla);
}

void MainWindow::Sobre() {
    ajuda_wid *Ajuda_Menu = new ajuda_wid(this, ajuda_wid::TipoWidgetSobre);
    Ajuda_Menu->show();
}
