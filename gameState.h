/* 
 * File:   game.h
 * Author: hammy
 *
 * Created on November 15, 2013, 8:45 PM
 */

#ifndef __GAME_GAME_STATE_H__
#define	__GAME_GAME_STATE_H__

// Forward declarations
struct SDL_WindowEvent;
struct SDL_KeyboardEvent;
struct SDL_MouseMotionEvent;
struct SDL_MouseButtonEvent;
struct SDL_MouseWheelEvent;
class subsystem;

enum state : unsigned {
    GAME_PAUSED,
    GAME_RUNNING,
    GAME_STOPPED
};

class gameState {
    friend class subsystem;
    
    /*
     * Event Management
     */
    protected:
        state currentState = GAME_STOPPED; // left to each implementation to manage
        
        virtual void onKeyboardUpEvent(const SDL_KeyboardEvent*) = 0;
        virtual void onKeyboardDownEvent(const SDL_KeyboardEvent*) = 0;
        virtual void onWindowEvent(const SDL_WindowEvent*) = 0;
        
        virtual void onMouseMoveEvent(const SDL_MouseMotionEvent*) = 0;
        virtual void onMouseButtonEvent(const SDL_MouseButtonEvent*) = 0;
        virtual void onMouseWheelEvent(const SDL_MouseWheelEvent*) = 0;
        
    public:
        gameState() {}
        gameState(const gameState&) = delete;
        gameState(gameState&&) = delete;
        
        virtual ~gameState() = 0;
        
        gameState& operator=(const gameState&) = delete;
        gameState& operator=(gameState&&) = delete;
        
        virtual bool init() = 0;
        virtual void terminate() = 0;
        
        virtual void onTick(float) {}
        
        virtual void onStart() { currentState = GAME_RUNNING; }
        virtual void onStop() { currentState = GAME_STOPPED; }
        virtual void onPause() { currentState = GAME_PAUSED; }
        virtual void onResume() { currentState = GAME_RUNNING; }
        
        state getState() const { return currentState; }
        void setState(state s) { currentState = s; }
        
        virtual void draw() const = 0;
};

#endif	/* __GAME_GAME_STATE_H__ */

