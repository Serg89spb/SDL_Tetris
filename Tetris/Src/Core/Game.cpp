#include "Game.h"
#include <cstdio>
#include <SDL_image.h>
#include <cmath>

#include "Drawable/DrawableUnit.h"
#include "Utils/color.h"
#include "Utils/vec2.h"
#include "Utils/Log.h"

namespace Tetris
{

Game::Game() : _win_width(400), _win_height(800) {}

Game::~Game() {}

bool Game::initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        TETRIS_ERROR("SDL Init Error {0}", SDL_GetError());
        return false;
    }
    constexpr Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

    _window = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _win_width, _win_height, window_flags);
    if (!_window)
    {
        TETRIS_ERROR("SDL window not create! SDL Error: {0}", SDL_GetError());
        return false;
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (!_renderer)
    {
        TETRIS_ERROR("SDL render not create! SDL Error: {0}", SDL_GetError());
        return false;
    }
    return true;
}

void Game::update()
{
    SDL_Event event;
    while (_running)
    {
        if (!_renderer)
        {
            throw std::runtime_error("renderer must be initialized");
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                _running = false;
            }
        }

        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(_renderer);

        gameRender();

        SDL_RenderPresent(_renderer);
    }
}

void Game::gameRender()
{
    drawFigure();
}

void Game::drawFigure()
{
    if (!_renderer) return;

    const color color(0xFF, 0xFF, 0xFF, 0xFF);
    const vec2<int> pos(0, 0);
    const vec2<int> size(40, 40);

    DrawableUnit unit(pos, size, color);
    unit.render(_renderer);
    unit.draw();
}

}  // namespace Tetris
