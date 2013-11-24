/* 
 * File:   hand.h
 * Author: hammy
 *
 * Created on November 22, 2013, 8:21 PM
 */

#ifndef __GSLAYERS_HAND_H__
#define	__GSLAYERS_HAND_H__

#include "main.h"
#include "card.h"

/******************************************************************************
 * Hand Class
 *  Beware:
 *      Hand objects hold pointers to cards. Dereference all cards in the hand
 *      before freeing memory used by the card!
******************************************************************************/
class hand {
    
    /*
     * Playable card pair
     * Used to determine if a card is active or not
     */
    struct playableCard {
        bool    isActive    = false;
        card*   pCard       = nullptr;
    };

    private:
        playableCard cards[_MAX_CARDS_PER_HAND];

    public:
        hand        ();
        hand        (const hand&);
        hand        (hand&&);
        
        ~hand()     {clearHand();}
        
        hand&       operator=           (const hand&);
        hand&       operator=           (hand&&);
        
        bool        selectCard          (unsigned index); // return false if no more cards can be selected
        void        deselectCard        (unsigned index);
        
        /*
         * Returns an array of _MAX_CARDS_PER_HAND cards.
         * Read the array like a character string,
         * A nullptr means the end of the array has been reached
         */
        void        getSelectedCards    (card* cardArray[_MAX_CARDS_PER_HAND]);
        void        getCards            (card* cardArray[_MAX_CARDS_PER_HAND]);
        card*       getCard             (unsigned index);
        
        bool        isCardActive        (unsigned index);
        
        /*
         * Draw "numCards" from a deck until the hand is full.
         * Returns the number of cards drawn, up to _MAX_CARDS_PER_HAND
         */
        unsigned    drawCards           (deck*, unsigned numCards = 1);
        void        removeCard          (unsigned index);
        void        clearHand           ();
        
        unsigned    getNumSelectedCards () const;
        unsigned    getNumCards         () const;
};

#endif	/* __GSLAYERS_HAND_H__ */

