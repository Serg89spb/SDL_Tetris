#pragma once
#include "Drawable/Brick.h"

namespace Tetris
{

class Figure : public Brick
{
public:
    void create(const int index, const vec2<int>& pos) const;

private:
};

}  // namespace Tetris
