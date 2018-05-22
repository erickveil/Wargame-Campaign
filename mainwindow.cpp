#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomtable.h"
#include "npcgenerator.h"

/*
 * Determine age
 * Determine family members
 *
 * Seven "cards"
 * first card is most outstanding trait
 * heart: good nature; Diamond:love of wealth; Spade: ambition; club: love of war (man), patriotism (woman)
 * Value of card determines depth of this passion.
 *
 * Remaining cards:
 * Ace:		Spade or club, a disloyal intriguer. Diamond, loyal intriguer. Heart, exceptonal good nature
 * King:	Spade or club, Energy. Heart or diamond, courage
 * Queen: 	Great lover
 * Knave: 	Spade or club, Unreliability, oath-breaker, liar. Heart or diamond: Merciless, revenge-prone.
 * Ten:		Diamonds: absolute loyalty, then hearts, clubs, and least loyalty from spades
 * 9:		Physical beauty, except for spade, which is ugliness
 * 8: 		Spade or club, Cruelty. Heart or Diamond, Generosity
 * 7:		Spade or club, Personality. Heart or Diamond, Jealous of family honor
 * 6:		Spade or club, Laxyness. Heart or Diamond, charm
 * 5:		Spade or club: Wisdom. Heart or Diamond: cunning
 * 4:	Spade or club: stupidity. Heart or diamond: cowardice
 * 3:		Spade or club: bad temper. heart or diamond: good temper
 * 2:		Spade or club: arrogance, pride. Heart or diamond: merciful
 * Reverced ace: hunchback or cripple
 *
 * commander competency
 * 1	inept commander, idion
 * 2	poor commander, inexperienced
 * 3	average commander, somewhat inefficient
 * 4	average commander competent
 * 5	excellent commander, above average competency
 * 6	superb commander, highly competent
 */

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
