#ifndef POLITICALNPC_H
#define POLITICALNPC_H

#include <QString>
#include <QStringList>
#include <QtMath>

#include "randomtable.h"
#include "libtcod.hpp"

#include <string>

class PoliticalNpc
{
    bool _isInit = false;

public:

    int Loyalty;
    int Ambition;
    int Leadership;
    int Cunning;
    int Subtlety;
    int Perception;
    int LocalSupport;

    int Strength;
    int Dexterity;
    int Constitution;
    int Intelligence;
    int Wisdom;
    int Charisma;

    QString Name;
    QString Gender;
    int Age;
    QStringList TraitList;

    PoliticalNpc();

    static int getMod(int abilityScore);
    static QStringList createTraitList();

    void initCharacter();
    void initAbilityScores();
    QString asString();
    QString createName(QString gender);
    int getCCR();

    QString StrDesc();
    QString DexDesc();
    QString ConDesc();
    QString IntDesc();
    QString WisDesc();
    QString ChaDesc();
};

#endif // POLITICALNPC_H
