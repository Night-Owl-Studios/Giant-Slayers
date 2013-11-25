/* 
 * File:   abilityCard.h
 * Author: hammy
 *
 * Created on November 17, 2013, 6:58 PM
 */

#ifndef __GSLAYER_ABILITYCARD_H__
#define	__GSLAYER_ABILITYCARD_H__

#include <utility>
#include "main.h"
#include "card.h"
#include "player.h"
#include "cardTypes.h"

/******************************************************************************
 * Ability Card Class
******************************************************************************/
template <hashVal_t hash, const int cost, const cardAbility ca>
class abilityCard final : public card {
    private:
        
    public:
        abilityCard     ()                              = default;
        abilityCard     (const abilityCard&)            = default;
        abilityCard     (abilityCard&&)                 = default;
        
        ~abilityCard    () {}
        
        abilityCard&    operator=       (const abilityCard&) = default;
        abilityCard&    operator=       (abilityCard&&) = default;
        
        /*
         * Inherited methods
         */
        int             getApCost       () const        { return cost; }
        const char*     getName         () const; // template specialization
        cardType        getType         () const        { return cardType::ability; }
        card*           clone           () const        { return new(std::nothrow) abilityCard(*this); }
        
        // Ability card applicatino needs to be specialized on a per-card basis
        void            applyToPlayers  (player* pPlayer, player* pEnemy) const;
};

/******************************************************************************
 * Ability Card Registration Macro
******************************************************************************/
#ifndef _DECLARE_ABILITY_CARD
    #define _DECLARE_ABILITY_CARD(signature, name, ap, ability)\
        typedef abilityCard<_GAME_HASH(name), ap, ability> ability_##signature;\
        \
        template <> inline const char* ability_##signature::getName() const { return name; }\
        \
        template <> void ability_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const
#endif

/******************************************************************************
 * Ability Card Definition Macro
******************************************************************************/
#ifndef _DEFINE_ABILITY_CARD
    #define _DEFINE_ABILITY_CARD(signature)\
        template <>\
        void ability_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const
#endif

/******************************************************************************
 * Ability Card Registrations
******************************************************************************/
/*
 * Healing Cards
 */
_DECLARE_ABILITY_CARD(healingSalve, "Healing Salve", 2, cardAbility::healing);
_DECLARE_ABILITY_CARD(soothingBalm, "Soothing Balm", 2, cardAbility::healing);
_DECLARE_ABILITY_CARD(rejuvenatingCharm, "Rejuvenating Charm", 2, cardAbility::healing);
_DECLARE_ABILITY_CARD(curedMeat, "Cured Meat", 2, cardAbility::healing);
_DECLARE_ABILITY_CARD(ambrosia, "Ambrosia", 2, cardAbility::healing);

/*
 * Damage Mitigation
 */
_DECLARE_ABILITY_CARD(deflectedHit, "Deflected Hit", 1, cardAbility::damage_mitigation);
_DECLARE_ABILITY_CARD(quickReaction, "Quick Reaction", 1, cardAbility::damage_mitigation);
_DECLARE_ABILITY_CARD(adrenalineRush, "Adrenaline Rush", 1, cardAbility::damage_mitigation);

#endif	/* __GSLAYER_ABILITYCARD_H__ */

