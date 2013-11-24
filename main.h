/* 
 * File:   main.h
 * Author: hammy
 *
 * Created on November 15, 2013, 8:37 PM
 */

#ifndef __GAME_MAIN_H__
#define	__GAME_MAIN_H__

#include <cstdint>
#include "hamLibs.h"

namespace math = hamLibs::math;

/******************************************************************************
 * GLOBAL MACROS
******************************************************************************/
#ifndef _GAME_NAME
    #define _GAME_NAME "Giant Slayers"
#endif

/*
 * System Defaults
 */
#ifndef _DEFAULT_DISPLAY_WIDTH
    #define _DEFAULT_DISPLAY_WIDTH 640
#endif

#ifndef _DEFAULT_DISPLAY_HEIGHT
    #define _DEFAULT_DISPLAY_HEIGHT 480
#endif

/*
 * Game Limits
 */
/*
 * Maximum amount of cards per deck
 */
#ifndef _MAX_CARDS_PER_DECK
    #define _MAX_CARDS_PER_DECK 50
#endif

/*
 * Maximum number of cards per hand
 */
#ifndef _MAX_CARDS_PER_HAND
    #define _MAX_CARDS_PER_HAND 5
#endif

/*
 * Game Defaults
 */
/*
 * Default player statistics
 */
#ifndef _PLAYER_DEFAULT_FORTIFICATION
    #define _PLAYER_DEFAULT_FORTIFICATION 0.f
#endif

#ifndef _PLAYER_DEFAULT_DODGE_CHANCE
    #define _PLAYER_DEFAULT_DODGE_CHANCE 0.f
#endif

#ifndef _PLAYER_DEFAULT_STRENGTH
    #define _PLAYER_DEFAULT_STRENGTH 1.f
#endif

/*
 * Giant Statistics
 */
#ifndef _GIANT_MIN_HEALTH
    #define _GIANT_MIN_HEALTH 3000.f
#endif

#ifndef _GIANT_MAX_HEALTH
    #define _GIANT_MAX_HEALTH 8000.f
#endif

/*
 * Debugging
 */
#ifdef _DEBUG
    #ifndef _DEBUG_LINE
        #define _DEBUG_LINE\
            std::cout\
            << "Testing line " << __LINE__\
            << " from file " << __FILE__\
            << std::endl;
    #endif

    #ifndef _DEBUG_WARN
        #define _DEBUG_WARN HL_WARN
    #endif
#else
    #ifndef _DEBUG_LINE
        #define _DEBUG_LINE
    #endif
    
    #ifndef _DEBUG_WARN
        #define DEBUG_WARN
    #endif
    
#endif

/******************************************************************************
 * FORWARD DECLARATIONS
******************************************************************************/
/*
 * Subsystems
 */
class gameState;
class display;
class subsystem;
class testState;

/*
 * Game-Specific Enumerations
 */
enum class deckType; //deck.h
enum class cardType; // cardTypes.h
enum class cardStrength; //cardTypes.h
enum class cardAbility; // cardTypes.h
enum class cardEffect; // cardTypes.h

/*
 * Game-Specific Classes
 */
class player;
class deck;
class card;
class giant;

template <const int cost, const cardStrength, const int strengthVal>
class attackCard;

template <const int cost, const cardAbility, const cardEffect>
class abilityCard;

/******************************************************************************
 * GLOBAL TYPE DEFINITIONS
******************************************************************************/
typedef math::vec4_t<uint8_t> color;

/******************************************************************************
 * GAME GLOBALS
******************************************************************************/
namespace global {
    extern display* pDisplay; // main.cpp
    extern subsystem* pSystem; // main.cpp
    extern hamLibs::utils::randomNum* pRandGen; // main.cpp
}

#endif	/* __GAME_MAIN_H__ */

