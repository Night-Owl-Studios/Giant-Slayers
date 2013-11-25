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
template <hashVal_t hash, const int cost, const cardStrength cs, const int strengthVal>
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
#ifndef _DECLARE_ATTACK_CARD
    #define _DECLARE_ATTACK_CARD(signature, name, ap, strength, val, flavor)\
        typedef attackCard<_GAME_HASH(name), ap, strength, val> attack_##signature;\
        \
        template <> inline const char* attack_##signature::getName() const { return name; }\
        template <> inline const char* attack_##signature::getFlavor() const { return flavor; }\
        template <> void attack_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const
#endif

/******************************************************************************
 * Attack Card Definition Macro
******************************************************************************/
#ifndef _DEFINE_ATTACK_CARD
    #define _DEFINE_ATTACK_CARD(signature)\
        template <>\
        void attack_##signature::applyToPlayers(player* pPlayer, player* pEnemy) const {\
            (void)pPlayer;\
            pEnemy->attack(getStrengthType(), getStrength());\
        }
#endif

/******************************************************************************
 * Attack Card Registrations
******************************************************************************/
/*
 * Aresa's Attacks
 */
_DECLARE_ATTACK_CARD(quickSlash, "Quick Slash", 1, cardStrength::normal, 200, "QUICK_SLASH");
_DECLARE_ATTACK_CARD(tripleStrike, "Triple Sword Strike", 1, cardStrength::heavy, 650, "TRIPLE_SWORD_STRIKE");
_DECLARE_ATTACK_CARD(furyStrike, "Fury Strike", 2, cardStrength::ultimate, 700, "FURY_STRIKE");
_DECLARE_ATTACK_CARD(deadlySlash, "Deadly Slash", 2, cardStrength::ultimate, 725, "DEADLY_SLASH");

/*
 * Minral's attacks
 */
_DECLARE_ATTACK_CARD(piercingShot, "Piercing Shot", 1, cardStrength::normal, 300, "PIERCING_SHOT");

#endif	/* __GSLAYER_ATTACKCARD_H__ */

