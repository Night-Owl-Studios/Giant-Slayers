/* 
 * File:   cardEffects.h
 * Author: hammy
 *
 * Created on November 19, 2013, 8:54 PM
 */

#ifndef __GSLAYER_CARDTYPES_H__
#define	__GSLAYER_CARDTYPES_H__

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
 * Card Strength Types
 */
enum class cardStrength {
    normal,
    heavy,
    ultimate
};


#endif	/* __GSLAYER_CARDTYPES_H__ */

