#include "Figure.h"
#include "TetrisCore.h"

namespace Tetris
{

namespace
{
// TODO remove from this

std::vector<std::vector<vec2<int>>> allFiguresPos = {
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},  // квадрат
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},  // I
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},  // L
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},  // T
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},  // Z
};

}  // namespace

void Figure::create(const int index, const vec2<int>& pos) const
{
    if (!_renderer)
    {
        throw std::runtime_error("renderer must be initialized");
    }

    for (const auto& oneBrickPos : allFiguresPos[index])
    {
        Brick brick(pos + oneBrickPos);
        brick.render(_renderer);
        brick.draw();
    }
}

}  // namespace Tetris
