#pragma once

#include "SDL.h"

class Game
{
public:
    Game();
    ~Game();

    void InitSDL();
    void Play();

    SDL_Window* getWindow() const { return _window; }
    SDL_Renderer* getRenderer() const { return _renderer; }

private:
    bool _gameLoop = true;
    int _win_width, _win_height;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    void GameRender();
    void DrawFigure();
};
