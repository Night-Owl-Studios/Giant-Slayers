/* 
 * File:   dealer.cpp
 * Author: hammy
 * 
 * Created on December 6, 2013, 10:08 PM
 */

#include <utility>
#include "dealer.h"
#include "aresaDeck.h"
#include "minralDeck.h"

/******************************************************************************
 * Dealer initialization
 *****************************************************************************/
bool dealer::init(deckType type) {
    if (pDeck != nullptr) {
        terminate();
    }
    
    switch (type) {
        case        deckType::aresa_deck:   pDeck = new(std::nothrow) aresaDeck;    break;
        case        deckType::minral_deck:  pDeck = new(std:::nothrow) minralDeck;  break;
        default:                            pDeck = nullptr;
    }
    
    if (pDeck == nullptr || !pDeck->init()) {
        return false;
    }
    
    return true;
}

/******************************************************************************
 * Dealer termination
 *****************************************************************************/
void dealer::terminate() {
    if (pDeck != nullptr) {
        pDeck->terminate();
        delete pDeck;
        pDeck = nullptr;
    }
}

/******************************************************************************
 * Shuffling a deck
 *****************************************************************************/
void dealer::shuffle() {
    #ifdef _DEBUG
        HL_ASSERT(pDeck != nullptr);
    #endif
    
    pDeck->shuffle();
}

/******************************************************************************
 * Can a dealer deal?
 *****************************************************************************/
bool dealer::canDeal() {
    #ifdef _DEBUG
        HL_ASSERT(pDeck != nullptr);
    #endif
    
    return pDeck->getNumCardsLeft() != 0;
}

/******************************************************************************
 * Dealing cards
 *****************************************************************************/
void dealer::deal(player* pPlayer) {
    #ifdef _DEBUG
        HL_ASSERT(pDeck != nullptr && pPlayer != nullptr && pPlayer->getHand() != nullptr);
    #endif
    
    hand* pHand = pPlayer->getHand();
    
    while ( pDeck->getNumCardsLeft() > 0
    &&      pHand->getNumCards() < _MAX_CARDS_PER_HAND
    ) {
        pHand->addCard(pDeck->pullCard());
    }
}
