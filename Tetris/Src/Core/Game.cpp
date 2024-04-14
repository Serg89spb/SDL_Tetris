#include "Game.h"
#include "Drawable/AreaElement.h"
#include "Drawable/Brick.h"
#include "Drawable/Figure.h"

namespace tetris
{
namespace running
{
constexpr int input_move_speed = 2;
}

bool Game::init_sdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        TETRIS_ERROR("SDL Init Error {0}", SDL_GetError());
        return false;
    }
    constexpr Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    window_ = SDL_CreateWindow(
        "SDL Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_absolute_size_.x, win_absolute_size_.y, window_flags);
    if (!window_)
    {
        TETRIS_ERROR("SDL window not create! SDL Error: {0}", SDL_GetError());
        return false;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer_)
    {
        TETRIS_ERROR("SDL render not create! SDL Error: {0}", SDL_GetError());
        return false;
    }

    last_frame_time_ = SDL_GetTicks();
    current_fig_ = Figure(true);

    return true;
}

void Game::update()
{
    while (running_)
    {
        if (!renderer_)
        {
            throw std::runtime_error("renderer must be initialized");
        }

        const auto bg = color::background;
        SDL_SetRenderDrawColor(renderer_, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer_);

        game_render();

        SDL_RenderPresent(renderer_);

        limit_fps(60);
    }
}

void Game::game_render()
{
    AreaElement frame;
    frame.render(renderer_);
    frame.create_frame();

    draw_figure();
}

void Game::draw_figure()
{
    input_.update(input_event_);
    if (input_.exit) running_ = false;

    auto fig_pos = current_fig_.get_location();

    fig_pos.x -= input_.is_key_pressed(SDLK_LEFT);
    fig_pos.x += input_.is_key_pressed(SDLK_RIGHT);
    if (input_.is_key_pressed(SDLK_UP)) current_fig_.rotate();

    if (game_counter_ % running::input_move_speed == 0)
    {
        fig_pos.x -= input_.is_handle_hold(SDLK_LEFT);
        fig_pos.x += input_.is_handle_hold(SDLK_RIGHT);
    }

    const auto temp_game_speed = input_.is_key_down(SDLK_DOWN) ? running::input_move_speed : invert_game_speed_;
    if (game_counter_ % temp_game_speed == 0)
    {
        fig_pos.y++;
    }
    if (game_counter_ == INT_MAX) game_counter_ = 0;
    game_counter_++;

    if (current_fig_.check_collision_x(fig_pos, bottom_bricks_pos_))
    {
        fig_pos.x = current_fig_.get_location().x;
    }

    if (current_fig_.check_collision_y(fig_pos, bottom_bricks_pos_))
    {
        for (const auto& fig_brick_pos : current_fig_.get_elem_pos())
        {
            add_unique(fig_brick_pos + current_fig_.get_location(), bottom_bricks_pos_);
        }
        check_line_filled();

        current_fig_ = Figure(true);
        fig_pos = current_fig_.get_location();
    }

    start_remove_if_filled();

    draw_bottom_bricks();

    current_fig_.set_location(fig_pos);
    current_fig_.render(renderer_);
    current_fig_.create();
}

void Game::check_line_filled()
{
    rmv_y_.clear();
    sort_vec2_y(bottom_bricks_pos_);

    int prev_y = -1;
    int gap_length = 0;
    int current_y = 0;

    for (const auto& point : bottom_bricks_pos_)
    {
        current_y = point.y;
        for (const int& elem : rmv_y_)
        {
            if (elem == current_y) return;
        }

        if (prev_y != current_y)
        {
            if (gap_length == game_field::max_x)
            {
                add_unique(prev_y, rmv_y_);
            }
            gap_length = 0;
        }
        else
        {
            gap_length++;
        }
        prev_y = current_y;
    }

    if (gap_length == game_field::max_x)
    {
        add_unique(current_y, rmv_y_);
    }
}

void Game::start_remove_if_filled()
{
    if (rmv_y_.empty()) return;
    for (const int& elemY : rmv_y_)
    {
        vec2<int> rmvPoint = {rmv_x_, elemY};
        const auto it = std::remove_if(
            bottom_bricks_pos_.begin(), bottom_bricks_pos_.end(), [rmvPoint](const vec2<int>& elem) { return elem == rmvPoint; });
        bottom_bricks_pos_.erase(it, bottom_bricks_pos_.end());
    }

    if (rmv_x_ > 0)
    {
        rmv_x_--;
    }
    else
    {
        rmv_x_ = game_field::max_x;
        std::reverse(rmv_y_.begin(), rmv_y_.end());
        for (const int& elem : rmv_y_)
        {
            shift_after_remove(elem);
        }
        rmv_y_.clear();
    }
}

void Game::shift_after_remove(const int rmv_y)
{
    for (auto& point : bottom_bricks_pos_)
    {
        if (point.y <= rmv_y)
        {
            point.y++;
        }
    }
}

void Game::draw_bottom_bricks() const
{
    for (const auto& brick_pos : bottom_bricks_pos_)
    {
        auto brick = Brick(brick_pos);
        brick.render(renderer_);
        brick.draw();
    }
}

void Game::limit_fps(const Uint32 fps_limit)
{
    const Uint32 delta = SDL_GetTicks() - last_frame_time_;
    if (delta < 1000 / fps_limit)
    {
        SDL_Delay(1000 / fps_limit - delta);
    }
    last_frame_time_ = SDL_GetTicks();
}
}  // namespace tetris
