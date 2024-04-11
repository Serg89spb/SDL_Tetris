#include "Utils/staticLibrary.h"
#include "Core/Game.h"

Game* GlobalGame = nullptr;

SDL_Window* staticLibrary::getWindow()
{
    return GlobalGame->getWindow();
}

SDL_Renderer* staticLibrary::getRenderer()
{
    return GlobalGame->getRenderer();
}
