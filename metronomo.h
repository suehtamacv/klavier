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
        enum MetronomoTipo {
            TipoDetectorBatidas,
            TipoManual
        };
        metronomo(QWidget*, MetronomoTipo);
        ~metronomo();
        float get_bpm();

    public slots:
        void botao_pressionado();
        void fechar();

    private:
        int rotacao;
        float bpm;
        Botao *botao;
        QHBoxLayout *hlayout;
        QVBoxLayout *vlayout;
        QTime tempo;
        QWidget *wid_metronomo, *filler, *parent;

        void calc_bpm();

    private slots:
        void set_bpm(int);
};

#endif // METRONOMO_H
