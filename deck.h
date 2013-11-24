/* 
 * File:   deck.h
 * Author: hammy
 *
 * Created on November 17, 2013, 5:20 PM
 */

#ifndef __GSLAYER_CARD_DECK_H__
#define	__GSLAYER_CARD_DECK_H__

#include "main.h"

/*
 * Card Deck Types
 */
enum class deckType {
    aresa_deck,
    minral_deck
};

/******************************************************************************
 * Card Deck
 * 
 * NOTES:
 *  It is the responsibility of derived objects to populate their deck arrays
******************************************************************************/
class deck {
    private:
        unsigned numCardsLeft = 0;
        card** pCards = nullptr; // Array of 50 cards
        
    public:
        deck() {}
        deck(const deck&);
        deck(deck&&);
        
        virtual ~deck() = 0;
        
        deck&               operator=           (const deck&);
        deck&               operator=           (deck&&);
        
        virtual bool        init                (); // creates an array of pointers
        virtual void        terminate           (); // destroys the array & cards
        bool                isInitialized       () const;
        
        virtual void        applySpecialAbility () = 0;
        virtual deckType    getDeckType         () const = 0;
        
        unsigned            getNumCardsLeft     () { return numCardsLeft; }
        
        void                shuffle             ();
        
        // Overloading the subscript operator might get confusing
        card*               useCard             (unsigned index); // decrements numCardsLeft
        card*               getCard             (unsigned index) const;
};

/******************************************************************************
 * Card Deck Initialization Check
******************************************************************************/
inline bool deck::isInitialized() const {
    return pCards != nullptr && pCards[0] != nullptr;
}

#endif	/* __GSLAYER_CARD_DECK_H__ */
