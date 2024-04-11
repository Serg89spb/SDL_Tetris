#include "Game.h"
#include "Utils/Log.h"

int main(int argc, char** argv)
{
    Tetris::Log::Init();
    Tetris::Game game = Tetris::Game();

    if (game.initSDL())
    {
        game.update();
    }
    return 0;
}
