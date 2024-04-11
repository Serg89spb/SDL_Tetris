#include <cstdio>
#include "DrawableUnit.h"
#include "SDL.h"
#include "Utils/Log.h"

namespace Tetris
{

DrawableUnit::DrawableUnit(vec2<int> location, vec2<int> size, const color& color)
    : _location(location), _size(size), _color(color), _renderer(nullptr)
{
    _rect = {location.x, location.y, size.x, size.y};
}

void DrawableUnit::draw() const
{
    if (_renderer)
    {
        SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
        SDL_RenderFillRect(_renderer, &_rect);
    }
    else
    {
        TETRIS_ERROR("{0}: renderer is nullptr", __FUNCTION__);
    }
}

void DrawableUnit::render(SDL_Renderer* renderer)
{
    if (!renderer)
    {
        TETRIS_ERROR("{0}: renderer is nullptr", __FUNCTION__);
        return;
    }
    _renderer = renderer;
}
}  // namespace Tetris
