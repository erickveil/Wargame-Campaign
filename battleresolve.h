#ifndef BATTLERESOLVE_H
#define BATTLERESOLVE_H

#include "dice.h"
#include "randomtable.h"
#include "qdebug.h"


class BattleResolve
{

public:
    bool _isAttkWins;

    int _attkSurvivors;
    int _defSurvivors;

    int _prisoners;
    int _winnerWounded;

    int _attkCost;
    int _defCost;

    BattleResolve();
    void fight(int attkPoints, int defPoints, int attkCcr, int defCcr, bool scavenge);

};

#endif // BATTLERESOLVE_H
