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
******************************************************************************/
deck::deck(const deck& cd) {
    this->operator =(cd);
}

deck::deck(deck&& cd) {
    this->operator =(std::move(cd));
}

/******************************************************************************
 * Card Deck Initialization
******************************************************************************/
deck::~deck() {
}

/******************************************************************************
 * Card Deck Copying & Moving
******************************************************************************/
deck& deck::operator =(const deck& cd) {
    //initialization for cards is done on an all-or-nothing basis.
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
    
    numCardsLeft = cd.numCardsLeft;
    return *this;
}

deck& deck::operator =(deck&& cd) {
    if (pCards) {
        terminate();
    }
    
    numCardsLeft = cd.numCardsLeft;
    cd.numCardsLeft = 0;
    
    pCards = cd.pCards;
    cd.pCards = nullptr;
    
    return *this;
}

/******************************************************************************
 * Card Deck Initialization
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
******************************************************************************/
void deck::terminate() {
    if (pCards) {
        if (pCards[0]) {
            for (unsigned i = 0; i < _MAX_CARDS_PER_DECK; ++i) {
                delete pCards[i];
                pCards[i] = nullptr;
            }
        }
        
        delete [] pCards;
        pCards = nullptr;
    }
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
}

/******************************************************************************
 * Card Deck Data Acquisition
******************************************************************************/
card* deck::useCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_DECK);
    #endif
    
    if (pCards) {
        numCardsLeft -= 1;
        return pCards[index];
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
