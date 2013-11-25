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
_DEFINE_ABILITY_CARD(ambrosia) {
    (void)pEnemy;
    
    pPlayer->applyEffect(
        cardAbility::healing,
        0,
        global::pRandGen->randRangeF(0.4f, 0.5f)
    );
}