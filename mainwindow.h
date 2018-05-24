#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "battleresolve.h"
#include "randomtable.h"
#include "npcgenerator.h"
#include "battleresolve.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    BattleResolve _battle;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbNpc_clicked();

    void on_pbBattle_clicked();

    void on_cbScavenge_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
