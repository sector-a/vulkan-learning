#ifndef VULKAN_GLOBAL_H
#define VULKAN_GLOBAL_H

#define VK_ASSERT(expression, message) \
    if (expression != VK_SUCCESS) { \
        printf(message); \
        exit(1); \
    }

#define VULKAN_INSTANCE_EXTENSION_COUNT 1
extern const char* instanceExtensions[VULKAN_INSTANCE_EXTENSION_COUNT];

#define VULKAN_DEVICE_EXTENSION_COUNT 6
extern const char* deviceExtensions[VULKAN_DEVICE_EXTENSION_COUNT];

#ifdef VALIDATION
    #define vkLayerCount 1
#else
    #define vkLayerCount 0
#endif
extern const char* vkLayers[vkLayerCount];

#include <vulkan/vulkan.h>
#include "API/Vulkan/vkFunctions.h"
#include "stdio.h"
#include "stdlib.h"
#include "Utils/numtypes.h"

typedef struct
{
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice;
    u32 mainQueueFamilyIndex;
    VkDevice device;
    VkQueue queue;
    VkCommandPool renderingCmdPool;
    VkCommandBuffer renderingCmdBuffer;
    VkSurfaceFormatKHR surfaceFormat;
    VkSurfaceCapabilitiesKHR surfaceCapabilities;
    VkSwapchainKHR swapChain;
    VkExtent2D swapChainExtent;
} VkExterns;

extern VkExterns vkExterns;

#endif