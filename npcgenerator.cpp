#include "npcgenerator.h"

npcGenerator::npcGenerator()
{

}

QString npcGenerator::createNpc()
{
    QList<QString> discardPile;

    RandomTable suits;
    suits.addEntry("Heart");
    suits.addEntry("Club");
    suits.addEntry("Spade");
    suits.addEntry("Diamond");

    // primary trait
    QString firstSuit= suits.getRollTableEntry();
    int firstVal = Dice::roll(1, 13);
    QString firstCard = QString::number(firstVal) + ": " + firstSuit;
    discardPile.append(firstCard);

    QString primaryTrait;
    if (firstSuit == "Spade")  {
        primaryTrait = "Ambition";
    }
    else if (firstSuit == "Club") {
        primaryTrait = "Love of War";
    }
    else if (firstSuit == "Heart") {
        primaryTrait = "Good Nature";
    }
    else {
        primaryTrait = "Love of Wealth";
    }

    primaryTrait += ": " + QString::number(firstVal);

    // other traits
    bool isHunchback = false;
    QList<QString> traits;
    for (int i = 1; i < 7; ++i) {

        // draw a card
        QString nextSuit = suits.getRollTableEntry();
        int nextVal = Dice::roll(1, 13);
        QString nextCard = QString::number(nextVal) + ": " + nextSuit;

        // prevent duplicates
        bool isUsed = false;
        for (int c = 0; c < discardPile.size(); ++c) {
            if (nextCard == discardPile[c]) {
                isUsed = true;
                break;
            }
        }
        if (isUsed) {
            --i;
            continue;
        }
        discardPile.append(nextCard);

        // interperet cards
        QString nextTrait;
        if (nextVal == 1) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Disloyal Intriguer";
            }
            else if (nextSuit == "Diamond") {
                nextTrait = "Loyal Intriguer";
            }
            else {
                nextTrait = "Exceptional Good Nature";
            }
            if (Dice::roll(1, 100) < 50) { isHunchback = true; }
        }
        else if (nextVal == 2) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Arrogance";
            }
            else {
                nextTrait = "Merciful";
            }
        }
        else if (nextVal == 3) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Bad Temper";
            }
            else {
                nextTrait = "Good Temper";
            }
        }
        else if (nextVal == 4) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Stupidity";
            }
            else {
                nextTrait = "Cowardice";
            }
        }
        else if (nextVal == 5) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Wisdom";
            }
            else {
                nextTrait = "Cunning";
            }
        }
        else if (nextVal == 6) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Laziness";
            }
            else {
                nextTrait = "Charm";
            }
        }
        else if (nextVal == 7) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Personality";
            }
            else {
                nextTrait = "Jealous of Family Honor";
            }
        }
        else if (nextVal == 8) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Cruelty";
            }
            else {
                nextTrait = "Generosity";
            }
        }
        else if (nextVal == 9) {
            if (nextSuit == "Spade") {
                nextTrait = "Ugliness";
            }
            else {
                nextTrait = "Physical Beauty";
            }
        }
        else if (nextVal == 10) {
            if (nextSuit == "Diamond") {
                nextTrait = "Completely Loyal";
            }
            else if (nextSuit == "Heart") {
                nextTrait = "Loyalty: 4";
            }
            else if (nextSuit == "Club") {
                nextTrait = "Loyalty: 2";
            }
            else {
                nextTrait = "Disloyal in all things";
            }
        }
        else if (nextVal == 11) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Unreliable liar and oathbreaker";
            }
            else {
                nextTrait = "Merciless and revenge-prone";
            }
        }
        else if (nextVal == 12) {
            nextTrait = "Great Lover";
        }
        else {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Energy";
            }
            else {
                nextTrait = "Courage";
            }
        }
        traits.append(nextTrait);
    } // end main loop

    // commander competency:
    int competency = Dice::roll(1,6);
    QString descriptor;
    if (competency == 1) {
        descriptor = "Inept Commander";
    }
    else if (competency == 2) {
        descriptor = "Poor Commander";
    }
    else if (competency == 3) {
        descriptor = "Somewhat Inefficient";
    }
    else if (competency == 4) {
        descriptor = "Competent";
    }
    else if (competency == 5) {
        descriptor = "Excellent Commander";
    }
    else {
        descriptor = "Superb Commander";
    }
    QString ccr = "CCR: " + QString::number(competency)
            + " (" + descriptor + ")\n";

    // formulate report
    int age = Dice::roll(1, 70) + 11;
    QString npcStats = "Age: " + QString::number(age) + "\n";
    npcStats += primaryTrait + "\n";
    npcStats += ccr;
    for (int i = 0; i < traits.size(); ++i) {
        npcStats += traits[i] + "\n";
    }
    if (isHunchback) {
        npcStats += "Hunchback\n";
    }
    return npcStats;

}

