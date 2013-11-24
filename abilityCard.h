/* 
 * File:   abilityCard.h
 * Author: hammy
 *
 * Created on November 17, 2013, 6:58 PM
 */

#ifndef __GSLAYER_ABILITYCARD_H__
#define	__GSLAYER_ABILITYCARD_H__

#include "main.h"
#include "card.h"
#include "player.h"

/******************************************************************************
 * Ability Card Class
******************************************************************************/
template <const int cost, const cardAbility ca, const cardEffect ce>
class abilityCard : public card {
    private:
        
    public:
        abilityCard             ()                              = default;
        abilityCard             (const abilityCard&)            = default;
        abilityCard             (abilityCard&&)                 = default;
        
        virtual ~abilityCard    () {}
        
        abilityCard&            operator=       (const abilityCard&) = default;
        abilityCard&            operator=       (abilityCard&&) = default;
        
        /*
         * Inherited methods
         */
        int                     getApCost       () const        { return cost; }
        virtual const char*     getName         () const        = 0;
        virtual cardType        getType         () const        { return cardType::ability; }
        virtual card*           clone           () const        = 0;
        virtual void            applyToPlayers  (player* pPlayer, player* pEnemy) const = 0;
};

#endif	/* __GSLAYER_ABILITYCARD_H__ */

