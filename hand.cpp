/* 
 * File:   hand.cpp
 * Author: hammy
 * 
 * Created on November 22, 2013, 8:21 PM
 */

#include "hand.h"
#include "deck.h"

/******************************************************************************
 * Hand Constructor
******************************************************************************/
hand::hand() {
}

/******************************************************************************
 * Hand - Card Selection
******************************************************************************/
bool hand::selectCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
        HL_ASSERT(cards[index].pCard != nullptr);
    #endif
    
    unsigned numActiveCards = 0;
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        if (cards[i].isActive == true && numActiveCards  < _MAX_CARDS_PER_HAND) {
            ++numActiveCards;
        }
        else {
            return false;
        }
    }
    
    cards[index].isActive = true;
    return true;
}

/******************************************************************************
 * Hand - Card Deselection
******************************************************************************/
void hand::deselectCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
        HL_ASSERT(cards[index].pCard != nullptr);
    #endif
    
        cards[index].isActive = false;
}

/******************************************************************************
 * Hand - Active Card Acquisition
******************************************************************************/
void hand::getSelectedCards(card* cardArray[_MAX_CARDS_PER_HAND]) {
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = _MAX_CARDS_PER_HAND-1;
    
    while (i <= k) {
        cardArray[i] = (cards[i].isActive)
            ? cardArray[++j] = cards[i].pCard
            : cardArray[--k] = nullptr;
        ++i;
    }
}

/******************************************************************************
 * Hand - Card Acquisition
******************************************************************************/
void hand::getCards(card* cardArray[_MAX_CARDS_PER_HAND]) {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        cardArray[i] = cards[i].pCard;
    }
}

/******************************************************************************
 * Hand - Individual Card Acquisition
******************************************************************************/
card* hand::getCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
        HL_ASSERT(cards[index].pCard != nullptr);
    #endif

    return cards[index].pCard;
}

/******************************************************************************
 * Hand - Individual Card Information
******************************************************************************/
bool hand::isCardActive(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
        HL_ASSERT(cards[index].pCard != nullptr);
    #endif
    
    return cards[index].isActive;
}

/******************************************************************************
 * Hand - Drawing from a deck
******************************************************************************/
unsigned hand::draw(deck* d, unsigned numCards) {
    #ifdef _DEBUG
        HL_ASSERT(d != nullptr);
        HL_ASSERT(numCards <= _MAX_CARDS_PER_HAND);
    #endif
    
    numCards = (numCards > d->getNumCardsLeft())
        ? d->getNumCardsLeft()
        : numCards;
    
    for (unsigned i = 0; i < numCards; ++i) {
        cards[i].pCard = d->getCard(i);
        cards[i].isActive = false;
    }
    
    return numCards;
}

/******************************************************************************
 * Hand - Card Removal
******************************************************************************/
void hand::removeCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
    #endif
    
    cards[index].isActive = false;
    cards[index].pCard = nullptr;
}

/******************************************************************************
 * Hand - Card Removal
******************************************************************************/
void hand::clearHand() {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        cards[i].isActive = false;
        cards[i].pCard = nullptr;
    }
}

/******************************************************************************
 * Hand - Card Selection information
******************************************************************************/
unsigned hand::getNumSelectedCards() const {
    unsigned numSelectedCards = 0;
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        if (cards[i].isActive == true) {
            ++numSelectedCards;
        }
    }
    
    return numSelectedCards;
}
