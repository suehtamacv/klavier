#include "ajuda_wid.h"
#include "ui_ajuda_wid.h"

ajuda_wid::ajuda_wid(QWidget *parent, TipoWidget tipo) : QDialog(parent), ui(new Ui::ajuda_wid) {
    ui->setupUi(this);
    connect(ui->FecharBotao,SIGNAL(clicked()),this,SLOT(close()));

    if (tipo == TipoWidgetAjuda) {
        criar_menu_ajuda();
    } else if (tipo == TipoWidgetSobre) {
        criar_menu_sobre();
    }
}

ajuda_wid::~ajuda_wid() {
    delete ui;
}

void ajuda_wid::criar_menu_ajuda() {
    this->setWindowTitle("Ajuda");
    ui->textBrowser->setSource(QUrl(QStringLiteral("qrc:/html/ajuda.html")));
}

void ajuda_wid::criar_menu_sobre() {
    this->setWindowTitle("Sobre o That Piano Program");
    ui->textBrowser->setSource(QUrl(QStringLiteral("qrc:/html/sobre.html")));
}
