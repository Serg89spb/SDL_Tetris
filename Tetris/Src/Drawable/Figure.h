#pragma once
#include <set>

#include "Drawable/Brick.h"

namespace tetris
{

class Figure : public Brick
{
public:
    Figure() = default;
    Figure(const unsigned int index, const vec2<int>& pos);
    Figure(bool init_random);

    void create() const;
    void set_location(const vec2<int>& loc) { location_ = loc; }

    std::vector<vec2<int>> get_elem_pos() const { return elems_pos_; }

    void rotate();
    bool check_collision_x(const vec2<int>& next_pos, const std::vector<vec2<int>>& bottom_bricks) const;
    bool check_collision_y(const vec2<int>& next_pos, const std::vector<vec2<int>>& bottom_bricks) const;

private:
    unsigned int index_{};
    std::vector<vec2<int>> elems_pos_;
    vec2<float> pivot_{};

    void init_elems_pos();
    void random_rotate();
};

}  // namespace tetris
