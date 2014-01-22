#include "metronomo.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QTime>

metronomo::metronomo(QWidget *parn, MetronomoTipo Tipo) : QWidget(parn) {
    if (Tipo == TipoDetectorBatidas) {
        parent = parn;
        rotacao=0;
        set_bpm(40);

        wid_metronomo = new QWidget();
        wid_metronomo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        wid_metronomo->setFixedSize(300,300);
        wid_metronomo->setWindowTitle("Metrônomo");
        wid_metronomo->show();

        QLabel *text = new QLabel("Clique quatro vezes no botão abaixo:", this);
        vlayout = new QVBoxLayout();
        hlayout = new QHBoxLayout();

        filler = new QWidget();
        filler->setMinimumSize(0,0);
        filler->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        botao = new Botao(this);
        botao->setFixedSize(70,70);
        botao->setIcon(QIcon(QPixmap(":/pics/clock1.png")));
        botao->setIconSize(QSize(40,40));
        botao->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        connect(botao,SIGNAL(pressed()),this,SLOT(botao_pressionado()));

        hlayout->addWidget(filler);
        hlayout->addWidget(botao);
        hlayout->addWidget(filler);

        vlayout->addWidget(text);
        vlayout->addWidget(filler);
        vlayout->addLayout(hlayout);
        vlayout->addWidget(filler);

        wid_metronomo->setLayout(vlayout);
        connect(this,SIGNAL(destroyed()),parent,SLOT(Adiciona_Botao_Metronomo()));
    } else if (Tipo == TipoManual) {
        parent = parn;

        QSpinBox *caixa_numerica = new QSpinBox;
        QSlider *seletor = new QSlider(Qt::Horizontal);
        QPushButton *botao = new QPushButton;

        caixa_numerica->setRange(40,120);
        seletor->setRange(40,120);
        set_bpm(40);

        connect(caixa_numerica, SIGNAL (valueChanged(int)), seletor, SLOT (setValue(int)));
        connect(seletor, SIGNAL (valueChanged(int)), caixa_numerica, SLOT (setValue(int)));
        connect(seletor,SIGNAL(valueChanged(int)),this,SLOT(set_bpm(int)));

        botao = new Botao(this);
        botao->setFixedSize(50,30);
        botao->setText("Ok");

        wid_metronomo = new QWidget();
        wid_metronomo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        wid_metronomo->setFixedSize(400,100);
        wid_metronomo->setWindowTitle("Metrônomo Manual");
        wid_metronomo->show();

        QLabel *text = new QLabel("Defina o valor em batimentos por minuto abaixo:", this);
        vlayout = new QVBoxLayout();
        hlayout = new QHBoxLayout();

        filler = new QWidget();
        filler->setMinimumSize(0,0);
        filler->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

        hlayout->addWidget(filler);
        hlayout->addWidget(caixa_numerica);
        hlayout->addWidget(seletor);
        hlayout->addWidget(botao);
        hlayout->addWidget(filler);

        vlayout->addWidget(text);
        vlayout->addWidget(filler);
        vlayout->addLayout(hlayout);
        vlayout->addWidget(filler);
        wid_metronomo->setLayout(vlayout);

        connect(botao,SIGNAL(pressed()),parent,SLOT(Adiciona_Botao_Metronomo()));
        connect(botao,SIGNAL(pressed()),this,SLOT(fechar()));
    }
}

metronomo::~metronomo() {
    delete wid_metronomo;
}

void metronomo::botao_pressionado() {
    switch(rotacao) {
        case 0: tempo.start(); rotacao++; botao->setIcon(QIcon(QPixmap(":/pics/clock2.png"))); break;
        case 1: rotacao++; botao->setIcon(QIcon(QPixmap(":/pics/clock3.png"))); break;
        case 2: rotacao++; botao->setIcon(QIcon(QPixmap(":/pics/clock4.png"))); break;
        case 3: botao->setIcon(QIcon(QPixmap(":/pics/clock1.png"))); rotacao=0; calc_bpm();break;
    }
}

void metronomo::calc_bpm() {
    bpm = tempo.elapsed();

    QMessageBox *result_bpm = new QMessageBox();
    result_bpm->setWindowTitle("Frequência");

    if (bpm==0) {
        result_bpm->setText("ERRO!");
        result_bpm->setInformativeText("O Metrônomo não conseguiu identificar a frequência da batida.");
        result_bpm->exec();
    } else {
        bpm = 240000.0/bpm;
        result_bpm->setText("O Metrônomo retorna uma batida de " + QString::number(bpm) + " bpm.");
        result_bpm->exec();
    }

    this->fechar();
}

void metronomo::fechar() {
    this->close();
}

float metronomo::get_bpm() {
    return bpm;
}

void metronomo::set_bpm(int valor) {
   bpm=valor;
}
