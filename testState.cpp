/* 
 * File:   testState.cpp
 * Author: hammy
 * 
 * Created on November 16, 2013, 1:20 AM
 */

#include <iostream>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_image.h>

#include "testState.h"
#include "display.h"
#include "system.h"

/******************************************************************************
 * State initialization
******************************************************************************/
bool testState::init() {
    if (pTexture) {
        terminate();
    }
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    pTexture = IMG_LoadTexture(pRenderer, "sprite.png");
    
    if (    !pTexture
    ||      SDL_SetTextureBlendMode(pTexture, SDL_BLENDMODE_BLEND)
    ) {
        std::cerr << "ERROR: Unable to load the test image." << std::endl;
        terminate();
        return false;
    }
    
    return true;
}

/******************************************************************************
 * State Termination
******************************************************************************/
void testState::terminate() {
    SDL_DestroyTexture(pTexture);
    pTexture = nullptr;
}

/******************************************************************************
 * Display Rectangle Drawing
******************************************************************************/
void testState::drawRectangle(const math::vec2i pos, const math::vec2i size, const color c) {
    SDL_Rect rect;
    rect.x = pos[0];
    rect.y = pos[1];
    rect.w = size[0];
    rect.h = size[1];
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    
    SDL_SetRenderDrawColor(pRenderer, c[0], c[1], c[2], c[3]);
    SDL_RenderFillRect(pRenderer, &rect);
}

/******************************************************************************
 * Keyboard Button Release Event
******************************************************************************/
void testState::onKeyboardUpEvent(const SDL_KeyboardEvent* pEvent) {
    SDL_Keycode key = pEvent->keysym.sym;
    
    switch (key) {
        case SDLK_ESCAPE:
            currentState = GAME_STOPPED;
            break;
    }
}

/******************************************************************************
 * Keyboard Button Press Event
******************************************************************************/
void testState::onKeyboardDownEvent(const SDL_KeyboardEvent* pEvent) {
    SDL_Keycode key = pEvent->keysym.sym;
    
    if (key == SDLK_LEFT) {
        drawRectangle(
            math::vec2i(0,0),
            math::vec2i(_DEFAULT_DISPLAY_WIDTH/2, _DEFAULT_DISPLAY_HEIGHT),
            color(0,255,0,255)
        );
    }
    
    if (key == SDLK_RIGHT) {
        drawRectangle(
            math::vec2i(_DEFAULT_DISPLAY_WIDTH/2,0),
            math::vec2i(_DEFAULT_DISPLAY_WIDTH, _DEFAULT_DISPLAY_HEIGHT),
            color(0,255,0,255)
        );
    }
}

/******************************************************************************
 * Window Event
******************************************************************************/
void testState::onWindowEvent(const SDL_WindowEvent* pEvent) {
    switch (pEvent->event) {
        case SDL_WINDOWEVENT_CLOSE:
            currentState = GAME_STOPPED;
        default:
            break;
    }
}

/******************************************************************************
 * Mouse Movement Event
******************************************************************************/
void testState::onMouseMoveEvent(const SDL_MouseMotionEvent* pEvent) {
    static math::vec2i lastPos = math::vec2i(0);
    math::vec2i delta = math::vec2i(pEvent->x, pEvent->y);
    
    drawRectangle(
        delta, delta-lastPos, color(255,0,255,255)
    );
    
    lastPos = delta;
}

/******************************************************************************
 * Mouse Button Event
******************************************************************************/
void testState::onMouseButtonEvent(const SDL_MouseButtonEvent* pEvent) {
    if (pEvent->state != SDL_PRESSED) {
        return;
    }
    
    math::vec2i delta = math::vec2i(pEvent->x, pEvent->y);
    
    drawRectangle(
        delta-5, math::vec2i(10), color(255,0,0,255)
    );
}

/******************************************************************************
 * Mouse Wheel Event
******************************************************************************/
void testState::onMouseWheelEvent(const SDL_MouseWheelEvent* pEvent) {
    math::vec2i delta = math::vec2i(pEvent->x, pEvent->y);
    math::vec2i halfRes = math::vec2i(
        _DEFAULT_DISPLAY_WIDTH/2, _DEFAULT_DISPLAY_HEIGHT/2
    )-5;
    
    drawRectangle(
        halfRes+delta, math::vec2i(10), color(255,255,0,255)
    );
}

/******************************************************************************
 * State Rendering
******************************************************************************/
void testState::draw() const {
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    SDL_Rect drawTarget;
    drawTarget.x = 0;
    drawTarget.y = 0;
    drawTarget.w = 64;
    drawTarget.h = 64;
    
    SDL_RenderCopy(pRenderer, pTexture, nullptr, &drawTarget);
}
