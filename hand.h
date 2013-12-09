/* 
 * File:   hand.h
 * Author: hammy
 *
 * Created on November 22, 2013, 8:21 PM
 */

#ifndef __GSLAYERS_HAND_H__
#define	__GSLAYERS_HAND_H__

#include "main.h"

/******************************************************************************
 * Hand Class
 *  Beware:
 *      Hand objects only hold pointers to cards. Dereference all cards in the
 *      hand or deallocate a hand before freeing memory used by each card!
 * 
 * Hands are managed like character strings. a null-pointer means that the end
 * of the hand's card array has been reached when iterating.
******************************************************************************/
class hand {
    private:
        card* cards[_MAX_CARDS_PER_HAND+1] = {nullptr};

    public:
        hand        ();
        hand        (const hand&);
        hand        (hand&&);
        
        ~hand()     {clearHand();}
        
        hand&       operator=           (const hand&);
        hand&       operator=           (hand&&);
        
        void        addCard             (card*); // adds until the hand is full
        void        removeCard          (unsigned index);
        
        void        setCard             (unsigned index, card*);
        const card* getCard             (unsigned index);
        
        void        clearHand           ();
        unsigned    getNumCards         () const;
};

#endif	/* __GSLAYERS_HAND_H__ */

