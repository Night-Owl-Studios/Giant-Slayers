/* 
 * File:   player.h
 * Author: hammy
 *
 * Created on November 17, 2013, 5:18 PM
 */

#ifndef __GSLAYER_PLAYER_H__
#define	__GSLAYER_PLAYER_H__

#include <vector>
#include "main.h"
#include "hand.h"
#include "cardTypes.h"

/******************************************************************************
 * Player Effects to be used by cards
******************************************************************************/
struct playerEffect {
    cardAbility effect;
    short duration;
    float amount;
};

/******************************************************************************
 * Typedefs
******************************************************************************/
typedef std::vector<playerEffect> effectList;

/* incoming damage is calculated as follows:
 *      health = (global::pRandGen->getRandRangeF(0.f, 1.f) <= dodgeChance)
 *          ? health
 *          : health - (damage * (1-fortification))
 *
 * Damage is added as:
 *      totalDamage = baseDamage * strength
 */

/******************************************************************************
 * Player class
******************************************************************************/
class player {
    private:
        float health        = 1.f;
        float fortification = _PLAYER_DEFAULT_FORTIFICATION; // Range: 0-1
        float dodgeChance   = _PLAYER_DEFAULT_DODGE_CHANCE;  // Range: 0-1
        float strength      = _PLAYER_DEFAULT_STRENGTH;      // Range: 0-1
        hand* pHand         = nullptr;
        effectList activeEffects;
        
    public:
        player              () {}
        player              (const player&);
        player              (player&&);
        
        virtual ~player     () = 0;
        
        player&             operator=           (const player&); // Does not copy hands
        player&             operator=           (player&&);
        
        bool                init                ();
        void                terminate           ();
        
        virtual float       getStartingHealth   () const = 0;
        float               getHealth           () const;
        void                setHealth           (float);
        
        float               getFortification    () const;
        float               getStrength         () const;
        float               getDodgeChance      () const;
        
        hand*               getHand             () { return pHand; }
        
        virtual void        playSelectedCards   (player* pEnemy);
        
        const effectList&   getActiveEffects    () const;
        
        // The following are used by polymorphic card types only
        void                attack              (cardStrength, float amount);
        void                applyEffect         (cardAbility, short duration, float amount);
        
        void                updateStats         ();
        
        virtual void        tick                (float) {}
        virtual void        draw                () const {}
};

/******************************************************************************
 * Get player health
******************************************************************************/
inline float player::getHealth() const {
    return health;
}

/******************************************************************************
 * Set player health
******************************************************************************/
inline void player::setHealth(float h) {
    health = h;
}

/******************************************************************************
 * Get p[layer shields
 *      Use after updating the player statistics
******************************************************************************/
inline float player::getFortification() const {
    return fortification;
}

/******************************************************************************
 * Get player strength
 *      Use after updating the player statistics
******************************************************************************/
inline float player::getStrength() const {
    return strength;
}

/******************************************************************************
 * Get player dodge chance
 *      Use after updating the player statistics
******************************************************************************/
inline float player::getDodgeChance() const {
    return dodgeChance;
}

/******************************************************************************
 * Player - Receiving an attack
******************************************************************************/
inline void player::attack(cardStrength, float amount) {
    health = (global::pRandGen->randRangeF(0.f, 1.f) <= dodgeChance)
        ? health
        : health - (amount * (1-fortification));
}


/******************************************************************************
 * Apply effects to players
 *      Should be used by cards or other players directly
******************************************************************************/
inline void player::applyEffect(cardAbility ca, short duration, float amount) {
    playerEffect pe;
    pe.effect = ca;
    pe.duration = duration;
    pe.amount = amount;
    activeEffects.push_back(pe);
}

/******************************************************************************
 * Acquire player statistics
******************************************************************************/
inline const effectList& player::getActiveEffects() const {
    return activeEffects;
}

#endif	/* __GSLAYER_PLAYER_H__ */

