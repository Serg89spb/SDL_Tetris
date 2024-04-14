#pragma once
#include <SDL_stdinc.h>

namespace tetris
{

struct color
{

    color() = default;
    color(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) : r(r), g(g), b(b), a(a) {}

    Uint8 r = 0;
    Uint8 g = 0;
    Uint8 b = 0;
    Uint8 a = 0;

    static const color background;
    static const color fill;
};

}  // namespace tetris
