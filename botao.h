#ifndef BOTAO_H
#define BOTAO_H

#include <QPushButton>

class Botao : public QPushButton //Esta classe foi criada para implementar os slots abaixo. Ela e filha de QPushButton.
{
    Q_OBJECT
public:
    Botao();
    Botao(QWidget *);
    
signals:
    
public slots:
    void ativar();
    void desativar();
    void mudar();
};

#endif // BOTAO_H
