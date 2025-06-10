#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include "API/Vulkan/vkSurface.h"
#include "API/Vulkan/global.h"

void CreateVulkanSurface(SDL_Window* window, VkInstance instance, VkSurfaceKHR* surface)
{
    if (!SDL_Vulkan_CreateSurface(window, instance, VK_NULL_HANDLE, surface))
    {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create Vulkan surface: %s\n", SDL_GetError());
        return;
	}
}

void DestroyVulkanSurface(VkInstance instance, VkSurfaceKHR surface)
{
    SDL_Vulkan_DestroySurface(instance, surface, VK_NULL_HANDLE);
}
