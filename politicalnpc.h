#ifndef POLITICALNPC_H
#define POLITICALNPC_H

#include <QString>
#include <QStringList>
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

    QString Name;
    QString Gender;
    int Age;
    QStringList TraitList;

    PoliticalNpc();

    static int getMod(int abilityScore);
    static QStringList createTraitList();

    void initCharacter();
    QString asString();
    QString createName();
};

#endif // POLITICALNPC_H
