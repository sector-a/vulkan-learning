#ifndef VK_INSTANCE_H
#define VK_INSTANCE_H

#include <vulkan/vulkan.h>

void CreateVulkanInstance(VkInstance* instance);

void DestroyVulkanInstance(VkInstance instance);

#endif