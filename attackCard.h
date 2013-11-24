/* 
 * File:   attackCard.h
 * Author: hammy
 *
 * Created on November 17, 2013, 6:44 PM
 */

#ifndef __GSLAYER_ATTACKCARD_H__
#define	__GSLAYER_ATTACKCARD_H__

#include <utility>
#include "main.h"
#include "card.h"
#include "cardTypes.h"

/******************************************************************************
 * Attack Card Class
******************************************************************************/
template <const int cost, const cardStrength cs, const int strengthVal>
class attackCard : public card {
    public:
        attackCard()                            = default;
        attackCard(const attackCard&)           = default;
        attackCard(attackCard&&)                = default;
        
        virtual ~attackCard     ()              = default;
        
        attackCard&             operator=       (const attackCard& ac) = default;
        attackCard&             operator=       (attackCard&& ac) = default;
        
        /*
         * Inherited methods
         */
        int                     getApCost       () const        { return cost; }
        virtual const char*     getName         () const        = 0;
        virtual cardType        getType         () const        { return cardType::attack; }
        virtual void            applyToPlayers  (player* pPlayer, player* pEnemy) const = 0;
        virtual card*           clone           () const        = 0;
        
        cardStrength            getStrengthType () const        { return cs; }
        int                     getStrength     () const        { return strengthVal; }
        virtual const char*     getFlavor       () const        { return "No Flavor!"; }
};

#endif	/* __GSLAYER_ATTACKCARD_H__ */

