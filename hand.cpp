/* 
 * File:   hand.cpp
 * Author: hammy
 * 
 * Created on November 22, 2013, 8:21 PM
 */

#include <utility>
#include "card.h"
#include "hand.h"
#include "deck.h"

/******************************************************************************
 * Hand Constructors
******************************************************************************/
hand::hand() {
}

hand::hand(const hand& h) {
    this->operator =(h);
}

hand::hand(hand&& h) {
    this->operator=(std::move(h));
}

/******************************************************************************
 * Hand Assignments
******************************************************************************/
hand& hand::operator =(const hand& h) {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        cards[i] = h.cards[i]->clone();
    }
    return *this;
}

hand& hand::operator =(hand&& h) {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        cards[i] = h.cards[i];
        h.cards[i] = nullptr;
    }
    return *this;
}


/******************************************************************************
 * Hand - Individual Card Acquisition
******************************************************************************/
const card* hand::getCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
    #endif

    return cards[index];
}

/******************************************************************************
 * Hand - Adding a card by index
******************************************************************************/
void hand::setCard(unsigned index, card* pCard) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
    #endif
    
    if (pCard == nullptr) {
        removeCard(index);
        return;
    }
    
    if (cards[index] == nullptr && pCard != nullptr) {
        addCard(pCard);
    }
    else {
        cards[index] = pCard;
    }
}

/******************************************************************************
 * Hand - Adding a card
******************************************************************************/
void hand::addCard(card* pCard) {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        if (cards[i] == nullptr) {
            cards[i] = pCard;
            break;
        }
    }
}

/******************************************************************************
 * Hand - Card Removal
******************************************************************************/
void hand::removeCard(unsigned index) {
    #ifdef _DEBUG
        HL_ASSERT(index < _MAX_CARDS_PER_HAND);
    #endif
    
    if (cards[index] == nullptr) {
        return;
    }
    
    if (index == _MAX_CARDS_PER_HAND-1) {
        cards[index] = nullptr;
        return;
    }
    
    // make sure that there is a contiguous array of non-null pointers
    for (unsigned i = index, j = index+1; i < _MAX_CARDS_PER_HAND; ++i, ++j) {
        if (cards[j] == nullptr && cards[i] == nullptr) {
            break;
        }
        
        cards[i] = cards[j];
    }
}

/******************************************************************************
 * Hand - Card Removal
******************************************************************************/
void hand::clearHand() {
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        cards[i] = nullptr;
    }
}

/******************************************************************************
 * Hand - Card Count information
******************************************************************************/
unsigned hand::getNumCards() const {
    unsigned numCards = 0;
    for (unsigned i = 0; i < _MAX_CARDS_PER_HAND; ++i) {
        if (cards[i] != nullptr) {
            ++numCards;
        }
        else {
            break;
        }
    }
    
    return numCards;
}
