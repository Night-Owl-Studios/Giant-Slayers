/* 
 * File:   attackTemplates.h
 * Author: hammy
 *
 * Created on November 17, 2013, 7:31 PM
 */

#ifndef __GSLAYER_ATTACKTEMPLATES_H__
#define	__GSLAYER_ATTACKTEMPLATES_H__

#include <utility>
#include "main.h"
#include "attackCard.h"

/*
 * NOTE:
 * The function "applyToPlayer()" still needs to be defined for all card types
 */
/******************************************************************************
 * Attack Card Registration Macro
******************************************************************************/
#define _DECLARE_ATTACK_CARD(signature, name, ap, strength, val, flavor)\
    typedef attackCard<ap, strength, val> attack_##signature;\
    \
    class signature final : public attackCard<ap, strength, val> {\
        public:\
            signature       () = default;\
            signature       (const signature&) = default;\
            signature       (signature&&) = default;\
            \
            ~signature      ()              = default;\
            \
            signature&      operator=       (const signature&) = default;\
            signature&      operator=       (signature&&) = default;\
            \
            const char*     getName         () const                { return name; }\
            void            applyToPlayers  (player* pPlayer, player* pEnemy) const;\
            card*           clone           () const                { return new(std::nothrow) signature(*this); }\
            const char*     getFlavor       () const                { return flavor; }\
    }

/******************************************************************************
 * Attack Card Definition Macro
******************************************************************************/
#define _DEFINE_ATTACK_CARD(signature)\
    void signature::applyTpPlayers(player* pPlayer, player* pEnemy) const {\
        (void)pPlayer;\
        pEnemy->attack(pEnemy, getStrengthType(), getStrength());\
    }

/******************************************************************************
 * Attack Card Registrations
******************************************************************************/
_DECLARE_ATTACK_CARD(furyStrike, "Fury Strike", 2, cardStrength::heavy, 700, "FURY_STRIKE");

#endif	/* __GSLAYER_ATTACKTEMPLATES_H__ */

