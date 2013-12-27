#include "widget.h"
#include "tecla_e_freq.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("That Piano Program");

    w.show();

    return a.exec();
}


