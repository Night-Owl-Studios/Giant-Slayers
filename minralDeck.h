/* 
 * File:   minralDeck.h
 * Author: hammy
 *
 * Created on November 24, 2013, 3:28 PM
 */

#ifndef _GSLAYERS_MINRALDECK_H_
#define	_GSLAYERS_MINRALDECK_H_

#include "main.h"
#include "deck.h"

/******************************************************************************
 * Minral Deck Template Specialization
******************************************************************************/
typedef deck_t<deckType::minral_deck, deckAbility::add_div> minralDeck;

bool minralDeck::init();

#endif	/* _GSLAYERS_MINRALDECK_H_ */

