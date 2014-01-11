#ifndef SOM_H
#define SOM_H
#ifndef SOM_H
#define SOM_H

#include <QKeyEvent>
#include <QMediaPlayer>
class sonora{

    public:

        sonora();
        void tocar_nota(QKeyEvent *);
        void parar_nota(QKeyEvent *);

        ~sonora();


    private:

        QMediaPlayer *Player;

};


#endif // SOM_H
#endif // SOM_H
