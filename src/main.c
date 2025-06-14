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
#include "API/Vulkan/vkDevice.h"
#include "API/Vulkan/vkCmd.h"
#include "API/Vulkan/vkSwapChain.h"

int main() {
	InitSDL(SDL_INIT_VIDEO);
	CreateSDLWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_VULKAN);

    LoadVulkanLoaderFunctions();

    CreateVulkanInstance(&vkExterns.instance);
    LoadVulkanInstanceFunctions(vkExterns.instance);

    CreateVulkanSurface(sdlExterns.window, vkExterns.instance, &vkExterns.surface);
    GetPhysicalDevice(&vkExterns.physicalDevice);
    GetSurfaceFormat(vkExterns.physicalDevice, vkExterns.surface, &vkExterns.surfaceFormat);
    GetSurfaceCapabilities(vkExterns.physicalDevice, vkExterns.surface, &vkExterns.surfaceCapabilities);
    CreateVulkanDevice(vkExterns.mainQueueFamilyIndex, vkExterns.physicalDevice, &vkExterns.device);
    LoadVulkanDeviceFunctions(vkExterns.device);
	
    GetDeviceQueue(vkExterns.device, vkExterns.mainQueueFamilyIndex, 0, &vkExterns.queue);
    CreateCmdPool(vkExterns.mainQueueFamilyIndex, vkExterns.device, &vkExterns.renderingCmdPool);
    AllocateCmdBuffer(vkExterns.device, vkExterns.renderingCmdPool, &vkExterns.renderingCmdBuffer);
    CreateVulkanSwapChain(vkExterns.device, vkExterns.surface, vkExterns.surfaceFormat, vkExterns.surfaceCapabilities, vkExterns.swapChainExtent, vkExterns.mainQueueFamilyIndex,
        &vkExterns.swapChain);

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

    DestroyCmdPool(vkExterns.device, vkExterns.renderingCmdPool);
    DestroyVulkanDevice(vkExterns.device);
    DestroyVulkanSurface(vkExterns.instance, vkExterns.surface);
    DestroyVulkanInstance(vkExterns.instance);
	CleanupSDL();
}