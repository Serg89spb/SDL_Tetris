#include "Figure.h"
#include "TetrisCore.h"

namespace tetris
{

namespace
{
// TODO remove from this
std::vector<std::vector<vec2<int>>> all_figures_pos = {
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},  // квадрат
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},  // I
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},  // L
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},  // T
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},  // Z
};

std::map<unsigned int, vec2<float>> pivots = {
    {0, {0.5f, 0.5f}},  // квадрат
    {1, {1.0f, 0.0f}},  // I
    {2, {1.0f, 0.0f}},  // L
    {3, {1.0f, 1.0f}},  // T
    {4, {1.0f, 0.0f}},  // Z
};

}  // namespace

Figure::Figure(const unsigned int index, const vec2<int>& pos) : index_(index)
{
    location_ = pos;
    init_elems_pos();
}

Figure::Figure(const bool init_random)
{
    if (init_random)
    {
        const int max_index = static_cast<int>(all_figures_pos.size()) - 1;
        index_ = get_random_int(0, max_index);
        init_elems_pos();
        random_rotate();
        location_ = {get_random_int(1, 8), 2};
        while (check_collision_x(location_, {}))
        {
            location_ = {get_random_int(1, 8), 2};
        }
    }
}

void Figure::create() const
{
    if (!renderer_)
    {
        throw std::runtime_error("renderer must be initialized");
    }

    for (const auto& one_brick_pos : elems_pos_)
    {
        Brick brick(location_ + one_brick_pos);
        brick.render(renderer_);
        brick.draw();
    }
}

void Figure::rotate()
{
    const auto currents_pos = elems_pos_;
    elems_pos_.clear();
    for (const vec2<int>& point : currents_pos)
    {
        const vec2<float> flt_point = {static_cast<float>(point.x), static_cast<float>(point.y)};
        const auto rel_point = flt_point - pivot_;

        const float new_x = -rel_point.y;
        const float new_y = rel_point.x;

        const auto flt_new_pos = pivot_ + vec2<float>{new_x, new_y};
        vec2<int> new_pos = {static_cast<int>(flt_new_pos.x), static_cast<int>(flt_new_pos.y)};

        elems_pos_.push_back(new_pos);
    }
}

bool Figure::check_collision_x(const vec2<int>& next_pos, const std::vector<vec2<int>>& bottom_bricks) const
{
    for (const auto& elem : elems_pos_)
    {
        const auto next_elem_pos = elem + next_pos;
        for (auto& bt_brick : bottom_bricks)
        {
            if (next_elem_pos == bt_brick) return true;
        }
        if (next_elem_pos.x < game_field::min_x || next_elem_pos.x > game_field::max_x) return true;
    }
    return false;
}

bool Figure::check_collision_y(const vec2<int>& next_pos, const std::vector<vec2<int>>& bottom_bricks) const
{
    for (const auto& elem : elems_pos_)
    {
        const auto next_elem_pos = elem + next_pos;
        for (auto& bt_brick : bottom_bricks)
        {
            if (next_elem_pos == bt_brick) return true;
        }
        if (next_elem_pos.y >= game_field::max_y) return true;
    }
    return false;
}

void Figure::init_elems_pos()
{
    elems_pos_.clear();
    elems_pos_ = all_figures_pos[index_];
    pivot_ = pivots[index_];
}

void Figure::random_rotate()
{
    for (int i = 0; i < get_random_int(1, 3); ++i)
        rotate();
}
}  // namespace tetris
