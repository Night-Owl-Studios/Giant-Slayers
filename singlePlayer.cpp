/* 
 * File:   game.cpp
 * Author: hammy
 * 
 * Created on November 21, 2013, 8:14 PM
 */

#include <utility>
#include <iostream>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include "singlePlayer.h"
#include "display.h"
#include "dealer.h"

/******************************************************************************
 * Single Player Constructor & Destructor
******************************************************************************/
singlePlayer::singlePlayer() {
}

singlePlayer::~singlePlayer() {
    terminate();
}

/******************************************************************************
 * Single Player Hardware Events
******************************************************************************/
/******************************************************************************
 * Single Player Key Up Event
******************************************************************************/
void singlePlayer::onKeyboardUpEvent(const SDL_KeyboardEvent* pEvent) {
    SDL_Keycode key = pEvent->keysym.sym;
    
    switch (key) {
        case SDLK_ESCAPE:
            currentState = GAME_STOPPED;
            break;
    }
}

/******************************************************************************
 * Single Player Key Down Event
******************************************************************************/
void singlePlayer::onKeyboardDownEvent(const SDL_KeyboardEvent*) {
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    SDL_RenderCopy(pRenderer, pTexture, nullptr, nullptr);
}

/******************************************************************************
 * Single Player Text Events
******************************************************************************/
void singlePlayer::onKeyboardTextEvent(const SDL_TextInputEvent* e) {
    SDL_Color col;
    SDL_Surface* pSurface = nullptr;
    col.r = 255;
    col.g = 0;
    col.b = 255;
    
    SDL_DestroyTexture(pTexture);
    pSurface = TTF_RenderText_Solid(pFont, e->text, col);
    if (!pSurface) {
        return;
    }
    else {
        pTexture = SDL_CreateTextureFromSurface(global::pDisplay->getRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    SDL_RenderCopy(pRenderer, pTexture, nullptr, nullptr);
}

/******************************************************************************
 * Single Player Window Event
******************************************************************************/
void singlePlayer::onWindowEvent(const SDL_WindowEvent* pEvent) {
    switch (pEvent->event) {
        case SDL_WINDOWEVENT_CLOSE:
            currentState = GAME_STOPPED;
        default:
            break;
    }
}

/******************************************************************************
 * Single Player Mouse Move Event
******************************************************************************/
void singlePlayer::onMouseMoveEvent(const SDL_MouseMotionEvent*) {
    
}

/******************************************************************************
 * Single Player Mouse Button Up Event
******************************************************************************/
void singlePlayer::onMouseButtonUpEvent(const SDL_MouseButtonEvent*) {
    
}

/******************************************************************************
 * Single Player Mouse Button Down Event
******************************************************************************/
void singlePlayer::onMouseButtonDownEvent(const SDL_MouseButtonEvent*) {
    
}

/******************************************************************************
 * Single Player Mouse Wheel Event
******************************************************************************/
void singlePlayer::onMouseWheelEvent(const SDL_MouseWheelEvent*) {
    
}

/******************************************************************************
 * Single Player Game Start
******************************************************************************/
void singlePlayer::startGame(gameDifficulty difficulty) {
    init();
    currDiff = difficulty;
    
    
    /*
     * Allow the player to choose their deck.
     * Determine which giant to play against depending on the difficulty
     */
    int selection = 0;
    deckType selectionType;
    while (selection != 1 || selection != 2) {
        std::cout
            << "Select your deck:\n\t"
            << "1: Aresa\n\t"
            << "2: Minral\n\t"
            << "3: Quit\n"
            << std::endl;
        std::cin >> selection;
    }
    
    if (selection == 1) {
        selectionType = aresa_deck;
    }
    else if (selection == 2) {
        selectionType = minral_deck;
    }
    else {
        currentState = GAME_STOPPED;
    }
    
    playerDealer.init(selectionType);
}

/******************************************************************************
 * Single Player Game End
******************************************************************************/
void singlePlayer::endGame() {
    /*
     * Print player statistics
     * Allow a high score to be saved
     */
}

/******************************************************************************
 * Single Player Initialization
******************************************************************************/
bool singlePlayer::init() {
    SDL_Color col;
    SDL_Surface* pSurface = nullptr;
    col.r = 255;
    col.g = 0;
    col.b = 255;
    
    pFont = TTF_OpenFont("testFont.ttf", 24);
    if (!pFont) {
        return false;
    }
    
    pSurface = TTF_RenderText_Solid(pFont, "Hello World", col);
    if (!pSurface) {
        return false;
    }
    
    pTexture = SDL_CreateTextureFromSurface(global::pDisplay->getRenderer(), pSurface);
    
    SDL_FreeSurface(pSurface);
            
    return pTexture != nullptr;
}

/******************************************************************************
 * Single Player Termination
******************************************************************************/
void singlePlayer::terminate() {
    SDL_DestroyTexture(pTexture);
    pTexture = nullptr;
    TTF_CloseFont(pFont);
    pFont = nullptr;
    delete pGiant;
    pGiant = nullptr;
    delete pPlayer;
    pPlayer = nullptr;
    
    playerDealer.terminate();
}

/******************************************************************************
 * Single Player Card Draw Phase
******************************************************************************/
void singlePlayer::drawCardPhase() {
    /*
     * If there are any more remaining cards in the deck, pick one.
     * 
     * If there are no cards left, call endGame();
     */
}

/******************************************************************************
 * Single Player Card Play Phase
******************************************************************************/
void singlePlayer::playCardPhase() {
    /*
     * Allow the player to choose which cards they want to play.
     * 
     * Queue the selected cards or remove any desired from the queue.
     */
}

/******************************************************************************
 * Single Player Turn End Phase
******************************************************************************/
void turnEndPhase() {
    /*
     * If it was the player's turn, attackGiantPhase()
     *  pPlayer->queueAbility(card c);
     * 
     * If it's the Giant's turn, giantAttackPhase()
     *  pGiant->queueAttackCard(Card c);
     * 
     * Count all health statistics.
     * End the game if necessary.
     */
}

/******************************************************************************
 * Single Player Attack Phase
******************************************************************************/
void attackPhase() {
    /*
     * Count all card statistics.
     * Apply all displayed abilities.
     * Attack the giant with all displayed attack cards.
     */
}

/******************************************************************************
 * Single Player Animation updating
******************************************************************************/
void singlePlayer::stepAnimations() {
    /*
     * Increment the movements of any animations currently displayed.
     */
}

/******************************************************************************
 * Single Player Game logic updating
******************************************************************************/
void singlePlayer::stepGameLogic() {
    /*
     * Get the current game state.
     * Determine which function to call.
     */
}

/******************************************************************************
 * Single Player graphics drawing
******************************************************************************/
void singlePlayer::draw() const {
}

/******************************************************************************
 * Single Player Time passing
******************************************************************************/
void singlePlayer::onTick(float tickTime) {
    (void)tickTime;
    /*
     * stepGameLogic()
     * stepAnimation()
     */
}
