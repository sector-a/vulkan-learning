#include <SDL3/SDL_vulkan.h>
#include "API/SDL3/global.h"
#include "API/Vulkan/vkInstance.h"
#include "API/Vulkan/global.h"

void CreateVulkanInstance(VkInstance* instance)
{
    #define VULKAN_INSTANCE_EXTENSION_COUNT 1
        const char* instanceExtensions[VULKAN_INSTANCE_EXTENSION_COUNT] = {"VK_KHR_get_physical_device_properties2"};

    #ifdef VALIDATION
        #define vkLayerCount 1
        const char* vkLayers[vkLayerCount] = {"VK_LAYER_KHRONOS_validation"};
    #else
        #define vkLayerCount 0
        const char* vkLayers[vkLayerCount] = {};
    #endif

    u32 sdlInstanceExtensionCount = 0;
    const char** sdlInstanceExtensions = SDL_Vulkan_GetInstanceExtensions(&sdlInstanceExtensionCount);

    const char* finalExtensionsNames[sdlInstanceExtensionCount + VULKAN_INSTANCE_EXTENSION_COUNT];
    for (u32 i = 0; i < sdlInstanceExtensionCount; i++)
    {
        finalExtensionsNames[i] = sdlInstanceExtensions[i];
    }

    for (u32 i = sdlInstanceExtensionCount; i < sdlInstanceExtensionCount + VULKAN_INSTANCE_EXTENSION_COUNT; i++)
    {
        finalExtensionsNames[i] = instanceExtensions[i - sdlInstanceExtensionCount];
    }

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = VK_NULL_HANDLE;
    createInfo.pApplicationInfo = VK_NULL_HANDLE;
    createInfo.enabledLayerCount = vkLayerCount;
    createInfo.ppEnabledLayerNames = &vkLayers;
    createInfo.enabledExtensionCount = sdlInstanceExtensionCount + VULKAN_INSTANCE_EXTENSION_COUNT;
    createInfo.ppEnabledExtensionNames = &finalExtensionsNames;

    VK_ASSERT(vkCreateInstance(&createInfo, NULL, instance), "Failed to create Vulkan Instance!");
}

void DestroyVulkanInstance(VkInstance instance)
{
    vkDestroyInstance(instance, NULL);
}