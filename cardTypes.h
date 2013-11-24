/* 
 * File:   cardEffects.h
 * Author: hammy
 *
 * Created on November 19, 2013, 8:54 PM
 */

#ifndef __GSLAYER_CARDEFFECTS_H__
#define	__GSLAYER_CARDEFFECTS_H__

#include "main.h"

/*
 * Card Types
 */
enum class cardType {
    attack,
    ability
};

/*
 * Card Ability Types
 */
enum class cardAbility {
    attack_increase,
    attack_multiply,
    damage_mitigation,
    dodge,
    healing
};

/*
 * Card Effect Types
 */
enum class cardEffect {
    add,
    subtract,
    multiply
};

/*
 * Card Strength Types
 */
enum class cardStrength {
    normal,
    heavy,
    ultimate
};


#endif	/* __GSLAYER_CARDEFFECTS_H__ */

