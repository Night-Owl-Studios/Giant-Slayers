/* 
 * File:   system.h
 * Author: hammy
 *
 * Created on November 15, 2013, 9:53 PM
 */

#ifndef __GAME_SYSTEM_H__
#define	__GAME_SYSTEM_H__

#include <vector>
#include <SDL2/SDL_timer.h>
#include "main.h"
#include "display.h"
#include "gameState.h"

class subsystem {
    private:
        bool gameIsRunning = false;
        float tickTime = 0.f;
        std::vector<gameState*> gameStack;
    
    public:
        subsystem() {}
        subsystem(const subsystem&) = delete;
        subsystem(subsystem&&) = delete;
        
        ~subsystem() { terminate(); }
        
        subsystem operator=(const subsystem&) = delete;
        subsystem operator=(subsystem&&) = delete;
        
        bool init();
        void terminate();
        
        void run();
        void stop() { gameIsRunning = false; }
        
        void pushGameState(gameState*);
        gameState* popGameState(); // returns the popped state in case of dynamic objects
};

#endif	/* __GAME_SYSTEM_H__ */

