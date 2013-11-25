/* 
 * File:   aresaDeck.h
 * Author: hammy
 *
 * Created on November 24, 2013, 1:27 PM
 */

#ifndef _GSLAYERS_ARESADECK_H_
#define	_GSLAYERS_ARESADECK_H_

#include "main.h"
#include "deck.h"

/******************************************************************************
 * Aresa Deck Template Specialization
******************************************************************************/
typedef deck_t<deckType::aresa_deck, deckAbility::mul_sub> aresaDeck;

template <>
bool aresaDeck::init();

#endif	/* _GSLAYERS_ARESADECK_H_ */

