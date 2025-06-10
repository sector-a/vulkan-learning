#include <stdio.h>
#include <SDL3/SDL.h>
#include <vulkan/vulkan.h>
#include "API/SDL3/global.h"
#include "API/SDL3/SDLFunctions.h"
#include "API/Vulkan/global.h"
#include "API/Vulkan/vkFunctions.h"
#include "API/Vulkan/vkInstance.h"
#include "API/Vulkan/vkSurface.h"
#include "API/Vulkan/vkPhysicalDevice.h"

int main() {
	InitSDL(SDL_INIT_VIDEO);
	CreateSDLWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_VULKAN);

    LoadVulkanLoaderFunctions();

    CreateVulkanInstance(&vkExterns.instance);
    LoadVulkanInstanceFunctions(vkExterns.instance);

    CreateVulkanSurface(sdlExterns.window, vkExterns.instance, &vkExterns.surface);
    GetPhysicalDevice(&vkExterns.physicalDevice);
	
	sdlExterns.loopActive = 1;
    while (sdlExterns.loopActive) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                sdlExterns.loopActive = 0;
            }
        }

        // Do game logic, present a frame, etc.
    }

    DestroyVulkanSurface(vkExterns.instance, vkExterns.surface);
    DestroyVulkanInstance(vkExterns.instance);
	CleanupSDL();
}