/* 
 * File:   testState.h
 * Author: hammy
 *
 * Created on November 16, 2013, 1:20 AM
 */

#ifndef __GAME_TESTSTATE_H__
#define	__GAME_TESTSTATE_H__

#include "main.h"
#include "gameState.h"

struct SDL_Surface;
struct SDL_Texture;

class testState final : virtual public gameState {
    private:
        SDL_Texture* pTexture = nullptr;
        
        void drawRectangle(const math::vec2i pos, const math::vec2i size, const color);
        
        void onKeyboardUpEvent(const SDL_KeyboardEvent*);
        void onKeyboardDownEvent(const SDL_KeyboardEvent*);
        void onWindowEvent(const SDL_WindowEvent*);
        
        void onMouseMoveEvent(const SDL_MouseMotionEvent*);
        void onMouseButtonEvent(const SDL_MouseButtonEvent*);
        void onMouseWheelEvent(const SDL_MouseWheelEvent*);

    public:
        testState() {}
        testState(const testState&) = delete;
        testState(testState&&) = delete;
        
        ~testState() { terminate(); }
        
        bool init();
        void terminate();
        
        testState operator=(const testState&) = delete;
        testState operator=(testState&&) = delete;
        
        void draw() const;
};

#endif	/* __GAME_TESTSTATE_H__ */
