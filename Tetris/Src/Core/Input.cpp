#include "Input.h"

namespace tetris
{
namespace
{
constexpr int hold_delay = 250;  // ms
}

Input::~Input()
{
    dispose();
}

void Input::dispose()
{
    key_map_.clear();
    previous_key_map_.clear();
}

void Input::update(SDL_Event event)
{
    for (auto& it : key_map_)
    {
        previous_key_map_[it.first] = it.second;
    }

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT: exit = true; break;

            case SDL_KEYDOWN:
                press_key(event.key.keysym.sym);
                is_holding_ = true;
                break;

            case SDL_KEYUP:
                release_key(event.key.keysym.sym);
                is_holding_ = false;
                break;
            default: break;
        }
    }
}

void Input::press_key(const unsigned key_id)
{
    key_map_[key_id] = true;
}

void Input::release_key(const unsigned key_id)
{
    key_map_[key_id] = false;
}

bool Input::is_key_down(const unsigned int key_id)
{
    const auto it = key_map_.find(key_id);
    return it != key_map_.end() ? it->second : false;
}

bool Input::is_key_pressed(const unsigned int key_id)
{
    if (is_key_down(key_id) && !was_key_down(key_id))
    {
        hold_key_id_ = key_id;
        start_hold_time_ = get_time_milliseconds();
    }
    return is_key_down(key_id) && !was_key_down(key_id);
}

bool Input::was_key_down(const unsigned int key_id)
{
    const auto it = previous_key_map_.find(key_id);
    return it != previous_key_map_.end() ? it->second : false;
}

bool Input::is_handle_hold(const unsigned int key_id)
{
    return is_holding_ && is_key_down(key_id) && key_id == hold_key_id_ && get_time_milliseconds() - start_hold_time_ > hold_delay;
}

}  // namespace tetris
