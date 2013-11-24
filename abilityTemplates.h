/* 
 * File:   abilityTemplates.h
 * Author: hammy
 *
 * Created on November 18, 2013, 7:40 PM
 */

#ifndef __GSLAYER_ABILITYTEMPLATES_H__
#define	__GSLAYER_ABILITYTEMPLATES_H__

#include <utility>
#include "main.h"
#include "abilityCard.h"
#include "cardTypes.h"

/******************************************************************************
 * Ability Card Registration Macro
******************************************************************************/
#define _DECLARE_ABILITY_CARD(signature, name, ap, ability, effect)\
    typedef abilityCard<ap, ability, effect> ability_##signature;\
    \
    class signature final : public abilityCard<ap, ability, effect> {\
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
            card*           clone           () const                { return new(std::nothrow) signature(*this); }\
            void            applyToPlayers  (player* pPlayer, player* pEnemy) const;\
    }

/******************************************************************************
 * Ability Card Definition Macro
******************************************************************************/
#define _DEFINE_ABILITY_CARD(signature)\
    void signature::applyToPlayers(player* pPlayer, player* pEnemy) const\

/******************************************************************************
 * Attack Card Registrations
******************************************************************************/
_DECLARE_ABILITY_CARD(ambrosia, "Ambrosia", 2, cardAbility::healing, cardEffect::add);

#endif	/* __GSLAYER_ABILITYTEMPLATES_H__ */
