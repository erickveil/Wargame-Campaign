#ifndef NPCGENERATOR_H
#define NPCGENERATOR_H

#include <QString>
#include <QList>
#include "randomtable.h"
#include "politicalnpc.h"

class npcGenerator
{
public:
    npcGenerator();

    static QString createNpc();
    static PoliticalNpc createPolitician();


};

#endif // NPCGENERATOR_H
