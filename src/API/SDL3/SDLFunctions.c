#include "API/SDL3/SDLFunctions.h"
#include "API/SDL3/global.h"
#include "Utils/numtypes.h"

void InitSDL(SDL_InitFlags flags)
{
    if (SDL_Init(flags) == 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not init SDL: %s\n", SDL_GetError());
		return;
	}
}

void CreateSDLWindow(const char *title, int w, int h, SDL_WindowFlags flags)
{
	sdlExterns.window = SDL_CreateWindow(title, w, h, flags);;
	if (sdlExterns.window == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return;
	}
}

void GetSDLWindowSize(SDL_Window* window, i32* width, i32* height)
{
	if (!SDL_GetWindowSizeInPixels(window, width, height))
    {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not get Window size: %s\n", SDL_GetError());
        return;
	}
}

void CleanupSDL()
{
	SDL_DestroyWindow(sdlExterns.window);
	SDL_Quit();
}