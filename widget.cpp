#include "widget.h"
#include "ui_widget.h"
#include "tecla_e_freq.h"
#include <QKeyEvent>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case C: ui->Keyb_C->animateClick(300); break;
        case Cs: ui->Keyb_Cs->animateClick(300); break;
        case D: ui->Keyb_D->animateClick(300); break;
        case Ds: ui->Keyb_Ds->animateClick(300); break;
        case E: ui->Keyb_E->animateClick(300); break;
        case F: ui->Keyb_F->animateClick(300); break;
        case Fs: ui->Keyb_Fs->animateClick(300); break;
        case G: ui->Keyb_G->animateClick(300); break;
        case Gs: ui->Keyb_Gs->animateClick(300); break;
        case A: ui->Keyb_A->animateClick(300); break;
        case As: ui->Keyb_As->animateClick(300); break;
        case B: ui->Keyb_B->animateClick(300); break;
    }
}

void Widget::on_Keyb_C_pressed() {
    this->setWindowTitle("C Pressionado!");
}
void Widget::on_Keyb_Cs_pressed() {
    this->setWindowTitle("C# Pressionado!");
}
void Widget::on_Keyb_D_pressed() {
    this->setWindowTitle("D Pressionado!");
}
void Widget::on_Keyb_Ds_pressed() {
    this->setWindowTitle("D# Pressionado!");
}
void Widget::on_Keyb_E_pressed() {
    this->setWindowTitle("E Pressionado!");
}
void Widget::on_Keyb_F_pressed() {
    this->setWindowTitle("F Pressionado!");
}
void Widget::on_Keyb_Fs_pressed() {
    this->setWindowTitle("F# Pressionado!");
}
void Widget::on_Keyb_G_pressed() {
    this->setWindowTitle("G Pressionado!");
}
void Widget::on_Keyb_Gs_pressed() {
    this->setWindowTitle("G# Pressionado!");
}
void Widget::on_Keyb_A_pressed() {
    this->setWindowTitle("A Pressionado!");
}
void Widget::on_Keyb_As_pressed() {
    this->setWindowTitle("A# Pressionado!");
}
void Widget::on_Keyb_B_pressed() {
    this->setWindowTitle("B Pressionado!");
}
