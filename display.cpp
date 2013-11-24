/* 
 * File:   display.cpp
 * Author: hammy
 * 
 * Created on November 15, 2013, 8:50 PM
 */

#include <iostream>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include "display.h"

/******************************************************************************
 * Constructors
******************************************************************************/

display::display(const math::vec2i inResolution, bool isFullScreen) {
    if (!init(inResolution, isFullScreen)) {
        terminate();
    }
}

/******************************************************************************
 * Display Initialization
******************************************************************************/
bool display::init(const math::vec2i inResolution, bool isFullScreen) {
    Uint32 windowFlags =
        SDL_WINDOW_OPENGL       |
        SDL_WINDOW_SHOWN        |
        SDL_WINDOW_INPUT_FOCUS  |
        SDL_WINDOW_MOUSE_FOCUS  |
        //SDL_WINDOW_INPUT_GRABBED|
        0;
    
    if (isFullScreen) {
        windowFlags |= SDL_WINDOW_FULLSCREEN;
    }
    
    /*
     * Create the window
     */
     pWindow = SDL_CreateWindow(
        _GAME_NAME,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        inResolution[0], inResolution[1], windowFlags
    );
    if (!pWindow) {
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    
     /*
      * Create a renderer that will be used for the window
      */
    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!pRenderer) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_DestroyWindow(pWindow);
        return false;
    }
    
    /*
     * Attempt to initialize additional image format support
     */
    const int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if ((IMG_Init(imgFlags)&imgFlags) != imgFlags) {
        std::cerr
            << "Warning: Unable to initialize JPG, PNG, and TIF image loaders."
            << std::endl;
    }
    
    /*
     * Misc
     */
    SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
    SDL_GL_SetSwapInterval(1);
    
    return true;
}

/******************************************************************************
 * Display Termination
******************************************************************************/
void display::terminate() {
    IMG_Quit();
    
    if (pRenderer) {
        SDL_DestroyRenderer(pRenderer);
    }
    
    if (pWindow) {
        SDL_DestroyWindow(pWindow);
    }
    
    pWindow = nullptr;
    pRenderer = nullptr;
}

/******************************************************************************
 * Display Resolution Handling
******************************************************************************/
const math::vec2i display::getResolution() const {
    math::vec2i res;
    SDL_GetWindowSize(pWindow, &res[0], &res[1]);
    return res;
}

void display::setResolution(const math::vec2i inResolution) {
    SDL_SetWindowSize(pWindow, inResolution[0], inResolution[1]);
}

/******************************************************************************
 * Fullscreen management
******************************************************************************/
void display::setFullscreen(bool fs) {
    if (fs == true) {
        SDL_SetWindowFullscreen(pWindow, SDL_WINDOW_FULLSCREEN);
        SDL_DisableScreenSaver();
    }
    else {
        SDL_SetWindowFullscreen(pWindow, 0);
        SDL_EnableScreenSaver();
    }
}

/******************************************************************************
 * Display BackBuffer Flipping
******************************************************************************/
void display::flip() {
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(pRenderer);
    SDL_RenderClear(pRenderer);
}
