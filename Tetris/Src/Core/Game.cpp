#include "Game.h"
#include "TetrisCore.h"
#include "Drawable/AreaElement.h"
#include "Drawable/Brick.h"
#include "Drawable/Figure.h"

namespace Tetris
{

Game::Game() {}

Game::~Game() {}

bool Game::initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        TETRIS_ERROR("SDL Init Error {0}", SDL_GetError());
        return false;
    }
    constexpr Uint32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;

    _window = SDL_CreateWindow(
        "SDL Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _win_absolute_size.x, _win_absolute_size.y, window_flags);
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

    _lastFrameTime = SDL_GetTicks();

    _spawnPos = {getRandomInt(1, 8), 0};
    _spawnFigureIndex = getRandomInt(0, 4);

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

        const auto bg = color::background;
        SDL_SetRenderDrawColor(_renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(_renderer);

        gameRender();

        SDL_RenderPresent(_renderer);

        limitFPS(60);
    }
}

void Game::gameRender()
{
    AreaElement frame;
    frame.render(_renderer);
    frame.createFrame();

    drawFigure();
}

void Game::drawFigure()
{
    if (_testFrameCounter == _testDelay)
    {
        _testFrameCounter = 0;
        _spawnPos = {_spawnPos.x, _spawnPos.y + 1};

        TETRIS_INFO("y: {0}", _spawnPos.y);

        if (_spawnPos.y == GameField::maxY)
        {
            _spawnPos = {getRandomInt(1, 8), 0};
            _spawnFigureIndex = getRandomInt(0, 4);
        }
    }
    _testFrameCounter++;

    Figure figure;
    figure.render(_renderer);
    figure.create(_spawnFigureIndex, _spawnPos);
}

void Game::limitFPS(Uint32 fpsLimit)
{
    const Uint32 delta = SDL_GetTicks() - _lastFrameTime;
    if (delta < 1000 / fpsLimit)
    {
        SDL_Delay(1000 / fpsLimit - delta);
    }
    _lastFrameTime = SDL_GetTicks();
}
}  // namespace Tetris
