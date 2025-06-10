#ifndef VULKAN_GLOBAL_H
#define VULKAN_GLOBAL_H

#define VK_ASSERT(expression, message) \
    if (expression != VK_SUCCESS) { \
        printf(message); \
        exit(1); \
    }

#include <vulkan/vulkan.h>
#include "API/Vulkan/vkFunctions.h"
#include "stdio.h"
#include "stdlib.h"
#include "numtypes.h"

typedef struct
{
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice;
    u32 mainQueueFamilyIndex;
} VkExterns;

extern VkExterns vkExterns;

#endif