#include "API/Vulkan/vkCmd.h"
#include "API/Vulkan/global.h"

void CreateCmdPool(u32 queueFamilyIndex, VkDevice device, VkCommandPool* cmdPool)
{
    VkCommandPoolCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    createInfo.pNext = VK_NULL_HANDLE;
    createInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    createInfo.queueFamilyIndex = queueFamilyIndex;

    VK_ASSERT(vkCreateCommandPool(device, &createInfo, VK_NULL_HANDLE, cmdPool), "Couldn't create Command Pool!\n");
}

void DestroyCmdPool(VkDevice device, VkCommandPool cmdPool)
{
    vkDestroyCommandPool(device, cmdPool, VK_NULL_HANDLE);
}

void AllocateCmdBuffer(VkDevice device, VkCommandPool cmdPool, VkCommandBuffer* cmdBuffer)
{
    VkCommandBufferAllocateInfo allocateInfo = {};
    allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocateInfo.pNext = VK_NULL_HANDLE;
    allocateInfo.commandPool = cmdPool;
    allocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocateInfo.commandBufferCount = 1;

    VK_ASSERT(vkAllocateCommandBuffers(device, &allocateInfo, cmdBuffer), "Couldn't allocate Primary Command Buffer!\n");
}