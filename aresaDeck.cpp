/* 
 * File:   aresaDeck.cpp
 * Author: hammy
 * 
 * Created on November 24, 2013, 1:27 PM
 */

#include "aresaDeck.h"

/******************************************************************************
 * Aresa Deck Initialization
******************************************************************************/
bool aresaDeck::init() {
    if (!deck::init()) {
        terminate();
        return false;
    }
    
    for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
        /*
         * Populate an array of cards specific to Aresa
         */
    }
    
    return true;
}
