#include "mainwindow.h"
#include <QApplication>
#include <QtGlobal>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qsrand(QDateTime::currentMSecsSinceEpoch());
    w.show();

    return a.exec();
}
