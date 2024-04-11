#pragma once

#include "Drawable.h"
#include "Utils/color.h"
#include "Utils/vec2.h"

namespace Tetris
{

class DrawableUnit : public Drawable
{
public:
    DrawableUnit(vec2<int> location, vec2<int> size, const color& color);
    void draw() const;
    void render(SDL_Renderer* renderer) override;

private:
    vec2<int> _location{};
    vec2<int> _size{};
    color _color{};

    SDL_Rect _rect;

    SDL_Renderer* _renderer;
};

}  // namespace Tetris
