#ifndef SOM_H
#define SOM_H

#include <QKeyEvent>
#include <QMediaPlayer>
#include <QString>
#include <QTemporaryFile>

class sonora {

    public:
        enum Instrumentos {
            Piano, Guitarra, Whatever
        };
        sonora();
        void tocar_nota(QKeyEvent *);
        void parar_nota(QKeyEvent *);
        void set_instrumento (Instrumentos);
        ~sonora();

    private:
        QMediaPlayer *Player;
        QFile **Files;
        void criar_arq_temp();
        void excluir_arq_temp();
};


#endif // SOM_H
