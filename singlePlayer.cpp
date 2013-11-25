/* 
 * File:   game.cpp
 * Author: hammy
 * 
 * Created on November 21, 2013, 8:14 PM
 */

#include <utility>
#include "singlePlayer.h"

/******************************************************************************
 * Single Player Constructor & Destructor
******************************************************************************/
singlePlayer::singlePlayer() {
}

singlePlayer::~singlePlayer() {
    terminate();
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
    return true;
}

/******************************************************************************
 * Single Player Termination
******************************************************************************/
void singlePlayer::terminate() {
    delete pPlayer;
    pPlayer = nullptr;
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
