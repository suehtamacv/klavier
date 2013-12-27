#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);
    ~Widget();

private slots:
    void on_Keyb_C_pressed();
    void on_Keyb_Cs_pressed();
    void on_Keyb_D_pressed();
    void on_Keyb_Ds_pressed();
    void on_Keyb_E_pressed();
    void on_Keyb_F_pressed();
    void on_Keyb_Fs_pressed();
    void on_Keyb_G_pressed();
    void on_Keyb_Gs_pressed();
    void on_Keyb_A_pressed();
    void on_Keyb_As_pressed();
    void on_Keyb_B_pressed();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
