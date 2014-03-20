#ifndef ERROS_H
#define ERROS_H

#include <QWidget>

class Erros {
    public:
        enum TipoErro {
            ErroComposicaoInexistente, ErroComposicaoTocando, ErroArquivoInexistente, ErroArquivoInacessivel, ErroQualquer
        };
        Erros(QWidget* = 0, TipoErro = ErroQualquer);
        void mostra_msg();
    private:
        QWidget *parent;
        TipoErro erro;
};

#endif // ERROS_H
