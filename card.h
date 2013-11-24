/* 
 * File:   card.h
 * Author: hammy
 *
 * Created on November 17, 2013, 5:18 PM
 */

#ifndef __GSLAYER_CARD_H__
#define	__GSLAYER_CARD_H__

#include "main.h"
#include "cardTypes.h"

/******************************************************************************
 * Card Class
******************************************************************************/
class card {
    public:
        card                    ()              = default;
        card                    (const card&)   = default;
        card                    (card&&)        = default;
        
        virtual ~card           ()              = default;
        
        card&                   operator=       (const card&)   = default;
        card&                   operator=       (card&&)        = default;

        virtual int             getApCost       () const        = 0;
        virtual const char*     getName         () const        = 0;
        virtual cardType        getType         () const        = 0;
        virtual void            applyToPlayers  (player* pPlayer, player* pEnemy) const = 0;
        virtual card*           clone           () const        = 0;
};

#endif	/* __GSLAYER_CARD_H__ */

