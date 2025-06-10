#ifndef SDLFUNCTIONS_H
#define SDLFUNCTIONS_H

#include "global.h"
#include <SDL3/SDL.h>

void InitSDL(SDL_InitFlags flags);

void CreateSDLWindow(const char *title, int w, int h, SDL_WindowFlags flags);

void CleanupSDL();

#endif