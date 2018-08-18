#include "politicalnpc.h"

PoliticalNpc::PoliticalNpc()
{

}

int PoliticalNpc::getMod(int abilityScore)
{
    if (abilityScore <= 1) { return -5; }
    if (abilityScore == 2 || abilityScore == 3) { return -4; }
    if (abilityScore == 4 || abilityScore == 5) { return -3; }
    if (abilityScore == 6 || abilityScore == 7) { return -2; }
    if (abilityScore == 8 || abilityScore == 9) { return -1; }
    if (abilityScore == 10 || abilityScore == 11) { return 0; }
    if (abilityScore == 12 || abilityScore == 13) { return 1; }
    if (abilityScore == 14 || abilityScore == 15) { return 2; }
    if (abilityScore == 16 || abilityScore == 17) { return 3; }
    if (abilityScore == 18 || abilityScore == 19) { return 4; }
    if (abilityScore == 20 || abilityScore == 21) { return 5; }
    if (abilityScore == 22 || abilityScore == 23) { return 6; }
    if (abilityScore == 24 || abilityScore == 25) { return 7; }
    if (abilityScore == 26 || abilityScore == 27) { return 8; }
    if (abilityScore == 28 || abilityScore == 29) { return 9; }
    return 10;
}

QStringList PoliticalNpc::createTraitList()
{
    QList<QString> discardPile;
    QStringList traitList;

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
        primaryTrait = "Patriotic";
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
    traitList.append(primaryTrait);

    // other traits
    bool isHunchback = false;
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
            if (nextSuit == "Spade"
                    || nextSuit == "Club"
                    || nextSuit == "Diamond") {
                nextTrait = "Intriguer";
            }
            else {
                nextTrait = "Good Natured";
            }
            if (Dice::roll(1, 100) < 50) { isHunchback = true; }
        }
        else if (nextVal == 2) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Arrogant";
            }
            else {
                nextTrait = "Merciful";
            }
        }
        else if (nextVal == 3) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Bad Tempered";
            }
            else {
                nextTrait = "Good Temper";
            }
        }
        else if (nextVal == 4) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Stupid";
            }
            else {
                nextTrait = "Cowardly";
            }
        }
        else if (nextVal == 5) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Wise";
            }
            else {
                nextTrait = "Foolish";
            }
        }
        else if (nextVal == 6) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Lazy";
            }
            else {
                nextTrait = "Charming";
            }
        }
        else if (nextVal == 7) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Outgoing";
            }
            else {
                nextTrait = "Jealous of family honor";
            }
        }
        else if (nextVal == 8) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Cruel";
            }
            else {
                nextTrait = "Generous";
            }
        }
        else if (nextVal == 9) {
            if (nextSuit == "Spade") {
                nextTrait = "Ugly";
            }
            else {
                nextTrait = "Attractive";
            }
        }
        else if (nextVal == 10) {
            nextTrait = "Tempered";
        }
        else if (nextVal == 11) {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Unreliable and dishonest";
            }
            else {
                nextTrait = "Merciless and vengeful";
            }
        }
        else if (nextVal == 12) {
            nextTrait = "Imposing";
        }
        else {
            if (nextSuit == "Spade" || nextSuit == "Club") {
                nextTrait = "Energetic";
            }
            else {
                nextTrait = "Couragious";
            }
        }
        traitList.append(nextTrait);
    } // end main loop

    // deformity
    RandomTable deformTable;
    deformTable.addEntry("Hunchback");
    deformTable.addEntry("Missing Eye");
    deformTable.addEntry("Missing Hand");
    deformTable.addEntry("Peg Leg");
    deformTable.addEntry("Club Foot");
    deformTable.addEntry("Albino");
    deformTable.addEntry("Asmatic");
    deformTable.addEntry("Sickly");
    deformTable.addEntry("Morbidly Obese");
    deformTable.addEntry("Cleft Lip");
    deformTable.addEntry("Missing Arm");
    deformTable.addEntry("Giantism");
    deformTable.addEntry("Dwarfism");
    deformTable.addEntry("Drug-adled");
    deformTable.addEntry("Drunk");
    deformTable.addEntry("Severe Gambling Addiction");

    // formulate report
    if (isHunchback) {
        traitList.append(deformTable.getRollTableEntry());
    }
    return traitList;


}

void PoliticalNpc::initCharacter()
{
    _isInit = true;
    Name = createName();
    Loyalty = Dice::roll(3, 6);
    Ambition = Dice::roll(3, 6);
    Leadership = Dice::roll(3, 6);
    Cunning = Dice::roll(3, 6);
    Subtlety = Dice::roll(3, 6);
    Perception = Dice::roll(3, 6);
    LocalSupport = Dice::roll(3, 6);

    Gender = (Dice::roll(1,6) < 4) ? "Male" : "Female";
    Age = Dice::roll(1,40) + 13;
    TraitList = createTraitList();
}

QString PoliticalNpc::asString()
{
    QString desc = Name + "\n"
            + "Gender: " + Gender + "\n"
            + "Age: " + QString::number(Age) + "\n"
            + "Loyalty: " + QString::number(Loyalty)
            + " (" + QString::number(getMod(Loyalty)) + ")\n"
            + "Ambition: " + QString::number(Ambition)
            + " (" + QString::number(getMod(Ambition)) + ")\n"
            + "Leadership: " + QString::number(Leadership)
            + " (" + QString::number(getMod(Leadership)) + ")\n"
            + "Cunning: " + QString::number(Cunning)
            + " (" + QString::number(getMod(Cunning)) + ")\n"
            + "Subtlety: " + QString::number(Subtlety)
            + " (" + QString::number(getMod(Subtlety)) + ")\n"
            + "Perception: " + QString::number(Perception)
            + " (" + QString::number(getMod(Perception)) + ")\n"
            + "Support: " + QString::number(LocalSupport)
            + " (" + QString::number(getMod(LocalSupport)) + ")\n"
            ;
    for (int i = 0; i < TraitList.size(); ++i) {
        desc += TraitList[i] + "\n";
    }

    return desc;


}

QString PoliticalNpc::createName()
{
    // NOTE: The file path needs to go in the run dirctory:
    // TODO: Figure out how to get more than one name out of this gen
    // (It generates the same first name it picks, over and over, possibly
    // from re-seeding)
    // Possibly look as sample code
    // TODO: select gender specific names from the referenced list
    // TODO: Create custom syllable list to draw names from.
    // TODO: Add a family name generator
    TCODNamegen::parse("namegen/mingos_norse.cfg");
    static char *newName = TCODNamegen::generate("Mingos Norse male");
    //char * newName = TCODNamegen::generate("Mingos Norse female");
    QString qName = QString(newName);
    TCODNamegen::destroy();
    return qName;
}

