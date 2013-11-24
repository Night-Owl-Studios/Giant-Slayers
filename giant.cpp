/* 
 * File:   giant.cpp
 * Author: hammy
 * 
 * Created on November 23, 2013, 3:29 PM
 */

#include <utility>
#include "giant.h"

/******************************************************************************
 * Giant - Constructors & Destructors
******************************************************************************/
giant::giant() {
    startingHealth = global::pRandGen->randRangeF(_GIANT_MIN_HEALTH, _GIANT_MAX_HEALTH);
}

giant::giant(const giant& g) {
    this->operator =(g);
}

giant::giant(giant&& g) {
    this->operator =(std::move(g));
}

giant::~giant() {
}

/******************************************************************************
 * Giant - Assignment & Movement
******************************************************************************/
giant& giant::operator =(const giant& g) {
    player::operator    = (g);
    startingHealth      = g.startingHealth;
    return *this;
}

giant& giant::operator=(giant&& g) {
    player::operator    = (std::move(g));
    startingHealth      = g.startingHealth;
    return *this;
}

