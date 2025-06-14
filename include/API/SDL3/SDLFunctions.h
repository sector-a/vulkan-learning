#ifndef SDLFUNCTIONS_H
#define SDLFUNCTIONS_H

#include "global.h"
#include "Utils/numtypes.h"
#include <SDL3/SDL.h>

void InitSDL(SDL_InitFlags flags);

void CreateSDLWindow(const char *title, int w, int h, SDL_WindowFlags flags);

void GetSDLWindowSize(SDL_Window* window, i32* width, i32* height);

void CleanupSDL();

#endif