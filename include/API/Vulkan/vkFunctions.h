#ifndef VK_FUNCTIONS_H
#define VK_FUNCTIONS_H

#include <vulkan/vulkan.h>

#ifdef VK_NO_PROTOTYPES
// vulkan loader functions
extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
extern PFN_vkCreateInstance vkCreateInstance;

// vulkan instance functions
extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
extern PFN_vkCreateDevice vkCreateDevice;
extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
extern PFN_vkDestroyInstance vkDestroyInstance;

// vulkan device functions
extern PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
extern PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
extern PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
extern PFN_vkDestroyCommandPool vkDestroyCommandPool;
extern PFN_vkCreateCommandPool vkCreateCommandPool;
extern PFN_vkGetDeviceQueue vkGetDeviceQueue;
extern PFN_vkDestroyDevice vkDestroyDevice;
#endif

void LoadVulkanLoaderFunctions();
void LoadVulkanInstanceFunctions(VkInstance instance);
void LoadVulkanDeviceFunctions(VkDevice device);

#endif
