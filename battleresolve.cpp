#include "battleresolve.h"

BattleResolve::BattleResolve()
{

}

void BattleResolve::fight(int attkPoints, int defPoints, int attkCcr, int defCcr, bool scavenge)
{
    int ccrFactor = 100;

    int accrVal = attkCcr * ccrFactor;
    int dccrVal = defCcr * ccrFactor;

    int attkVal = accrVal + attkPoints;
    int defVal = dccrVal + defPoints;

    int target = ((float)attkVal / (float)(attkVal + defVal)) * 100;

    _isAttkWins = Dice::roll(1, 100) <= target;

    int loserLoss = Dice::roll(1, 6);
    float loserLossFactor = (loserLoss == 1)
            ? 1.0f
            : (loserLoss <=4) ? 2.0f / 3.0f : 1.0f / 3.0f;
    int winnerLoss = Dice::roll(1, 6);
    float winnerLossFactor = (winnerLoss <= 2)
            ? 2.0f / 3.0f
            : (winnerLoss <= 4) ? 0.5f : 1.0f / 3.0f;

    // straglers - half of the losses that are back with the army after the battle.
    // prisoners - quarter of the losses of the losing army that are moderately wounded.
    // wounded - quarter of the losses of the winner that are moderately wounded, rejoin in 2 months
    // killed - quarter of the losses that are gone for good

    int attackBaseLoss;
    int defendBaseLoss;
    int attackStraglers;
    int defendStraglers;
    int attackModerateWounds;
    int defendModerateWounds;
    int attkKilled;
    int defKilled;
    float costFactor = scavenge ? 1.5f : 3.0f;

    if (_isAttkWins) {
        defendBaseLoss = ((float)defPoints * loserLossFactor);
        attackBaseLoss = (float)defendBaseLoss * winnerLossFactor;

        attackStraglers = (float)attackBaseLoss * 0.5f;
        defendStraglers = (float)defendBaseLoss * 0.5f;

        attackModerateWounds = (float)attackBaseLoss * 0.25f;
        defendModerateWounds = (float)defendBaseLoss * 0.25f;

        attkKilled = (float)attackBaseLoss * 0.25f;
        defKilled = (float)defendBaseLoss * 0.25f;

        _attkSurvivors = (attkPoints - attackBaseLoss) + attackStraglers;
        _defSurvivors = (defPoints - defendBaseLoss) + defendStraglers;

        _prisoners = defendModerateWounds;
        _winnerWounded = attackModerateWounds;

        _attkCost = (float)(attkPoints - _attkSurvivors) * costFactor;
        _defCost = (float)(defPoints - _defSurvivors) * 3.0f;
    }
    else {
        attackBaseLoss = ((float)attkPoints * loserLossFactor);
        defendBaseLoss = (float)attackBaseLoss * winnerLossFactor;
        attackStraglers = (float)attackBaseLoss * 0.5f;
        defendStraglers = (float)defendBaseLoss * 0.5f;
        attackModerateWounds = (float)attackBaseLoss * 0.25f;
        defendModerateWounds = (float)defendBaseLoss * 0.25f;
        attkKilled = (float)attackBaseLoss * 0.25f;
        defKilled = (float)defendBaseLoss * 0.25f;

        _attkSurvivors = (attkPoints - attackBaseLoss) + attackStraglers;
        _defSurvivors = (defPoints - defendBaseLoss) + defendStraglers;
        _prisoners = attackModerateWounds;
        _winnerWounded = defendModerateWounds;

        _attkCost = (float)(attkPoints - _attkSurvivors) * 3.0f;
        _defCost = (float)(defPoints - _defSurvivors) * costFactor;
    }

    _isCommanderKilled = Dice::roll(1,6) < 3;

}

void BattleResolve::recalcCosts(int attkPoints, int defPoints, bool scavenge)
{
    float costFactor = scavenge ? 1.5f : 3.0f;
    if (_isAttkWins) {
        _attkCost = (float)(attkPoints - _attkSurvivors) * costFactor;
        _defCost = (float)(defPoints - _defSurvivors) * 3.0f;
    }
    else {
        _attkCost = (float)(attkPoints - _attkSurvivors) * 3.0f;
        _defCost = (float)(defPoints - _defSurvivors) * costFactor;
    }
}

