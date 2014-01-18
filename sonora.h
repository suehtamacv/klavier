#ifndef SOM_H
#define SOM_H

#include <QWidget>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QString>
#include <QTime>
#include <QFile>


class sonora : public QWidget {
    Q_OBJECT
    public:
        enum Estado {
            Gravando, Parado, Tocando
        };
        enum Instrumentos {
            Piano, Guitarra, Whatever
        };
        sonora(QWidget*);
        void tocar_nota(QKeyEvent *);
        void parar_nota(QKeyEvent *);
        void set_instrumento (Instrumentos);
        void set_estado (Estado);
        int is_Composicao_Criada(void);
        int get_estado();
        void salvar_arquivo(QString);
        void abrir_arquivo(QString);
        ~sonora();
        void Gravar();
        void Parar();
        void Play();

    signals:
        int nota_tocada(int);
        int nota_parada(int);
        void reproducao_terminada();

    private:
        QWidget *parent;
        QMediaPlayer *Player;
        QFile **Files;
        void criar_arq_temp();
        void excluir_arq_temp();
        void configurar_de_arquivo(QFile*);
        int Estado_Atual;
        long int Diferenca_tempo(int,int,int,int,int,int,int,int);
        void iniciar_gravacao(QKeyEvent *);
        void parar_gravacao(QKeyEvent *);
        int procurar_nota(int);
        QTime Relogio_Master;
        QTime Relogio[24];
        int Musica[100][3]; // Matriz que vai armazenar a composição. Identificação: Nota, Tempo Inicial, Tempo Final
        int Num_Notas;
        int Composicao_Criada;
        int Notas_Tocadas;
        int auxiliar_relogio;
        QTimer RelogioInicio[5], RelogioFim[5];

    private slots:
        void play_nota_gravada();
        void stop_nota_gravada();

};


#endif // SOM_H
