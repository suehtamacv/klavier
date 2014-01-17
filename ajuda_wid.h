#ifndef AJUDA_WID_H
#define AJUDA_WID_H

#include <QDialog>

namespace Ui {
class ajuda_wid;
}

class ajuda_wid : public QDialog
{
    Q_OBJECT
    
public:
    enum TipoWidget {
        TipoWidgetAjuda,
        TipoWidgetSobre
    };
    explicit ajuda_wid(QWidget * = 0, TipoWidget = TipoWidgetAjuda);
    ~ajuda_wid();

    
private:
    Ui::ajuda_wid *ui;
    void criar_menu_ajuda();
    void criar_menu_sobre();

};

#endif // AJUDA_WID_H
