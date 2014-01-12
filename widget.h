#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void tratar_tecla_pressionada(QKeyEvent *);
    void tratar_tecla_solta(QKeyEvent *);

private:
    Ui::Widget *ui;

};

#endif
