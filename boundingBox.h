/* 
 * File:   boundingBox.h
 * Author: hammy
 *
 * Created on November 24, 2013, 6:48 PM
 */

#ifndef __GAME_BOUNDINGBOX_H__
#define	__GAME_BOUNDINGBOX_H__

#include "main.h"
#include "math/math.h"

using vec2 = math::vec2;

/******************************************************************************
 * Bounding Box
******************************************************************************/
class boundingBox {
    private:
        vec2 tr; // Top Right
        vec2 bl; // Bottom Left
        
    public:
        boundingBox() = default;
        boundingBox(const boundingBox&) = default;
        boundingBox(boundingBox&&) = default;
        ~boundingBox() = default;
        
        boundingBox& operator=      (const boundingBox&) = default;
        boundingBox& operator=      (boundingBox&&) = default;
        
        const vec2& getTopRight     () const            { return tr; }
        void        setTopRight     (const vec2& TR)    { tr = TR; }
        
        const vec2& getBottomLeft   () const            { return bl; }
        void        setBottomLeft   (const vec2& BL)    { bl = BL; }
        
        vec2        getPos          () const;
        void        setPos          (const vec2& p);
        void        move            (const vec2& p)     { tr += p; bl += p; }
        
        bool        containsPoint   (const vec2& p) const;
        
        void        draw            (const color& c = color(1,0,0,1)) const;
};

/******************************************************************************
 * Bounding Sphere
******************************************************************************/
class boundingSphere {
    private:
        vec2 pos; // Top Left
        float rad;
        
    public:
        boundingSphere() = default;
        
        boundingSphere(const boundingSphere&) = default;
        boundingSphere(boundingSphere&&) = default;
        ~boundingSphere() = default;
        
        boundingSphere& operator=   (const boundingSphere&) = default;
        boundingSphere& operator=   (boundingSphere&&) = default;
        
        vec2        getPos          () const            { return pos; }
        void        setPos          (const vec2& p);
        void        move            (const vec2& p)     { pos += p; }
        
        bool        containsPoint   (const vec2& p) const;
        
        void        draw            (const color& c = color(1,0,0,1)) const;
};

#endif	/* __GAME_BOUNDINGBOX_H__ */

