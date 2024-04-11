#pragma once

#include "SDL.h"

namespace Tetris
{

class Game
{
public:
    Game();
    ~Game();

    bool initSDL();
    void update();

    SDL_Window* getWindow() const { return _window; }
    SDL_Renderer* getRenderer() const { return _renderer; }

private:
    bool _running = true;
    int _win_width, _win_height;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    void gameRender();
    void drawFigure();
};
}  // namespace Tetris
