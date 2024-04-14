#pragma once

#include "TetrisCore.h"

namespace tetris
{

class Input
{
public:
    ~Input();

    void update(SDL_Event event);

    bool is_key_down(unsigned int key_id);
    bool is_key_pressed(unsigned int key_id);
    bool is_handle_hold(unsigned int key_id);
    bool exit = false;

private:
    void dispose();
    void press_key(unsigned int key_id);
    void release_key(unsigned int key_id);

    bool was_key_down(unsigned int key_id);

    bool is_holding_ = false;
    unsigned int hold_key_id_{};
    double start_hold_time_{};

    std::unordered_map<unsigned int, bool> key_map_;
    std::unordered_map<unsigned int, bool> previous_key_map_;
};

}  // namespace tetris
