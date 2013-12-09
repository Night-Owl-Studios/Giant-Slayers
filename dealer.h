/* 
 * File:   dealer.h
 * Author: hammy
 *
 * Created on December 6, 2013, 10:08 PM
 */

#ifndef __GSLAYERS_DEALER_H__
#define	__GSLAYERS_DEALER_H__

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

class dealer {
    private:
        deck* pDeck = nullptr;
        
    public:
        dealer          () {}
        dealer          (const dealer&) = delete;
        dealer          (dealer&&) = delete;
        
        virtual ~dealer () {}
        
        dealer&         operator=   (const dealer&) = delete;
        dealer&         operator=   (dealer&&) = delete;
        
        virtual bool    init        () = 0;
        void            terminate   ();
        
        void            shuffle     ();
        bool            canDeal     ();
        void            deal        (player* p);
};

template <typename deckType>
class dealer_t {
    
};

#endif	/* __GSLAYERS_DEALER_H__ */

