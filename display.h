/* 
 * File:   display.h
 * Author: hammy
 *
 * Created on November 15, 2013, 8:50 PM
 */

#ifndef __GAME_DISPLAY_H__
#define	__GAME_DISPLAY_H__

#include "main.h"

struct SDL_Window;
struct SDL_Renderer;

class display {
    private:
        SDL_Window* pWindow = nullptr;
        SDL_Renderer* pRenderer = nullptr;

    public:
        display() {}
        display(const math::vec2i inResolution, bool isFullScreen);
        display(const display&) = delete;
        display(display&&) = delete;
        
        ~display() { terminate(); }
        
        display operator=(const display&) = delete;
        display operator=(display&&) = delete;
        
        bool init(const math::vec2i inResolution = math::vec2i(
            _DEFAULT_DISPLAY_WIDTH,
            _DEFAULT_DISPLAY_HEIGHT),
            bool isFullScreen = false
        );
        void terminate();
        
        const math::vec2i getResolution() const;
        void setResolution(const math::vec2i inResolution);
        
        void setFullscreen(bool fs);
        bool isFullscreen() const;
        
        bool isRunning() const { return pWindow != nullptr; }
        
        void flip();
        
        SDL_Window* getWindow() const {
            return pWindow;
        }
        
        SDL_Renderer* getRenderer() const {
            return pRenderer;
        }
};

#endif	/* __GAME_DISPLAY_H__ */

