#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbNpc_clicked()
{
    QString desc = npcGenerator::createNpc();
    ui->pteOutput->setPlainText(desc);
}

void MainWindow::on_pbBattle_clicked()
{
    int attkPoints = ui->sbAttkPoints->value();
    int defPoints = ui->sbDefPoints->value();
    int attkCcr = ui->sbAttkCCR->value();
    int defCcr = ui->sbDefCCR->value();
    bool scavenge = ui->cbScavenge->isChecked();

    _battle.fight(attkPoints, defPoints, attkCcr, defCcr, scavenge);

    ui->leLoseCaptured->setText(QString::number(_battle._prisoners));
    ui->leAttkSurvive->setText(QString::number(_battle._attkSurvivors));
    ui->leDefSurvive->setText(QString::number(_battle._defSurvivors));
    ui->leDefCost->setText(QString::number(_battle._defCost));
    ui->leWinner->setText(
                (_battle._isAttkWins) ? "Attacker Wins" : "Defender Wins" );
    ui->leWinnerWounded->setText(QString::number(_battle._winnerWounded));
    ui->leAttkCost->setText(QString::number(_battle._attkCost));

}
