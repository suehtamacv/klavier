#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>


class QAction;
class QActionGroup;

class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    // Funções
    void Composicao();
    void Abrir();
    void Salvar();
    void Metronomo();
    void Oitava();
    void Instrumento_1();
    void Instrumento_2();
    void Instrumento_3();

private:
  // Isso é necessário para poder fazer as ações
    void createActions();
    void createMenus();
// São as abas de menu
    QMenu *ArquivoMenu;
    QMenu *editMenu;
    QMenu *TimbreMenu;

// Cada Ação correspondente a uma função, para diferenciar das funções coloquei " _A "
// Esses elementos serão chamados no menu
    QAction *Composicao_A;
    QAction *Abrir_A;
    QAction *Salvar_A;
    QAction *Sair_A;
    QAction *Metronomo_A;
    QAction *Oitava_A;
    QAction *Instrumento_1_A;
    QAction *Instrumento_2_A;
    QAction *Instrumento_3_A;

};

#endif
