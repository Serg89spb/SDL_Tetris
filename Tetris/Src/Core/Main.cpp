#include "Game.h"
#include "Utils/staticLibrary.h"

int main(int argc, char** argv)
{
    GlobalGame = new Game();

    GlobalGame->InitSDL();
    GlobalGame->Play();

    return 0;
}
