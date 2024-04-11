#pragma once

#include "SDL.h"

extern "C" class Game* GlobalGame;

class staticLibrary
{
public:
    static SDL_Window* getWindow();
    static SDL_Renderer* getRenderer();
};
