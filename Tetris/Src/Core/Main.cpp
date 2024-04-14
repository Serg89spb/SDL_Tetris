#include "Game.h"
#include "Utils/Log.h"

int main(int argc, char** argv)
{
    tetris::Log::init();
    auto game = tetris::Game();

    if (game.init_sdl())
    {
        game.update();
    }
    return 0;
}
