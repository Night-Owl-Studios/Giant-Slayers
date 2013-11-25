/* 
 * File:   boundingBox.cpp
 * Author: hammy
 * 
 * Created on November 24, 2013, 6:48 PM
 */

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include "display.h"
#include "boundingBox.h"

namespace math = hamLibs::math;

/******************************************************************************
 * Bounding Box
******************************************************************************/
/*
 * Bounding Box
 * Positioning from the center
 */
vec2 boundingBox::getPos() const {
    return vec2(tr[0]-bl[0], tr[1]-bl[1]) * 0.5f;
}

void boundingBox::setPos(const vec2& p) {
    vec2 distBetween = vec2(tr - bl) * 0.5f;
    tr = p + distBetween;
    bl = p - distBetween;
}

/*
 * Bounding Box
 * Box-Point intersection test
 */
bool boundingBox::containsPoint(const vec2& p) const {
    return  (p[0] <= tr[0]) && (p[0] >= bl[0]) &&
            (p[1] <= tr[1]) && (p[1] >= bl[1]);
}

/*
 * Bounding Box
 * Drawing
 */
void boundingBox::draw(const color& c) const {
    SDL_Rect rect;
    rect.x = bl[0];
    rect.y = tr[1];
    rect.w = tr[0]-bl[0];
    rect.h = tr[1]-bl[1];
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    
    SDL_SetRenderDrawColor(pRenderer, c[0], c[1], c[2], c[3]);
    SDL_RenderDrawRect(pRenderer, &rect);
}

/******************************************************************************
 * Bounding Sphere
******************************************************************************/
/*
 * Bounding Sphere
 * Sphere-Point intersection test
 */
bool boundingSphere::containsPoint(const vec2& p) const {
    return ((pos[0]*pos[0])+(pos[1])*pos[1])-((p[0]*p[0])+p[1]*p[1]) <= (rad*rad);
}

/*
 * Bounding Sphere
 * Drawing
 */
void boundingSphere::draw(const color& c) const {
    SDL_Rect rect;
    rect.x = pos[0]+rad;
    rect.y = pos[1]+rad;
    rect.w = rad;
    rect.h = rad;
    
    SDL_Renderer* pRenderer = global::pDisplay->getRenderer();
    
    SDL_SetRenderDrawColor(pRenderer, c[0], c[1], c[2], c[3]);
    SDL_RenderDrawRect(pRenderer, &rect);
}
