#include "widget.h"
#include "ui_widget.h"
#include "tecla_e_freq.h"
#include <QKeyEvent>
#include <QtWidgets>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(parent);
}

void Widget::tratar_tecla_pressionada(QKeyEvent *event) {
    switch(event->key()) {
        case C1: ui->Key_C1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesqp.png"))); break;
        case Cs1: ui->Key_Cs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case D1: ui->Key_D1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case Ds1: ui->Key_Ds1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case E1: ui->Key_E1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadirp.png"))); break;
        case F1: ui->Key_F1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesqp.png"))); break;
        case Fs1: ui->Key_Fs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case G1: ui->Key_G1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case Gs1: ui->Key_Gs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case A1: ui->Key_A1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case As1: ui->Key_As1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case B1: ui->Key_B1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadirp.png"))); break;
        case C2: ui->Key_C2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesqp.png"))); break;
        case Cs2: ui->Key_Cs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case D2: ui->Key_D2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case Ds2: ui->Key_Ds2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case E2: ui->Key_E2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadirp.png"))); break;
        case F2: ui->Key_F2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesqp.png"))); break;
        case Fs2: ui->Key_Fs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case G2: ui->Key_G2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case Gs2: ui->Key_Gs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case A2: ui->Key_A2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancameip.png"))); break;
        case As2: ui->Key_As2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpretap.png"))); break;
        case B2: ui->Key_B2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadirp.png"))); break;
    }
}

void Widget::tratar_tecla_solta(QKeyEvent *event) {
    switch(event->key()) {
        case C1: ui->Key_C1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesq.png"))); break;
        case Cs1: ui->Key_Cs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case D1: ui->Key_D1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case Ds1: ui->Key_Ds1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case E1: ui->Key_E1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadir.png"))); break;
        case F1: ui->Key_F1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesq.png"))); break;
        case Fs1: ui->Key_Fs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case G1: ui->Key_G1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case Gs1: ui->Key_Gs1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case A1: ui->Key_A1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case As1: ui->Key_As1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case B1: ui->Key_B1->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadir.png"))); break;
        case C2: ui->Key_C2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesq.png"))); break;
        case Cs2: ui->Key_Cs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case D2: ui->Key_D2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case Ds2: ui->Key_Ds2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case E2: ui->Key_E2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadir.png"))); break;
        case F2: ui->Key_F2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancaesq.png"))); break;
        case Fs2: ui->Key_Fs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case G2: ui->Key_G2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case Gs2: ui->Key_Gs2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case A2: ui->Key_A2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancamei.png"))); break;
        case As2: ui->Key_As2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecpreta.png"))); break;
        case B2: ui->Key_B2->setPixmap(QPixmap(QString::fromUtf8(":/pics/tecbrancadir.png"))); break;
    }
}
