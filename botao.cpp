#include "botao.h"

Botao::Botao() : QPushButton() {

}

Botao::Botao(QWidget *parent) {
    new QPushButton(parent);
}

void Botao::ativar() {
    setEnabled(true);
}

void Botao::desativar() {
    setDisabled(true);
}

void Botao::mudar() {
    setEnabled(!isEnabled());
}
