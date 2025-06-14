#include "API/Vulkan/vkSwapChain.h"
#include "API/Vulkan/global.h"
#include "API/SDL3/SDLFunctions.h"
#include "API/SDL3/global.h"
#include "Utils/mathUtils.h"

void CreateVulkanSwapChain(VkDevice device, VkSurfaceKHR surface, VkSurfaceFormatKHR surfaceFormat, VkSurfaceCapabilitiesKHR surfaceCapabilities, VkExtent2D swapChainExtent, 
    u32 queueFamilyIndex, VkSwapchainKHR* swapChain)
{
    u32 swapChainImageCount;
    if (surfaceCapabilities.minImageCount + 1 <= surfaceCapabilities.maxImageCount)
    {
        swapChainImageCount = surfaceCapabilities.minImageCount + 1;
    }
    else
    {
        swapChainImageCount = surfaceCapabilities.minImageCount;
    }

    if (surfaceCapabilities.currentExtent.width != 0xFFFFFFFF)
    {
        swapChainExtent = surfaceCapabilities.currentExtent;
    }
    else
    {
        i32 width;
        i32 height;

        GetSDLWindowSize(sdlExterns.window, &width, &height);

        swapChainExtent.width = width;
        swapChainExtent.height = height;
        
        clamp(&swapChainExtent.width, surfaceCapabilities.minImageExtent.width, surfaceCapabilities.maxImageExtent.width);
        clamp(&swapChainExtent.height, surfaceCapabilities.minImageExtent.height, surfaceCapabilities.maxImageExtent.height);
    }
    
    u32 queueFamilyIndexCount = 1;
    const u32* queueFamilyIndices = {&queueFamilyIndex};

    VkSwapchainCreateInfoKHR createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.pNext = VK_NULL_HANDLE;
    createInfo.surface = surface;
    createInfo.minImageCount = swapChainImageCount;
    createInfo.imageFormat = surfaceFormat.format;
    createInfo.imageColorSpace = surfaceFormat.colorSpace;
    createInfo.imageExtent = swapChainExtent;
    createInfo.imageArrayLayers = 1;
    createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    createInfo.queueFamilyIndexCount = queueFamilyIndexCount;
    createInfo.pQueueFamilyIndices = queueFamilyIndices;
    createInfo.preTransform = surfaceCapabilities.currentTransform;
    createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    createInfo.presentMode = VK_PRESENT_MODE_FIFO_KHR;
    createInfo.clipped = VK_TRUE;
    createInfo.oldSwapchain = VK_NULL_HANDLE;

    VK_ASSERT(vkCreateSwapchainKHR(device, &createInfo, VK_NULL_HANDLE, swapChain), "Couldn't create Vulkan SwapChain!\n");
}

void DestroyVulkanSwapChain(VkDevice device, VkSwapchainKHR swapChain)
{
    vkDestroySwapchainKHR(device, swapChain, VK_NULL_HANDLE);
}