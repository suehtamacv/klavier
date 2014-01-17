#ifndef SOM_H
#define SOM_H

#include <QKeyEvent>
#include <QMediaPlayer>
#include <QString>
#include <QTime>
#include <QTemporaryFile>

class sonora {

    public:
        enum Estado {
            Gravando, Nao_Gravando
        };

        enum Instrumentos {
            Piano, Guitarra, Whatever
        };
        sonora();
        void tocar_nota(QKeyEvent *);
        void parar_nota(QKeyEvent *);
        void set_instrumento (Instrumentos);
        void set_estado (Estado);
        int Musica[100][3]; // Matriz que vai armazenar a composição. Identificação: Nota, Tempo Inicial, Tempo Final
        ~sonora();

    public slots:
        void Gravar();

    private:
        QMediaPlayer *Player;
        QFile **Files;
        void criar_arq_temp();
        void excluir_arq_temp();
        int Estado_Atual;
        int Diferenca_tempo(int,int,int,int,int,int);
        void iniciar_gravacao(QKeyEvent *);
        void parar_gravacao(QKeyEvent *);
        QTime Relogio_Master;
        QTime Relogio[24];
};


#endif // SOM_H
