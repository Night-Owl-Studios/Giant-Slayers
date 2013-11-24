/* 
 * File:   deck.cpp
 * Author: hammy
 * 
 * Created on November 17, 2013, 5:20 PM
 */

#include <new>
#include <utility>
#include "deck.h"
#include "card.h"

/******************************************************************************
 * Card Deck Copy & move constructors
 * 
 * These don't call the corresponding assignment operators due to the
 * possibility of creating a memory leak when initialized through inherited
 * objects' copy/move constructors.
******************************************************************************/
deck::deck(const deck& cd) {
    if (!cd.pCards || !cd.pCards[0]) {
        return;
    }
    
    if (!pCards) {
        // Attempt to initialize the card list
        if (!this->init()) {
            return;
        }
    }
    
    for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
        pCards[i] = cd.pCards[i]->clone();
        
        if (!pCards[i]) {
            terminate();
            return;
        }
    }
    
    drawOffset = cd.drawOffset;
}

/*
 * Move Constructor
 */
deck::deck(deck&& cd) {
    drawOffset = cd.drawOffset;
    cd.drawOffset = 0;
    
    pCards = cd.pCards;
    cd.pCards = nullptr;
}

/******************************************************************************
 * Card Deck Initialization
******************************************************************************/
deck::~deck() {
}

/******************************************************************************
 * Card Deck Copying & Moving
 * 
 * Initialization for cards is done on an all-or-nothing basis. If one card
 * fails to initialize, terminate everything.
******************************************************************************/
deck& deck::operator =(const deck& cd) {
    // If the first card isn't a NULL pointer, no card is a NULL pointer
    if (!cd.pCards || !cd.pCards[0]) {
        return *this;
    }
    
    if (!pCards) {
        // Attempt to initialize the card list
        if (!this->init()) {
            return *this;
        }
    }
    
    for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
        delete pCards[i];
        
        pCards[i] = cd.pCards[i]->clone();
        
        if (!pCards[i]) {
            terminate();
            return *this;
        }
    }
    
    drawOffset = cd.drawOffset;
    return *this;
}

deck& deck::operator =(deck&& cd) {
    if (pCards) {
        terminate();
    }
    
    drawOffset = cd.drawOffset;
    cd.drawOffset = 0;
    
    pCards = cd.pCards;
    cd.pCards = nullptr;
    
    return *this;
}

/******************************************************************************
 * Card Deck Initialization
 * 
 * Creates an array of 50 card pointers.
 * The array should be populated by individual deck types.
******************************************************************************/
bool deck::init() {
    if (pCards) {
        terminate();
    }
    
    pCards = new(std::nothrow) card*[_MAX_CARDS_PER_DECK];
    
    if (!pCards) {
        return false;
    }
    
    for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
        pCards[i] = nullptr;
    }
    
    return true;
}

/******************************************************************************
 * Card Deck Termination
 * 
 * Delete all cards before destroying the deck array
******************************************************************************/
void deck::terminate() {
    drawOffset = 0;
    
    if (pCards) {
        for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
            delete pCards[i];
            pCards[i] = nullptr;
        }
    }
    
    delete [] pCards;
    pCards = nullptr;
}

/******************************************************************************
 * Card Deck Shuffling
******************************************************************************/
void deck::shuffle() {
    if (!isInitialized()) {
        return;
    }
    
    // Swap each card in the deck with a random one
    for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
        unsigned long randIndex = global::pRandGen->genRandNum() % _MAX_CARDS_PER_DECK;
        card* currentCard = pCards[i];
        pCards[i] = pCards[randIndex];
        pCards[randIndex] = currentCard;
    }
    
    drawOffset = 0;
}

/******************************************************************************
 * Card Deck Data Acquisition
******************************************************************************/
card* deck::pullCard() {
    if (pCards && drawOffset != _MAX_CARDS_PER_DECK) {
        return pCards[drawOffset++];
    }
    
    return nullptr;
}

/******************************************************************************
 * Card Deck Data Acquisition
******************************************************************************/
card* deck::getCard(unsigned index) const {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_DECK);
    #endif
    
    return pCards ? pCards[index] : nullptr;
}
