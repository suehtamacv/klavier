#ifndef METRONOMO_H
#define METRONOMO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTime>
#include "botao.h"

class metronomo : public QWidget
{
    Q_OBJECT
public:
    metronomo(QWidget*);
    metronomo(QWidget*, int); // O inteiro serve para diferenciar o outro construtor
    ~metronomo();
    float get_bpm();

signals:

public slots:
    void on_botao_pressed();
    void fechar();

private:
    QWidget *wid_metronomo, *filler, *parent;
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QTime tempo;
    Botao *botao;
    int rotacao;
    time_t tempo_ini, tempo_fin;
    float bpm;
    void calc_bpm();

private slots:
    void definir_bpm(int);
};

#endif // METRONOMO_H
