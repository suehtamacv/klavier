#include "botao.h"

Botao::Botao() : QPushButton() {

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
