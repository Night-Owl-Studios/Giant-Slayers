/* 
 * File:   system.cpp
 * Author: hammy
 * 
 * Created on November 15, 2013, 9:53 PM
 */

#include <iostream>
#include <SDL2/SDL.h>

#include "main.h"
#include "system.h"
#include "display.h"

/******************************************************************************
 * SubSystem Initialization
******************************************************************************/
bool subsystem::init() {
    SDL_SetMainReady();
    
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << "SDL successfully initialized." << std::endl;
    }
    else {
        std::cerr << "Unable to initialize SDL.\n";
        std::cerr << "Complain to your local programmer." << std::endl;
        return false;
    }
    
    std::cout
        << "Successfully initialized the game hardware interface.\n"
        << SDL_GetError()
        << std::endl;
    
    return true;
}

/******************************************************************************
 * SubSystem Termination
******************************************************************************/
void subsystem::terminate() {
    if (SDL_WasInit(0u)) {
        SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
        SDL_Quit();
    }
    
    tickTime = 0.f;
    gameIsRunning = false;
    gameStack.clear();
}

/******************************************************************************
 * SubSystem Running
******************************************************************************/
void subsystem::run() {
    Uint64 prevTime = 0u;
    float frameCounter = 0.f;
    bool redraw = false;
    gameIsRunning = true;
    
    while (gameIsRunning && gameStack.size()) {
        SDL_Event pEvent;
        gameState* pState = gameStack.back();
        
        if (!global::pDisplay->isRunning()) {
            std::cerr << SDL_GetError() << std::endl;
            gameIsRunning = false;
        }
        
        /*
         * Frame Time Management
         */
        const Uint64 currTime = SDL_GetPerformanceCounter();
        tickTime = (float)(currTime-prevTime)/(float)SDL_GetPerformanceFrequency();
        prevTime = currTime;
        frameCounter += tickTime;
        
        if (frameCounter >= 1.f/60.f) {
            std::cout << "Frame Time (ms/f): " << frameCounter << "\t\t\r";
            redraw = true;
            frameCounter = 0;
        }
        
        /*
         * Hardware events passed through SDL
         */
        switch (pEvent.type) {
            case SDL_QUIT:
                gameIsRunning = false;
                break;
            case SDL_WINDOWEVENT:
                pState->onWindowEvent(&pEvent.window);
                break;
            case SDL_KEYUP:
                pState->onKeyboardUpEvent(&pEvent.key);
                break;
            case SDL_KEYDOWN:
                pState->onKeyboardDownEvent(&pEvent.key);
                //break;
            case SDL_TEXTINPUT:
                pState->onKeyboardTextEvent(&pEvent.text);
                break;
            case SDL_MOUSEMOTION:
                pState->onMouseMoveEvent(&pEvent.motion);
                break;
            case SDL_MOUSEBUTTONUP:
                pState->onMouseButtonUpEvent(&pEvent.button);
                break;
            case SDL_MOUSEBUTTONDOWN:
                pState->onMouseButtonDownEvent(&pEvent.button);
                break;
            case SDL_MOUSEWHEEL:
                pState->onMouseWheelEvent(&pEvent.wheel);
                break;
        }
        
        /*
         * Game state management
         */
        for(unsigned i = 0; i < gameStack.size(); ++i) {
            switch(gameStack[i]->getState()) {
                case GAME_RUNNING:
                    gameStack[i]->onTick(tickTime);
                    break;
                case GAME_STOPPED:
                    gameStack.erase(gameStack.begin()+i);
                    break;
                case GAME_PAUSED:
                default:
                    break;
            }
        }
        
        /*
         * Render to the screen after all events have been processed
         */
        //if (!SDL_PollEvent(&pEvent) && redraw) {
        if (!SDL_WaitEventTimeout(&pEvent, 1) && redraw) {
            for (unsigned int i = 0; i < gameStack.size(); ++i) {
                gameStack[i]->draw();
            }
            global::pDisplay->flip();
            redraw = false;
        }
    }
}

/******************************************************************************
 * SubSystem State Addition
******************************************************************************/
void subsystem::pushGameState(gameState* pState) {
    if (pState == nullptr) {
        std::cerr
            << "ERROR: A null pointer was passed into the \"pushGameState()\" method!"
            << std::endl;
    }
    
    if (gameStack.size()) {
        gameStack.back()->onPause();
    }
    
    gameStack.push_back(pState);
    pState->onStart();
}

/******************************************************************************
 * SubSystem State Removal
******************************************************************************/
gameState* subsystem::popGameState() {
    if (!gameStack.size()) {
        gameIsRunning = false;
        return nullptr;
    }
    
    gameState* pState = gameStack.back();
    gameStack.pop_back();
    pState->onStop();

    if (gameStack.size() > 0) {
        gameStack.back()->onResume();
    }

    return pState;
}
