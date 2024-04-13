#pragma once

#include <vector>

#include "SDL.h"
#include "variables.h"
#include "Utils/vec2.h"

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

    vec2<int> _all_field_size = {17, 25};
    vec2<int> _win_absolute_size = _all_field_size * unit;
    vec2<int> _game_field_size = {GameField::maxX, GameField::maxY};

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    Uint32 _lastFrameTime = 0;

    Uint32 _testDelay = 15;
    Uint32 _testFrameCounter = 0;

    vec2<int> _spawnPos{};
    int _spawnFigureIndex = 0;

    void gameRender();
    void drawFigure();
    void limitFPS(Uint32 fpsLimit);
};
}  // namespace Tetris
