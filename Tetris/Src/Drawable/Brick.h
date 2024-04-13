#pragma once

#include <vector>

#include "Drawable.h"
#include "Utils/vec2.h"

namespace Tetris
{

class Brick : public Drawable
{
public:
    Brick() = default;

    // Initialize the location in relative values of the playing field, e.g (5,6) -> (5*unit, 6*unit)
    Brick(vec2<int> location);
    void render(SDL_Renderer* renderer) override;
    void draw() override;

private:
    vec2<int> _location{};
    vec2<int> _size{};

    std::vector<SDL_Rect> _rects;
};

}  // namespace Tetris
