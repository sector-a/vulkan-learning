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

    const VkDeviceQueueCreateInfo queueCreateInfos[1] = {queueCreateInfo};
    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.pNext = VK_NULL_HANDLE;
    createInfo.queueCreateInfoCount = 1;
    createInfo.pQueueCreateInfos = queueCreateInfos;
    createInfo.enabledLayerCount = vkLayerCount;
    createInfo.ppEnabledLayerNames = vkLayers;
    createInfo.enabledExtensionCount = VULKAN_DEVICE_EXTENSION_COUNT; 
    createInfo.ppEnabledExtensionNames = deviceExtensions;

    VK_ASSERT(vkCreateDevice(physicalDevice, &createInfo, VK_NULL_HANDLE, device), "Couldn't create logical device!\n");
}