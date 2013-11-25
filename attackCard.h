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
class attackCard final : public card {
    public:
        attackCard      ()                            = default;
        attackCard      (const attackCard&)           = default;
        attackCard      (attackCard&&)                = default;
        
        ~attackCard     ()              {}
        
        attackCard&     operator=       (const attackCard& ac) = default;
        attackCard&     operator=       (attackCard&& ac) = default;
        
        /*
         * Inherited methods
         */
        int             getApCost       () const        { return cost; }
        const char*     getName         () const;
        cardType        getType         () const        { return cardType::attack; }
        void            applyToPlayers  (player* pPlayer, player* pEnemy) const;
        card*           clone           () const        { return new(std::nothrow) attackCard(*this); }
        
        cardStrength    getStrengthType () const        { return cs; }
        int             getStrength     () const        { return strengthVal; }
        const char*     getFlavor       () const;
};

/******************************************************************************
 * Attack Card Registration Macro
 * NOTE:
 * The function "applyToPlayer()" still needs to be defined for all card types
******************************************************************************/
#define _DECLARE_ATTACK_CARD(signature, name, ap, strength, val, flavor)\
    typedef attackCard<ap, strength, val> attack_##signature;\
    \
    template <> inline const char* attack_##signature::getName() const { return name; }\
    template <> inline const char* attack_##signature::getFlavor() const { return flavor; }\
    template <> void attack_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const

/******************************************************************************
 * Attack Card Definition Macro
******************************************************************************/
#define _DEFINE_ATTACK_CARD(signature)\
    template <>\
    void attack_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const {\
        (void)pPlayer;\
        pEnemy->attack(getStrengthType(), getStrength());\
    }

/******************************************************************************
 * Attack Card Registrations
******************************************************************************/
_DECLARE_ATTACK_CARD(furyStrike, "Fury Strike", 2, cardStrength::heavy, 700, "FURY_STRIKE");

#endif	/* __GSLAYER_ATTACKCARD_H__ */

