/* 
 * File:   abilityCard.cpp
 * Author: hammy
 * 
 * Created on November 17, 2013, 6:58 PM
 */

#include "abilityCard.h"

/******************************************************************************
 * Ability Card Registrations
******************************************************************************/
/*
 * Healing cards
 */
_DEFINE_ABILITY_CARD(healingSalve) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::healing, 0, global::pRandGen->randRangeF(0.4f, 0.5f));
}

_DEFINE_ABILITY_CARD(soothingBalm) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::healing, 0, global::pRandGen->randRangeF(0.4f, 0.5f));
}

_DEFINE_ABILITY_CARD(rejuvenatingCharm) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::healing, 0, global::pRandGen->randRangeF(0.4f, 0.5f));
}

_DEFINE_ABILITY_CARD(curedMeat) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::healing, 0, global::pRandGen->randRangeF(0.4f, 0.5f));
}

_DEFINE_ABILITY_CARD(ambrosia) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::healing, 0, global::pRandGen->randRangeF(0.4f, 0.5f));
}

/*
 * Damage Mitigation
 */
_DEFINE_ABILITY_CARD(deflectedHit) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::damage_mitigation, 1, global::pRandGen->randRangeF(0.1f, 0.2f));
}

_DEFINE_ABILITY_CARD(quickReaction) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::damage_mitigation, 1, global::pRandGen->randRangeF(0.1f, 0.2f));
}

_DEFINE_ABILITY_CARD(adrenalineRush) {
    (void)pEnemy;
    pPlayer->applyEffect(cardAbility::damage_mitigation, 1, global::pRandGen->randRangeF(0.1f, 0.2f));
}
