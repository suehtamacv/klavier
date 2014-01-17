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
    explicit ajuda_wid(QWidget *parent = 0);
    ~ajuda_wid();
    
private:
    Ui::ajuda_wid *ui;
};

#endif // AJUDA_WID_H
