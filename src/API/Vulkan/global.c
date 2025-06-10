#include "API/Vulkan/global.h"

const char* instanceExtensions[VULKAN_INSTANCE_EXTENSION_COUNT] = {"VK_KHR_get_physical_device_properties2"};
const char* deviceExtensions[VULKAN_DEVICE_EXTENSION_COUNT] = {"VK_KHR_swapchain", 
    "VK_KHR_dynamic_rendering", "VK_KHR_depth_stencil_resolve", "VK_KHR_create_renderpass2", "VK_KHR_multiview", "VK_KHR_maintenance2"};

#ifdef VALIDATION
    const char* vkLayers[vkLayerCount] = {"VK_LAYER_KHRONOS_validation"};
#else
    const char* vkLayers[vkLayerCount] = {};
#endif

VkExterns vkExterns = {};