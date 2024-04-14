#pragma once

#include <vector>

namespace tetris
{
constexpr int unit = 32;

namespace game_field
{
constexpr int min_x = 0;
constexpr int max_x = 9;
constexpr int min_y = 4;
constexpr int max_y = 24;
}  // namespace game_field

namespace frame
{
constexpr int y_offset = 4;
}

}  // namespace tetris
