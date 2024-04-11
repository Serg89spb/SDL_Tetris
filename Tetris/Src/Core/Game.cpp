#include "Game.h"
#include <cstdio>
#include <SDL_image.h>
#include <cmath>

#include "Drawable/DrawableUnit.h"
#include "Utils/color.h"
#include "Utils/vec2.h"

Game::Game() : _win_width(400), _win_height(800) {}

Game::~Game() {}

void Game::InitSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("SDL Init Error: %s", SDL_GetError());
    }
    constexpr Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

    _window = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _win_width, _win_height, window_flags);
    if (!_window)
    {
        printf("SDL window not create! SDL Error: %s\n", SDL_GetError());
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (!_renderer)
    {
        printf("SDL render not create! SDL Error: %s\n", SDL_GetError());
    }
}

void Game::Play()
{
    SDL_Event event;
    while (_gameLoop)
    {
        if (!_renderer) return;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                _gameLoop = false;
            }
        }

        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(_renderer);

        GameRender();

        SDL_RenderPresent(_renderer);
    }
}

void Game::GameRender()
{
    DrawFigure();
}

void Game::DrawFigure()
{
    if (!_renderer) return;

    const color color(0xFF, 0xFF, 0xFF, 0xFF);
    const vec2<int> pos(0, 0);
    const vec2<int> size(40, 40);

    DrawableUnit unit(pos, size, color);
}
