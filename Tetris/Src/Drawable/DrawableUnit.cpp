#include <cstdio>

#include "DrawableUnit.h"
#include "Utils/staticLibrary.h"

DrawableUnit::DrawableUnit(vec2<int> location, vec2<int> size, const color& color) : _location(location), _size(size), _color(color)
{
    const SDL_Rect rect = {location.x, location.y, size.x, size.y};
    if (const auto renderer = staticLibrary::getRenderer())
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }
    else
    {
        printf("renderer not exist! \n");
    }
}
