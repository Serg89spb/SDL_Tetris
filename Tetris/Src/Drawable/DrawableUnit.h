#pragma once

#include "Utils/color.h"
#include "Utils/vec2.h"

class DrawableUnit
{
public:
    DrawableUnit(vec2<int> location, vec2<int> size, const color& color);

private:
    vec2<int> _location{};
    vec2<int> _size{};
    color _color{};
};
