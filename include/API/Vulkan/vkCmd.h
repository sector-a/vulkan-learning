#ifndef VK_CMD_H
#define VK_CMD_H

#include <Vulkan/vulkan.h>
#include "Utils/numtypes.h"

void CreateVulkanCmdPool(u32 queueFamilyIndex, VkDevice device, VkCommandPool* cmdPool);

void DestroyVulkanCmdPool(VkDevice device, VkCommandPool cmdPool);

void AllocateCmdBuffer(VkDevice device, VkCommandPool cmdPool, VkCommandBuffer* cmdBuffers);

#endif