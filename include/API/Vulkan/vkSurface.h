#ifndef VK_SURFACE_H
#define VK_SURFACE_H

#include <vulkan/vulkan.h>

void CreateVulkanSurface(SDL_Window* window, VkInstance instance, VkSurfaceKHR* surface);

void DestroyVulkanSurface(VkInstance instance, VkSurfaceKHR surface);

#endif