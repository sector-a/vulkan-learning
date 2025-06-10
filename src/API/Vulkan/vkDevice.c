#include "API/Vulkan/vkDevice.h"
#include "API/Vulkan/global.h"

void CreateVulkanDevice(u32 queueFamilyIndex, VkPhysicalDevice physicalDevice, VkDevice* device)
{
    const float queuePriorities[1] = {1.0f};
    VkDeviceQueueCreateInfo queueCreateInfo = {};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.pNext = VK_NULL_HANDLE;
    queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
    queueCreateInfo.queueCount = 1;
    queueCreateInfo.pQueuePriorities = queuePriorities;

    VkPhysicalDeviceDynamicRenderingFeaturesKHR dynamicRenderingFeatures = {};
    dynamicRenderingFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR;
    dynamicRenderingFeatures.pNext = VK_NULL_HANDLE;
    dynamicRenderingFeatures.dynamicRendering = VK_TRUE;

    VkPhysicalDeviceFeatures2KHR deviceFeatures = {};
    deviceFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR;
    deviceFeatures.pNext = &dynamicRenderingFeatures;

    const VkDeviceQueueCreateInfo queueCreateInfos[1] = {queueCreateInfo};
    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.pNext = &deviceFeatures;
    createInfo.queueCreateInfoCount = 1;
    createInfo.pQueueCreateInfos = queueCreateInfos;
    createInfo.enabledLayerCount = vkLayerCount;
    createInfo.ppEnabledLayerNames = vkLayers;
    createInfo.enabledExtensionCount = VULKAN_DEVICE_EXTENSION_COUNT; 
    createInfo.ppEnabledExtensionNames = deviceExtensions;

    VK_ASSERT(vkCreateDevice(physicalDevice, &createInfo, VK_NULL_HANDLE, device), "Couldn't create logical device!\n");
}

void GetDeviceQueue(VkDevice device, u32 queueFamilyIndex, u32 queueCount, VkQueue* queue)
{
    vkGetDeviceQueue(device, queueFamilyIndex, queueCount, queue);
}

void DestroyVulkanDevice(VkDevice device)
{
    vkDestroyDevice(device, VK_NULL_HANDLE);
}