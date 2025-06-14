#ifndef VK_DEVICE_H
#define VK_DEVICE_H

#include <Vulkan/vulkan.h>
#include "Utils/numtypes.h"

void CreateVulkanDevice(u32 queueFamilyIndex, VkPhysicalDevice physicalDevice, VkDevice* device);

void GetDeviceQueue(VkDevice device, u32 queueFamilyIndex, u32 queueCount, VkQueue* queue);

void DestroyVulkanDevice(VkDevice device);

#endif