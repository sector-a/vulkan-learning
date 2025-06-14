#ifndef VK_PHYSICAL_DEVICE_H
#define VK_PHYSICAL_DEVICE_H

#include <vulkan/vulkan.h>

void GetPhysicalDevice(VkPhysicalDevice* physicalDevice);

void GetSurfaceFormat(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceFormatKHR* surfaceFormat);

void GetSurfaceCapabilities(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* surfaceCapabilities);

#endif