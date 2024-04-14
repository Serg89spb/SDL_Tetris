#include <cstdio>
#include "Brick.h"
#include "TetrisCore.h"

namespace tetris
{
namespace
{
vec2<int> size = {unit, unit};
constexpr int offset1 = 1;
constexpr int offset2 = 3;
constexpr int offset3 = 6;
}  // namespace

Brick::Brick(const vec2<int> location) : location_(location)
{
    location_ = location_ * unit;

    rects_.push_back({location_.x, location_.y, size.x, size.y});
    rects_.push_back({location_.x + offset1, location_.y + offset1, size.x - offset1 * 2, size.y - offset1 * 2});
    rects_.push_back({location_.x + offset2, location_.y + offset2, size.x - offset2 * 2, size.y - offset2 * 2});
    rects_.push_back({location_.x + offset3, location_.y + offset3, size.x - offset3 * 2, size.y - offset3 * 2});
}

void Brick::draw()
{
    if (!renderer_)
    {
        throw std::runtime_error("renderer must be initialized");
    }

    bool render_rect = true;
    if (location_.x < game_field::min_x * unit || location_.x > game_field::max_x * unit ||  //
        location_.y < game_field::min_y * unit || location_.y > game_field::max_y * unit)    //
    {
        render_rect = false;
    }

    if (render_rect)
    {
        bool is_bg_color = true;
        for (const auto& rect : rects_)
        {
            const auto clr = is_bg_color ? bg_ : fl_;
            SDL_SetRenderDrawColor(renderer_, clr.r, clr.g, clr.b, clr.a);
            SDL_RenderFillRect(renderer_, &rect);
            is_bg_color = !is_bg_color;
        }
    }
}

void Brick::render(SDL_Renderer* renderer)
{
    if (!renderer)
    {
        throw std::runtime_error("renderer must be initialized");
    }
    renderer_ = renderer;
}
}  // namespace tetris
