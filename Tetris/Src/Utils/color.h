#pragma once

#include <SDL_stdinc.h>

struct color
{
    color() = default;
    color(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a) : r(_r), g(_g), b(_b), a(_a) {}

    Uint8 r = 0;
    Uint8 g = 0;
    Uint8 b = 0;
    Uint8 a = 0;
};
