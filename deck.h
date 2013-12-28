/* 
 * File:   deck.h
 * Author: hammy
 *
 * Created on November 17, 2013, 5:20 PM
 */

#ifndef __GSLAYER_CARD_DECK_H__
#define	__GSLAYER_CARD_DECK_H__

#include <utility>
#include "main.h"

/*
 * Card Deck Specialities
 */
enum class deckAbility {
    mul_sub, // Aresa
    add_div // Minral
};

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
    protected:
        unsigned drawOffset = 0;
        card** pCards = nullptr; // Array of 50 cards
        
    public:
        deck                () {}
        deck                (const deck&);
        deck                (deck&&);
        
        virtual ~deck       () = 0;
        
        deck&               operator=           (const deck&);
        deck&               operator=           (deck&&);
        
        virtual bool        init                (); // creates an array of pointers
        void                terminate           (); // destroys the array & pointers
        bool                isInitialized       () const;
        
        virtual deckType    getDeckType         () const = 0;
        virtual deckAbility getSpecialAbility   () const = 0;
        
        unsigned            getNumCardsLeft     () const;
        
        void                shuffle             ();
        
        card*               pullCard            (); // increments drawOffset
        card*               getCard             (unsigned index) const;
};

/*
 * Card Deck Remaining Card Count
 */
inline unsigned deck::getNumCardsLeft() const {
    return _MAX_CARDS_PER_DECK-drawOffset;
}

/*
 * Card Deck Initialization Check
*/
inline bool deck::isInitialized() const {
    return pCards != nullptr && pCards[0] != nullptr;
}

/******************************************************************************
 * Deck Type Templates
******************************************************************************/
template <deckType dt, deckAbility da>
class deck_t : virtual public deck {
    public:
        deck_t      ();
        deck_t      (const deck_t&);
        deck_t      (deck_t&&);
        
        ~deck_t     ();
        
        deck_t&     operator =          (const deck_t&);
        deck_t&     operator =          (deck_t&&);
        
        bool        init                ();
        
        deckType    getDeckType         () const { return dt; }
        deckAbility getSpecialAbility   () const { return da; }
};

/*
 * Deck Template Constructor
 */
template <deckType dt, deckAbility da>
deck_t<dt, da>::deck_t() :
    deck()
{}

/*
 * Deck Template Move & Assignment
 */
template <deckType dt, deckAbility da>
deck_t<dt, da>::deck_t(const deck_t<dt, da>& ad) :
    deck(ad)
{}

template <deckType dt, deckAbility da>
deck_t<dt, da>::deck_t(deck_t<dt, da>&& ad) :
    deck(std::move(ad))
{}

/*
 * Deck Template Destructor
 */
template <deckType dt, deckAbility da>
deck_t<dt, da>::~deck_t<dt, da>() {
}

/*
 * Deck Template Copy & Move Assignment
 */
template <deckType dt, deckAbility da>
deck_t<dt, da>& deck_t<dt, da>::operator =(const deck_t<dt, da>& ad) {
    deck::operator =(ad);
    return *this;
}

template <deckType dt, deckAbility da>
deck_t<dt, da>& deck_t<dt, da>::operator =(deck_t<dt, da>&& ad) {
    deck::operator =(std::move(ad));
    return *this;
}

#endif	/* __GSLAYER_CARD_DECK_H__ */
