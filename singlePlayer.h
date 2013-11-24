/* 
 * File:   game.h
 * Author: hammy
 *
 * Created on November 21, 2013, 8:14 PM
 */

#ifndef __GSLAYERS_SINGLEPLAYER_H__
#define	__GSLAYERS_SINGLEPLAYER_H__

#include "main.h"
#include "gameState.h"
#include "player.h"

class singlePlayer : virtual public gameState {
    private:
        player* pPlayer         = nullptr;
        giant* pGiant           = nullptr;
        player* currentPlayer   = nullptr;
        deck* pDeck             = nullptr;
        
        void    onKeyboardUpEvent   (const SDL_KeyboardEvent*);
        void    onKeyboardDownEvent (const SDL_KeyboardEvent*);
        void    onWindowEvent       (const SDL_WindowEvent*);
        void    onMouseMoveEvent    (const SDL_MouseMotionEvent*);
        void    onMouseButtonEvent  (const SDL_MouseButtonEvent*);
        void    onMouseWheelEvent   (const SDL_MouseWheelEvent*);
        
    public:
        singlePlayer();
        singlePlayer(const singlePlayer&);
        singlePlayer(singlePlayer&&);
        
        ~singlePlayer();
        
        singlePlayer& operator=(const singlePlayer&);
        singlePlayer& operator=(singlePlayer&&);
        
        void startGame(int difficulty);
        void endGame();
        
        bool init();
        void terminate();
        
        void drawCardPhase();
        void playCardPhase();
        
        void turnEndPhase();
        
        void attackGiantPhase();
        void giantAttackPhase();
        
        void stepAnimations();
        void stepGameLogic();
        
        void draw() const = 0;
        void onTick(float tickTime);
};

#endif	/* __GSLAYERS_SINGLEPLAYER_H__ */
