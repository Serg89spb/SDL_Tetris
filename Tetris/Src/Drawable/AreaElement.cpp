#include "AreaElement.h"

#include "TetrisCore.h"

namespace Tetris
{
namespace Frame
{
const vec2<int> locHor1 = {0, 24 * unit};
const vec2<int> locHor2 = {0, yOffset* unit - 2};
const vec2<int> sizeHor = {10 * unit, 2};

const vec2<int> locVert = {10 * unit, yOffset* unit};
const vec2<int> sizeVer = {2, 20 * unit};
}  // namespace Frame

void AreaElement::render(SDL_Renderer* renderer)
{
    if (!renderer)
    {
        TETRIS_ERROR("{0}: renderer is nullptr", __FUNCTION__);
        return;
    }
    _renderer = renderer;
}

void AreaElement::draw() {}

void AreaElement::createFrame() const
{
    std::vector<SDL_Rect> rects;
    rects.push_back({Frame::locHor1.x, Frame::locHor1.y, Frame::sizeHor.x, Frame::sizeHor.y});
    rects.push_back({Frame::locHor2.x, Frame::locHor2.y, Frame::sizeHor.x, Frame::sizeHor.y});
    rects.push_back({Frame::locVert.x, Frame::locVert.y, Frame::sizeVer.x, Frame::sizeVer.y});

    for (const auto& rect : rects)
    {
        SDL_SetRenderDrawColor(_renderer, _fl.r, _fl.g, _fl.b, _fl.a);
        SDL_RenderFillRect(_renderer, &rect);
    }
}

}  // namespace Tetris
