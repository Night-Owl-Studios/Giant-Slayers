/* 
 * File:   game.cpp
 * Author: hammy
 * 
 * Created on November 21, 2013, 8:14 PM
 */

#include "singlePlayer.h"

singlePlayer::singlePlayer() {
}

singlePlayer::singlePlayer(const singlePlayer&) {
}

singlePlayer::singlePlayer(singlePlayer&&) {
}

singlePlayer::~singlePlayer() {
    terminate();
}

void singlePlayer::startGame(int difficulty) {
    (void)difficulty;
    /*
     * Allow the player to choose their deck.
     * Determine which giant to play against depending on the difficulty
     */
}

void singlePlayer::endGame() {
    /*
     * Print player statistics
     * Allow a high score to be saved
     */
}

bool singlePlayer::init() {
    return true;
}

void singlePlayer::terminate() {
    delete pPlayer;
    pPlayer = nullptr;
}

void singlePlayer::drawCardPhase() {
    /*
     * If there are any more remaining cards in the deck, pick one.
     * 
     * If there are no cards left, call endGame();
     */
}

void singlePlayer::playCardPhase() {
    /*
     * Allow the player to choose which cards they want to play.
     * 
     * Queue the selected cards or remove any desired from the queue.
     */
}

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

void attackGiantPhase() {
    /*
     * Count all card statistics.
     * Apply all displayed abilities.
     * Attack the giant with all displayed attack cards.
     */
}

void singlePlayer::giantAttackPhase() {
    /*
     *  Determine attack chance.
     *  Determine critical chance.
     *  Attack the player.
     */
}

void singlePlayer::stepAnimations() {
    /*
     * Increment the movements of any animations currently displayed.
     */
}

void singlePlayer::stepGameLogic() {
    /*
     * Get the current game state.
     * Determine which function to call.
     */
}

void singlePlayer::tick(float tickTime) {
    (void)tickTime;
    /*
     * stepGameLogic()
     * stepAnimation()
     */
}
