#ifndef VK_SWAP_CHAIN_H
#define VK_SWAP_CHAIN_H

#include "Vulkan/vulkan.h"
#include "Utils/numtypes.h"

void CreateVulkanSwapChain(VkDevice device, VkSurfaceKHR surface, VkSurfaceFormatKHR surfaceFormat, VkSurfaceCapabilitiesKHR surfaceCapabilities, VkExtent2D swapChainExtent,
    u32 queueFamilyIndex, VkSwapchainKHR* swapChain);

void DestroyVulkanSwapChain(VkDevice device, VkSwapchainKHR swapChain);

#endif