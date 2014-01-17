#include "ajuda_wid.h"
#include "ui_ajuda_wid.h"

ajuda_wid::ajuda_wid(QWidget *parent) : QDialog(parent), ui(new Ui::ajuda_wid) {
    ui->setupUi(this);
}

ajuda_wid::~ajuda_wid() {
    delete ui;
}
