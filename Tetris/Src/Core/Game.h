#pragma once

#include <vector>

#include "TetrisCore.h"
#include "Input.h"
#include "Drawable/Figure.h"

namespace tetris
{

class Game
{
public:
    Game() = default;

    bool init_sdl();
    void update();

    SDL_Window* get_window() const { return window_; }
    SDL_Renderer* get_renderer() const { return renderer_; }

private:
    bool running_ = true;

    Uint32 last_frame_time_ = 0;
    Uint32 invert_game_speed_ = 25;
    Uint32 game_counter_ = 0;

    vec2<int> all_field_size_ = {17, 25};
    vec2<int> win_absolute_size_ = all_field_size_ * unit;
    vec2<int> game_field_size_ = {game_field::max_x, game_field::max_y};

    SDL_Window* window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    SDL_Event input_event_{};
    Input input_{};

    Figure current_fig_{};

    std::vector<vec2<int>> bottom_bricks_pos_;
    std::vector<int> rmv_y_{};
    int rmv_x_ = game_field::max_x;

    void game_render();
    void draw_figure();
    void draw_bottom_bricks() const;
    void check_line_filled();
    void start_remove_if_filled();
    void shift_after_remove(const int rmv_y);

    void limit_fps(Uint32 fps_limit);
};
}  // namespace tetris
