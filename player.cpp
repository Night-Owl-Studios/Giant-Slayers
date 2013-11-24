/* 
 * File:   player.cpp
 * Author: hammy
 * 
 * Created on November 17, 2013, 5:18 PM
 */

#include <new>
#include <iostream>
#include <utility>
#include "main.h"
#include "player.h"

/******************************************************************************
 * Player Constructors
******************************************************************************/
player::player(const player& p) {
    health          = p.health;
    fortification   = p.fortification;
    dodgeChance     = p.dodgeChance;
    strength        = p.strength;
    activeEffects   = p.activeEffects;
}

player::player(player&& p) {
    health          = p.health;
    p.health        = 1.f;
    
    fortification   = p.fortification;
    p.fortification = _PLAYER_DEFAULT_FORTIFICATION;
    
    dodgeChance     = p.dodgeChance;
    p.dodgeChance   = _PLAYER_DEFAULT_DODGE_CHANCE;
    
    strength        = p.strength;
    p.strength      = _PLAYER_DEFAULT_STRENGTH;
    
    activeEffects   = std::move(p.activeEffects);
    
    pHand = p.pHand;
    p.pHand = nullptr;
}

/******************************************************************************
 * Player Destructor
******************************************************************************/
player::~player() {
}

/******************************************************************************
 * Player Copy/Move Operators
******************************************************************************/
player& player::operator=(const player& p) {
    health          = p.health;
    fortification   = p.fortification;
    dodgeChance     = p.dodgeChance;
    strength        = p.strength;
    activeEffects   = p.activeEffects;
    return *this;
}

player& player::operator=(player&& p) {
    health          = p.health;
    p.health        = 1.f;
    
    fortification   = p.fortification;
    p.fortification = _PLAYER_DEFAULT_FORTIFICATION;
    
    dodgeChance     = p.dodgeChance;
    p.dodgeChance   = _PLAYER_DEFAULT_DODGE_CHANCE;
    
    strength        = p.strength;
    p.strength      = _PLAYER_DEFAULT_STRENGTH;
    
    activeEffects   = std::move(p.activeEffects);
    
    pHand = p.pHand;
    p.pHand = nullptr;
    
    return *this;
}

/******************************************************************************
 * Player Initialization
******************************************************************************/
bool player::init() {
    if (pHand) {
        terminate();
    }
    
    health          = 1.f;
    fortification   = _PLAYER_DEFAULT_FORTIFICATION;
    dodgeChance     = _PLAYER_DEFAULT_DODGE_CHANCE;
    strength        = _PLAYER_DEFAULT_STRENGTH;
    pHand           = new(std::nothrow) hand();
    
    return pHand != nullptr;
}

/******************************************************************************
 * Player Termination
******************************************************************************/
void player::terminate() {
    delete pHand;
    pHand = nullptr;
}

/******************************************************************************
 * Player - Play the currently selected hand
******************************************************************************/
void player::playSelectedCards(player* pEnemy) {
    for (unsigned int i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        if (pHand->isCardActive(i) == false) {
            continue;
        }
        
        card* pCard = pHand->getCard(i);
        pCard->applyToPlayers(this, pEnemy);
        pHand->removeCard(i);
    }
}

/******************************************************************************
 * Player Stats update
******************************************************************************/
void player::updateStats() {
    fortification = _PLAYER_DEFAULT_FORTIFICATION;
    dodgeChance   = _PLAYER_DEFAULT_DODGE_CHANCE;
    strength      = _PLAYER_DEFAULT_STRENGTH;
    
    for (unsigned i = 0; i < activeEffects.size(); ++i) {
        
        playerEffect& pe = activeEffects[i];
        
        switch(pe.effect) {
            case cardAbility::attack_increase:
                strength += pe.amount;
                break;
            case cardAbility::attack_multiply:
                strength *= pe.amount;
                break;
            case cardAbility::damage_mitigation:
                fortification += pe.amount;
                break;
            case cardAbility::dodge:
                dodgeChance = 1.f;
                break;
            case cardAbility::healing:
                health += getStartingHealth() * (1.f+pe.amount);
                break;
            default:
                std::cerr << "Error: Unknown card ability applied to player." << std::endl;
        }
        
        if (pe.duration == -1) {
            // infinite ability
            continue;
        }
        else if (pe.duration > 0) {
            pe.duration -= 1;
        }
        else {
            activeEffects.erase(activeEffects.begin() + i);
            --i;
        }
    }
}
