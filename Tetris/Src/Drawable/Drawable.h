#pragma once
#include <SDL_render.h>

#include "Utils/color.h"

namespace Tetris
{

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void draw() = 0;

protected:
    SDL_Renderer* _renderer = nullptr;
    color _bg = color::background;
    color _fl = color::fill;
};

}  // namespace Tetris
