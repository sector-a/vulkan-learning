#ifndef SDL_GLOBAL_H
#define SDL_GLOBAL_H

#define WINDOW_TITLE "Vulkan Studying Shit"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <SDL3/SDL.h>
#include "numtypes.h"

typedef struct
{
    SDL_Window* window;
    u8 loopActive;
} SDLExterns;

extern SDLExterns sdlExterns;

#endif