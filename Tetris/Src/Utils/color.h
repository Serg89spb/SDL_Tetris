#pragma once
#include <SDL_stdinc.h>

namespace Tetris
{

struct color
{

    color() = default;
    color(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a) : r(_r), g(_g), b(_b), a(_a) {}

    Uint8 r = 0;
    Uint8 g = 0;
    Uint8 b = 0;
    Uint8 a = 0;

    static const color background;  // rgb(182,194,182)
    static const color fill;        // rgb(31,35,31)
};

}  // namespace Tetris
