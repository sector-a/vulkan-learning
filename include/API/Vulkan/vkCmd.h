#ifndef VK_CMD_H
#define VK_CMD_H

#include <Vulkan/vulkan.h>
#include "numtypes.h"

void CreateCmdPool(u32 queueFamilyIndex, VkDevice device, VkCommandPool* cmdPool);

void DestroyCmdPool(VkDevice device, VkCommandPool cmdPool);

void AllocateCmdBuffer(VkDevice device, VkCommandPool cmdPool, VkCommandBuffer* cmdBuffers);

#endif