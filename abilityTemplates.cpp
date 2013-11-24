/* 
 * File:   abilityTemplates.cpp
 * Author: hammy
 * 
 * Created on November 18, 2013, 7:40 PM
 */

#include "player.h"
#include "abilityTemplates.h"


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