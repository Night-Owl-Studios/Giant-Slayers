/* 
 * File:   main.cpp
 * Author: hammy
 *
 * Created on November 15, 2013, 8:28 PM
 */

#include <iostream>
#include "main.h"
#include "system.h"
#include "singlePlayer.h"

/**
 * Simple Weekend Game #1
 */
bool startGame();
void endGame();

/**
 * Global variables declared in main.h
 */
namespace global {
    display* pDisplay = nullptr;
    subsystem* pSystem = nullptr;
    hamLibs::utils::randomNum* pRandGen = nullptr;
}
// Super secret globals
namespace {
    gameState* pState = nullptr;
}
    
bool startGame(int argc, char** argv) {
    /*
     * Game Initialization
     */
    std::cout << "Parameter count: " << argc << '\n';
    std::cout << "Parameters:" << '\n';
    for (int argCount = 0; argCount < argc; ++argCount) {
        std::cout << '\t' << argCount << ":\t" << argv[argCount] << '\n';
    }
    
    global::pSystem = new(std::nothrow) subsystem();
    if (!global::pSystem || !global::pSystem->init()) {
        return false;
    }
    
    global::pDisplay = new(std::nothrow) display();
    if (!global::pDisplay || !global::pDisplay->init(
            math::vec2i(_DEFAULT_DISPLAY_WIDTH, _DEFAULT_DISPLAY_HEIGHT), false)
    ) {
        return false;
    }
    
    global::pRandGen = new(std::nothrow) hamLibs::utils::randomNum(
        hamLibs::utils::clock::globalSecond()
    );
    if (!global::pRandGen) {
        return false;
    }
    
    pState = new(std::nothrow) singlePlayer();
    if (!pState || !pState->init()) {
        std::cerr << "ERROR: Unable to create a runnable test environment." << std::endl;
        pState->terminate();
        return false;
    }
    
    return true;
}

/*
 * Main
 */
int main(int argc, char** argv) {
    if (!startGame(argc, argv)) {
        endGame();
        return false;
    }
    global::pSystem->pushGameState(pState);
    
    global::pSystem->run();
    
    endGame();
    
    return 0;
}

/*
 * Game Termination
 */  
void endGame() {
    if (pState) {
        pState->terminate();
    }
    delete pState;
    pState = nullptr;
    
    if (global::pDisplay) {
        global::pDisplay->terminate();
    }
    delete global::pDisplay;
    global::pDisplay = nullptr;
    
    if (global::pSystem) {
        global::pSystem->terminate();
    }
    delete global::pSystem;
    global::pSystem = nullptr;
    
    delete global::pRandGen;
    global::pRandGen = nullptr;
    
    std::cout << "Game successfully terminated." << std::endl;
    
    return;
}

