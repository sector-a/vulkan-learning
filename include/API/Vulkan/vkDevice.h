#ifndef VK_DEVICE_H
#define VK_DEVICE_H

#include <Vulkan/vulkan.h>
#include <numtypes.h>

void CreateVulkanDevice(u32 queueFamilyIndex, VkPhysicalDevice physicalDevice, VkDevice* device);

#endif