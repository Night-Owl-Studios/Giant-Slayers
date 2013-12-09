/* 
 * File:   giant.h
 * Author: hammy
 *
 * Created on November 23, 2013, 3:29 PM
 */

#ifndef __GSLAYERS_GIANT_H__
#define	__GSLAYERS_GIANT_H__

#include "main.h"
#include "player.h"

class giant : virtual public player {
    private:
        mutable float startingHealth; // Shouldn't change unless the giant is copied
        card* pCard = nullptr;
        
    public:
        giant       ();
        giant       (const giant&);
        giant       (giant&&);
        
        ~giant      ();
        
        giant&      operator=           (const giant&);
        giant&      operator=           (giant&&);
        
        float       getStartingHealth   () const { return startingHealth; }
};

#endif	/* __GSLAYERS_GIANT_H__ */

