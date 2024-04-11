#pragma once
#include <SDL_render.h>

namespace Tetris
{

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
};

}  // namespace Tetris
