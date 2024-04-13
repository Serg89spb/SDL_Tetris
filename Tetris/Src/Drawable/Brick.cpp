#include <cstdio>
#include "Brick.h"
#include "TetrisCore.h"
#include <algorithm>

namespace Tetris
{
namespace
{
vec2<int> size = {unit, unit};
constexpr int Offset1 = 1;
constexpr int Offset2 = 3;
constexpr int Offset3 = 7;
}  // namespace

Brick::Brick(vec2<int> location) : _location(location)
{
    _location = _location * unit;
    _location.x = clamp(_location.x, GameField::minX * unit, GameField::maxX * unit);
    _location.y = clamp(_location.y, GameField::minY * unit, GameField::maxY * unit) + Frame::yOffset * unit;

    _rects.push_back({_location.x, _location.y, size.x, size.y});
    _rects.push_back({_location.x + Offset1, _location.y + Offset1, size.x - Offset1 * 2, size.y - Offset1 * 2});
    _rects.push_back({_location.x + Offset2, _location.y + Offset2, size.x - Offset2 * 2, size.y - Offset2 * 2});
    _rects.push_back({_location.x + Offset3, _location.y + Offset3, size.x - Offset3 * 2, size.y - Offset3 * 2});
}

void Brick::draw()
{
    if (_renderer)
    {
        bool isBgColor = true;
        for (const auto& rect : _rects)
        {
            const auto clr = isBgColor ? _bg : _fl;
            SDL_SetRenderDrawColor(_renderer, clr.r, clr.g, clr.b, clr.a);
            SDL_RenderFillRect(_renderer, &rect);
            isBgColor = !isBgColor;
        }
    }
    else
    {
        TETRIS_ERROR("{0}: renderer is nullptr", __FUNCTION__);
    }
}

void Brick::render(SDL_Renderer* renderer)
{
    if (!renderer)
    {
        TETRIS_ERROR("{0}: renderer is nullptr", __FUNCTION__);
        return;
    }
    _renderer = renderer;
}
}  // namespace Tetris
