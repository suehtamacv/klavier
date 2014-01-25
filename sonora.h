#ifndef SONORA_H
#define SONORA_H

#include <QWidget>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QTime>
#include <QFile>


class sonora : public QWidget {
    Q_OBJECT
    public:
        enum Estado {
            Gravando, Parado, Tocando
        };
        enum Instrumentos {
            Piano, Guitarra, Vibraphone
        };

        sonora(QWidget*);
        ~sonora();

        void abrir_arquivo(QString);
        int get_estado();
        void Gravar();
        int is_Composicao_Criada(void);
        void Parar();
        void parar_nota(QKeyEvent *);
        void Play();
        void salvar_arquivo(QString);
        void set_instrumento (Instrumentos);
        void set_estado (Estado);
        void tocar_nota(QKeyEvent *);

    signals:
        int nota_tocada(int);
        int nota_parada(int);
        void reproducao_terminada();

    private:
        int Composicao_Criada, Estado_Atual, Notas_Paradas, Notas_Tocadas, Num_Notas, _RAND_NUMBER_, *Vetor_Auxiliar;
        int Musica[200][3]; // Matriz que vai armazenar a composição. Identificação: Nota, Tempo Inicial, Tempo Final
        QFile **FilesP, **FilesG, **FilesV;
        QMediaPlayer *Player;
        QTime Relogio_Master, Relogio[24];
        QTimer *Relogio_Inicio_Nota, *Relogio_Fim_Nota;
        QWidget *parent;

        void configurar_de_arquivo(QFile*);
        void criar_arq_temp();
        void excluir_arq_temp();
        void iniciar_gravacao(QKeyEvent *);
        void parar_gravacao(QKeyEvent *);
        int procurar_nota(int);
        void set_vetor_auxiliar();


    private slots:
        void parar_nota_gravada();
        void tocar_nota_gravada();
};


#endif // SONORA_H
