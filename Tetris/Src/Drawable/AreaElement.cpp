#include "AreaElement.h"

#include "TetrisCore.h"

namespace tetris
{
namespace frame
{
const vec2<int> loc_hor1 = {0, 24 * unit};
const vec2<int> loc_hor2 = {0, y_offset* unit - 2};
const vec2<int> size_hor = {10 * unit, 2};

const vec2<int> loc_vert = {10 * unit, y_offset* unit};
const vec2<int> size_ver = {2, 20 * unit};
}  // namespace frame

void AreaElement::render(SDL_Renderer* renderer)
{
    if (!renderer)
    {
        throw std::runtime_error("renderer must be initialized");
    }
    renderer_ = renderer;
}

void AreaElement::create_frame() const
{
    std::vector<SDL_Rect> rects;
    rects.push_back({frame::loc_hor1.x, frame::loc_hor1.y, frame::size_hor.x, frame::size_hor.y});
    rects.push_back({frame::loc_hor2.x, frame::loc_hor2.y, frame::size_hor.x, frame::size_hor.y});
    rects.push_back({frame::loc_vert.x, frame::loc_vert.y, frame::size_ver.x, frame::size_ver.y});

    for (const auto& rect : rects)
    {
        SDL_SetRenderDrawColor(renderer_, fl_.r, fl_.g, fl_.b, fl_.a);
        SDL_RenderFillRect(renderer_, &rect);
    }
}

}  // namespace tetris
