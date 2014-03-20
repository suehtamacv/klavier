#include "erros.h"
#include <QMessageBox>

Erros::Erros(QWidget *nparent, TipoErro nerro) {
    parent = nparent;
    erro = nerro;
}

void Erros::mostra_msg() {
    QMessageBox *janela_erro = new QMessageBox(parent);
    janela_erro->setIcon(QMessageBox::Warning);
    janela_erro->setWindowTitle("Cuidado!");

    switch(erro) {
        case ErroComposicaoTocando:
            janela_erro->setText("Uma composição está sendo reproduzida no momento.");
            break;
        case ErroComposicaoInexistente:
            janela_erro->setText("Nenhuma composição foi criada até o momento.");
            break;
        case ErroArquivoInacessivel:
            janela_erro->setText("O arquivo não pôde ser aberto.");
            break;
        case ErroArquivoInexistente:
            janela_erro->setText("O arquivo não pôde ser encontrado.");
            break;
        default:
            janela_erro->setText("Ocorreu um erro indeterminado.");
            break;
    }

    janela_erro->exec();
}
