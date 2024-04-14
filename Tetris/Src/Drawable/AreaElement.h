#pragma once
#include "Drawable.h"

namespace tetris
{

class AreaElement : public Drawable
{
public:
    AreaElement() = default;

    void render(SDL_Renderer* renderer) override;
    void draw() override {}
    void create_frame() const;
};

}  // namespace tetris
