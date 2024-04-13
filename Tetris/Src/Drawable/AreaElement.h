#pragma once
#include "Drawable.h"

namespace Tetris
{

class AreaElement : public Drawable
{
public:
    AreaElement() {}

    void render(SDL_Renderer* renderer) override;
    void draw() override;

    void createFrame() const;
};

}  // namespace Tetris
