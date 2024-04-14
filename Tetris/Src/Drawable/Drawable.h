#pragma once
#include <SDL_render.h>

#include "Utils/color.h"

namespace tetris
{

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void draw() = 0;

protected:
    SDL_Renderer* renderer_ = nullptr;
    color bg_ = color::background;
    color fl_ = color::fill;
};

}  // namespace tetris
