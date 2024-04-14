#pragma once

#include <vector>

#include "Drawable.h"
#include "Utils/vec2.h"

namespace tetris
{

class Brick : public Drawable
{
public:
    Brick() = default;

    // Initialize the location in relative values of the playing field, e.g (5,6) -> (5*unit, 6*unit)
    Brick(vec2<int> location);
    void render(SDL_Renderer* renderer) override;
    void draw() override;

    vec2<int> get_location() const { return location_; }

protected:
    vec2<int> location_{};

private:
    std::vector<SDL_Rect> rects_;
};

}  // namespace tetris
